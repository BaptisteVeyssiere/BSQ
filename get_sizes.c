/*
** get_sizes.c for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Dec  1 14:35:16 2015 Baptiste veyssiere
** Last update Wed Dec  9 17:35:07 2015 Baptiste veyssiere
*/

#include "prototypes.h"

void	line_loop(char buf[2], char *lines, int fd)
{
  int	i;

  i = 0;
  while (buf[0] != '\n')
    {
      if (buf[0] < '0' || buf[0] > '9')
        error_function();
      lines[i++] = buf[0];
      if (read(fd, buf, 1) == -1)
        error_function();
    }
  lines[i] = 0;
}

int	get_nbr_of_lines(int *length, char *file)
{
  int   fd;
  char  buf[2];
  char  *lines;

  buf[1] = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    error_function();
  if (read(fd, buf, 1) == -1)
    error_function();
  if ((lines = malloc(sizeof(*lines) * 11)) == NULL)
    error_function();
  line_loop(buf, lines, fd);
  if (lines[0] != 0)
    *length = my_getnbr(lines);
  free(lines);
  close(fd);
  return (0);
}

void	get_nbr_of_column(int *length, char *file)
{
  int   fd;
  char  buf[2];

  buf[1] = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    error_function();
  if (read(fd, buf, 1) == - 1)
    error_function();
  while (buf[0] != '.' && buf[0] != 'o')
    if (read(fd, buf, 1) == - 1)
      error_function();
  *length = 0;
  while (buf[0] != '\n')
    {
      if (read(fd, buf, 1) == -1)
	error_function();
      *length += 1;
    }
  close(fd);
}

void	copy_tab(char **tab, char *str, int line, int column)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  while (i < line)
    {
      j = 0;
      while (j < column)
	tab[i][j++] = str[k++];
      k++;
      i++;
    }
  free(str);
}

char	*get_tab(char *file, int lines, int column)
{
  int	fd;
  char	*buf;

  if ((buf = malloc(sizeof(*buf) * (lines * (column + 1) + 1))) == NULL)
    error_function();
  if ((fd = open(file, O_RDONLY)) == -1)
    error_function();
  if (read(fd, buf, 1) == -1)
    error_function();
  while (buf[0] != '\n')
    if (read(fd, buf, 1) == -1)
      error_function();
  if (read(fd, buf, lines * (column + 1)) == -1)
    error_function();
  buf[lines * (column + 1)] = 0;
  return (buf);
}
