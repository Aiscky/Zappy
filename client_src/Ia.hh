// ia.hh for ia in /home/boutet_a/ZAPPY_TESTS
//
// Made by Mehdi Boutet
// Login   <boutet_a@epitech.net>
//
// Started on  Tue Jun 16 15:39:46 2015 Mehdi Boutet
// Last update Fri Jun 19 19:18:11 2015 Mehdi Boutet
//


#ifndef				I_A_
# define			I_A_

#include			"iostream"
#include			"fstream"

class				Ia
{
public:
  int				w_w;
  int		       		w_h;
  std::vector<std::string>     	inv;
  short				lvl;

  Ia();
  ~Ia();
  void				my_getrocks(std::vector<std::string> obj)
};

std::vector<std::string>        my_getobjective(int lvl);

#endif				/* I_A_ */
