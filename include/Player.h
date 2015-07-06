/*
 * Player.h
 *
 *  Created on: Jul 1, 2015
 *      Author: woivre_t
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "includeGraphic.hh"
#include "ImageManager.hh"
#include "../Utils.hpp"
#include "Network.hh"

#define PLAYER_HEIGHT 100
#define PLAYER_WIDTH 50
#define TAKE_DURATION 7
#define DROP_DURATION 7

class Player {
public:

	enum direction {
		TOPRIGHT = 1,
		BOTTOMRIGHT = 2,
		BOTTOMLEFT = 3,
		TOPLEFT = 4
	};

	Player(int id, int xIso, int yIso, direction direction, int level, std::string, ImageManager *);
	~Player();
	void draw(sf::RenderWindow *);
	void setBasicSprite();
	void setActionSprite(const std::string &, int duration);
	void movePlayer(int xIso, int yIso, direction direction);
	void setLevel(int level) {
		_level = level;
	}
	void setInventory(std::vector<int> &inventory) {
		_inventory = inventory;
	}

private:
	ImageManager			*_imageManager;
	int						_id;
	int						_level;
	direction 				_direction;
	std::string				_teamName;
	std::vector<int> 		_inventory;
	sf::Sprite				_sprite;
	bool					_busy;
	sf::Clock				_timer;
	float					_timeUnit;
	int						_actionDuration;
};

#endif /* PLAYER_H_ */

