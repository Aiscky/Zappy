//
// Network.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/serv
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Tue Jun 16 15:39:38 2015 Thibault WOIVRE
// Last update Sat Jun 27 18:46:37 2015 Thibault WOIVRE
//

#ifndef					NETWORK_HH
#define					NETWORK_HH

#include				"serveur.h"

#include				"includeGraphic.hh"
#include				"../Utils.hpp"

class					Network {

public:

	static int			Frequency;

	Network(std::string, int);
	~Network();
	bool							Connect();
	void							Send(std::string);
	std::vector<std::string>		*Receive();
	std::vector<std::string>		*Select();
	void							setTimeout(int frequency) {
		float						waitTime;

		Frequency = frequency;
		waitTime = Utils::min(7.f / (float)frequency, 0.01f);
		_timeout.tv_sec = floor(waitTime * 1000000) / 1000000;
		_timeout.tv_usec = (waitTime - _timeout.tv_sec) * 1000000;
		_isTimeout = true;
	}


private:

	int							_socket;
	int							_port;
	std::string					_host;
	fd_set						_readfds;
	struct timeval				_timeout;
	bool						_isTimeout;
};

#endif
