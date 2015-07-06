//
// GameEngine.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Thu Jun 25 15:47:09 2015 Thibault WOIVRE
// Last update Tue Jun 30 15:14:55 2015 Thibault WOIVRE
//

#ifndef			GAMEENGINE_HH
#define			GAMEENGINE_HH

#include		"includeGraphic.hh"
#include		"Network.hh"
#include		"Map.hh"
#include		"Managers.hh"
#include		"EventManager.hh"
#include		"InputManager.h"

class			EventManager;

class			GameEngine {

public:

	static bool		gameEnded;

	GameEngine(Network *);
	~GameEngine();
	bool			setConnection();
	bool			setWindow();
	bool			setMap();
	bool			loadAssets();
	bool			run();
	void			draw();
	void			update();

private:

	Map			*_map;
	Managers		*_managers;
	EventManager	*_eventManager;
};

#endif
