/*
** voir.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Fri Jun 26 23:36:00 2015 lucie wautelet
** Last update Sun Jul  5 17:06:38 2015 lucie wautelet
*/

#include	"../include/serveur.h"

void		print_voir_case(t_server *s_info, int x, int y, int sock)
{
  int		n;
  int		i;

  n = 0;
  while (socket_com[n].socket != -1)
    {
      if (socket_com[n].x == x && socket_com[n].y == y)
	dprintf(socket_com[sock].socket, " joueur");
      n += 1;
    }
  n = 0;
  while (s_info->map[x][y][n] != -2)
    {
      i = s_info->map[x][y][n];
      if (s_info->map[x][y][n] != -1)
	dprintf(socket_com[sock].socket, " %s", s_info->stone[i]);
      n += 1;
    }
}

void		voir_case0(t_server *s_info, int n)
{
  int		x;
  int		y;
  int		r;
  int		max;
  int		inc;

  max = 1;
  r = 0;
  while (r < socket_com[n].level + 1)
    {
      x = verif_negla_voir(socket_com[n].x, r * -1, s_info->width);
      y = verif_negla_voir(socket_com[n].y, r * -1, s_info->height);
      inc = 0;
      while (inc < max)
	{
	  if (inc != 0 || r != 0)
	    dprintf(socket_com[n].socket, ",");
 	  print_voir_case(s_info, x, y, n);
	  x = verif_maxla_voir(x, 1, s_info->width);
	  inc += 1;
	}
      max += 2;
      r += 1;
    }
}

void		voir_case2(t_server *s_info, int n)
{
  int		x;
  int		y;
  int		r;
  int		max;
  int		inc;

  max = 1;
  r = 0;
  while (r < socket_com[n].level + 1)
    {
      x = verif_negla_voir(socket_com[n].x, r * -1, s_info->width);
      y = verif_max_haut_voir(socket_com[n].y, r, s_info->height);
      inc = 0;
      while (inc < max)
	{
	  if (inc != 0 || r != 0)
	    dprintf(socket_com[n].socket, ",");
 	  print_voir_case(s_info, x, y, n);
	  x = verif_maxla_voir(x, 1, s_info->width);
	  inc += 1;
	}
      max += 2;
      r += 1;
    }
}

void		voir_case1(t_server *s_info, int n)
{
  int		x;
  int		y;
  int		r;
  int		max;
  int		inc;

  max = 1;
  r = 0;
  while (r < socket_com[n].level + 1)
    {
      x = verif_max_haut_voir(socket_com[n].x, r, s_info->width);
      y = verif_negla_voir(socket_com[n].y, r*(-1), s_info->height);
      inc = 0;
      while (inc < max)
	{
	  if (inc != 0 || r != 0)
	    dprintf(socket_com[n].socket, " ,");
	  print_voir_case(s_info, x, y, n);
	  y = verif_maxla_voir(y, 1, s_info->height);
	  inc += 1;
	}
      max += 2;
      r += 1;
    }
}

void		voir_case3(t_server *s_info, int n)
{
  int		x;
  int		y;
  int		r;
  int		max;
  int		inc;

  max = 1;
  r = 0;
  while (r < socket_com[n].level + 1)
    {
      x = verif_negla_voir(socket_com[n].x, r*(-1), s_info->width);
      y = verif_negla_voir(socket_com[n].y, r*(-1), s_info->height);
      inc = 0;
      while (inc < max)
	{
	  if (inc != 0 || r != 0)
	    dprintf(socket_com[n].socket, ",");
 	  print_voir_case(s_info, x, y, n);
	  y = verif_maxla_voir(y, 1, s_info->height);
	  inc += 1;
	}
      max += 2;
      r += 1;
    }
}
