/*
** EPITECH PROJECT, 2017
** utils2.c
** File description:
** utils2.c file of the {{project_name}} project
*/

#include "my.h"

int hidenp(char *src, char *to_search)
{
	for (; *src; src++) {
		if (*to_search && *to_search == *src)
			to_search++;
	}
	if (!*to_search)
		return (1);
	return (0);
}

char *my_concat_triple(char *dest, char *first_src, char *second_src)
{
	int dest_len = my_strlen(dest);
	int first_len = my_strlen(first_src);
	int second_len = second_src ? my_strlen(second_src) : 0;
	int final_len = 0;
	char *temp = malloc(dest_len + first_len + second_len + 1);

	my_strcpy(temp, dest);
	if (first_src)
		temp = my_strcat(temp, first_src);
	if (second_src)
		temp = my_strcat(temp, second_src);
	temp[my_strlen(temp)] = '\0';
	return (temp);
}
