/*
** get_sizes.c for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Dec  1 14:35:16 2015 Baptiste veyssiere
** Last update Tue Dec  1 19:26:13 2015 Baptiste veyssiere
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int     get_nbr_of_lines(int *length, char *file)
{
  int   fd;
  char  buf[2];
  char  *lines;
  int   i;

  buf[1] = 0;
  i = 0;
  fd = open(file, O_RDONLY);
  read(fd, buf, 1);
  lines = malloc(sizeof(*lines) * 11);
  while (buf[0] != '\n')
    {
      if (buf[0] < '0' || buf[0] > '9')
        {
          write(2, "Invalid size of array\n", 22);
          exit(1);
	}
      lines[i++] = buf[0];
      read(fd, buf, 1);
    }
  lines[i] = 0;
  if (lines[0] != 0)
    *length = my_getnbr(lines);
  free(lines);
  close(fd);
}

void     get_nbr_of_column(int *length, char *file)
{
  int   fd;
  char  buf[2];

  buf[1] = 0;
  fd = open(file, O_RDONLY);
  read(fd, buf, 1);
  while (buf[0] != '.' && buf[0] != 'o')
    read(fd, buf, 1);
  *length = 0;
  while (buf[0] != '\n')
    {
      read(fd, buf, 1);
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

  buf = malloc(sizeof(*buf) * (lines * (column + 1) + 1));
  fd = open(file, O_RDONLY);
  read(fd, buf, 1);
  while (buf[0] != '\n')
    read(fd, buf, 1);
  read(fd, buf, lines * (column + 1));
  buf[lines * (column + 1)] = 0;
  return (buf);
}
