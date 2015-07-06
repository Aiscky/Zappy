//
// EventManager.hh for zappy in /home/woivre_t/rendu/PSU_2014_zappy/include
// 
// Made by Thibault WOIVRE
// Login   <woivre_t@epitech.net>
// 
// Started on  Sat Jun 27 16:57:41 2015 Thibault WOIVRE
// Last update Mon Jun 29 17:02:29 2015 Thibault WOIVRE
//

#ifndef			EVENTMANAGER_HH
#define			EVENTMANAGER_HH

#include		"GameEngine.hh"
#include		"Map.hh"
#include		"includeGraphic.hh"
#include		"../Utils.hpp"
#include		"Managers.hh"

class			EventManager {

public:

  EventManager(Map *map, Managers *managers);
  ~EventManager();
  void			eventHandler(std::string &);
  void			setDimensions(std::vector<std::string>*);
  void			setTile(std::vector<std::string>*);
  void			addTeamName(std::vector<std::string>*);
  void			setFrequency(std::vector<std::string>*);
  void			createPlayer(std::vector<std::string>*);
  void			setPlayerLevel(std::vector<std::string>*);
  void			setPlayerInventory(std::vector<std::string>*);
  void			movePlayer(std::vector<std::string>*);
  void			takeRessource(std::vector<std::string>*);
  void			dropRessource(std::vector<std::string>*);
  void			startIncantation(std::vector<std::string>*);
  void			endIncantation(std::vector<std::string>*);
  void			expulse(std::vector<std::string>*);
  void			speak(std::vector<std::string>*);
  void			playerBorn(std::vector<std::string>*);
  void			playerDie(std::vector<std::string>*);
  void			playerLaying(std::vector<std::string>*);
  void			eggLayed(std::vector<std::string>*);
  void			eggHatched(std::vector<std::string>*);
  void			eggRotted(std::vector<std::string>*);
  void			gameEnd(std::vector<std::string>*);
  void			serverMsg(std::vector<std::string>*);
  void			unknownCommand(std::vector<std::string>*);
  void			wrongArgument(std::vector<std::string>*);
  
private:

  Map			*_map;
  Managers		*_managers;
  std::map<std::string, void (EventManager::*)(std::vector<std::string>*)> _fonctions;
};

#endif
