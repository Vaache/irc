#include "ircserv.hpp"
#include <iostream>
#include <ostream>

int main(int ac, char ** av) {
	if (ac != 3) {
		std::cout << "Please enter the correct port and password." << std::endl;
		return 1;
	}
	const int lvl = 1;
	String sport = av[1];
	String passwd = av[2];
	int port = atoi(sport.c_str());
	int clientSock;
	int servSock = socket(AF_INET, SOCK_STREAM, 0);

	if (servSock < 0) {
		std::cerr << "servSock" << strerror(errno) << std::endl;
		return 1;
	}

	if (setsockopt(servSock, SOL_SOCKET, SO_REUSEADDR, (void *)&lvl, sizeof(lvl)) < 0) {
		std::cerr << "setsockopt" << strerror(errno) << std::endl;
	}

	struct sockaddr_in in, client_in;
	socklen_t clientLen = sizeof(client_in);

	memset((void*)&in, 0, sizeof(in));
	in.sin_family = AF_INET;
	in.sin_addr.s_addr = INADDR_ANY;
	in.sin_port = htons(port);


	if (bind(servSock, (struct sockaddr *)&in, sizeof(in)) == -1) {
		std::cerr << "bind" << strerror(errno) << std::endl;
		return 1;
	}

    if (listen(servSock, 10) == -1) {
		std::cerr << "listen" << strerror(errno) << std::endl;
        return 1;
	}

	while (1) {
		clientSock = accept(servSock, (struct sockaddr *)&client_in, &clientLen);
		if (clientSock < 0) {
			std::cerr << "accept" << strerror(errno) << std::endl;
			continue;
		}
		char buff[1024] = {0};

		while (recv(clientSock, buff, sizeof(buff), 0) != -1)
			std::cout << buff;
	}

	return 0;
}
