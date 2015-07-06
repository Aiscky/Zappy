/*
** my_getnbr.c for my_getnbr in /home/wautel_l/lib
** 
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
** 
** Started on  Tue Oct 15 19:16:51 2013 wautelet lucie
** Last update Thu Nov  7 20:36:21 2013 wautelet lucie
*/

int	verif_nbr(char *str, int i, int nb)
{
  int neg;

  neg = 0;
  while (str[i] > 47 && str[i] < 58)
    {
      nb = nb * 10;
      nb = nb + str[i] - 48;
      if (str[i -1] == 45)
	{
	  neg = 1;
	}
      i = i + 1;
    }
  if (neg == 1)
    {
      nb = -1 * nb;
    }
  return (nb);
}


int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	neg;

  i = 0;
  nb = 0;
  neg = 0;
  while (str[i] < 48 || str[i] > 57)
    {
      i = i + 1;
      if (str[i] == '\0')
	{
	  nb = 0;
	  return (nb);
	}
    }
  nb = verif_nbr(str, i, nb);
  return (nb);
}




