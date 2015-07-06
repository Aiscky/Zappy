//
// GameEngine.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Thu Jun 25 15:46:38 2015 Thibault WOIVRE
// Last update Tue Jun 30 16:43:56 2015 Thibault WOIVRE
//

#include			"../include/GameEngine.hh"

bool				GameEngine::gameEnded = false;

GameEngine::GameEngine(Network *network) {
	_managers = new Managers();
	_managers->setNetwork(network);
}

GameEngine::~GameEngine() {}

bool				GameEngine::setConnection() {
	if (_managers->getNetwork()->Connect())
		return (true);
	return (false);
}

bool				GameEngine::setWindow() {
	_managers->setApp(new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), WINDOW_NAME));
	_managers->getApp()->SetFramerateLimit(60);
	return (true);
}

bool				GameEngine::setMap() {
	std::vector<std::string>	*buffer;

	buffer = _managers->getNetwork()->Receive();
	_map = new Map(_managers);
	if ((*buffer)[0] == "BIENVENUE" && buffer->size() == 1)
		_managers->getNetwork()->Send(std::string("GRAPHIC\n"));
	return (true);
}

bool				GameEngine::loadAssets() {
	_managers->setImageManager(new ImageManager());
	if (!_managers->getImageManager()->initialize())
		return (false);
	return (true);
}

bool				GameEngine::run() {
	std::vector<std::string>	*serverInput;
	InputManager				inputManager(_managers, _map);

	_eventManager = new EventManager(_map, _managers);
	while (_managers->getApp()->IsOpened()) {

		serverInput = _managers->getNetwork()->Select();

		for (size_t i = 0; i != serverInput->size(); ++i)
			_eventManager->eventHandler((*serverInput)[i]);

		inputManager.getEvent();

		_managers->getApp()->Clear();
		draw();
		_managers->getApp()->Display();
		if (gameEnded == true)
			_managers->getApp()->Close();

	}
	return (true);
}

void				GameEngine::draw() {
	_map->draw(_managers->getApp());
}
