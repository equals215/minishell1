/*
** EPITECH PROJECT, 2017
** env.c
** File description:
** env.c file of the {{project_name}} project
*/

#include "my.h"

char *my_getenv(char **env, char *name, int *pos)
{
	int len = 0;
	int i = 0;
	char *name_dup = NULL;
	char *env_var = NULL;
	char **env_dup = NULL;

	*pos = 0;
	if (name == NULL || env == NULL)
		return (NULL);
	for (name_dup = name; *name_dup && *name_dup != '='; ++name_dup);
	len = name_dup - name;
	for (env_dup = env; (env_var = *env_dup) != NULL;
	++env_dup, *pos += 1) {
		for (name_dup = name, i = len; i && *env_var; i--)
			if (*env_var++ != *name_dup++)
				break;
		if (i == 0 && *env_var++ == '=')
			return (env_var);
	}
	return (NULL);
}

int env_handling(char **env, shell_t *shell)
{
	int pos = 0;
	int fd_hostname = open("/etc/hostname", O_RDONLY);
	char *home = my_strdup("/home/");

	if (!(shell->env))
		shell->env = env;
	if (!(shell->path))
		shell->path = my_getenv(env, "PATH", &pos);
	if (!(shell->env_1d_len))
		shell->env_1d_len = my_strtab_len(env);
	if (!(shell->curr_dir))
		shell->curr_dir = my_strdup(my_getenv(env, "PWD", &pos));
	if (!(shell->user))
		shell->user = my_strdup(my_getenv(env, "USER", &pos));
	if (!(shell->home_dir))
		shell->home_dir = my_strcat(home, shell->user);
	if(!(shell->hostname))
		shell->hostname = get_next_line(fd_hostname);
	return (0);
}
