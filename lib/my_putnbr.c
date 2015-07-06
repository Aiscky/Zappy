/*
** my_put_nbr.c for my_put_nbr in /home/leroux_p/rendu/Piscine-C-lib
**
** Made by leroux pierre-henri
** Login   <leroux_p@epitech.net>
**
** Started on  Tue Oct  8 09:46:55 2013 leroux pierre-henri
** Last update Fri Jun  5 15:46:22 2015 lucie wautelet
*/

int	my_putnbr(int nb, int id)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-', id);
      my_putnbr(nb, id);
    }
  else
    {
      if (nb < 10)
	my_putchar(nb + 48, id);
      else
	{
	  my_putnbr(nb / 10, id);
	  my_putnbr(nb % 10, id);
	}
    }
}
