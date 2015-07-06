//
// Map.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/include
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Fri Jun 26 15:14:00 2015 Thibault WOIVRE
// Last update Tue Jun 30 16:21:15 2015 Thibault WOIVRE
//

#ifndef				MAP_HH
#define				MAP_HH

#include			"includeGraphic.hh"
#include			"Tile.hh"

class				Map {

public:

  Map(Managers *);
  ~Map();
  int				getWidth() const;
  void				setWidth(int);
  int				getHeight() const;
  void				setHeight(int);
  void				createTile(int, int, std::vector<int>, ImageManager *);
  void				setTile(int, int, std::vector<int>);
  bool				isTile(int x, int y);
  void				setTexture(int, int);
  void				loadMapTexture();
  void				createPlayer(int id, int x, int y, int direction, int level, std::string teamName);
  void				movePlayer(int id, int x, int y, int direction);
  void				setPlayerLevel(int id, int level);
  void				setPlayerInventory(int id, std::vector<int> &inventory);
  void				setFrequency(int timeUnit);
  void				addTeamName(std::string);
  void				draw(sf::RenderWindow *);
  void				drawLayer(int, sf::RenderWindow *);
  Tile				*&getTile(int x, int y) {
	  return (_contentMap[x][y]);
  }
  Player			*&getPlayer(int id) {
	  return (_contentMap[_playersMap[id].x][_playersMap[id].y]->getPlayer(id));
  }
  Egg				*&getEgg(int id) {
	  return (_contentMap[_eggsMap[id].x][_eggsMap[id].y]->getEgg(id));
  }
  const sf::Vector2f &getPlayerCoordinates(int id) {
	  return (_playersMap[id]);
  }
  std::map<int, sf::Vector2f> &getPlayersCoordinates() {
	  return (_playersMap);
  }

private:

  int											_width;
  int											_height;
  sf::Sprite									_background;
  Managers										*_managers;
  bool											_isMapTextureLoaded;
  std::map<int, sf::Vector2f>					_playersMap;
  std::map<int, sf::Vector2f>					_eggsMap;
  std::map<int, std::map<int, Tile*> > 			_contentMap;
  std::map<int, std::map<int, sf::Sprite > >	_textureMap;
  std::vector<std::string>						_teamNames;
  float											_frequency;
};

#endif
