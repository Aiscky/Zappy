/*
** broadcast.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Mon Jun 29 13:03:29 2015 lucie wautelet
** Last update Sun Jul  5 20:19:22 2015 lucie wautelet
*/

#include	"../include/serveur.h"

float		calcangle(int *coord)
{
  float		longu;
  float		adj;
  float		angle;

  longu = sqrt(pow(coord[0], 2) + pow(coord[1], 2));
  adj = abs(coord[0]);
  angle =  cos(adj / longu);
  angle = (angle * 180) / PI;
  angle = 90 / angle;
  (angle < 0) ? angle = angle * -1 : 1;
  return (angle);
}

void		send_broadcast(int n, char *str, t_server *s_info, int *co)
{
  float		xref;
  float		yref;
  float		angle;
  int		dir;

  xref = socket_com[n].x + co[0] - s_info->width / 2;
  yref = socket_com[n].y + co[1] - s_info->height / 2;
  angle = calcangle(co);
  if (abs(xref) > s_info->width / 2)
    (xref > 0) ? xref -= s_info->width : xref += s_info->width;
  if (abs(yref) > s_info->height / 2)
    (yref > 0) ? yref -= s_info->height : yref += s_info->height;
  dir = choose_dir(angle, xref, yref, n);
}

void		broadcast_fct(char *str, int n, t_server *s_info)
{
  float		co[2];
  int		i;

  i = 0;
  co[0] = s_info->width / 2 + socket_com[n].x;
  co[1] = s_info->hegiht / 2 + socket_com[n].y;
  while (socket_com[i].socket != -1)
    {
      if (i == n)
	{
	  my_printsd(s_info->socket_com[i].socket, "ok");
	  dprintf(s_info->socket_com[i].socket, "ok\n");
	}
      else
	send_broadcast(i, str, s_info, co);
      i += 1;
    }
}
