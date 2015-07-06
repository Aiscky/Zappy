/*
 * InputManager.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: woivre_t
 */

#include "../include/InputManager.h"

InputManager::InputManager(Managers *managers, Map *map) {
	_managers = managers;
	_map = map;
	_pressed = false;
	_mouseX = _managers->getApp()->GetInput().GetMouseX();
	_mouseY = _managers->getApp()->GetInput().GetMouseY();
}

InputManager::~InputManager() {
}

void InputManager::getEvent() {
	while (_managers->getApp()->GetEvent(_event)) {
		switch (_event.Type) {
		case sf::Event::Closed:
			_managers->getApp()->Close();
			break;
		case sf::Event::KeyPressed:
			keyHandler();
			break;
		case sf::Event::MouseWheelMoved:
			wheelEvent();
			break;
		default:
			break;
		}
	}
	moveEvent();
}

void 				InputManager::wheelEvent() {
	_managers->getViewManager()->zoom(1 + _event.MouseWheel.Delta * SCROLL_COEF);
}

void InputManager::moveEvent() {
	if (_managers->getApp()->GetInput().IsKeyDown(sf::Key::Up))
		_managers->getViewManager()->move(0, -1);
	if (_managers->getApp()->GetInput().IsKeyDown(sf::Key::Down))
		_managers->getViewManager()->move(0, 1);
	if (_managers->getApp()->GetInput().IsKeyDown(sf::Key::Left))
		_managers->getViewManager()->move(-1, 0);
	if (_managers->getApp()->GetInput().IsKeyDown(sf::Key::Right))
		_managers->getViewManager()->move(1, 0);
}

void InputManager::keyHandler() {
	if (_managers->getApp()->GetInput().IsKeyDown(sf::Key::Escape))
		_managers->getApp()->Close();
}
