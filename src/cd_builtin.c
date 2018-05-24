/*
** EPITECH PROJECT, 2017
** cd_builtin.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** cd_builtin.c file of the {{project_name}} project
*/

#include "my.h"

char *tilde_handling(shell_t *shell, char *path_to_cd)
{
	char *return_str = my_strdup(shell->home_dir);

	path_to_cd += 1;
	if (*path_to_cd != '\0')
		path_to_cd += 1;
	return_str = my_strcat(return_str, path_to_cd);
	return (return_str);
}

int do_cd(shell_t *shell, char *path_to_cd)
{
	if (*path_to_cd == '~')
		path_to_cd = tilde_handling(shell, path_to_cd);
	if (access(path_to_cd, F_OK) == -1)
		return (my_error("No such file or directory.", "cd"));
	if (access(path_to_cd, R_OK) == -1)
		return (my_error("Permission denied.", "cd"));
	if (chdir(path_to_cd) == -1)
		return (my_error(
			"Access to this directory is restricted.", "cd"));
	if (is_path(path_to_cd))
		shell->curr_dir = path_to_cd;
	else
		shell->curr_dir = my_concat_triple(shell->curr_dir, "/", path_to_cd);
	return (0);
}
