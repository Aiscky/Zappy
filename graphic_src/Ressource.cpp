//
// Ressource.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Mon Jun 29 15:10:46 2015 Thibault WOIVRE
// Last update Mon Jun 29 17:18:56 2015 Thibault WOIVRE
//

#include			"../include/Ressource.hh"

Ressource::Ressource(int x, int y, const sf::Image &image, Type ressourceType) {
	_sprite.SetImage(image);
	_sprite.Resize(RESSOURCE_SIZE, RESSOURCE_SIZE);
	_sprite.SetPosition(x, y);
	_ressourceType = ressourceType;
}


Ressource::~Ressource() {
}

void Ressource::draw(sf::RenderWindow *app) {
	app->Draw(_sprite);
}
