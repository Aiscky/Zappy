/*
** verif_cours.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Wed Jun 24 12:03:46 2015 lucie wautelet
** Last update Sun Jul  5 22:44:01 2015 lucie wautelet
*/

#include "../include/serveur.h"

void		parc_sock(t_server *s_info)
{
  int		n;

  n = 0;
  while (socket_com[n].socket != -1)
    {
      if (socket_com[n].socket != s_info->graph)
	dead_test(s_info, n);
      n += 1;
    }
}

int		dead_test(t_server *s_info, int n)
{
  float		time;

  time = (float)clock();
  if (socket_com[n].end <= time && socket_com[n].socket != 0)
    {
      if (socket_com[n].inventaire[0] > 1)
	{
	  socket_com[n].inventaire[0] -= 1;
	  socket_com[n].end += 126 / (float)s_info->delay * 100;
	  return (0);
	}
      dprintf(s_info->graph, "pdi %d\n", socket_com[n].socket);
      dprintf(socket_com[n].socket, "mort\n");
      my_printsd(socket_com[n].socket, "mort");
      close(socket_com[n].socket);
      s_info->nbteam[recup_team(n, s_info)] -= 1;
      socket_com[n].socket = -1;
      free(socket_com[n].team);
      return (1);
    }
  return (0);
}

void		verif_cours(t_server *s_info, char *buffer, int n)
{
  float		time;
  int		act;

  act = 0;
  if (list_empty(s_info, n) == 0)
    {
      if (strncmp(buffer, "incantation", 11) == 0)
	{
	  if (elevation_fct(n, s_info) == 1)
	    s_info->list = stock_list_cours(s_info, buffer, n);
	}
      else
	s_info->list = stock_list_cours(s_info, buffer, n);
    }
  else
    {
      s_info->list = stock_list(s_info, buffer, n);
    }
}
