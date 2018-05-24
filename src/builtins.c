/*
** EPITECH PROJECT, 2017
** builtins.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** builtin_picker.c file of the {{project_name}} project
*/

#include "my.h"

int cd(char **prompt, shell_t *shell)
{
	int len = my_strtab_len(prompt);

	if (len >= 3)
		return (my_error("Too many arguments", prompt[0]));
	else if (len >= 2)
		do_cd(shell, prompt[1]);
	else
		do_cd(shell, "~");
	return (84);
}

int my_setenv(char **prompt_array, shell_t *shell)
{
	char *to_append = NULL;
	char **new_env = my_realloc_env(shell->env, shell);

	if (prompt_array[1] != NULL) {
		to_append = prompt_array[1];
		if (prompt_array[2] != NULL)
			to_append = my_concat_triple(to_append, "=",
							prompt_array[2]);
		else
			to_append = my_concat_triple(to_append, "=", NULL);
		new_env[shell->env_1d_len - 1] = to_append;
		shell->env = new_env;
		return (0);
	}
	return (84);
}

int my_unsetenv(char **prompt_array, shell_t *shell)
{
	return (0);
}

int env(char **prompt_array, shell_t *shell)
{
	if (prompt_array[1] &&
	 	my_strcmp(prompt_array[1], "-u") == 0 && prompt_array[2])
		return (my_unsetenv(prompt_array, shell));
	if (prompt_array[1] &&
	  my_strcmp(prompt_array[1], "-u") == 0 && !prompt_array[2])
		return (my_error("option requires an argument -- 'u'",
			prompt_array[0]));
	else if (prompt_array[1])
		return (my_error_append("invalid option -- '",
			prompt_array[0], prompt_array[1][1]));
	else
		for (int i = 0; shell->env[i] != NULL; i++)
			my_printf("%s\n", shell->env[i]);
	return (0);
}

int my_exit(char **prompt_array, shell_t *shell)
{
	if (!prompt_array[1])
		if (!shell->last_return)
			exit(shell->last_return);
		else
			exit(0);
	else if (prompt_array[1])
		exit(my_atoi(prompt_array[1]));
	return (0);
}
