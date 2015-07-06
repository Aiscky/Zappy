/*
** utils.c for plazza in /home/wautel_l/rendu/PSU_2014_zappy/serveur
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue May 12 15:08:54 2015 lucie wautelet
** Last update Sun Jul  5 18:05:59 2015 lucie wautelet
*/

#include "../include/serveur.h"

void	my_init_verifarg(int *verif)
{
  int	i;

  i = 0;
  while (i < 7)
    verif[i++] = 0;
}

int	my_strlenint(int *tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    i++;
  return (i);
}

void	my_perror(char *str)
{
  if (strncmp("Usage", str, 5) == 0)
    {
      printf("Usage: ./server -p [port] -x [width] -y [height] -n [team1]");
      printf(" [team2] -c [number of client by team] -t [delay of action]\n");
    }
  else
    write(1, str, strlen(str));
  exit(0);
}

void	my_prompt_welc(t_server *s_info)
{
  int	i;

  i = 0;
  s_info->graph = -2;
  dprintf(1, "listening on port %d...\n", s_info->port);
  dprintf(1, "Configuration Max(%d) World(%d*%d) T(%d)\n", s_info->client,
	    s_info->width, s_info->height, s_info->delay);
  dprintf(1, "Team:\n");
  while (s_info->team[i])
    {
      dprintf(1, "\tName(%s): Max(%d)\n", s_info->team[i], s_info->client);
      i++;
    }
  dprintf(1, "Generating world... done\n");
}

char	*my_cutn(char *str, char a)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == a)
	{
	  str[i] = 0;
	  return (str);
	}
      i++;
    }
}
