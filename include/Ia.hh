// ia.hh for ia in /home/boutet_a/ZAPPY_TESTS
//
// Made by Mehdi Boutet
// Login   <boutet_a@epitech.net>
//
// Started on  Tue Jun 16 15:39:46 2015 Mehdi Boutet
// Last update Sun Jul  5 23:18:26 2015 manin dylan
//


#ifndef				IA_HH
# define			IA_HH

#include			"includeClient.hh"
#include			"NetworkClient.hh"
#include			"../Utils.hpp"

class				Ia
{
public:
  int				_id;
  int				_x;
  int		       		_y;
  int				_nb_up;
  int				_where;
  int				_food;
  int				_flag;
  bool				_alive;
  bool				_needlvlup;
  int				_checkedDirections;
  short				_lvl;
  NetworkClient			*_network;
  std::string			_name;
  std::string			_answer;
  std::vector<std::string>     	_inv;

  Ia(NetworkClient *, std::string);
  ~Ia();

  void				run();
  void				setIdMap();
  bool				setConnection();
  int				my_findmatch(std::string stock, std::vector<std::string> target);
  int				loopReply(std::vector<std::string> *reply, std::string ans);
  int				handlerMsg(std::string msg);
  void				SendAndWait(std::string cmd, std::string answer);
  bool				my_findrocks(std::vector<std::string> &target, std::string view);
  std::string			my_getobj(std::string view, std::size_t mul_pos, std::size_t pos);
  std::vector<std::string>	my_getobjective();
  void                          my_putrocks();
  int                           my_getfood();
  bool				my_findfood(std::string food, std::string view);
  void                          my_goto(int coma);
  void                          my_axis(int i);
  void                          my_diago(int i);
  int                           check_players(std::string view);
  int				getVisualRange(int level);
  void                          my_lvlup();
  int                           check_broad(std::string broad);

};

#endif				/* I_A_ */
