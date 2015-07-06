/*
** main.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serveur
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Tue May 12 15:05:25 2015 lucie wautelet
** Last update Sat Jun 27 16:09:54 2015 lucie wautelet
*/

#include "../include/serveur.h"

void		gener_instr(t_server *s_info)
{
  s_info->instr[0] = strdup("avance");
  s_info->instr[1] = strdup("droite");
  s_info->instr[2] = strdup("gauche");
  s_info->instr[3] = strdup("voir");
  s_info->instr[4] = strdup("prend");
  s_info->instr[5] = strdup("pose");
  s_info->instr[6] = strdup("expulse");
  s_info->instr[7] = strdup("broadcast");
  s_info->instr[8] = strdup("inventaire");
  s_info->instr[9] = strdup("incantation");
  s_info->instr[10] = strdup("connect_nbr");
}

int		main(int ac, char **av)
{
  t_server	begin;

  if (ac == 1)
    my_perror("Usage");
  my_init_arg(av, &begin);
  my_gener_map(&begin);
  my_gener_inv(&begin);
  gener_instr(&begin);
  my_init_serveur(&begin);
}
