/*
** check.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue Jun 16 18:36:53 2015 lucie wautelet
** Last update Sun Jul  5 14:10:15 2015 lucie wautelet
*/

#include "../include/serveur.h"

int	checked(t_server *s_info, int inc, int i, int *team)
{
  if (socket_com[i].team != NULL && (strcmp(socket_com[i].team,
					    "GRAPHIC") == 0))
    return (1);
  if (socket_com[i].team == NULL ||
      (strcmp(socket_com[i].team, s_info->team[inc]) == 0))
    {
      if (socket_com[i].level == 6 && socket_com[i].team != NULL)
	team[inc] += 1;
      return (1);
    }
  else
    return (0);
}

int	check_victory(t_server *s_info)
{
  int	i;
  int	inc;
  int	*team;

  if ((team = malloc(sizeof(int) * s_info->totteam)) == NULL)
    my_perror("memory allocation problem\n");
  i = 0;
  inc = 0;
  while (socket_com[i].socket != -1)
    {
      if (checked(s_info, inc, i, team) == 1)
	{
	  i++;
	  inc = 0;
	}
      else
	inc++;
    }
  inc = 0;
  while (inc < s_info->totteam)
    if  (team[inc++] == 6)
      return (1);
  return (0);
}
