/*
** EPITECH PROJECT, 2021
** my lib header
** File description:
** my lib header
*/

#ifndef MY_LIB_H_
#define MY_LIB_H_

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
int my_put_nbr_h(short nb);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char * my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int n);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
void my_showstr(char const *);
int my_showmem(char const *str, int size);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int get_nbr_len_in_base(int, int const);
void my_putnbr_base(int, char const *);
char **my_str_to_word_array(char const *);
char *my_strdup(char const *);
int my_isalpha(char);
int my_isnum(char);
int my_isalnum(char);
int my_islower(char);
int my_isupper(char);
int my_isprint(char);
int get_word_count(char const *);
int my_printf(char *, ...);
void my_put_nbr_base_unsigned_ull(unsigned long long nbr, char const *base_str);
void my_put_nbr_base_unsigned_uh(unsigned short nbr, char const *base_str);
int get_nbr_len_in_base_unsigned(unsigned long long nbr, int const base);

#endif
