/*
** my_put.c for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Dec  1 11:27:15 2015 Baptiste veyssiere
** Last update Wed Dec  9 17:44:45 2015 Baptiste veyssiere
*/

#include "prototypes.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *s)
{
  while (*s != 0)
    my_putchar(*s++);
}
