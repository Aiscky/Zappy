/*
** function.c for my_printf in /home/wautel_l/rendu/printf
**
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
**
** Started on  Fri Nov 15 17:24:18 2013 wautelet lucie
** Last update Fri Jun  5 15:51:06 2015 lucie wautelet
*/

#include <stdarg.h>
#include <stdlib.h>

char	*convert_base(char *nbr, char *base_to, char *base_from);
char	*my_stock_int_in_char(unsigned int nb);

int	my_put_int_binary(const char *format, va_list *vl, int i, int id)
{
  char	*res;

  if (format[i] == 'b')
    {
      res = malloc(sizeof(char) * 300);
      res = my_stock_int_in_char(va_arg(*vl, unsigned int));
      my_putstr(convert_base(res, "0123456789", "01"), id);
      free(res);
    }
  if (format[i] == 'p')
    {
      my_putstr(convert_base((va_arg(vl, void *)), "0123456789", "0123456789abcdef"), id);
    }
}

int	my_type_char(const char *format, va_list *vl, int i, int id)
{
  char	*str;
  int	a;

  a = 0;
  if (format[i] == 's')
    {
      my_putstr(va_arg(*vl, const char *), id);
    }
  if (format[i] == 'S')
    {
      str = va_arg(*vl, char *);
      while (str[a] != '\0')
	{
	  if (str[a] < 32 || str[a] >= 127)
	    {
	      my_putchar(92, id);
	      my_putstr(convert_base(my_stock_int_in_char(str[a]), \
				     "0123456789", "01234567"), id);
	    }
	  else
	    my_putchar(str[a], id);
	  a = a + 1;
	}
    }
  return (0);
}

int	my_type_unsigned_int(const char *format, va_list *vl, int i, int id)
{
  char	*res;

  res = malloc(sizeof(char) * 300);
  if (format[i] == 'u')
    my_putnbr(va_arg(*vl, unsigned int), id);
  if (format[i] == 'o')
    {
      res = my_stock_int_in_char(va_arg(*vl, unsigned int));
      my_putstr(convert_base(res, "0123456789", "01234567"), id);
    }
  free(res);
  return (0);
}

int	my_type_unsigned_int_to_hexa(const char *format, va_list *vl, int i, int id)
{
  char	*res;

  if (format[i] == 'X')
    {
      res = malloc(sizeof(char) * 300);
      res = my_stock_int_in_char(va_arg(*vl, unsigned int));
      my_putstr(convert_base(res, "0123456789", "0123456789ABCDEF"), id);
      free(res);
    }
  if (format[i] == 'x')
    {
      res = malloc(sizeof(char) * 300);
      res = my_stock_int_in_char(va_arg(*vl, unsigned int));
      my_putstr(convert_base(res, "0123456789", "0123456789abcdef"), id);
      free(res);
    }
  return (0);
}
