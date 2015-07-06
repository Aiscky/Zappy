/*
** server2.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sun Jul  5 14:31:32 2015 lucie wautelet
** Last update Sun Jul  5 22:56:38 2015 lucie wautelet
*/

#include	"../include/serveur.h"

void		recv_perso(fd_set *readfd, t_server *s_info)
{
  int		i;
  char		buffer[BUFFER_SIZE + 1];
  int		tmp;

  i = 0;
  while (socket_com[i].socket != -2)
    {
      if (socket_com[i].socket != 0 && FD_ISSET(socket_com[i].socket, readfd))
	{
	  tmp = recv(socket_com[i].socket, buffer, BUFFER_SIZE, 0);
	  if (tmp == 0)
	    {
	      if (s_info->graph > -1)
		dprintf(s_info->graph, "pdi %d\n", socket_com[i].socket);
	      dprintf(1, "mort du joueur %d", socket_com[i].socket);
	      s_info->nbteam[recup_team(i, s_info)] -= 1;
	      close(socket_com[i].socket);
	      socket_com[i].socket = -1;
	    }
	  buffer[tmp] = 0;
	  handler_s(s_info, buffer, i);
	}
      i++;
    }
}
