/*
** my_getnbr.c for my_getnbr in /home/scutar_n/rendu/tests
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Fri Oct  9 13:59:03 2015 nathan scutari
** Last update Sun Nov 29 16:53:24 2015 nathan scutari
*/

int	is_positive(char *tab)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while ((tab[i] < 48 || tab[i] > 57) && tab[i] != '\0')
    {
      if (tab[i] != '+' && tab[i] != '-')
	return (2);
      i = i + 1;
    }
  i = i - 1;
  while (tab[i] == '-' || tab[i] == '+')
    {
      if (tab[i] == '-')
	n = n + 1;
      i = i - 1;
    }
  if ((n / 2) *2 == n)
    return (1);
  else
    return (0);
}

int	number_length(char *tab)
{
  int	i;
  int	taille;

  i = 0;
  taille = 0;
  while ((tab[i] < 48 || tab[i] > 57) && tab[i] != '\0')
    i = i + 1;
  while (tab[i] <= 57 && tab[i] >= 48)
    {
      taille = taille + 1;
      i = i + 1;
    }
  return (taille);
}

int	str_to_int(char *tab, int length, int puissance)
{
  int	i;
  int	j;
  int	result;

  i = 0;
  j = 0;
  result = 0;
  while (tab[j] <= 47 || tab[j] >= 58)
    j = j + 1;
  while (i < length - 1)
    {
      puissance = puissance * 10;
      i = i + 1;
    }
  i = 0;
  while (i < length)
    {
      result = result + (tab[j] - 48) * puissance;
      j = j + 1;
      puissance = puissance / 10;
      i = i + 1;
    }
  return (result);
}

int	is_overflow(char *tab, int length)
{
  int	test;
  int	i;

  i = 0;
  if (length > 10)
    return (1);
  if (length < 10)
    return (0);
  if (length == 10)
    {
      test = str_to_int(tab, length - 1, 1);
      if (test < 214748364)
	return (0);
      if (test > 214748364)
	return (1);
      if (test ==  214748364)
	{
	  while (tab[i] <= 48 || tab[i] >= 57)
	    i = i + 1;
	  if (tab[i + 9] > '7')
	    return (1);
	  else
	    return (0);
	}
    }
}

int	my_getnbr(char *tab)
{
  int	posit;
  int	length;
  int	over;
  int	result;

  posit = is_positive(tab);
  if (posit == 2)
    return (0);
  length = number_length(tab);
  over = is_overflow(tab, length);
  if (over)
    return (0);
  result = str_to_int(tab, length, 1);
  if (posit == 0)
    result = result * -1;
  return (result);
}
