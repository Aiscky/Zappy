/*
** my_sendrcv.c for zappy in /home/wautel_l/rendu/PSU_2014_zappy/lib
**
** Made by lucie wautelet
** Login   <wautel_l@epitech.net>
**
** Started on  Fri Jun  5 17:36:26 2015 lucie wautelet
** Last update Fri Jun  5 17:52:14 2015 lucie wautelet
*/

#include "../include/serveur.h"

int		my_printsd(int id, const char *format, ...)
{
  int		(*function[256])(const char *, va_list *, int, int);
  int		i;
  va_list	vl;
  int		a;

  va_start(vl, format);
  i = 0;
  my_function_alloc(function);
  my_putstr("\t\t\tSending message \"", 1);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  a = format[i + 1];
	  function[a](format, &vl, i + 1, 1);
	  i = i + 1;
	}
      else
	my_putchar(format[i], 1);
      i = i + 1;
    }
  my_putstr("\" to ", 1);
  my_putnbr(id, 1);
  my_putstr("\n", 1);
  va_end(vl);
}
