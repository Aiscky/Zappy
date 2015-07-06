//
// Parse.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/client_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Wed Jun 17 18:42:51 2015 Thibault WOIVRE
// Last update Mon Jun 29 13:04:56 2015 manin dylan
//

#include			"../include/ParseClient.hh"

Parse::Parse(char **args) {
  _args = args;
  _teamName = "";
  _host = "";
  _port = 0;
}

Parse::~Parse() {

}

bool				Parse::parse() {
  std::string			arg;

  for(int i = 1; _args[i] && _args[i + 1]; ++i) {
    arg = _args[i];
    if (arg == "-n" && _teamName == "")
      _teamName = std::string(_args[++i]);
    else if (arg == "-p" && _port == 0)
      _port = atoi(_args[++i]);
    else if (arg == "-h" && _host == "")
      _host = std::string(_args[++i]);
    else if (arg == "-n" || arg == "-p" || arg == "-h") {
      std::cerr << "Redefinition of argument" << std::endl;
      return (false);
    }
    else {
      std::cerr << "Invalid argument: " << _args[i] << std::endl;
      return (false);
    }
  }
  if (_teamName == "" || _host == "" || _port == 0) {
    std::cerr << "./client -n teamname -p port -h host" << std::endl;
    return (false);
  }
  return (true);
}

std::string			Parse::getHost() const {
  return (_host);
}

std::string			Parse::getTeamName() const {
  return (_teamName);
}

int				Parse::getPort() const {
  return (_port);
}
