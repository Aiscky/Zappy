/*
** direction.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Mon Jun 29 14:29:41 2015 lucie wautelet
** Last update Sun Jul  5 20:19:16 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		getdir(int n)
{
  if (socket_com[n].direction % 2 == 0)
    {
      if (socket_com[n].direction == 0)
	return (0);
      else
	return (4);
    }
  else
    {
      if (socket_com[n].direction == 1)
	return (2);
      else
	return (6);
    }
}

int		choose_angle(float angle, float xref, float yref, int n)
{
  int		dir;

  if (xref > 0)
    if (yref > 0)
      dir = fourth_quart(n, angle);
    else if (yref < 0)
      dir = first_quart(n, angle);
  if (xref < 0)
    if (yref > 0)
      dir = third_quart(n, angle);
    else if (yref <  0)
      dir = second_quart(n, angle);
  return (dir);
}

int		choose_dir(float angle, float xref, float yref, int n)
{
  int		dir;

  if (xref == 0 || yref == 0)
    {
      if (xref == 0)
	{
	  if (yref < 0)
	    dir = 5 + getdir(n) % 8;
	  else if (yref > 0)
	    dir = 1 + getdir(n) % 8;
	  else
	    dir = 0;
	}
      else if (yref == 0)
	{
	  if (xref < 0)
	    dir = 7 + getdir(n) % 8;
	  else if (yref > 0)
	    dir = 3 + getdir(n) % 8;
	}
    }
  else
    dir = choose_angle(angle, xref, yref, n);
}
