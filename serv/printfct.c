/*
** printfct.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Fri Jun 19 18:35:14 2015 lucie wautelet
** Last update Fri Jun 26 16:58:27 2015 lucie wautelet
*/

#include "../include/serveur.h"

void	print_case_graph(t_server *s_info, char *buffer)
{
  int	x;
  int	y;
  int	inc;

  x = recup_coord(buffer, 1);
  y = recup_coord(buffer, 2);
  print_inv_case(s_info, x, y);
}

void	print_map_graph(t_server *s_info)
{
  int	x;
  int	y;

  y = 0;
  while (y < s_info->height)
    {
      x =  0;
      while (x < s_info->width)
	{
	  print_inv_case(s_info, x, y);
	  x += 1;
	}
      y += 1;
    }
}
