/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header file that contain all the function of my_lib
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define READ_SIZE 128
#define BUILTINS_NB 5

#include "shell_core.h"
#include "funcs.h"

void exec_prog(char *path, char **args, char **env);

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a , int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char * str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase (char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum (char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable (char const *str);
char **my_str_to_word_array(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest , char const *src, int nb);
int my_strtod(char const *str, char *base, char *endptr);
void my_itoa(int n, char s[]);
int get_length(int nb, int length);
int get_nb_size(int nb, int size);
char *fill_s(char *s, int m, int nb, int length);
char *my_itos(int nb);
int my_atoi(char *str);
void my_printf(char const *format, ...);
void sum_stdarg(int i, int nb, ...);
void disp_stdarg(char *s, ...);
void my_put_nbrbase(int nb, char *base);
void my_putstr_print(char const *str);
void my_put_nbr_oct(int nb, char *base);
void my_put_nbrp(int nb, char *base);
void my_put_nbr_hexa(int nb, char *base);
void check_format_diese(char const *format, int i, va_list list);
void check_format(char const *format, int i, va_list list);
void my_put_nbr_hexa2(int nb, char *base);
void flag_base(char const *s, int i, va_list list);
void flag_with_hastag(char const *s, int i, va_list list);
void flag_classic(char const *s, int i, va_list list);
void check_format_diese(char const *format, int i, va_list list);
char *my_strdup(char const *src);
char *get_next_line(int fd);

#endif
