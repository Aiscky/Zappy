/*
 * Egg.h
 *
 *  Created on: Jul 5, 2015
 *      Author: woivre_t
 */

#ifndef EGG_H_
#define EGG_H_

#define	EGG_WIDTH 40
#define EGG_HEIGHT 50

#include "ImageManager.hh"

class Egg {
public:

	enum {
		NOTHATCHED,
		HATCHED,
	};

	Egg(int xIso, int yIso, bool status, ImageManager *);
	~Egg();
	inline void setSprite(const std::string &img) {
		_sprite.SetImage(_imageManager->getImage(img));
	}
	void draw(sf::RenderWindow *);

private:
	sf::Sprite _sprite;
	ImageManager *_imageManager;
};

#endif /* EGG_H_ */
