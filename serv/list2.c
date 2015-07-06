/*
** list2.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Mon Jun 29 23:37:08 2015 lucie wautelet
** Last update Sun Jul  5 18:45:05 2015 lucie wautelet
*/

#include	"../include/serveur.h"

t_buffer	*check_next(t_buffer *list, int n, t_server *s_info)
{
  t_buffer	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->id == n)
	{
	  tmp->end = (float)clock() + definetim(tmp->buffer, s_info) * 100;
	  my_parse_buff(tmp->buffer, tmp->id, s_info);
	  return (tmp);
	}
      tmp = tmp->next;
    }
  return (tmp);
}

t_buffer	*list_parc(t_buffer *list, int count, t_server *s_info)
{
  int		id;

  if (strncmp(list->buffer, "incantation", 11) != 0)
    my_parse_buff(list->buffer, list->id, s_info);
  check_incantation(list, list->id, s_info);
  id = list->id;
  list = delete_in_list(list, count);
  list = check_next(list, id, s_info);
  return (list);
}

int		list_empty(t_server *s_info, char *buffer, int id)
{
  while (s_info->list != NULL)
    {
      if (s_info->list->id == id)
	return (1);
      s_info->list = s_info->list->next;
    }

  return (0);
}
