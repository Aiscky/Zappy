//
// ImageManager.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Sun Jun 28 18:47:23 2015 Thibault WOIVRE
// Last update Tue Jun 30 15:43:44 2015 Thibault WOIVRE
//

#include			"../include/ImageManager.hh"

ImageManager::ImageManager() {}

ImageManager::~ImageManager() {}

bool							ImageManager::initialize() {
	std::vector<std::string>	assets;

	assets.push_back("soil_0");
	assets.push_back("soil_1");
	assets.push_back("soil_2");
	assets.push_back("soil_3");
	assets.push_back("ressource_0");
	assets.push_back("ressource_1");
	assets.push_back("ressource_2");
	assets.push_back("ressource_3");
	assets.push_back("ressource_4");
	assets.push_back("ressource_5");
	assets.push_back("ressource_6");
	assets.push_back("player_1");
	assets.push_back("player_2");
	assets.push_back("player_3");
	assets.push_back("player_4");
	assets.push_back("player_take");
	assets.push_back("player_dead");
	assets.push_back("player_speak");
	assets.push_back("egg_0");
	assets.push_back("egg_1");
	for (size_t i = 0; i != assets.size(); ++i) {
		if (!_images[assets[i]].LoadFromFile(std::string(GRAPHIC_ASSETS) + assets[i] + std::string(".png")))
			return (false);
	}
	return (true);
}

sf::Image			&ImageManager::getImage(std::string name) {
	return (_images[name]);
}
