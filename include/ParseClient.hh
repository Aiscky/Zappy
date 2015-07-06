//
// Parse.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/client_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Wed Jun 17 18:42:58 2015 Thibault WOIVRE
// Last update Thu Jun 25 15:31:36 2015 Thibault WOIVRE
//

#ifndef			PARSECLIENT_HH
#define			PARSECLIENT_HH

#include		<cstdlib>
#include		"../Utils.hpp"

class			Parse {

public:

  Parse(char **);
  ~Parse();
  bool			parse();
  std::string		getHost() const;
  std::string		getTeamName() const;
  int			getPort() const;

private:

  char			**_args;
  std::string		_teamName;
  std::string		_host;
  int			_port;

};

#endif
