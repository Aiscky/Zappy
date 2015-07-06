/*
** check_lvl.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue Jun  9 20:03:24 2015 lucie wautelet
** Last update Sun Jul  5 18:34:50 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		check_first(t_server *begin, int n, int x, int y)
{
  dprintf(1, "%d", nb_by_case(begin, x, y, 1));
  if (nb_by_case(begin, x, y, 1) >= 1)
    return (1);
  return (0);
}

int		check_second(t_server *begin , int n, int x, int y)
{
  char		tmp[3];
  int		total;
  int		i;

  i = 0;
  tmp[0] = nb_by_case(begin, x, y, 1);
  tmp[1] = nb_by_case(begin, x, y, 2);
  tmp[2] = nb_by_case(begin, x, y, 3);
  while (socket_com[i].socket != -1)
    {
      if (i != n && socket_com[i].x == x && socket_com[i].y == y)
	if (socket_com[i].level == 2)
	  total += 1;
      i += 1;
    }
  if (total >= 2 && tmp[0] >= 1 && tmp[1] >= 1 && tmp[2] >= 1)
    return (1);
  return (0);
}

int		check_third(t_server *begin , int n, int x, int y)
{
  char		tmp[3];
  int		total;
  int		i;

  i = 0;
  tmp[0] = nb_by_case(begin, x, y, 1);
  tmp[1] = nb_by_case(begin, x, y, 3);
  tmp[2] = nb_by_case(begin, x, y, 5);
  while (socket_com[i].socket != -1)
    {
      if (i != n && socket_com[i].x == x && socket_com[i].y == y)
	if (socket_com[i].level == 3)
	  total += 1;
      i += 1;
    }
  if (total >= 2 && tmp[0] >= 2 && tmp[1] >= 1 && tmp[2] >= 2)
    return (1);
  return (0);
}

int		check_fourth(t_server *begin , int n, int x, int y)
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
	if (socket_com[i].level == 4)
	  total += 1;
      i += 1;
    }
  if (total >= 4 && tmp[0] >= 1 && tmp[1] >= 1 && tmp[2] >= 2 && tmp[3] >= 1)
    return (1);
  return (0);
}

int		check_fifth(t_server *begin , int n, int x, int y)
{
  char		tmp[4];
  int		total;
  int		i;

  i = 0;
  tmp[0] = nb_by_case(begin, x, y, 1);
  tmp[1] = nb_by_case(begin, x, y, 2);
  tmp[2] = nb_by_case(begin, x, y, 3);
  tmp[3] = nb_by_case(begin, x, y, 4);
  while (socket_com[i].socket != -1)
    {
      if (i != n && socket_com[i].x == x && socket_com[i].y == y)
	if (socket_com[i].level == 5)
	  total += 1;
      i += 1;
    }
  if (total >= 4 && tmp[0] >= 1 && tmp[1] >= 2 && tmp[2] >= 1 && tmp[3] >= 3)
    return (1);
  return (0);
}
