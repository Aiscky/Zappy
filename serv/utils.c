/*
** utils.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sat Jul  4 14:31:01 2015 lucie wautelet
** Last update Sat Jul  4 16:12:23 2015 lucie wautelet
*/

#include	"../include/serveur.h"

void		co_default(int fd, t_server *s_info)
{
  dprintf(1, "tentative de connexion sur le port par defaut\n");
  s_info->server_sin.sin_port = htons(4258);
  s_info->port = 4258;
  if (bind(fd, (struct sockaddr *)&(s_info->server_sin),
	   sizeof(s_info->server_sin)) == -1)
    {
      close(fd);
      perror("bind");
    }
}

int		recup_coord(char *str, int nb)
{
  int	i;
  int	tmp;

  tmp = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] > 47 && str[i] < 58)
	{
	  if (tmp == nb)
	    return (atoi(&str[i]));
	  while (str[i] > 47 && str[i] < 58)
	    i++;
	  tmp += 1;
	}
      i += 1;
    }
}
