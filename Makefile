##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c					\
		src/init_game.c				\
		src/get_random.c			\
		src/game_loop.c 			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ./include -g3

NAME	=	my_yams

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
