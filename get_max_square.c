/*
** get_max_square.c for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Dec  1 18:50:27 2015 Baptiste veyssiere
** Last update Wed Dec  2 00:25:10 2015 Baptiste veyssiere
*/

#include "struct.h"

int	check_abs(char **tab, int length[2], int *size, t_coord coord)
{
  int	i;
  int	j;

  i = *size + coord.y;
  j = coord.x;
  while (j <= *size + coord.x)
    {
      if (tab[i][j] == 'o')
	return (1);
      else
	j++;
    }
  j = coord.y;
  i = *size + coord.x;
  while (j <= *size + coord.y)
    {
      if (tab[j][i] == 'o')
	return (1);
      else
	j++;
    }
  return (0);
}

void		found_square(char **tab, int length[2], t_coord coord, int *size)
{
  int	key;

  key = 0;
  *size = 0;
  while (key == 0 && tab[coord.x][coord.y] == '.')
    {
      if (*size + coord.x >= length[1] || *size + coord.y >= length[0]
	  || check_abs(tab, length, size, coord) == 1)
	key = 1;
      else
	*size += 1;
    }
}

void	draw_the_square(char **tab, int length[2], int *max_size, t_coord coord_max)
{
  int	i;
  int	j;

  i = 0;
  while(i < length[0])
    {
      j = 0;
      while (j < length[1])
	{
	  if (i < (coord_max.y + *max_size) && i >= (coord_max.y) && j < (coord_max.x + *max_size) && j >= (coord_max.x))
	    my_putchar('x');
	  else
	    my_putchar(tab[i][j]);
	  j++;
	}
      my_putchar('\n');
      i++;
    }
}

void		get_max_square_at(char **tab, int length[2], int *max_size)
{
  t_coord	coord;
  t_coord	coord_max;
  int		size;

  coord.x = 0;
  while (coord.x < length[0])
    {
      coord.y = 0;
      while (coord.y < length[1])
	{
	  found_square(tab, length, coord, &size);
	  if (*max_size < size)
	    {
	      *max_size = size;
	      coord_max.x = coord.x;
	      coord_max.y = coord.y;
	    }
	  coord.y += 1;
	}
      coord.x += 1;
    }
  draw_the_square(tab, length, max_size, coord_max);
}
