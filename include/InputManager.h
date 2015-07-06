/*
 * InputManager.h
 *
 *  Created on: Jul 1, 2015
 *      Author: woivre_t
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "Managers.hh"
#include "Map.hh"
#include "../Utils.hpp"

class InputManager {
public:
	InputManager(Managers *, Map *);
	virtual ~InputManager();
	void getEvent();
	void wheelEvent();
	void moveEvent();
	void keyHandler();

private:
	int _mouseX;
	int _mouseY;
	bool _pressed;
	Map *_map;
	Managers *_managers;
	sf::Event _event;
};

#endif /* INPUTMANAGER_H_ */
