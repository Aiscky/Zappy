/*
** coord.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Wed Jun 24 14:08:27 2015 lucie wautelet
** Last update Wed Jun 24 14:43:55 2015 lucie wautelet
*/

#include "../include/serveur.h"

void		coord_voir(t_server *s_info, int n, int coord[2])
{
  int		height;
  int		larg;
  int		width;

  width = 1;
  larg = 0;
  height = 0;
  while (height < socket_com[n].level)
    {
      while (larg < width)
	{
	  inv_case(s_info, coord[0], coord[1], n);
	  larg += 1;
	}
      width += 2;
      larg = 0;
      height += 1;
      coord[0] = reinitx(height, coord[1], n, s_info);
    }
}

int		verifxplus(t_server *s_info, int x, int n)
{
  if (socket_com[n].direction == 0
      if (x == )
}

int		verify(t_server *s_info, int y, int opt)
{
    if (opt == 1)
    {
    }
  else if (opt == 2)
    {
    }
}
