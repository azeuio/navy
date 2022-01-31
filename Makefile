##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME		=	navy

SRC			=	src/main.c				\
				src/print_help.c		\
				src/signals.c			\
				src/game.c				\
				src/board.c				\
				src/board_has_ships.c	\
				src/board_draw.c		\
				src/player_turn.c		\
				src/av_contains.c		\

TEST_SRC	=	tests/av_contains.c		\

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -I./include

LDFLAGS		=	-Llib -lmy

all:	lib $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

lib:
	$(MAKE) -C lib

clean:	clean_tests
	$(MAKE) -C lib clean
	rm -f $(OBJ)

fclean:	clean fclean_tests
	$(MAKE) -C lib fclean
	find . -name \*.o -delete
	rm -f $(NAME)

clean_tests:
	find . -name \*.gc\* -delete
	rm -f $(OBJ)

fclean_tests:	clean_tests
	rm -f unit_tests

tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion
tests_run:	lib $(OBJ)
	$(CC) -o unit_test $(filter-out src/main.o, $(OBJ)) \
	$(TEST_SRC) $(CFLAGS) $(LDFLAGS)
	./unit_test
	$(MAKE) clean_tests

coverage:
	gcovr --branch

re:	fclean all

.PHONY:	all $(NAME) lib clean fclean re clean_tests fclean_tests \
tests_run coverage