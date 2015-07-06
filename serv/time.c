/*
** time.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue Jun 16 17:38:05 2015 lucie wautelet
** Last update Sun Jul  5 21:51:05 2015 lucie wautelet
*/

#include "../include/serveur.h"

float	definetim(char *str, t_server *s_info)
{
  float	res;
  int	i;

  res = -1.0;
  i = 0;
  while (s_info->instr[i])
    {
      if (i < 8 && strncmp(str, s_info->instr[i],
			   strlen(s_info->instr[i])) == 0)
	res = 7.0 / s_info->delay;
      else if (i == 8 && strncmp(str, s_info->instr[i],
				 strlen(s_info->instr[i])) == 0)
	res = 1.0 /s_info->delay;
      else if (res == -1.0)
	if (i == 9 && strncmp(str, s_info->instr[i],
			      strlen(s_info->instr[i])) == 0)
	  res = 300.0 / s_info->delay;
	else if (i == 10 && strncmp(str, s_info->instr[i],
				    strlen(s_info->instr[i])) == 0)
	  res = 0.0;
        else if (res == -1.0 && i == 10)
	  res = 42.0 / s_info->delay;
      i++;
    }
  return (res);
}
