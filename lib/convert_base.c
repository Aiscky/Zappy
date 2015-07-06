/*
** convert_base.c for printf in /home/wautel_l/rendu/printf
** 
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
** 
** Started on  Fri Nov 15 12:48:11 2013 wautelet lucie
** Last update Sat Nov 16 16:03:46 2013 wautelet lucie
*/
#include <stdlib.h>

char	*convert_base(char *nb, char *base_from, char *base_to)
{
  char  *res;
  int	i;
  int	lenght;
  int	dec_nb;

  i = 0;
  res = malloc(200);
  dec_nb = my_getnbr_base(nb, base_from);
  lenght = my_strlen(base_to);
  while (dec_nb > 0)
    {
      res[i] = base_to[dec_nb % lenght];
      dec_nb = dec_nb / lenght;
      i = i + 1;
    }
  my_revstr(res);
  return (res);
}
