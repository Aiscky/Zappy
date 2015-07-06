/*
** map2.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sun Jun 28 15:25:41 2015 lucie wautelet
** Last update Sat Jul  4 21:28:02 2015 lucie wautelet
*/

#include	 "../include/serveur.h"

void		my_gener_persomap(t_server *begin, int n)
{
  int		x;
  int		y;

  x = -1;
  y = -1;
  while (x == -1)
    {
      x = rand() % begin->width;
      y = rand() % begin->height;
    }
  socket_com[n].x = x;
  socket_com[n].y = y;
  socket_com[n].direction = rand() % 4;
  dprintf(1, "***Added new player %d in %d %d\n",
	    socket_com[n].socket, x, y);
}

void		send_map(t_server *s_info)
{
  int		x;
  int		y;

  y = 0;
  while (y < s_info->height)
    {
      x = 0;
      while (x < s_info->width)
	{
	  print_inv_case(s_info, x, y);
	  x += 1;
	}
      y += 1;
    }
}
