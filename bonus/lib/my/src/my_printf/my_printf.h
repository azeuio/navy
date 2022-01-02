/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>

enum printf_flag
{
    left_justify_fflag,
    signed_fflag,
    space_fflag,
    hash_fflag,
    zero_fflag,
    width_fflags,
    precision_fflag,
    len_fflag
};

void add_padding(unsigned long long n, char *format, char specifier, char c);
void add_prefix(unsigned long long n, char *format, char specifier);
void add_suffix(unsigned long long n, char *format, char specifier);
void add_zeros(unsigned long long n, char *format, char specifier);
void add_sign(unsigned long long n, char *format, char specifier);
void get_format_flag(char **all_flags, char *str, int *i, int flag_idx);
int print_arg(char *str, int *i, va_list *ap);
void showstr_octal(char *str);
void print_x_char(int x, char c);
int get_specifier_idx(char *str, int i);
int my_printf(char *str, ...);

#endif
