/*
** print.c for printf in /home/wautel_l/rendu/printf
**
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
**
** Started on  Fri Nov 15 13:07:19 2013 wautelet lucie
** Last update Thu Jun 11 16:55:49 2015 lucie wautelet
*/

#include <stdio.h>
#include <stdarg.h>

int	my_type_char(const char *, va_list *, int, int);
int	my_type_unsigned_int(const char *, va_list *, int, int);
int	my_type_unsigned_int_to_hexa(const char *, va_list *, int, int);
int	my_put_int_binary(const char *, va_list *, int, int);

int	my_putchar_percentage(const char *format, va_list *vl, int i, int id)
{
  my_putchar('%', id);
  return (0);
}

int	my_putchar_error(const char *format, va_list *vl, int i, int id)
{
  my_putstr("bad flags: error", id);
  return(0);
}

int	my_putchar_int(const char *format, va_list *vl, int i, int id)
{
  if (format[i] == 'd' || format[i] == 'i')
    my_putnbr(va_arg(vl, int), id);
  if (format[i] == 'c')
    my_putchar(va_arg(vl, int), id);
  return (0);
}

void  my_function_alloc(int (*function[])(const char *, va_list *, int, int))
{
  int	i;

  i = 0;
  while (i < 257)
    {
      function[i] = &my_putchar_error;
      i++;
    }
  function[37] = &my_putchar_percentage;
  function[83] = &my_type_char;
  function[88] = &my_type_unsigned_int_to_hexa;
  function[99] = &my_putchar_int;
  function[100] = &my_putchar_int;
  function[105] = &my_putchar_int;
  function[98] = &my_put_int_binary;
  function[111] = &my_type_unsigned_int;
  function[115] = &my_type_char;
  function[117] = &my_type_unsigned_int;
  function[120] = &my_type_unsigned_int_to_hexa;
  function[112] = &my_type_unsigned_int_to_hexa;
}

int		my_printf(int id, const char *format, ...)
{
  int		(*function[256])(const char *, va_list *, int, int);
  int		i;
  va_list	vl;
  int		a;

  va_start(vl, format);
  i = 0;
  my_function_alloc(function);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  a = format[i + 1];
	  function[a](format, &vl, i + 1, id);
	  i = i + 1;
	}
      else
	my_putchar(format[i], id);
      i = i + 1;
    }
  va_end(vl);
}
