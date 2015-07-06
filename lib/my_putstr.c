/*
** my_putstr.c for my_putsr in /home/wautel_l/rendu/Piscine-C-Jour_04
**
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
**
** Started on  Thu Oct  3 13:21:08 2013 wautelet lucie
** Last update Fri Jun  5 14:11:23 2015 lucie wautelet
*/

int	my_putstr(char *str, int id)
{
  int	i;

  i = 0;
  while (str[i]  != '\0')
    {
      my_putchar(str[i], id);
      i =  i + 1;
    }
}
