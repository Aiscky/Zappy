/*
** map.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Thu Jun  4 13:42:33 2015 lucie wautelet
** Last update Sun Jul  5 19:09:11 2015 lucie wautelet
*/

#include	"../include/serveur.h"

void		my_full_zero(t_server *begin)
{
  int		total;
  int		inc;
  int		x;
  int		y;

  x = 0;
  y = 0;
  inc = 0;
  while (x < begin->width)
    {
      y = 0;
      while (y < begin->height)
	{
	  begin->map[x][y][0] = -2;
	  y += 1;
	}
      x += 1;
    }
}

void		full_nourriture(t_server *begin)
{
  int		x;
  int		y;
  int		total;
  int		inc;
  int		inc2;

  inc = 0;
  total = begin->width * begin->height;
  while (inc < total)
    {
      x = rand() % begin->width;
      y = rand() % begin->height;
      inc2 = 0;
      while (begin->map[x][y][inc2] != -2)
	inc2 += 1;
      begin->map[x][y][inc2] = 0;
      begin->map[x][y][inc2 + 1] = -2;
      inc += 1;
    }
}

void		my_full_map(t_server *begin)
{
  int		nb;
  int		x;
  int		y;
  int		inc;
  int		f;
  int		stone;

  inc = 0;
  nb = 100;
  my_full_zero(begin);
  while (inc < nb)
    {
      f= 0;
      x = rand() % begin->width;
      y = rand() % begin->height;
      stone = rand() % 6 + 1;
      while (begin->map[x][y][f] != -2)
	f += 1;
      begin->map[x][y][f] = stone;
      begin->map[x][y][f + 1] = -2;
      inc += 1;
    }
  full_nourriture(begin);
}

void		my_gener_map(t_server *begin)
{
  int		inc;
  int		a;

  inc = 0;
  if ((begin->map = malloc(sizeof(int **) * begin->width)) == NULL)
    my_perror("error during memory allocation\n");
  while (inc < begin->width)
    {
      a = 0;
      if ((begin->map[inc] = malloc(sizeof(int *) * begin->height)) == NULL)
	my_perror("error during memory allocation\n");
      while (a < begin->height)
	{
	  if ((begin->map[inc][a] = malloc(sizeof(int) * 10)) == NULL)
	    my_perror("error during memory allocation\n");
	  a += 1;
	}
      inc += 1;
    }
  srand(time(NULL));
  my_full_map(begin);
}
