//
// ParseGraphic.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/include
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Mon Jun 22 14:32:28 2015 Thibault WOIVRE
// Last update Thu Jun 25 15:36:27 2015 Thibault WOIVRE
//

#ifndef			PARSEGRAPHIC_HH
#define			PARSEGRAPHIC_HH

#include		<cstdlib>
#include		<iostream>
#include		"../Utils.hpp"

class			Parse {

public:

  Parse(char **av);
  ~Parse();
  bool			parse();
  std::string		getHost() const;
  int			getPort() const;

private:

  char			**_args;
  std::string		_host;
  int			_port;
};

#endif
