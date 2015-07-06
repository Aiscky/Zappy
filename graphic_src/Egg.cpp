/*
 * Egg.cpp
 *
 *  Created on: Jul 5, 2015
 *      Author: woivre_t
 */

#include "../include/Egg.h"

Egg::Egg(int xIso, int yIso, bool status, ImageManager *imageManager) {
	if (status == Egg::HATCHED)
		_sprite.SetImage(_imageManager->getImage("hatched_egg"));
	if (status == Egg::NOTHATCHED)
		_sprite.SetImage(_imageManager->getImage("egg"));
	_sprite.SetPosition(xIso, yIso);
	_sprite.Resize(EGG_HEIGHT, EGG_WIDTH);
}

Egg::~Egg() {
}

void Egg::draw(sf::RenderWindow *app) {
	app->Draw(_sprite);
}
