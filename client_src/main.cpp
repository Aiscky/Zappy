//
// main.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/client_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Tue Jun 16 16:31:40 2015 Thibault WOIVRE
// Last update Sun Jul  5 12:57:20 2015 manin dylan
//

#include		"../include/includeClient.hh"
#include		"../include/NetworkClient.hh"
#include		"../include/ParseClient.hh"
#include		"../include/Ia.hh"

int			main(int ac, char **av) {
  Parse			*args;
  NetworkClient		*network;
  Ia			*ia;

  args = new Parse(av);
  if (!args->parse())
    return (1);
  network = new NetworkClient(args->getHost(), args->getPort());
  ia = new Ia(network, args->getTeamName());
  if (!ia->setConnection())
    return (1);
  ia->run();
  return (0);
}
