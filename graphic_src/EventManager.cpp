//
// EventManager.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Sat Jun 27 17:00:57 2015 Thibault WOIVRE
// Last update Tue Jun 30 15:51:22 2015 Thibault WOIVRE
//

#include			"../include/EventManager.hh"

EventManager::EventManager(Map *map, Managers *managers) {
  _map = map;
  _managers = managers;
  _fonctions["msz"] = &EventManager::setDimensions;
  _fonctions["bct"] = &EventManager::setTile;
  _fonctions["pnw"] = &EventManager::createPlayer;
  _fonctions["ppo"] = &EventManager::movePlayer;
  _fonctions["tna"] = &EventManager::addTeamName;
  _fonctions["sgt"] = &EventManager::setFrequency;
  _fonctions["plv"] = &EventManager::setPlayerLevel;
  _fonctions["pin"] = &EventManager::setPlayerInventory;
  _fonctions["suc"] = &EventManager::unknownCommand;
  _fonctions["sbp"] = &EventManager::wrongArgument;
  _fonctions["pgt"] = &EventManager::takeRessource;
  _fonctions["pdr"] = &EventManager::dropRessource;
  _fonctions["pie"] = &EventManager::startIncantation;
  _fonctions["pic"] = &EventManager::endIncantation;
  _fonctions["pex"] = &EventManager::expulse;
  _fonctions["pbc"] = &EventManager::speak;
  _fonctions["smg"] = &EventManager::serverMsg;
  _fonctions["pfk"] = &EventManager::playerLaying;
  _fonctions["pdi"] = &EventManager::playerDie;
  _fonctions["enw"] = &EventManager::eggLayed;
  _fonctions["eht"] = &EventManager::eggHatched;
  _fonctions["ebo"] = &EventManager::playerBorn;
  _fonctions["edi"] = &EventManager::eggRotted;
  _fonctions["seg"] = &EventManager::gameEnd;
}

EventManager::~EventManager() {}

void					EventManager::eventHandler(std::string &cmd) {
  std::vector<std::string>	*parsedCmd;

  parsedCmd = Utils::split(cmd, " ");
  if (_fonctions.find((*parsedCmd)[0]) == _fonctions.end())
    return;
  (this->*_fonctions[(*parsedCmd)[0]])(parsedCmd);
}

void					EventManager::setDimensions(std::vector<std::string> *args) {
	sf::Vector2f	center;
	sf::Vector2f	halfSize;

	if (args->size() != 3)
		return;

	_map->setWidth(Utils::stringToInt((*args)[1]));
	_map->setHeight(Utils::stringToInt((*args)[2]));
	_map->loadMapTexture();
	_managers->getViewManager()->setWidth(_map->getWidth());
	_managers->getViewManager()->setHeight(_map->getHeight());
	center = _managers->getViewManager()->getVisualFieldCenter();
	halfSize = _managers->getViewManager()->getVisualFieldHalfSize();
	_managers->getViewManager()->setView(center, halfSize);
	_managers->getViewManager()->setVisualFieldRect(_managers->getViewManager()->getView().GetRect());
}

void					EventManager::setTile(std::vector<std::string> *args) {
  std::map<int, std::map<int, Tile *> >	tab;
  std::vector<int>						rsc;
  int									x;
  int									y;

  x = Utils::stringToInt((*args)[1]);
  y = Utils::stringToInt((*args)[2]);
  rsc.push_back(Utils::stringToInt((*args)[3]));
  rsc.push_back(Utils::stringToInt((*args)[4]));
  rsc.push_back(Utils::stringToInt((*args)[5]));
  rsc.push_back(Utils::stringToInt((*args)[6]));
  rsc.push_back(Utils::stringToInt((*args)[7]));
  rsc.push_back(Utils::stringToInt((*args)[8]));
  rsc.push_back(Utils::stringToInt((*args)[9]));

  if (!_map->isTile(x, y))
    _map->createTile(x, y, rsc, _managers->getImageManager());
  else
    _map->setTile(x, y, rsc);
}

void					EventManager::createPlayer(std::vector<std::string> *args) {
	int					id;
	int					x;
	int					y;
	int					level;
	int					direction;

	id = Utils::stringToInt((*args)[1]);
	x = Utils::stringToInt((*args)[2]);
	y = Utils::stringToInt((*args)[3]);
	direction = Utils::stringToInt((*args)[4]);
	level = Utils::stringToInt((*args)[5]);
	_map->createPlayer(id, x, y, direction, level, (*args)[5]);
}

