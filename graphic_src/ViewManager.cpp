/*
 * ViewManager.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: woivre_t
 */

#include "../include/ViewManager.h"

ViewManager::ViewManager() {}

ViewManager::~ViewManager() {
}

sf::View& ViewManager::getView() {
	return _view;
}

void ViewManager::setView(sf::Vector2f _halfCenter, sf::Vector2f _halfSize) {
	_view.SetCenter(_halfCenter);
	_view.SetHalfSize(_halfSize);
}



const sf::Vector2f ViewManager::getVisualFieldCenter() const {
	sf::Vector2f center;

	center.x = 0;
	center.y = ((Utils::max(_height, _width) + 1) * TILE_SIZE) / 2;
	return (center);
}

const sf::Vector2f ViewManager::getVisualFieldHalfSize() const {
	sf::Vector2f halfSize;
	int width;
	int height;

	//TODO: Correct fonction and clean
	width = Utils::cartesianToIsoY(_width * TILE_SIZE, _height * TILE_SIZE) + TILE_SIZE;
	height = Utils::cartesianToIsoX(_width * TILE_SIZE, 0) + TILE_SIZE - Utils::cartesianToIsoX(0, _height);
	halfSize.x = (Utils::max(_height, _width) + 1) * TILE_SIZE;
	halfSize.y = (Utils::max(_height, _width) + 1) * TILE_SIZE * SCREEN_HEIGHT / SCREEN_WIDTH;
	return (halfSize);
}

const sf::FloatRect &ViewManager::getVisualFieldRect() const {
	return (_visualViewRect);
}

void ViewManager::setVisualFieldRect(const sf::FloatRect& rect) {
	_visualViewRect = rect;
}

void ViewManager::zoom(float delta) {
	sf::FloatRect	newRect;
	sf::FloatRect	visualFieldRect;

	_view.Zoom(delta);
	visualFieldRect = getVisualFieldRect();
	newRect = _view.GetRect();

	if (newRect.Right - newRect.Left < 2 * TILE_SIZE)
		_view.SetHalfSize(TILE_SIZE, TILE_SIZE * SCREEN_HEIGHT / SCREEN_WIDTH);
	if (!Utils::RectInRect(newRect, visualFieldRect))
		_view.SetFromRect(fitInVisualField(newRect));
}

const sf::FloatRect ViewManager::fitInVisualField(const sf::FloatRect& rect) const {
	sf::FloatRect newRect(rect.Left, rect.Top, rect.Right, rect.Bottom);

	if ((rect.Top - _visualViewRect.Top +  _visualViewRect.Bottom - rect.Bottom <= 0) ||
			(rect.Left - _visualViewRect.Left +  _visualViewRect.Right - rect.Right <= 0))
		return (_visualViewRect);
	if (rect.Top < _visualViewRect.Top) {
		newRect.Top = _visualViewRect.Top;
		newRect.Bottom = rect.Bottom - rect.Top + _visualViewRect.Top;
	}
	if (rect.Bottom > _visualViewRect.Bottom) {
		newRect.Bottom = _visualViewRect.Bottom;
		newRect.Top = rect.Top - rect.Bottom + _visualViewRect.Bottom;
	}
	if (rect.Left < _visualViewRect.Left) {
		newRect.Left = _visualViewRect.Left;
		newRect.Right = rect.Right - rect.Left + _visualViewRect.Left;
	}
	if (rect.Right > _visualViewRect.Right) {
		newRect.Right = _visualViewRect.Right;
		newRect.Left = rect.Left - rect.Right + _visualViewRect.Right;
	}
	return (newRect);
}

void ViewManager::move(float x, float y) {
	sf::FloatRect rect;

	_view.Move(x * (_visualViewRect.Right -_visualViewRect.Left) / 100.f,
			y * (_visualViewRect.Bottom - _visualViewRect.Top) / 100.f);
	rect = _view.GetRect();
	if (!Utils::RectInRect(rect, _visualViewRect))
		_view.SetFromRect(fitInVisualField(rect));
}
