//
// Parse.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Mon Jun 22 14:33:05 2015 Thibault WOIVRE
// Last update Mon Jun 22 17:37:14 2015 Thibault WOIVRE
//

#include			"../include/ParseGraphic.hh"

Parse::Parse(char **args) {
  _args = args;
  _port = 0;
  _host = "";
}

Parse::~Parse() {}

bool                            Parse::parse() {
  std::string                   arg;

  for(int i = 1; _args[i] && _args[i + 1]; ++i) {
    arg = _args[i];
    if (arg == "-p" && _port == 0)
      _port = atoi(_args[++i]);
    else if (arg == "-h" && _host == "")
      _host = std::string(_args[++i]);
    else if (arg == "-p" || arg == "-h") {
      std::cerr << "Redefinition of argument" << std::endl;
      return (false);
    }
    else {
      std::cerr << "Invalid argument: " << _args[i] << std::endl;
      return (false);
    }
  }
  if ( _host == "" || _port == 0) {
    std::cerr << "./graphic -p port -h host" << std::endl;
    return (false);
  }
  return (true);
}

std::string			Parse::getHost() const {
  return (_host);
}

int				Parse::getPort() const {
  return (_port);
}
