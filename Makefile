##
## Makefile for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Tue Dec  1 11:23:47 2015 Baptiste veyssiere
## Last update Wed Dec  9 19:01:46 2015 Baptiste veyssiere
##

CFLAGS	= -W -Werror -Wall -Wextra -ansi -pedantic

NAME	= bsq

SRCS	= bsq.c \
	my_put.c \
	my_getnbr.c \
	get_sizes.c \
	get_max_square.c

OBJS	= $(SRCS:.c=.o)

$(NAME):
	cc -c $(CFLAGS) $(SRCS) -I./include
	cc -o $(NAME) $(OBJS) -I./include

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
