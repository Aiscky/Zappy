/*
** checl_lastlvl.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue Jun  9 20:26:57 2015 lucie wautelet
** Last update Thu Jun 25 11:35:25 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		check_sixth(t_server *begin, int n, int x, int y)
{
  char		tmp[4];
  int		total;
  int		i;

  i = 0;
  tmp[0] = nb_by_case(begin, x, y, 1);
  tmp[1] = nb_by_case(begin, x, y, 2);
  tmp[2] = nb_by_case(begin, x, y, 3);
  tmp[3] = nb_by_case(begin, x, y, 5);
  while (socket_com[i].socket != -1)
    {
      if (i != n && socket_com[i].x == x && socket_com[i].y == y)
	if (socket_com[i].level == 6)
	  total += 1;
      i += 1;
    }
  if (total >= 6 && tmp[0] >= 1 && tmp[1] >= 2 && tmp[2] >= 3 && tmp[3] >= 1)
    return (1);
  return (0);
}

int		check_seventh(t_server *begin, int n, int x, int y)
{
  char		tmp[6];
  int		total;
  int		i;

  i = 0;
  tmp[0] = nb_by_case(begin, x, y, 1);
  tmp[1] = nb_by_case(begin, x, y, 2);
  tmp[2] = nb_by_case(begin, x, y, 3);
  tmp[3] = nb_by_case(begin, x, y, 4);
  tmp[3] = nb_by_case(begin, x, y, 5);
  tmp[3] = nb_by_case(begin, x, y, 6);
  while (socket_com[i].socket != -1)
    {
      if (i != n && socket_com[i].x == x && socket_com[i].y == y)
	if (socket_com[i].level == 4)
	  total += 1;
      i += 1;
    }
  if (total >= 6 && tmp[0] >= 2 && tmp[1] >= 2 && tmp[2] >= 2 && tmp[3] >= 2)
    if (tmp[4] >= 2 && tmp[5] >= 1)
      return (1);
  return (0);
}
