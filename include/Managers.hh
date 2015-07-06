//
// Managers.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/include
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Mon Jun 29 15:57:27 2015 Thibault WOIVRE
// Last update Tue Jun 30 15:09:30 2015 Thibault WOIVRE
//

#ifndef			MANAGERS_HH
#define			MANAGERS_HH

#include		"includeGraphic.hh"
#include		"ImageManager.hh"
#include		"Network.hh"
#include		"ViewManager.h"

class			Managers {

public:

	Managers();
	~Managers();
	sf::RenderWindow	*getApp() const;
	ImageManager		*getImageManager() const;
	Network				*getNetwork() const;
	void				setApp(sf::RenderWindow *);
	void				setImageManager(ImageManager *);
	void				setNetwork(Network *);
	ViewManager* 		getViewManager();
	void 				setViewManager(ViewManager* viewManager);

private:

	sf::RenderWindow	*_app;
	ImageManager		*_imageManager;
	Network				*_network;
	ViewManager			*_viewManager;
};

#endif
