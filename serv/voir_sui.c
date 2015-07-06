/*
** voir_sui.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/serv
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Sat Jun 27 00:17:03 2015 lucie wautelet
** Last update Sat Jun 27 02:09:52 2015 lucie wautelet
*/

#include	"../include/serveur.h"

int		verif_negla_voir(int x, int add, int ref)
{
  if (x + add < 0 && add > 0)
    {
      x = ref + (add * -1) + 1;
      return (x);
    }
  else if (x + add < 0 && add < 0)
    {
      x = ref + x + add;
    }
  return (x + add);
}

int		verif_max_haut_voir(int x, int add, int ref, int xbas)
{
  if (x + add >= ref)
    {
      x = x - ref + add;
      return (x);
    }
  return (x + add);
}

int		verif_maxla_voir(int x, int add, int ref, int opt)
{
  if (x + add >= ref)
    {
      x = 0;
      return (x);
    }
  return (x + add);
}
