/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utils.c file of the {{project_name}} project
*/

#include "my.h"

int my_strtab_len(char **tab)
{
	int i = 0;

	for(; tab[i] != NULL; i++);
	return (i);
}

void shell_init(shell_t *shell)
{
	shell->last_return = 0;
	shell->env = NULL;
	shell->env_1d_len = 0;
	shell->path = NULL;
	shell->prompted = NULL;
	shell->last_dir = NULL;
	shell->curr_dir = NULL;
	shell->home_dir = NULL;
	shell->user = NULL;
	shell->hostname = NULL;
}

bool is_alpha(char c)
{
	if ((c <= 90 && c >= 65) || (c <= 122 && c >= 97))
		return (true);
	return (false);
}

bool is_path(char *str)
{
	for (int i = 0; !(is_alpha(str[i])) && str[i] != '\0'; i++)
		if (str[i] == '/')
			return (true);
	return (false);
}

char **my_realloc_env(char **env, shell_t *shell)
{
	int i = 0;
	char **env_dup = malloc(sizeof(char **) * (shell->env_1d_len + 2));

	for (; i < shell->env_1d_len + 1; i++) {
		env_dup[i] = malloc(sizeof(char *) * (env[i] ? my_strlen(env[i]) : 2));
		env_dup[i] = my_strcpy(env_dup[i], env[i] ? env[i] : "");
	}
	env_dup[i + 1] = NULL;
	shell->env = env_dup;
	shell->env_1d_len = i;
	return (env_dup);
}
