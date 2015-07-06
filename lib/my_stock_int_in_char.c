/*
** my_stock_int_in_char.c for printf in /home/wautel_l/rendu/printf
** 
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
** 
** Started on  Sat Nov 16 11:06:47 2013 wautelet lucie
** Last update Sat Nov 16 13:44:58 2013 wautelet lucie
*/

#include <stdlib.h>

char 		*my_stock_int_in_char(unsigned int nb)
{
  int		inc;
  char		*stock;
  unsigned int	puissance;
  int		test;

  test = 1;
  puissance = 1000000000;
  stock = malloc(sizeof(char) * 200);
  while (nb / puissance == 0)
    puissance = puissance / 10;
  while (puissance >= 1)
    {
      if (nb / puissance != 0)
	{
	  test = 1;
	}
      if (test == 1)
	{
	  stock[inc] = (nb / puissance  + 48);
	  nb = nb - puissance * (nb / puissance);
	}
      puissance = puissance / 10;
      inc = inc + 1;
    }
  return (stock);
}
