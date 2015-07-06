/*
** my_putchar.c for my_putchar in /home/wautel_l/lib
**
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
**
** Started on  Tue Oct  8 17:49:11 2013 wautelet lucie
** Last update Fri Jun  5 14:08:52 2015 lucie wautelet
*/

void	my_putchar(char c, int id)
{
  write(id, &c, 1);
}
