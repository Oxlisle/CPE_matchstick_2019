##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC		=	sources/lib_functions/my_putchar.c\
			sources/lib_functions/my_putstr.c\
			sources/lib_functions/my_getnbr.c\
			sources/lib_functions/my_putnbr.c\
			sources/lib_functions/my_putnchar.c\
			sources/lib_functions/my_putstr_error.c\
			sources/lib_functions/my_putstrstr.c\
			sources/main_functions/main.c\
			sources/error_functions/main_error.c\
			sources/matchstick_functions/stat_functions/stat.c\
			sources/matchstick_functions/stat_functions/stat2.c\
			sources/matchstick_functions/game.c\
			sources/matchstick_functions/player_functions/player_turn.c\
			sources/matchstick_functions/ia_functions/ia_turn.c\

OBJ		=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-Wall -Wshadow -Wextra -Iinclude/

CC		=	gcc

all		:	$(NAME) clean

$(NAME)	:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re