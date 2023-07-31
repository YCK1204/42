#include "Exception.hpp"
#include "Http.hpp"
#include "ft.hpp"
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <sys/wait.h>

pid_t pid;

std::string Http::waitChild(int fd[2])
{
	std::string ret;
	char buf[1001];
	int n, status;

	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		std::cerr << "Error dup2()" << std::endl;
	sleep(1);
	kill(pid, SIGKILL);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) || WEXITSTATUS(status)) {
		std::stringstream ss;
		ss << "Error exit code not successful: ";
		if (WIFSIGNALED(status))
			ss << "signaled(" << WTERMSIG(status) << ")";
		else
			ss << WEXITSTATUS(status);
		FT_THROW(ss.str(), RunCgiException());
	}
	while ((n = read(fd[0], buf, 1)) > 0) {
		buf[n] = '\0';
		ret += buf;
	}
	if (dup2(0, fd[0]) == -1)
		std::cerr << "Error dup2()" << std::endl;
	close(fd[0]);
	return ret;
}

void Http::ft_execve(int fd[2], char** argv, std::string cmd)
{
	if (dup2(fd[1], 1) == -1)
		std::cerr << "Error dup2()" << std::endl;
	close(fd[0]);
	execve(cmd.c_str(), argv, NULL);

	for (int i = 0; argv[i]; i++)
		delete[] argv[i];
	delete[] argv;
	exit(1);
}

char** Http::getArgv(cgis type, std::string file_path, std::string argv, std::string cmd)
{
	char** cmds;

	cmds = new char*[4];

	cmds[0] = ft::strdup(cmd.c_str());
	cmds[1] = ft::strdup(file_path.c_str());
	cmds[3] = NULL;
	if (type == KEY || type == SESSION) {
		cmds[2] = NULL;
	} else {
		cmds[2] = ft::strdup(argv.c_str());
	}
	return cmds;
}

std::string Http::runCgi(cgis type, std::string file_path, std::string argv, std::string cmd)
{
	std::string ret;
	int fd[2];

	if (pipe(fd) == -1) {
		FT_THROW("Error: pipe()", RunCgiException());
	}
	pid = fork();
	if (pid == -1) {
		FT_THROW("Error: fork()", RunCgiException());
	} else if (pid == 0) {
		char** av;

		av = getArgv(type, file_path, argv, cmd);
		ft_execve(fd, av, cmd);
	}
	return waitChild(fd);
}

/* calculator*/
std::string Http::occurDivisionZero(std::string display)
{
	std::string ret, line, file_path;

	file_path = "./docs/fusion_web/calculator.html";
	ret = readFile(file_path);
	std::size_t len = ret.find("name=\"display\" readonly") - 1;
	ret.insert(len, "value=\"" + display + "\" ");
	return ret;
}

std::string Http::cgiCalculator(int clnt_sock)
{
	std::string file_path = "./docs/cgi/calculate.py";

	clients[clnt_sock].cal.result = runCgi(CAL, file_path, clients[clnt_sock].cal.display, PYTHON_PATH);
	if (clients[clnt_sock].cal.result.empty())
		return occurDivisionZero(clients[clnt_sock].cal.display);
	return clients[clnt_sock].cal.result;
}
/* calculator */

/* sha-256 */
std::string Http::cgiSha_256(std::string str)
{
	std::string file_path = "./docs/cgi/sha-256.py";

	return runCgi(SHA, file_path, str, PYTHON_PATH);
}
/* sha-256 */
