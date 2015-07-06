//
// ImageManager.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/include
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Sun Jun 28 18:47:35 2015 Thibault WOIVRE
// Last update Mon Jun 29 17:08:43 2015 Thibault WOIVRE
//

#ifndef						IMAGEMANAGER_HH
#define						IMAGEMANAGER_HH

#include					"includeGraphic.hh"

class						ImageManager {

public:

  ImageManager();
  ~ImageManager();
  bool						initialize();
  sf::Image					&getImage(std::string);

private:

  std::map<std::string, sf::Image>		_images;
};

#endif
