/*
 * Player.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: woivre_t
 */

#include "../include/Player.h"

Player::Player(int id, int xIso, int yIso, direction direction, int level,
		std::string teamName, ImageManager *imageManager) {
	_id = id;
	_level = level;
	_teamName = teamName;
	_direction = direction;
	_imageManager = imageManager;
	setBasicSprite();
	_sprite.SetPosition(xIso, yIso);
	_sprite.Resize(PLAYER_WIDTH, PLAYER_HEIGHT);
	_busy = false;
	_timeUnit = 1.f / Network::Frequency;
}

Player::~Player() {}


void Player::setBasicSprite() {
	_sprite.SetImage(_imageManager->getImage("player_" + Utils::intToString((int)_direction)));
}

void Player::setActionSprite(const std::string &imageName, int actionDuration) {
	_actionDuration = actionDuration;
	_sprite.SetImage(_imageManager->getImage(imageName));
	_timer.Reset();
	_busy = true;
}

void Player::movePlayer(int xIso, int yIso, direction direction) {
	_direction = direction;
	_sprite.SetPosition(xIso, yIso);
	setBasicSprite();
}

void Player::draw(sf::RenderWindow *app) {
	if (_busy && _timer.GetElapsedTime() >= _actionDuration * _timeUnit)
		setBasicSprite();
	app->Draw(_sprite);
}
