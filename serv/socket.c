/*
** socket.c for myirc in /home/manin_d/rendu/PSU_2014_myirc/server
**
** Made by manin dylan
** Login   <manin_d@epitech.net>
**
** Started on  Sun Apr 19 17:19:31 2015 manin dylan
** Last update Sun Jul  5 22:50:19 2015 lucie wautelet
*/

#include		"../include/serveur.h"

void			create_socket_s(t_server *s_info) {
  struct protoent	*pe;

  if ((pe = getprotobyname("TCP")) == NULL)
    perror("getprotobyname");
  if ((socket_s = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    perror("socket");
  s_info->server_sin.sin_family = AF_INET;
  s_info->server_sin.sin_port = htons(s_info->port);
  s_info->server_sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(socket_s, (struct sockaddr *)&(s_info->server_sin),
           sizeof(s_info->server_sin)) == -1)
    co_default(socket_s, s_info);
  if (listen(socket_s, 42) == -1) {
    close(socket_s);
    perror("listen");
  }
  socket_com[0].socket = -1;
  socket_com[1].socket = -2;
}

void			add_sui(int socket, t_server *s, struct sockaddr_in *ad, int i)
{
  dprintf(1, "New connection from %d.%d.%d.%d\n",
	    (int)ad->sin_addr.s_addr&0xFF, (int)((ad->sin_addr.s_addr&0xFF00)>>8),
	    (int)((ad->sin_addr.s_addr&0xFF0000)>>16),
	    (int)((ad->sin_addr.s_addr&0xFF000000)>>24));
  my_gener_persomap(s, i);
  dprintf(socket, "BIENVENUE\n");
  my_printsd(socket, "BIENVENUE");
}

void                    add_socket(int fd, struct sockaddr_in *a, t_server *s)
{
  int			i;
  int			n;

  n = 1;
  i = 0;
  while (socket_com[i].socket != -1) {
    i++;
  }
  if (socket_com[i].socket == -1 && socket_com[i + 1].socket == -2)
    {
      socket_com[i + 1].socket = -1;
      socket_com[i + 2].socket = -2;
    }
  socket_com[i].socket = fd;
  socket_com[i].username = NULL;
  socket_com[i].team = NULL;
  socket_com[i].inventaire[0] = 10;
  socket_com[i].level = 1;
  socket_com[i].end = clock() + 126 / (float)s->delay * 100;
  socket_com[i].pv = 1260 / (float)s->delay;
  while (n < 7)
    socket_com[i].inventaire[n++] = 0;
  add_sui(fd, s, a, i);
}

int			socket_com_size() {
  int			i;
  int			size;

  i = 0;
  size = 0;
  while (socket_com[i].socket != -2) {
    if (socket_com[i].socket)
      size++;
    i++;
  }
  return (size - 1);
}
