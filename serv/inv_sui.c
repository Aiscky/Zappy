/*
** inv_sui.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Thu Jun 25 10:54:11 2015 lucie wautelet
** Last update Thu Jun 25 10:56:16 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		nb_by_case(t_server *s_info, int x, int y, int stone)
{
  int		inc;
  int		result;

  result = 0;
  inc = 0;
  while (s_info->map[x][y][inc] != -2)
    {
      if (s_info->map[x][y][inc] == stone)
	result += 1;
      inc += 1;
    }
  return (result);
}
