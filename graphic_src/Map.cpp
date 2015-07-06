//
// Map.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Fri Jun 26 15:16:19 2015 Thibault WOIVRE
// Last update Tue Jun 30 16:27:46 2015 Thibault WOIVRE
//

#include			"../include/Map.hh"

Map::Map(Managers *managers) {
	_managers = managers;
	_isMapTextureLoaded = false;
	_width = 0;
	_height = 0;
	for (size_t x = 0; x != _width; ++x) {
		for (size_t y = 0; y != _height; ++y) {
			_contentMap[x][y] = NULL;
		}
	}
}

Map::~Map() {
	std::map<int, std::map<int, Tile *> >::iterator	it;
	/* suppression */
}


void				Map::createTile(int x, int y, std::vector<int> rsc, ImageManager *imageManager) {
	_contentMap[x][y] = new Tile(x, y, rsc);
	_contentMap[x][y]->setRessourcesSprites(imageManager);
}

void				Map::setTile(int x, int y, std::vector<int> rsc) {
	_contentMap[x][y]->setTile(x, y, rsc);
}

void				Map::setWidth(int width) {
	_width = width;
}

int					Map::getWidth() const {
	return (_width);
}

void				Map::setHeight(int height) {
	_height = height;
}

int					Map::getHeight() const {
	return (_height);
}

void				Map::setTexture(int x, int y) {
	int				xiso;
	int				yiso;

	_textureMap[x][y].Resize(TILE_SIZE * 2, TILE_SIZE);
	xiso = Utils::cartesianToIsoX(x * TILE_SIZE, y * TILE_SIZE) - TILE_SIZE;
	yiso = Utils::cartesianToIsoY(x * TILE_SIZE, y * TILE_SIZE);
	_textureMap[x][y].SetPosition(xiso, yiso);
}

void				Map::loadMapTexture() {
	int				tmp;

	for (int x = 0; x != _width; ++x) {
		for (int y = 0; y != _height; ++y) {
			tmp = rand() % 4;
			_textureMap[x][y].SetImage(_managers->getImageManager()->getImage(std::string("soil_") +
					Utils::intToString(tmp)));
			setTexture(x, y);
		}
	}
	_isMapTextureLoaded = true;
}

void				Map::drawLayer(int layer, sf::RenderWindow *app) {
	int										x;
	int										y;

	x = Utils::min(layer, _height);
	y = layer - x;
	for (; x >= 0 && y < _height ; ++y) {
		if (_contentMap[x][y] != NULL)
			_contentMap[x][y]->draw(app);
		x--;
	}
}

void				Map::draw(sf::RenderWindow *app) {


	if (_isMapTextureLoaded) {
		for(int x = 0; x != _width; ++x) {
			for (int y = 0; y != _height; ++y) {
				_managers->getApp()->Draw(_textureMap[x][y]);
			}
		}
	}
	for (size_t i = 0; i != _width + _height; ++i) {
		drawLayer(i, app);
	}
}

bool 				Map::isTile(int x, int y) {
	if (_contentMap[x][y] == NULL)
		return (false);
	return (true);
}

void 				Map::createPlayer(int id, int x, int y, int direction,
		int level, std::string teamName) {
	_playersMap[id].x = x;
	_playersMap[id].y = y;
	_contentMap[x][y]->createPlayer(id, direction, level, teamName, _managers->getImageManager());
}

void 				Map::movePlayer(int id, int x, int y, int direction) {
	Player			*player;

	player = _contentMap[_playersMap[id].x][_playersMap[id].y]->removePlayer(id);
	_contentMap[x][y]->insertPlayer(player, id, direction);
	_playersMap[id].x = x;
	_playersMap[id].y = y;
}

void				Map::addTeamName(std::string teamName) {
	_teamNames.push_back(teamName);
}

void				Map::setFrequency(int frequency) {
	_frequency = frequency;
}

void				Map::setPlayerLevel(int id, int level) {
	if (_playersMap.find(id) != _playersMap.end())
		_contentMap[_playersMap[id].x][_playersMap[id].y]->setPlayerLevel(id, level);
}

void				Map::setPlayerInventory(int id, std::vector<int> &inventory) {
	if (_playersMap.find(id) != _playersMap.end())
		_contentMap[_playersMap[id].x][_playersMap[id].y]->setPlayerInventory(id, inventory);
}
