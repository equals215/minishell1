/*
** EPITECH PROJECT, 2017
** shell_core.c
** File description:
** shell_core.c file of the {{project_name}} project
*/

#include "my.h"

int(*builtins[BUILTINS_NB])(char **, shell_t *) =
	{my_exit, cd, env, my_unsetenv, my_setenv};

int prompt_display(shell_t *shell)
{
	char *tmp = malloc(sizeof(char) * my_strlen(shell->curr_dir));

	if (hidenp(shell->curr_dir, shell->home_dir)) {
		tmp = my_strdup(shell->curr_dir);
		tmp += my_strlen(shell->home_dir);
		my_printf("[%s@%s]: ~%s >$ ", shell->user, shell->hostname,
		*tmp != '\0' ? tmp : "");
	} else
		my_printf("[%s@%s]: %s >$ ", shell->user, shell->hostname,
			shell->curr_dir);
	return (0);
}

static int path_executable_handling(char **prompt_array, shell_t *shell)
{
	char *tmp = malloc(sizeof(char) *
	(my_strlen(shell->path ? shell->path : "")
	+ my_strlen(prompt_array[0])));
	char *path;
	int ret;
	int j = 0;

	for (int i = 5; shell->path[i] != '\0'; i++) {
		for (j = 0; shell->path[i] != ':' &&
		shell->path[i] != '\0'; i++, j++)
			tmp[j] = shell->path[i];
		tmp[j] = '/';
		tmp[j + 1] = '\0';
		path = my_strcat(tmp, prompt_array[0]);
		if ((ret = access(path, X_OK)) >= 0) {
			exec_prog(path, prompt_array, shell->env);
			break;
		}
	}
	return (ret >= 0 ? 0 : 84);
}

static int executable_handling(char **prompt_array, char **env)
{
	if (access(prompt_array[0], X_OK) >= 0)
		exec_prog(prompt_array[0], prompt_array, env);
	else
		my_printf("%s: Command not found.\n", prompt_array[0]);
	return (0);
}

static int builtin_handling(char **prompt_array, shell_t *shell)
{
	int i = 0;
	int ret = 0;
	const int builtin_list_len = BUILTINS_NB;
	char builtin_list[BUILTINS_NB][9] =
	{"exit", "cd", "env", "unsetenv", "setenv"};

	for (; i < builtin_list_len; i++)
		if (my_strcmp(prompt_array[0], builtin_list[i]) == 0)
			return ((*builtins[i])(prompt_array, shell));
	if ((ret = path_executable_handling(prompt_array, shell)) == 84)
		my_printf("%s: Command not found.\n", prompt_array[0]);
	return (ret);
}

int prompt_handling(char *prompted, shell_t *shell)
{
	char **prompt_array = NULL;

	shell= shell;
	if (!prompted || prompted[0] == '\0')
		return (0);
	prompt_array = my_str_to_word_array(prompted);
	if (!prompt_array[0])
		return (0);
	if (is_path(prompt_array[0]) && my_str_isprintable(prompt_array[0]))
		executable_handling(prompt_array, shell->env);
	else if (my_str_isprintable(prompt_array[0]))
		builtin_handling(prompt_array, shell);
	return (0);
}
