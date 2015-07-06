/*
** inv.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Thu Jun  4 19:13:25 2015 lucie wautelet
** Last update Sun Jul  5 18:09:38 2015 lucie wautelet
*/

#include	"../include/serveur.h"

void		inv_case(t_server *s_info, int x, int y, int n)
{
  int		inc;
  int		stone;

  inc = 0;
  while (socket_com[n].socket != -1)
    {
      if (socket_com[n].x == x && socket_com[n].y == y)
	dprintf(socket_com[n].socket, " joueur");
      n += 1;
    }
  while (s_info->map[x][y][inc] != -2)
    {
      if (s_info->map[x][y][inc] != -1)
	{
	  stone = s_info->map[x][y][inc];
	  dprintf(socket_com[n].socket, " %s", stone);
	}
      inc += 1;
    }
  dprintf(socket_com[n].socket, ",");
}

void		nb_inv(int i, t_server *s_info, int x, int y)
{
  int		inc;
  int		res;

  res = 0;
  inc = 0;
  while (s_info->map[x][y][inc] != -2)
    {
      if (s_info->map[x][y][inc] == i)
	res++;
      inc++;
    }
  if (s_info->graph > -1)
    dprintf(s_info->graph, " %d", res);
}

void		print_inv_case(t_server *s_info, int x, int y)
{
  int		i;

  if (s_info->graph > -1)
    dprintf(s_info->graph, "bct %d %d", x, y);
  i = 0;
  while (i < 7)
    {
      nb_inv(i, s_info, x, y);
      i++;
    }
  if (s_info->graph > -1)
    dprintf(s_info->graph, "\n");
}

void		print_inv(t_server *s_info, int n)
{
  int		i;

  i = 0;
  if (s_info->graph > -1)
    dprintf(s_info->graph, "pin %d %d %d", socket_com[n].socket,
	    socket_com[n].x, socket_com[n].y);
  if (s_info->graph > -1)
    my_printsd(s_info->graph, "pin %d %d %d", socket_com[n].socket,
	       socket_com[n].x, socket_com[n].y);
  while (i < 7)
    {
      if (s_info->graph > -1)
	dprintf(s_info->graph, " %d", socket_com[n].inventaire[i]);
      if (s_info->graph > -1)
	my_printsd(s_info->graph, " %d", socket_com[n].inventaire[i]);
      i++;
    }
  if (s_info->graph > -1)
    dprintf(s_info->graph, "\n");
}

void		my_gener_inv(t_server *info)
{
  info->stone[0] = strdup("nourriture");
  info->stone[1] = strdup("linemate");
  info->stone[2] = strdup("deraumere");
  info->stone[3] = strdup("sibur");
  info->stone[4] = strdup("mendiane");
  info->stone[5] = strdup("phiras");
  info->stone[6] = strdup("thystame");
}
