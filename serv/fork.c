/*
** fork.c for  in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sat Jun 27 15:56:28 2015 lucie wautelet
** Last update Sun Jul  5 18:07:44 2015 lucie wautelet
*/

#include	"../include/serveur.h"

t_egg		*add_list_egg(t_server *s_info, int n, int team)
{
  t_egg		*tmp;
  t_egg		*ele;

  if ((tmp = malloc(sizeof(t_egg))) != NULL)
    {
      tmp->team = team;
      tmp->beg = (float)clock() + (42.0 / s_info->delay * 100);
      tmp->end = tmp->beg + 600 / s_info->delay * 100;
      tmp->id = recup_last_id(s_info) + 1;
      tmp->next = NULL;
      if (s_info->egg == NULL)
	return (tmp);
      else
	{
	  ele = s_info->egg;
	  while (ele->next != NULL)
	    ele = ele->next;
	  ele->next = tmp;
	  return (ele);
	}
    }
}

t_egg		*remove_list_egg(t_egg *list, int count, t_server *s_info)
{
  t_egg		*tmp;
  int		i;

  i = 0;
  tmp = NULL;
  while (i < count || list->next != NULL)
    {
     tmp  = list;
     list = list->next;
     i++;
    }
  (s_info->graph > -1) ? dprintf(s_info->graph, "edi %d\n", list->id) : 1;
  if (list->next != NULL || count != 0)
    tmp->next = list->next;
  free(list);
  return (tmp);
}

int		parc_list_egg(t_server *s_info, int team)
{
  int		res;
  float		time;

  time = (float)clock();
  res = 0;
  while (s_info->egg != NULL)
    {
      if (s_info->egg->team == team && s_info->egg->end > time &&
	  s_info->egg->beg < time)
	  res += 1;
      s_info->egg = s_info->egg->next;
    }
  return (res);
}

void		fork_fct(int n, t_server *s_info)
{
  int		i;

  i = 0;
  dprintf(socket_com[n].socket, "ok\n");
  (s_info->graph > -1) ? dprintf(s_info->graph, "pfk %d\n",
				 socket_com[n].socket) : 1;
}

void	       	verif_egg(t_server *s_info)
{
  t_egg		*tmp;
  float		time;
  int		count;

  count = 0;
  time = (float)clock();
  tmp = s_info->egg;
  while (tmp != NULL)
    {
      dprintf(1,"time : %3f   %3f", time, tmp->end);
      if (tmp->end < time)
	s_info->egg = remove_list_egg(tmp, count, s_info);
      count++;
      if (tmp != NULL)
	tmp = tmp->next;
    }
}
