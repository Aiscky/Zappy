//
// Managers.cpp for zappy in /home/woivre_t/rendu/PSU_2014_zappy/graphic_src
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Mon Jun 29 15:59:08 2015 Thibault WOIVRE
// Last update Tue Jun 30 15:09:49 2015 Thibault WOIVRE
//

#include			"../include/Managers.hh"

Managers::Managers() {
	_viewManager = new ViewManager();
}

Managers::~Managers() {}

sf::RenderWindow		*Managers::getApp() const {
  return (_app);
}

ImageManager			*Managers::getImageManager() const {
  return (_imageManager);
}

Network				*Managers::getNetwork() const {
  return (_network);
}

void				Managers::setApp(sf::RenderWindow *app) {
  _app = app;
  _app->SetView(_viewManager->getView());
}

void				Managers::setImageManager(ImageManager *imageManager) {
  _imageManager = imageManager;
}

void				Managers::setNetwork(Network *network) {
  _network = network;
}


ViewManager			*Managers::getViewManager() {
	return _viewManager;
}

void Managers::setViewManager(ViewManager* viewManager) {
	_viewManager = viewManager;
}
