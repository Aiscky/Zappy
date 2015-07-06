//
// Network.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/serv
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Tue Jun 16 15:39:38 2015 Thibault WOIVRE
// Last update Sun Jul  5 12:55:16 2015 manin dylan
//

#ifndef					NETWORKCLIENT_HH
#define					NETWORKCLIENT_HH

# include               <stdlib.h>
# include               <stdio.h>
# include               <stdarg.h>
# include               <stdbool.h>
# include               <netdb.h>
# include               <sys/types.h>
# include               <sys/time.h>
# include               <sys/socket.h>
# include               <sys/select.h>
# include               <netinet/in.h>
# include               <unistd.h>
# include               <fcntl.h>
# include               <netinet/in.h>
# include               <arpa/inet.h>
# include               <string.h>
# include               <signal.h>
# include               <errno.h>
# include               <time.h>

#include				"includeGraphic.hh"
#include				"../Utils.hpp"

class					NetworkClient {

public:

  NetworkClient(std::string, int);
  ~NetworkClient();
  bool							Connect();
  void							Send(std::string);
  std::vector<std::string>		*Receive();
  std::vector<std::string>		*Select();

private:

  int							_socket;
  std::string					_host;
  int							_port;
  fd_set						_readfds;
  struct timeval				_timeout;
};

#endif
