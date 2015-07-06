//
// Tile.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Fri Jun 26 15:19:18 2015 Thibault WOIVRE
// Last update Tue Jun 30 19:47:24 2015 Thibault WOIVRE
//

#include			"../include/Tile.hh"

Tile::Tile(int x, int y, std::vector<int> ressourcesQuantity) {
	_xCartesian = x;
	_yCartesian = y;
	_ressourcesQuantity = ressourcesQuantity;
	_xIso = Utils::cartesianToIsoX(_xCartesian * TILE_SIZE, _yCartesian * TILE_SIZE);
	_yIso = Utils::cartesianToIsoY(_xCartesian * TILE_SIZE, _yCartesian * TILE_SIZE);
}

Tile::~Tile() {
	//TODO: Do destructor
}

void										Tile::setTile(int x, int y, std::vector<int> ressourcesQuantity) {
	_xCartesian = x;
	_yCartesian = y;
	_ressourcesQuantity = ressourcesQuantity;
	_xIso = Utils::cartesianToIsoX(_xCartesian * TILE_SIZE, _yCartesian * TILE_SIZE);
	_yIso = Utils::cartesianToIsoY(_xCartesian * TILE_SIZE, _yCartesian * TILE_SIZE);
}

void 										Tile::setRessourcesSprites(ImageManager *imageManager) {
	sf::Vector2f							vectorUnit;
	int										x;
	int										y;
	int										type;

	for (size_t x = 0; x != _ressourcesObjs.size(); ++x) {
		for (size_t y = 0; y != _ressourcesObjs.size(); ++y) {
			_ressourcesObjs[x][y] = NULL;
		}
	}
	vectorUnit.x = TILE_SIZE / 3;
	vectorUnit.y = TILE_SIZE / 6;
	for (int i = 0; i != 7; ++i) {
		do {
			x = rand() % 3;
			y = rand() % 3;
		}
		while (_ressourcesObjs[x][y] != NULL);
		_ressourcesObjs[x][y] = new Ressource(_xIso + vectorUnit.x * (x - y - 0.5), _yIso + vectorUnit.y * (x + y - 0.5),
				imageManager->getImage("ressource_" + Utils::intToString(i)), (Ressource::Type)i);
	}
}

void										Tile::drawLayer(int layer, sf::RenderWindow *app) {
	int										x;
	int										y;

	x = Utils::min(layer, 2);
	y = layer - x;
	for (; x >= 0 && y < 3 ; ++y) {
		if (_ressourcesObjs[x][y] != NULL && _ressourcesQuantity[_ressourcesObjs[x][y]->getRessourceType()] > 0)
			_ressourcesObjs[x][y]->draw(app);
		x--;
	}
}

void										Tile::drawPlayers(sf::RenderWindow *app) {
	for (std::map<int, Player *>::iterator it = _players.begin(); it != _players.end(); ++it) {
		it->second->draw(app);
	}
}

Player										*Tile::removePlayer(int id) {
	Player									*player;

	player = _players[id];
	_players.erase(id);
	return (player);
}

void										Tile::draw(sf::RenderWindow *app) {
	drawLayer(0, app);
	drawLayer(1, app);
	drawLayer(2, app);

	/* Draw Player */
	drawPlayers(app);

	drawLayer(3, app);
	drawLayer(4, app);
}

void 										Tile::createPlayer(int id, int direction, int level,
		std::string teamName, ImageManager *imageManager) {
	_players[id] = new Player(id, _xIso - PLAYER_WIDTH / 2 , _yIso + TILE_SIZE / 2 - PLAYER_HEIGHT,
			(Player::direction)direction, level, teamName, imageManager);
}

void										Tile::insertPlayer(Player *player, int id, int direction) {
	player->movePlayer(_xIso - PLAYER_WIDTH / 2 , _yIso + TILE_SIZE / 2 - PLAYER_HEIGHT,
			(Player::direction)direction);
	_players[id] = player;
}

void										Tile::setPlayerLevel(int id, int level) {
	_players[id]->setLevel(level);
}

void										Tile::setPlayerInventory(int id, std::vector<int> &inventory) {
	_players[id]->setInventory(inventory);
}
