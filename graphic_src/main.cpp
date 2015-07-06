//
// main.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Mon Jun 22 14:17:10 2015 Thibault WOIVRE
// Last update Tue Jun 30 15:14:56 2015 Thibault WOIVRE
//

#include		"../include/Network.hh"
#include		"../include/ParseGraphic.hh"
#include		"../include/GameEngine.hh"
#include		"../include/ImageManager.hh"

int			main(int ac, char **av) {
	Parse                 *args;
	Network               *network;
	GameEngine		*engine;

	srand(time(NULL));
	args = new Parse(av);
	if (!args->parse())
		return (1);
	network = new Network(args->getHost(), args->getPort());
	engine = new GameEngine(network);
	if (!engine->setConnection())
		return (1);
	if (!engine->setWindow())
		return (1);
	if (!engine->setMap())
		return (1);
	if (!engine->loadAssets())
		return (1);
	engine->run();
	return (0);
}
