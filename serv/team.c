/*
** team.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue Jun  2 16:12:49 2015 lucie wautelet
** Last update Sun Jul  5 14:07:47 2015 lucie wautelet
*/

#include "../include/serveur.h"

void	send_team(t_server *s_info)
{
  int	i;

  i = 0;
  while (s_info->team[i])
    {
      dprintf(s_info->graph, "tna %s\n", s_info->team[i]);
      i++;
    }
}

int	check_graphic(t_server *s_info, char *str, int n)
{
  if (strcmp(str, "GRAPHIC") == 0)
    {
      s_info->graph = socket_com[n].socket;
      socket_com[n].team = strdup("GRAPHIC");
      dprintf(s_info->graph, "msz %d %d\n", s_info->width, s_info->height);
      dprintf(s_info->graph, "sgt %d\n", s_info->delay);
      send_map(s_info);
      send_team(s_info);
      return (1);
    }
  return (0);
}

void	print_team(t_server *s_info, int n, int i, int sup)
{
  if (sup != 0)
    dprintf(1, "eht %d\n", recup_last_id_team(s_info, i));
  send_map(s_info);
  print_inv(s_info, n);
  dprintf(s_info->graph, "pnw %d %d %d %d %s\n", socket_com[n].socket,
	    socket_com[n].x, socket_com[n].y, socket_com[n].direction + 1,
	    socket_com[n].team);
  dprintf(socket_com[n].socket, "%d\n%d %d\n",
	    s_info->client - s_info->nbteam[i], s_info->width, s_info->height);
  my_printsd(socket_com[n].socket, "%d", s_info->client - s_info->nbteam[i]
	     + sup);
  my_printsd(socket_com[n].socket, "%d %d", s_info->width, s_info->height);
}

int	handl_team(char *str, t_server *s_info, int n)
{
  int	i;
  int	sup;

  i = 0;
  if (check_graphic(s_info, str, n) == 0)
    {
      while (s_info->team[i] != NULL)
	{
	  if (strcmp(s_info->team[i], str) == 0)
	    {
	      sup = parc_list_egg(s_info, i);
	      if (s_info->nbteam[i] != s_info->client + sup)
		s_info->nbteam[i] += 1;
	      else
		return (0);
	      socket_com[n].team = strdup(s_info->team[i]);
	      print_team(s_info, n, i, sup);
	      return (1);
	    }
	  i++;
	}
      return (0);
    }
  return (1);
}

int	recup_team(int n, t_server *s_info)
{
  int	i;

  i = 0;
  while (s_info->team[i])
    {
      if (strcmp(s_info->team[i], socket_com[n].team) == 0)
	return (i);
      i +=1;
    }
}
