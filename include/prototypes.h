/*
** prototypes.h for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Tue Dec  1 17:18:20 2015 Baptiste veyssiere
** Last update Wed Dec  9 15:33:46 2015 Baptiste veyssiere
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	get_nbr_of_lines(int*, char*);
int     get_nbr_of_lines(int*, char*);
char    *get_tab(char*, int, int);
void	my_putchar(char);
int	my_getnbr(char*);
void    get_max_square_at(char**, int*, int*);
void    get_nbr_of_column(int*, char*);
void    copy_tab(char**, char*, int, int);
int	error_function();

#endif /* !PROTOTYPES_H_ */
