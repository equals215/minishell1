/*
** EPITECH PROJECT, 2017
** shell_core.h
** File description:
** shell_core.h file of the {{project_name}} project
*/

#ifndef SHELL_CORE_H
#define SHELL_CORE_H

typedef struct shell_s
{
	int last_return;
	char **env;
	int env_1d_len;
	char *path;
	char **prompted;
	char *last_dir;
	char *curr_dir;
	char *home_dir;
	char *user;
	char *hostname;
}shell_t;

int prompt_handling(char *prompted, shell_t *shell);
int prompt_display(shell_t *shell);

#endif
