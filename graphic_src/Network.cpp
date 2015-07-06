//
// Network.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/client
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Tue Jun 16 15:41:17 2015 Thibault WOIVRE
// Last update Sat Jun 27 18:46:58 2015 Thibault WOIVRE
//

#include		"../include/Network.hh"

int 			Network::Frequency = 1;

Network::Network(std::string host, int port) {
	_host = host;
	_port = port;
	_timeout.tv_sec = 0;
	_timeout.tv_usec = 0;
}

Network::~Network() {
	close(_socket);
}

bool			Network::Connect() {
	struct protoent	*pe;
	struct sockaddr_in	addr;
	struct hostent	*host;

	if ((pe = getprotobyname("TCP")) == NULL) {
		std::cerr << "Error: cannot get struct protoent" << std::endl;
		return (false);
	}
	if ((host = gethostbyname(_host.c_str())) == NULL) {
		std::cout << "Can't resolve host" << std::endl;
		return (false);
	}
	if ((_socket = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1) {
		std::cerr << "Error: cannot create socket\n" << std::endl;
		exit(EXIT_FAILURE);
	}
	addr.sin_family = AF_INET;
	addr.sin_port = htons(_port);
	addr.sin_addr = *(struct in_addr *)host->h_addr;
	if (connect(_socket, (const  struct sockaddr *)&(addr), sizeof(addr)) == -1) {
		perror("connect");
		return (false);
	}
	return (true);
}

std::vector<std::string> 		*Network::Receive() {
	int							tmp;
	char							*buffer;
	std::vector<std::string>		*input;
	static std::string			rest;

	buffer = (char *)malloc(GRAPHIC_BUFFER + 1);
	tmp = recv(_socket, buffer, GRAPHIC_BUFFER, 0);
	if (tmp <= 0) {
		std::cerr << "Server disconnected" << std::endl;
		//TODO close socket
		exit(EXIT_FAILURE);
	}
	buffer[tmp] = 0;
	input = Utils::split(std::string(buffer), "\n");
	if (!rest.empty()) {
		(*input)[0] = rest + (*input)[0];
		rest.clear();
	}
	if (buffer[tmp - 1] != '\n') {
		rest = input->back();
		input->pop_back();
	}
	return (input);
}

void						Network::Send(std::string str) {
	if (send(_socket, str.c_str(), str.length(), 0) < 0) {
		std::cerr << "Error in send" << std::endl;
		exit(EXIT_FAILURE);
	}
}

std::vector<std::string>	*Network::Select() {
	std::vector<std::string>	*input;
	struct timeval			timeout;

	FD_ZERO(&_readfds);
	FD_SET(_socket, &_readfds);
	timeout.tv_sec = _timeout.tv_sec;
	timeout.tv_usec = _timeout.tv_usec;
	if (_isTimeout)
		select(FD_SETSIZE, &_readfds, NULL, NULL, &timeout);
	else
		select(FD_SETSIZE, &_readfds, NULL, NULL, NULL);
	if (FD_ISSET(_socket, &_readfds)) {
		input = Receive();
		return (input);
	}
	input = new std::vector<std::string>();
	return (input);
}
