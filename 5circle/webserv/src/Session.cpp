#include "Http.hpp"

SessionData Http::getMemberData(std::string session_id)
{
	for (std::map<std::string, SessionData>::iterator it = session.begin(); it != session.end(); it++) {
		if (!it->first.compare(session_id))
			return it->second;
	}
	return session.begin()->second;
}

void Http::deleteSession(std::string session_id)
{
	for (std::map<std::string, SessionData>::iterator it = session.begin(); it != session.end();) {
		if (!it->first.compare(session_id))
			session.erase(it);
		else
			it++;
	}
}

SessionData Http::makeSession(int clnt_sock)
{
	SessionData ret;

	ret.id = getId(clients[clnt_sock].body_request);
	ret.port = ft_stoi(getPort(clients[clnt_sock].request));
	ret.start_time = std::time(NULL);
	return ret;
}

void Http::checkSession(int clnt_sock)
{
	std::string session_id, cookie;

	cookie = clients[clnt_sock].cookie;
	if (!cookie.empty()) {
		session_id = cookie.substr();
		for (std::map<std::string, SessionData>::iterator it = session.begin(); it != session.end(); it++) {
			if (!it->first.compare(session_id)) {
				if (std::time(NULL) - it->second.start_time > 600)
					session.erase(session_id);
			}
		}
	}
}
