##
## EPITECH PROJECT, 2021
## libmy
## File description:
## Makefile
##

NAME		=	libmy.a

SRC			=	src/my_putchar.c						\
				src/my_isneg.c							\
				src/my_put_nbr.c						\
				src/my_swap.c							\
				src/my_putstr.c							\
				src/my_strlen.c							\
				src/my_getnbr.c							\
				src/my_compute_power_rec.c				\
				src/my_compute_square_root.c			\
				src/my_is_prime.c						\
				src/my_find_prime_sup.c					\
				src/my_strcpy.c							\
				src/my_strncpy.c						\
				src/my_revstr.c							\
				src/my_strstr.c							\
				src/my_strcmp.c							\
				src/my_strncmp.c						\
				src/my_strupcase.c						\
				src/my_strlowcase.c						\
				src/my_strcapitalize.c					\
				src/my_str_isalpha.c					\
				src/my_str_isnum.c						\
				src/my_str_islower.c					\
				src/my_str_isupper.c					\
				src/my_str_isprintable.c				\
				src/my_showstr.c						\
				src/my_strcat.c							\
				src/my_strncat.c						\
				src/get_nbr_len_in_base.c				\
				src/my_putnbr_base.c					\
				src/my_put_nbr_base_unsigned.c			\
				src/my_str_to_word_array.c				\
				src/my_strdup.c							\
				src/my_isalpha.c						\
				src/my_isnum.c							\
				src/my_isalnum.c						\
				src/my_islower.c						\
				src/my_isupper.c						\
				src/get_word_count.c					\
				src/my_isprint.c						\
				src/my_printf/my_printf.c				\
				src/my_printf/print_arg.c				\
				src/my_printf/get_flags.c				\
				src/my_printf/add_sign_and_zeroes.c		\
				src/my_printf/add_prefix_suffix.c		\
				src/my_printf/add_padding.c				\
				src/my_strchr.c							\


TEST_SRC	=	tests/my_putchar.c				\
				tests/my_isneg.c				\
				tests/my_put_nbr.c				\
				tests/my_swap.c					\
				tests/my_putstr.c				\
				tests/my_strlen.c				\
				tests/my_getnbr.c				\
				tests/my_compute_power_rec.c	\
				tests/my_compute_square_root.c	\
				tests/my_is_prime.c				\
				tests/my_find_prime_sup.c		\
				tests/my_strcpy.c				\
				tests/my_strncpy.c				\
				tests/my_revstr.c				\
				tests/my_strstr.c				\
				tests/my_strcmp.c				\
				tests/my_strncmp.c				\
				tests/my_strupcase.c			\
				tests/my_strlowcase.c			\
				tests/my_strcapitalize.c		\
				tests/my_str_isalpha.c			\
				tests/my_str_isnum.c			\
				tests/my_str_islower.c			\
				tests/my_str_isupper.c			\
				tests/my_str_isprintable.c		\
				tests/my_strcat.c				\
				tests/my_strncat.c				\
				tests/get_nbr_len_in_base.c		\
				tests/my_putnbr_base.c			\
				tests/my_str_to_word_array.c	\
				tests/my_strdup.c				\
				tests/my_isalpha.c				\
				tests/my_isnum.c				\
				tests/my_islower.c				\
				tests/my_isupper.c				\
				tests/get_word_count.c			\
				tests/my_printf.c


CC			=	gcc

CFLAGS		=	-Wall -Wextra -I./include

LDFLAGS		=

OBJ			=	$(SRC:.c=.o)

HEADERS		=	include/my.h	\

ROOT		=	../..

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(HEADERS) $(ROOT)/include

clean:		clean_tests
	rm -f $(OBJ)

fclean:		clean fclean_tests
	rm -f $(NAME)
	rm -f ../$(NAME)

re:			fclean all

clean_tests:
	rm -f ./*.gc*
	rm -f **/*.gc*

fclean_tests:	clean_tests
	rm -f unit_test

tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion
tests_run:	$(OBJ)
	$(CC) -o unit_test $(OBJ) $(TEST_SRC) $(CFLAGS) $(LDFLAGS)
	./unit_test

coverage:
	gcovr --branch

.PHONY:	all $(NAME) clean fclean re