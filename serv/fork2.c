/*
** fork2.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/include
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sun Jun 28 14:19:05 2015 lucie wautelet
** Last update Sun Jul  5 16:19:17 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		recup_last_id(t_server *s_info)
{
  int		id;

  id = -1;
  while (s_info->egg != NULL)
    {
      if (s_info->egg->id > id)
	id = s_info->egg->id;
      s_info->egg = s_info->egg->next;
    }
  return (id);
}

int		recup_last(t_server *s_info)
{
  int		id;

  while (s_info->egg != NULL)
    {
      if (s_info->egg->next == NULL)
	return (s_info->egg->id);
      s_info->egg = s_info->egg->next;
    }
  return (0);
}

int		recup_last_id_team(t_server *s_info, int team)
{
  int		id;

  id = -1;
  while (s_info->egg != NULL)
    {
      if (s_info->egg->id > id && s_info->egg->team == team)
	id = s_info->egg->id;
      s_info->egg = s_info->egg->next;
    }
  return (id);
}
