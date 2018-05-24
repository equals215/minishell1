/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main.c file of the {{project_name}} project
*/

#include "my.h"

int main(int argc, char **argv, char **env)
{
	char *prompted = NULL;
	shell_t *shell = malloc(sizeof(shell_t));

	shell_init(shell);
	do {
		env_handling(env, shell);
		prompt_handling(prompted, shell);
		prompt_display(shell);
	} while((prompted = get_next_line(0)));
	my_printf("exit\n");
	return (0);
}
