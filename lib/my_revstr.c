/*
** my_revstr.c for my_revstr in /home/wautel_l/rendu/Piscine-C-Jour_06/ex_03
** 
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
** 
** Started on  Mon Oct  7 13:50:17 2013 wautelet lucie
** Last update Sat Nov 16 16:47:43 2013 wautelet lucie
*/

char	*my_revstr(char *str)
{
  int	i;
  char	stock;
  int	n;

  i = 0;
  n = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  i = i - 1;
  while (n < i)
    {
      stock = str[n];
      str[n] = str[i];
      str[i] =  stock;
      i = i - 1;
      n = n + 1;
    }
  return (str);
}

