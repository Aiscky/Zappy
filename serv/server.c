/*
** server.c for myirc in /home/woivre_t/rendu/myirc
**
** Made by Thibault WOIVRE
** Login   <woivre_t@epitech.net>
**
** Started on  Mon Apr 13 15:08:04 2015 Thibault WOIVRE
** Last update Sun Jul  5 22:58:21 2015 lucie wautelet
*/

#include		"../include/serveur.h"

int			socket_s;
t_info_c		socket_com[MAX_CLIENTS];

void			handler_s(t_server *s_info, char *buffer, int n) {
  int			(*tab_handler[7])(char **, t_server *, int);
  char			**cmd;
  int			i;

  verif_egg(s_info);
  if (strlen(buffer) != 0)
    {
      my_cutn(buffer, '\n');
      dprintf(1, "\t\t\tReceiving message from %d : %s\n"
		, socket_com[n].socket, buffer);
      if (socket_com[n].team == NULL)
	{
	  if (handl_team(buffer, s_info, n) == 0)
	    {
	      dprintf(socket_com[n].socket, "ko\n");
	      close(socket_com[n].socket);
	      dprintf(1, "***Deleting player %d\n", socket_com[n].socket);
	      socket_com[n].socket = 0;
	    }
	}
      else if (strcmp(socket_com[n].team, "GRAPHIC") == 0)
	parse_graph(s_info, buffer, n);
      else
	verif_cours(s_info, buffer, n);
    }
}

void			create_ele_fct(t_server *s_info)
{
  s_info->elevation[0] = &check_first;
  s_info->elevation[1] = &check_second;
  s_info->elevation[2] = &check_third;
  s_info->elevation[3] = &check_fourth;
  s_info->elevation[4] = &check_fifth;
  s_info->elevation[5] = &check_sixth;
  s_info->elevation[6] = &check_seventh;
}

void			select_s(t_server *s_info, fd_set *rfd, struct timeval *time)
{
  int			i;
  int			tmp;
  int			al;
  struct sockaddr_in	addr;
  char			buffer[BUFFER_SIZE + 1];
  int			res;

  res = select(FD_SETSIZE, rfd, NULL, NULL, time);
  al = sizeof(addr);
  if (socket_com_size() <= MAX_CLIENTS && FD_ISSET(socket_s, rfd)) {
    if ((tmp =
	 accept(socket_s, (struct sockaddr *)&addr, (socklen_t *)&al)) == -1) {
      dprintf(1, "accept error\n");
      exit (0);
    }
    add_socket(tmp, &addr, s_info);
  }
  i = 0;
  recv_perso(rfd, s_info);
}

void			my_init_serveur(t_server *s_info) {
  fd_set		readfds;
  int			i = 0;
  time_t		*t;
  struct timeval	*time;

  create_socket_s(s_info);
  s_info->graph = 0;
  my_prompt_welc(s_info);
  s_info->list = NULL;
  s_info->egg = NULL;
  create_ele_fct(s_info);
  while (check_victory(s_info) != 1) {
    time->tv_sec= 1;
    FD_ZERO(&readfds);
    FD_SET(socket_s, &readfds);
    parc_sock(s_info);
    s_info->list = parse_list(s_info);
    i = 0;
    while (socket_com[i].socket != -2) {
      if (socket_com[i].socket != -1)
	FD_SET(socket_com[i].socket, &readfds);
      i++;
    }
    select_s(s_info, &readfds, time);
  }
}
