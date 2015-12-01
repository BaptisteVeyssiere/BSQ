/*
** bsq.c for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Dec  1 11:28:26 2015 Baptiste veyssiere
** Last update Wed Dec  2 00:25:20 2015 Baptiste veyssiere
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "prototypes.h"

void	free_function(char **tab, int line, int column)
{
  int	i;

  i = 0;
  while (i < line)
    free(tab[i++]);
  free(tab);
}

void	square(char **tab, int length[2])
{
  int	max_size;

  max_size = 0;
  get_max_square_at(tab, length, &max_size);
}

int	main(int ac, char **av)
{
  char	**tab;
  char	*str;
  int	length[2];
  int	i;

  if (ac != 2)
    {
      write(2, "usage: ./bsq file\n", 18);
      return (1);
    }
  length[0] = 0;
  length[1] = 0;
  get_nbr_of_lines(&length[0], av[1]);
  if (length[0] < 1)
    {
      write(2, "Please enter a number of line\n", 30);
      exit(1);
    }
  get_nbr_of_column(&length[1], av[1]);
  i = 0;
  str = get_tab(av[1], length[0], length[1]);
  tab = malloc(sizeof(*tab) * length[0]);
  while (i < length[0])
    tab[i++] = malloc(sizeof(**tab) * length[1]);
  copy_tab(tab, str, length[0], length[1]);
  square(tab, length);
  free_function(tab, length[0], length[1]);
  return (0);
}
