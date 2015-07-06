/*
** my_getnbr_base.c for my_getnbr_base in /home/wautel_l
** 
** Made by wautelet lucie
** Login   <wautel_l@epitech.net>
** 
** Started on  Thu Nov 14 10:39:28 2013 wautelet lucie
** Last update Sat Nov 16 10:45:39 2013 wautelet lucie
*/

int     init(int *nbr, int *j, int *i)
{
  *nbr = 0;
  *j = 0;
  *i = 1;
  return (0);
}

int     check_neg(char *s)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  while (s[i] && s[i] == '-')
    {
      cpt = cpt + 1;
      i = i + 1;
    }
  if (cpt % 2 == 0)
    {
      return (1);
    }
  return (-1);
}

int     check_base(char *base, int n)
{
  int   i;

  n = 0;
  while (base[n] != '\0')
    {
      i = 0;
      while (base[i] != '\0')
        {
          if (i != n)
            {
              if (base[n] == base[i])
                {
                  return (-1);
                }
            }
          i = i + 1;
        }
      n = n + 1;
    }
  return (0);
}

int     my_getnbr_base(char *str, char *base)
{
  int   nbr;
  int   j;
  int   k;
  int   i;

  init(&nbr, &j, &i);
  i = check_neg(str);
  if (check_base(base, 0) == -1)
    {
      my_putstr("bad base");
      return (0);
    }
  while (str[j] != '\0')
    {
      if (str[j] != '-' && str[j] != '+' && (str[j] < 48 || str[j] > 57))
	return (0);
      k = 0;
      while (k < my_strlen(base) && base[k] != str[j])
        k = k + 1;
      if (base[k] == str[j])
        nbr = nbr * my_strlen(base) + k;
      j = j + 1;
    }
  nbr = nbr * i;
  return (nbr);
}

