##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME		=	navy

SRC			=	src/main.c			\
				src/print_help.c	\
				src/board.c			\
				src/board_draw.c	\

TEST_SRC	=	

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -I./include -g

LDFLAGS		=	-Llib -lmy

all:	lib $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

lib:
	$(MAKE) -C lib

clean:	clean_tests
	$(MAKE) -C lib clean
	rm -f **/*.o

fclean:	clean fclean_tests
	$(MAKE) -C lib fclean
	rm -f $(NAME)

clean_tests:
	rm -f ./*.gc*
	rm -f $(OBJ)

fclean_tests:	clean_tests
	rm -f unit_tests

tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion
tests_run:	lib $(OBJ)
	$(CC) -o unit_test $(filter-out src/main.o, $(OBJ)) \
	$(TEST_SRC) $(CFLAGS) $(LDFLAGS)
	./unit_test

coverage:
	gcovr --branch

re:	fclean all

.PHONY:	all $(NAME) lib clean fclean re clean_tests fclean_tests \
tests_run coverage