##
## Makefile for bsq in /home/VEYSSI_B/rendu/CPE_2015_BSQ
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Tue Dec  1 11:23:47 2015 Baptiste veyssiere
## Last update Tue Dec  1 19:18:53 2015 Baptiste veyssiere
##

NAME	= bsq

SRCS	= bsq.c \
	my_put.c \
	my_getnbr.c \
	get_sizes.c \
	get_max_square.c

OBJS	= $(SRCS:.c=.o)

$(NAME):
	cc -c $(SRCS) -I./include
	cc -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bis: fclean all
	rm -f $(OBJS)
