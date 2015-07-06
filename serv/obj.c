/*
** obj.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sun Jun 14 17:48:49 2015 lucie wautelet
** Last update Sun Jul  5 22:22:13 2015 lucie wautelet
*/

#include "../include/serveur.h"

void	print_obj(int opt, t_server *s_info, int n, int num)
{
  if (opt == 1)
    {
      dprintf(s_info->graph, "pdr %d %d\n", socket_com[n].socket, num);
    }
  else if (opt == 2)
    {
      dprintf(s_info->graph, "pgt %d %d\n", socket_com[n].socket, num);
    }
  print_inv_case(s_info, socket_com[n].x, socket_com[n].y);
}

void	my_prendok(int n, t_server *s_info, int inc, int i)
{
  int	x;
  int	y;

  x = socket_com[n].x;
  y = socket_com[n].y;
  if (s_info->map[x][y][inc + 1] == -2 && inc != 0)
    s_info->map[x][y][inc] = -2;
  else
    s_info->map[x][y][inc] = -1;
  if (i == 0)
    socket_com[n].pv += 126 / s_info->delay;
  socket_com[n].inventaire[i] += 1;
  dprintf(socket_com[n].socket, "ok\n");
  my_printsd(socket_com[n].socket, "ok");
}

void	my_prend(int n, t_server *s_info, char *str)
{
  int	i;
  int	inc;
  int	x;
  int	y;
  int	bol;

  bol = 0;
  i = 0;
  while (i < 7 && strcmp(s_info->stone[i], str) != 0)
    i += 1;
  inc = 0;
  x = socket_com[n].x;
  y = socket_com[n].y;
  while (s_info->map[x][y][inc] != -2)
    if (s_info->map[x][y][inc++] == i && bol == 0)
      {
	my_prendok(n, s_info, inc - 1, i);
	bol = 1;
	socket_com[n].pv -= definetim(str, s_info);
      }
  if (bol == 0)
    {
      dprintf(socket_com[n].socket, "ko\n");
      my_printsd(socket_com[n].socket, "ko");
    }
  print_obj(2, s_info, n, i);
}

void	my_posegood(int n, t_server *s_info, int j, int i)
{
  int	x;
  int	y;

  x = socket_com[n].x;
  y = socket_com[n].y;

  socket_com[n].inventaire[i] -= 1;
  if (s_info->map[x][y][j] == -2 && j < 20)
    s_info->map[x][y][j + 1] = -2;
  s_info->map[x][y][j] = i;
  dprintf(socket_com[n].socket, "ok\n");
  my_printsd(socket_com[n].socket, "ok");
}

void	my_pose(int n, t_server *s_info, char *str)
{
  int	i;
  int	j;
  int	x;
  int	y;

  x = socket_com[n].x;
  y = socket_com[n].y;
  j = 0;
  i = 0;
  while (i < 7 && strcmp(s_info->stone[i], str) != 0)
    i += 1;
  if (socket_com[n].inventaire[i] > 0)
    while (s_info->map[x][y][j] > 0 && j < 20)
      j += 1;
  if (j == 20 || socket_com[n].inventaire[i] < 1)
    {
      dprintf(socket_com[n].socket, "ko\n");
      my_printsd(socket_com[n].socket, "ko");
      socket_com[n].pv -= definetim(str, s_info);
    }
  if (j != 20)
    my_posegood(n, s_info, j, i);
  print_obj(1, s_info, n, i);
}