void					EventManager::movePlayer(std::vector<std::string> *args) {
	int					id;
	int					x;
	int					y;
	int					direction;

	id = Utils::stringToInt((*args)[1]);
	x = Utils::stringToInt((*args)[2]);
	y = Utils::stringToInt((*args)[3]);
	direction = Utils::stringToInt((*args)[4]);

	_map->movePlayer(id, x, y, direction);
}

void					EventManager::addTeamName(std::vector<std::string> *args) {
	_map->addTeamName((*args)[1]);
}

void					EventManager::setFrequency(std::vector<std::string> *args) {
	int					frequency;

	frequency = Utils::stringToInt((*args)[1]);
	_map->setFrequency(frequency);
	_managers->getNetwork()->setTimeout(frequency);
}

void					EventManager::unknownCommand(std::vector<std::string> *args) {
	std::cerr << "zappy_graphic: unknown command" << std::endl;
}

void					EventManager::wrongArgument(std::vector<std::string> *args) {
	std::cerr << "zappy_graphic: wrong arguments" << std::endl;
}

void 					EventManager::setPlayerLevel(std::vector<std::string>* args) {
	int					id;
	int					level;

	id = Utils::stringToInt((*args)[1]);
	level = Utils::stringToInt((*args)[2]);
	_map->setPlayerLevel(id, level);
}

void 					EventManager::setPlayerInventory(std::vector<std::string>* args) {
	int					id;
	std::vector<int>	inventory;

	id = Utils::stringToInt((*args)[1]);
	inventory.push_back(Utils::stringToInt((*args)[4]));
	inventory.push_back(Utils::stringToInt((*args)[5]));
	inventory.push_back(Utils::stringToInt((*args)[6]));
	inventory.push_back(Utils::stringToInt((*args)[7]));
	inventory.push_back(Utils::stringToInt((*args)[8]));
	inventory.push_back(Utils::stringToInt((*args)[9]));
	inventory.push_back(Utils::stringToInt((*args)[10]));
	_map->setPlayerInventory(id, inventory);
}

void 					EventManager::takeRessource(std::vector<std::string>* args) {
	int					id;

	id = Utils::stringToInt((*args)[1]);
	_map->getPlayer(id)->setActionSprite("player_take", 7);
}

void 					EventManager::dropRessource(std::vector<std::string>* args) {
	int					id;

	id = Utils::stringToInt((*args)[1]);
	_map->getPlayer(id)->setActionSprite("player_take", 7);
}

void					EventManager::startIncantation(std::vector<std::string> *args) {
	for (size_t i = 3; i != args->size(); ++i) {
		_map->getPlayer(Utils::stringToInt((*args)[i]))->setActionSprite("player_incantation", 300);
	}
}

void					EventManager::speak(std::vector<std::string> *args) {}

void					EventManager::expulse(std::vector<std::string> *args) {
	//TODO expulse
}

void 					EventManager::endIncantation(std::vector<std::string>* allocator) {
	//TODO ADD SOUND FOR END INCANTATION
}

void					EventManager::serverMsg(std::vector<std::string> *args) {
	//TODO handle server msg
}

void 					EventManager::playerDie(std::vector<std::string> *args) {
	int					id;
	sf::Vector2f		xy;
	Tile				*tile;
	Player				*player;

	id = Utils::stringToInt((*args)[1]);
	xy = _map->getPlayerCoordinates(id);
	tile = _map->getTile(xy.x, xy.y);
	_map->getPlayersCoordinates().erase(id);
	tile->getPlayers().erase(id);
}

void 					EventManager::playerLaying(std::vector<std::string>* allocator) {
}

void 					EventManager::eggLayed(std::vector<std::string>* allocator) {
}

void 					EventManager::playerBorn(std::vector<std::string>* allocator) {
}

void 					EventManager::eggHatched(std::vector<std::string>* allocator) {
}

void 					EventManager::eggRotted(std::vector<std::string>* allocator) {
}

void					EventManager::gameEnd(std::vector<std::string>* allocator) {
	GameEngine::gameEnded = true;
}
