/*
** parse_act.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Thu Jun  4 18:41:21 2015 lucie wautelet
** Last update Sun Jul  5 20:24:25 2015 lucie wautelet
*/

#include	"../include/serveur.h"

void		my_parse_other(char *str, int n, t_server *s_info)
{
  if (strcmp("expulse", str) == 0)
    my_expulse(n, s_info);
  else if (strcmp("connect_nbr", str) == 0)
    my_connectnbr(n, s_info);
  else
    parse_rest(str, n, s_info);
}

void		my_parse_voir(char *str, int n, t_server *s_info)
{
  int		x;
  int		y;
  int		i;

  i = 0;
  if (strcmp(str, "voir") == 0)
    act_voir(s_info, n);
  else if (strncmp(str, "pose", 4) == 0)
    my_pose(n, s_info, &str[5]);
  else
    my_parse_other(str, n , s_info);
}

void		my_parse_buff_direction(char *str, int n, t_server *s_info)
{
  if (strcmp(str, "gauche") == 0)
    {
      socket_com[n].direction--;
      if (socket_com[n].direction == -1)
	socket_com[n].direction = 3;
      dprintf(socket_com[n].socket, "ok\n");
      dprintf(s_info->graph, "ppo %d %d %d %d\n", socket_com[n].socket,
	      socket_com[n].x, socket_com[n].y, socket_com[n].direction + 1);
      socket_com[n].pv -= definetim(str, s_info);
    }
  else if (strcmp(str, "droite") == 0)
    {
      socket_com[n].direction++;
      if (socket_com[n].direction == 4)
	socket_com[n].direction = 0;
      dprintf(socket_com[n].socket, "ok\n");
      dprintf(s_info->graph, "ppo %d %d %d %d\n", socket_com[n].socket,
	      socket_com[n].x, socket_com[n].y, socket_com[n].direction + 1);
      socket_com[n].pv -= definetim(str, s_info);
    }
  else
    my_parse_voir(str, n , s_info);
}

void		my_parse_buff_av(char *str, int n, t_server *s_info)
{
  if (strcmp(str, "avance") == 0)
    my_avance(n, s_info);
  else if (strncmp(str, "prend", 5) == 0)
    my_prend(n, s_info, &str[6]);
  else
    my_parse_buff_direction(str, n, s_info);
}

void		my_parse_buff(char *str, int n, t_server *s_info)
{
  int	       i;

  i = 0;
  if (strcmp(str, "inventaire") == 0)
    {
      dprintf(socket_com[n].socket, "{");
      while (i < 7)
	{
 	  dprintf(socket_com[n].socket, "%s : %d", s_info->stone[i],
		    socket_com[n].inventaire[i] );
	  (i == 6) ? 0 : dprintf(socket_com[n].socket, ", ");
	  i++;
	}
      dprintf(socket_com[n].socket, "}\n");
      socket_com[n].pv -= definetim(str, s_info);
    }
  else
    my_parse_buff_av(str, n, s_info);
  socket_com[n].end -= definetim(str, s_info) * 100;
}
