/*
** EPITECH PROJECT, 2017
** exec.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** exec.c file of the {{project_name}} project
*/

#include "my.h"

void exec_prog(char *path, char **args, char **env)
{
	int a = 0;
	pid_t tmp = fork();

	if (tmp == 0)
		execve(path, args, env);
	else
		wait(&a);
}
