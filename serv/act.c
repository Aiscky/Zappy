/*
** act.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Wed Jun 24 12:26:39 2015 lucie wautelet
** Last update Sun Jul  5 21:53:33 2015 lucie wautelet
*/

#include "../include/serveur.h"

void		check_incantation(t_buffer *list, int n, t_server *s_info)
{
  int		level;
  int		team;

  if (strncmp(list->buffer , "incantation", 11) == 0)
    {
      socket_com[n].level += 1;
      level = socket_com[n].level;
      dprintf(socket_com[n].socket, "niveau actuel : %d\n", level);
      my_printsd(socket_com[n].socket, "niveau actuel : %d", level);
    }
  else if (strcmp(list->buffer, "fork") == 0)
    {
      team = recup_team(n, s_info);
      s_info->egg = add_list_egg(s_info, n, team);
      if (s_info->graph > 0)
	{
	  dprintf(s_info->graph, "enw %d %d\n", recup_last(s_info), socket_com[n].socket);
	  my_printsd(s_info->graph, "enw %d %d\n", recup_last(s_info), socket_com[n].socket);
	}
    }
}

int		elevation_failed(int n)
{
  dprintf(socket_com[n].socket, "ko\n");
  my_printsd(socket_com[n].socket, "ko");
  return (0);
}

void		empty_list(int n, t_server *s_info)
{
  int		count;

  count = 0;
  while (s_info->list != NULL)
    {
      if (s_info->list->id == n)
	s_info->list = delete_in_list(s_info->list, count);
      count += 1;
      if (s_info->list != NULL && s_info->list->next != NULL)
	s_info->list = s_info->list->next;
    }
}

int		elevation_fct(int n, t_server *s_info)
{
  int		i;

  i = 0;
  if (s_info->elevation[socket_com[n].level - 1](s_info, n,
						 socket_com[n].x, socket_com[n].y) == 1)
    {
      dprintf(socket_com[n].socket, "elevation en cours\n");
      my_printsd(socket_com[n].socket, "elevation en cours");
      while (socket_com[i].socket != -1)
	{
	  if (i != n && socket_com[i].x == socket_com[n].x)
	    if (socket_com[n].y == socket_com[i] .y && socket_com[i].level
		== socket_com[n].level)
	      {
		empty_list(i, s_info);
		dprintf(socket_com[i].socket, "elevation en cours\n");
		my_printsd(socket_com[i].socket, "elevation en cours");
	      }
	  i += 1;
	}
      dprintf(socket_com[n].socket, "elevation en cours\n");
      return (1);
    }
  else
    return (elevation_failed(n));
}
