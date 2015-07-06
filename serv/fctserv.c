/*
** fctserv.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sun Jun 14 14:11:48 2015 lucie wautelet
** Last update Sun Jul  5 20:25:04 2015 lucie wautelet
*/

#include "../include/serveur.h"

void	my_avance(int n, t_server *s_info)
{
  if (socket_com[n].direction % 2 == 0)
    {
      if (socket_com[n].direction == 0)
	{
	  (socket_com[n].y == 0) ? socket_com[n].y = s_info->height-1
	    : socket_com[n].y--;
	}
      else
	(socket_com[n].y == s_info->height - 1) ? socket_com[n].y = 0
	  : socket_com[n].y++;
	}
  else
    {
      if (socket_com[n].direction == 3)
	(socket_com[n].x == 0) ? socket_com[n].x = s_info->width-1
	      : socket_com[n].x--;
      else
	(socket_com[n].x == s_info->width - 1) ? socket_com[n].x = 0
	  : socket_com[n].x++;
    }
  dprintf(s_info->graph, "ppo %d %d %d %d\n", socket_com[n].socket,
	  socket_com[n].x, socket_com[n].y, socket_com[n].direction + 1);
  dprintf(socket_com[n].socket, "ok\n");
  my_printsd(socket_com[n].socket, "ok");
  socket_com[n].pv -= definetim("avance", s_info);}


void	my_expulse(int n, t_server *s_info)
{
  int	i;
  int	dir;

  i = 0;
  dprintf(s_info->graph, "pex %d\n", socket_com[n].socket);
  while (socket_com[i].socket != -1)
    {
      if (socket_com[i].x == socket_com[n].x && i != n)
	{
	  if (socket_com[i].y == socket_com[n].y)
	    {
	      my_avance(i, s_info);
	      if (socket_com[i].direction  <= 1)
		dir = socket_com[i].direction + 2;
	      else
		dir = socket_com[i].direction - 2;
	      dprintf(s_info->graph, "ppo %d %d %d %d\n", socket_com[n].socket,
		      socket_com[n].x, socket_com[n].y, socket_com[n].direction + 1);
	      dprintf(socket_com[i].socket, "K:%d\n", dir);
	      my_printsd(socket_com[i].socket, "K:%d\n", dir);
	    }
	}
      i += 1;
    }
  socket_com[n].pv -= definetim("expulse", s_info);
}

void	my_connectnbr(int n, t_server *s_info)
{
  int	i;
  int	nb;

  i = 0;
  while (strcmp(s_info->team[i], socket_com[n].team) == 0)
    i++;
  nb = s_info->client - s_info->nbteam[i] + parc_list_egg(s_info, i);
  dprintf(socket_com[n].socket, "%d\n", nb);
  my_printsd(socket_com[n].socket, "%d", nb);
  socket_com[n].pv -= definetim("connect_nbr", s_info);
}

void	act_voir(t_server *s_info, int n)
{
  dprintf(socket_com[n].socket, "{");
  if (check_taille(s_info, n) == 0)
    {
      if (socket_com[n].direction % 2 == 0)
	{
	  if (socket_com[n].direction == 0)
	    voir_case0(s_info, n);
	  else if (socket_com[n].direction == 2)
	    voir_case2(s_info, n);
	}
      else
	{
	  if (socket_com[n].direction == 1)
	    voir_case1(s_info, n);
	  else if (socket_com[n].direction == 3)
	    voir_case3(s_info, n);
	}
    }
  dprintf(socket_com[n].socket, "}\n");
}
