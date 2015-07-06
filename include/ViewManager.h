/*
 * ViewManager.h
 *
 *  Created on: Jul 1, 2015
 *      Author: woivre_t
 */

#ifndef VIEWMANAGER_H_
#define VIEWMANAGER_H_

#include "includeGraphic.hh"
#include "../Utils.hpp"

class ViewManager {
public:
	ViewManager();
	virtual ~ViewManager();
	sf::View& getView();
	void setView(sf::Vector2f, sf::Vector2f);
	//void setView(sf::FloatRect const &);
	const sf::Vector2f getVisualFieldCenter() const;
	const sf::Vector2f getVisualFieldHalfSize() const;
	void setVisualFieldRect(const sf::FloatRect &);
	const sf::FloatRect &getVisualFieldRect() const;
	void zoom(float delta);
	const sf::FloatRect fitInVisualField(const sf::FloatRect &) const;
	void move(float x, float y);

	int getHeight() const {
		return _height;
	}

	void setHeight(int height) {
		_height = height;
	}

	int getWidth() const {
		return _width;
	}

	void setWidth(int width) {
		_width = width;
	}

private:
	sf::View _view;
	sf::FloatRect _visualViewRect;
	int _width;
	int _height;
};

#endif /* VIEWMANAGER_H_ */
