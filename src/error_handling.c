/*
** EPITECH PROJECT, 2017
** error_handling.c
** File description:
** error_handling.c file of the {{project_name}} project
*/

#include "my.h"

int my_error(char *error_message, char *command)
{
	my_printf("%s: %s\n", command, error_message);
	return (84);
}

int my_error_append(char *error_message, char *command, char append)
{
	my_printf("%s: %s%c'\n", command, error_message, append);
	return (84);
}
