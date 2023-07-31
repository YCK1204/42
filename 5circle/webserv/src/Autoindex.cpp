#include "Http.hpp"
#include "Location.hpp"

#include <iomanip>

bool compareFiles(const FileInfo& file1, const FileInfo& file2)
{
	return file1.name < file2.name;
}

std::string Http::formatSize(double size)
{
	const char* units[] = { "B", "KB", "MB", "GB", "TB" };
	int unitIndex = 0;
	while (size >= 1024 && unitIndex < 4) {
		size /= 1024;
		unitIndex++;
	}

	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << size << " " << units[unitIndex];
	return oss.str();
}

std::string Http::formatTime(const time_t& time)
{
	struct tm* timeinfo;
	char buffer[80];
	timeinfo = localtime(&time);
	strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", timeinfo);
	return std::string(buffer);
}

std::string Http::buildAutoindex(std::string server_root, std::string location_root)
{
	std::string ret, msg, dir_root;
	DIR* dir;
	struct dirent* entry;
	struct stat file_stat;
	std::vector<FileInfo> files;

	dir_root = server_root;
	if (location_root[0] == '/')
		location_root = location_root.substr(1);
	dir_root += location_root;
	dir = opendir(dir_root.c_str());
	if (dir) {
		while ((entry = readdir(dir)) != NULL) {
			std::string file_path = dir_root + "/" + entry->d_name;
			if (stat(file_path.c_str(), &file_stat) == -1) {
				err = 503;
				return "";
			}
			FileInfo file;
			file.name = static_cast<std::string>(entry->d_name);
			file.lastModified = file_stat.st_mtime;
			file.size = file_stat.st_size;
			if (S_ISDIR(file_stat.st_mode))
				file.is_dir = true;
			else
				file.is_dir = false;
			files.push_back(file);
		}
		std::sort(files.begin(), files.end(), compareFiles);
		msg += "    <table>\n<tr><th>Name</th><th>Last Modified</th><th>Size</th></tr>\n";
		for (std::vector<FileInfo>::iterator it = files.begin(); it != files.end(); it++) {
			msg += "    <tr>";
			if (it->is_dir)
				msg += "        <td><a href=\"" + it->name + "/\">" + it->name + "/</a></td>\n";
			else
				msg += "        <td><a href=\"" + it->name + "\">" + it->name + "</a></td>\n";
			msg += "        <td>" + formatTime(it->lastModified) + "</td>\n";
			double fileSize = static_cast<double>(it->size);
			msg += "        <td>" + formatSize(fileSize) + "</td>\n";
			msg += "    </tr>\n";
		}
		msg += "    </table>\n";
		ret = buildHtml(msg);
	} else {
		err = 500;
		return "";
	}
	return ret;
}
