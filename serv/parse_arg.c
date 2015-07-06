/*
** parse_arg.c for plazza in /home/wautel_l/rendu/PSU_2014_zappy/serveur
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue May 12 15:15:12 2015 lucie wautelet
** Last update Sun Jul  5 17:47:36 2015 lucie wautelet
*/

#include "../include/serveur.h"

void	my_stock_larg(char *str, t_server *begin, char code, int *verif)
{
  if (code == 'p')
    {
      (verif[0] == 1) ? my_perror("Usage") : (verif[0] = 1);
      begin->port = atoi(str);
    }
  else if (code =='x')
    {
      (verif[1] == 1) ? my_perror("Usage") : (verif[1] = 1);
      begin->width = atoi(str);
      if (begin->width < 1)
	my_perror("x must be superior to 0\n");
    }
  else
    {
      (verif[2] == 1) ? my_perror("Usage") : (verif[2] = 1);
      begin->height = atoi(str);
      if (begin->height < 1)
	my_perror("y must be superior to 0\n");
    }
}

void	my_stock_timeplay(char *str, t_server *begin, char code, int *verif)
{
  if (code == 'c')
    {
      (verif[3] == 1) ? my_perror("Usage") : (verif[3] = 1);
      begin->client = atoi(str);
    }
  else if (code =='t')
    {
      begin->delay = atoi(str);
      if (begin->delay == 0)
	begin->delay = 100;
    }
}

void	my_stock_team(char **av, int lim, t_server *begin, int *nbarg)
{
  int	i;

  i = 0;
  if (lim == 0)
    my_perror("Usage");
  (nbarg[4] == 1) ? my_perror("Usage") : (nbarg[4] = 1);
  while (i < lim)
    {
      begin->team[i] = strdup(av[i]);
      begin->nbteam[i] = 0;
      i++;
    }
  begin->team[i] = NULL;
  begin->totteam = i;
}

void	my_verif_second(char **av, int *nbarg, t_server *begin)
{
  int	i;
  int	sauv;

  i = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == '-' && av[i][1] == 'n')
	{
	  sauv = i++;
	  while (av[i] != NULL && av[i][0] != '-')
	    i++;
	  my_stock_team(&av[sauv + 1], i - sauv - 1, begin, nbarg);
	}
      i++;
    }
  if (my_strlenint(nbarg) != 5)
    my_perror("Usage");
}

void	my_init_arg(char **av, t_server *begin)
{
  int	i;
  int	*verifarg;

  verifarg = malloc(sizeof(int) * 7);
  my_init_verifarg(verifarg);
  i = 0;
  begin->delay = 100;
  while (av[i] != NULL)
    {
      if (av[i][0] == '-' && (av[i][1] == 'p' ||
			      av[i][1] == 'x' || av[i][1] == 'y'))
	{
	  if (av[i + 1] == NULL || av[i + 1][0] == '-')
	    my_perror("Usage");
	  my_stock_larg(av[i + 1], begin, av[i][1], verifarg);
	}
      else if (av[i][0] == '-' && (av[i][1] == 'c' || av[i][1] == 't'))
	{
	   if (av[i + 1] == NULL || av[i + 1][0] == '-')
	     my_perror("Usage");
	   my_stock_timeplay(av[i + 1], begin, av[i][1], verifarg);
	}
      i++;
    }
  my_verif_second(av, verifarg, begin);
}
