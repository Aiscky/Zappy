/*
** my_strlen.c for my_strlen in /home/wautel_l/rendu/Piscine-C-Jour_04
** 
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
** 
** Started on  Thu Oct  3 14:25:47 2013 wautelet lucie
** Last update Sat Nov 16 16:33:55 2013 wautelet lucie
*/


int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}


