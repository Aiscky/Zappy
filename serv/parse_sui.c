/*
** parse_sui.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Thu Jun 25 10:05:52 2015 lucie wautelet
** Last update Sun Jul  5 18:29:25 2015 lucie wautelet
*/

#include	"../include/serveur.h"

void		parse_last(char *str, int n, t_server *s_info)
{
  if (strncmp(str, "broadcast", 9) == 0)
    ; //    broadcast_fct(str, n, s_info);
  else
    {
      dprintf(socket_com[n].socket, "ko\n");
      dprintf(s_info->graph, "suc\n");
    }
}

void		parse_rest(char *str, int n, t_server *s_info)
{
  if (strncmp(str, "incantation", 11) == 0)
    elevation_fct(n, s_info);
  else if (strncmp(str, "fork", 4) == 0)
    fork_fct(n, s_info);
  else
    parse_last(str, n, s_info);
}
