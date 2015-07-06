/*
** graph.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue Jun 23 16:06:45 2015 lucie wautelet
** Last update Sun Jul  5 20:26:11 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		parse_graph_team(t_server *s_info, char *buffer)
{
  if (strncmp("tna", buffer, 3) == 0)
    {
      send_team(s_info);
      return (1);
    }
  return (0);
}

int		print_pos_player(t_server *s_info, char *buffer)
{
  int		play;
  int		x;
  int		y;
  int		i;

  i = 0;
  play = recup_coord(buffer, 1);
  while (socket_com[i].socket != -1)
    {
      if (socket_com[i].socket == play)
	{
	  if (s_info->graph > -1)
	    dprintf(s_info->graph, "ppo %d %d %d %d\n",
		    socket_com[i].socket, socket_com[i].x, socket_com[i].y,
		    socket_com[i].direction + 1);
	}
      i += 1;
    }
}

int		parse_perso(t_server *s_info, char *buffer)
{
  if (strncmp("ppo", buffer, 3) == 0)
    {
      print_pos_player(s_info, buffer);
      return (1);
    }
  else if (strncmp("plv", buffer, 3) == 0)
    {
      print_lvl_player(s_info, buffer);
      return (1);
    }
  else if (strncmp("pin", buffer, 3) == 0)
    {
      print_inv_player(s_info, buffer, 0);
      return (1);
    }
  return (0);
}

void		parse_graph(t_server *s_info, char *buffer, int n)
{
  if (parse_graph_map(s_info, buffer) == 0)
    {
      if (parse_graph_team(s_info, buffer) == 0)
	if (parse_perso(s_info, buffer) == 0)
	  parse_graph_time(s_info, buffer);
    }
}

int		parse_graph_map(t_server *s_info, char *buffer)
{
  if ((strncmp("msz", buffer, 3)) == 0)
    {
      if (s_info->graph > -1)
	{
	  dprintf(s_info->graph, "msz %d %d\n", s_info->width, s_info->height);
	  my_printsd("msz %d %d", s_info->width, s_info->height);
	}
      return (1);
    }
  else if ((strncmp("bct", buffer, 3)) == 0)
    {
      print_case_graph(s_info, buffer);
      return (1);
    }
  else if ((strncmp("mct", buffer, 3)) == 0)
    {
      print_map_graph(s_info);
      return (1);
    }
  return (0);
}
