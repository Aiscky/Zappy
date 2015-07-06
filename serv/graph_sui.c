/*
** graph_sui.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Fri Jun 26 17:34:45 2015 lucie wautelet
** Last update Sun Jul  5 18:03:02 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		print_lvl_player(t_server *s_info, char *buffer)
{
  int		player;
  int		i;

  i = 0;
  player = recup_coord(buffer, 1);
  while (socket_com[i].socket != -1)
    {
      if (socket_com[i].socket == player)
	if (s_info->graph > -1)
	  dprintf(s_info->graph, "plv %d %d\n",
		  socket_com[i].socket, socket_com[i].level);
      i += 1;
    }
}

int		print_inv_player(t_server *s_info, char *buffer, int id)
{
  int		player;
  int		i;

  i = 0;
  player = recup_coord(buffer, 1);
  while (socket_com[i].socket != -1)
    {
      if (socket_com[i].socket == player)
	print_inv(s_info, i);
      i += 1;
    }
}

int		parse_graph_time(t_server *s_info, char *buffer)
{
  if (strncmp(buffer, "sgt", 3) == 0)
    {
      	if (s_info->graph > -1)
	  dprintf(s_info->graph, "sgt %d\n", s_info->delay);
      return (1);
    }
  else if (strncmp(buffer, "sst", 3) == 0)
    {
      s_info->delay = recup_coord(buffer, 1);
      if (s_info->graph > -1)
	dprintf(s_info->graph, "sgt %d\n", s_info->delay);
      return (1);
    }
  return (0);
}
