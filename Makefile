##
## Makefile for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Tue Dec  1 11:23:47 2015 Baptiste veyssiere
## Last update Thu Dec 10 11:55:02 2015 Baptiste veyssiere
##

CFLAGS	= -W -Werror -Wall -Wextra -ansi -pedantic -I./include

NAME	= bsq

SRCS	= bsq.c \
	my_put.c \
	my_getnbr.c \
	get_sizes.c \
	get_max_square.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
