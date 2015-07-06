//
// Ressource.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/serv
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Mon Jun 29 15:11:01 2015 Thibault WOIVRE
// Last update Mon Jun 29 15:14:15 2015 Thibault WOIVRE
//

#ifndef					RESSOURCE_HH
#define					RESSOURCE_HH

#include				"includeGraphic.hh"

#define					RESSOURCE_SIZE 30

class					Ressource {

public:

	enum Type {
		FOOD,
		LINEMATE,
		DERAUMERE,
		SIBUR,
		MENDIANE,
		PHYRAS,
		THISTAME
	};

	Ressource(int x, int y, const sf::Image &sprite, Type ressourceType);
	~Ressource();
	void				draw(sf::RenderWindow *);
	inline Type			getRessourceType() {
		return (_ressourceType);
	}

private:

	sf::Sprite			_sprite;
	Type				_ressourceType;
};

#endif
