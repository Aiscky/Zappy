//
// Tile.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/include
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Fri Jun 26 15:19:32 2015 Thibault WOIVRE
// Last update Tue Jun 30 16:49:55 2015 Thibault WOIVRE
//

#ifndef											TILE_HH
#define											TILE_HH

#include										"../include/includeGraphic.hh"
#include										"../include/Managers.hh"
#include										"../include/Ressource.hh"
#include										"../include/Player.h"
#include										"../include/Egg.h"
#include										"../Utils.hpp"

class											Tile {

public:

	Tile(int x, int y, std::vector<int> ressources);
	~Tile();
	void										setTile(int xIso, int yIso, std::vector<int> ressourcesQuantity);
	void										createPlayer(int id, int direction, int level, std::string teamName, ImageManager *);
	void										insertPlayer(Player *, int id, int direction);
	void										setPlayerLevel(int id, int level);
	void										setPlayerInventory(int id, std::vector<int> &inventory);
	Player										*removePlayer(int id);
	void										setRessourcesSprites(ImageManager *);
	void										drawLayer(int Layer, sf::RenderWindow *);
	void										drawPlayers(sf::RenderWindow *);
	void										draw(sf::RenderWindow *);
	Player										*&getPlayer(int id) {
		return (_players[id]);
	}
	std::map<int, Player *>						&getPlayers() {
		return (_players);
	}
	Egg											*&getEgg(int id) {
		return (_eggs[id]);
	}

private:

	int											_xCartesian;
	int											_yCartesian;
	int											_xIso;
	int											_yIso;
	std::map<int, Player *>						_players;
	std::map<int, Egg *>						_eggs;
	std::map<int, std::map<int, Ressource*> >	_ressourcesObjs;
	std::vector<int>							_ressourcesQuantity;
	//std::map<int, Player>						_players;
};

#endif
