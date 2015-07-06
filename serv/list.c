/*
** list.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue Jun 16 16:51:33 2015 lucie wautelet
** Last update Sun Jul  5 21:51:38 2015 lucie wautelet
*/

#include "../include/serveur.h"

t_buffer	*stock_list_second(t_buffer *tmp, t_buffer *s_infolist)
{
  t_buffer	*ele;
  t_buffer	*sauv;

  ele = s_infolist;
  while (ele->next != NULL)
    ele = ele->next;
  ele->next = tmp;
  tmp->prev = ele;
  return (ele);
}

t_buffer	*stock_list(t_server *s_info, char *buffer, int n)
{
  t_buffer	*tmp;
  t_buffer	*ele;

  if (socket_com[n].socket == s_info->graph)
    parse_graph(s_info, buffer);
  else
    {
      if ((tmp = malloc(sizeof(t_buffer))) == NULL)
	my_perror("allocation problem\n");
      tmp->id = n;
      tmp->buffer = strdup(buffer);
      tmp->end = 0;
      tmp->next = NULL;
      tmp->prev = NULL;
      if (s_info->list == NULL)
	return (tmp);
      else
	{
	  ele = stock_list_second(tmp, s_info->list);
	  return (ele);
	}
    }
}

t_buffer	*stock_list_cours(t_server *s_info, char *buffer, int n)
{
  t_buffer	*tmp;
  t_buffer	*ele;

  if (socket_com[n].socket == s_info->graph)
    parse_graph(s_info, buffer);
  else
    {
      if ((tmp = malloc(sizeof(t_buffer))) == NULL)
	my_perror("allocation problem\n");
      tmp->id = n;
      tmp->buffer = strdup(buffer);
      tmp->end = (float)clock() + definetim(buffer, s_info) * 100;
      tmp->prev = NULL;
      tmp->next = NULL;
      if (s_info->list == NULL)
	return (tmp);
      else
	{
	  ele = stock_list_second(tmp, s_info->list);
	  return (ele);
	}
    }
}

t_buffer	*delete_in_list(t_buffer *tmp, int count)
{
  t_buffer	*list;
  t_buffer	*ele;
  int		i;

  i = 0;
  list = NULL;
  ele = NULL;
  while (i < count && tmp->next != NULL)
    {
      ele = tmp->prev;
      list = tmp;
      tmp = tmp->next;
      i++;
    }
  if (count == 0 && tmp->next != NULL)
    {
      list = tmp->next;
      list->prev = NULL;
      list->next = tmp->next->next;
    }
  else if (count != 0)
    list->next = tmp->next->next;
  return (list);
}

t_buffer	*parse_list(t_server *s_info)
{
  t_buffer	*tmp;
  t_buffer	tmp2;
  float		time;
  int		count;

  tmp = s_info->list;
  count = 0;
  time = (float)clock();
  verif_egg(s_info);
  while (tmp != NULL)
    {
      if (tmp->end < clock() && tmp->end != 0)
	tmp = list_parc(tmp, count, s_info);
      count++;
	if (tmp != NULL && tmp->next == NULL)
	  {
	    while (tmp->prev != NULL)
	      tmp = tmp->prev;
	    return (tmp);
	  }
	(tmp != NULL) ? tmp = tmp->next : 0;
    }
  return (tmp);
}
