#ifndef IRC_IRCMASTERSERVER_HPP
#define IRC_IRCMASTERSERVER_HPP

#include "IRCClientConnection.hpp"
#include "IRCChannel.hpp"
#include "headers.hpp"

class IRCMasterServer {
private:
	int serverSocket;
	std::vector<IRCClientConnection> clients;
	std::vector<IRCChannel> channels;
	pollfd* fds;
	size_t numFds;
};


#endif //IRC_IRCMASTERSERVER_HPP
