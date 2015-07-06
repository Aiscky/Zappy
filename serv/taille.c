/*
** taille.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sun Jul  5 17:09:02 2015 lucie wautelet
** Last update Sun Jul  5 17:38:49 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		check_taille(t_server *s_info, int n)
{
  int		r;
  int		max;
  int		inc;
  int		x;
  int		y;

  x = socket_com[n].x;
  y = socket_com[n].y;
  r = 0;
  max = 1;
  if (s_info->width == 1 && s_info->height == 1)
    {
      while (r < socket_com[n].level + 1)
	{
	  inc = 0;
	  while (inc < max)
	    {
	      if (inc != 0 || r != 0)
		dprintf(socket_com[n].socket, ",");
	      print_voir_case(s_info, x, y, n);
	      inc += 1;
	    }
	  max += 2;
	  r += 1;
	}
      return (1);
    }
  return (0);
}
