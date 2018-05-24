/*
** EPITECH PROJECT, 2017
** funcs.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** funcs.h file of the {{project_name}} project
*/

/* src/env_handling.c */
char *my_getenv(char **, char *, int *);
int env_handling(char **, shell_t *);
/* src/utils2.c */
int hidenp(char *, char *);
char *my_concat_triple(char *, char *, char *);
/* src/command_parsing.c */
/* src/error_handling.c */
int my_error(char *, char *);
int my_error_append(char *, char *, char);
/* src/cd_builtin.c */
char *tilde_handling(shell_t *, char *);
int do_cd(shell_t *, char *);
/* src/main.c */
int main(int, char **, char **);
/* src/exec.c */
void exec_prog(char *, char **, char **);
/* src/utils.c */
int my_strtab_len(char **);
void shell_init(shell_t *);
_Bool is_alpha(char);
_Bool is_path(char *);
char **my_realloc_env(char **, shell_t *);
/* src/shell_core.c */
int prompt_display(shell_t *);
int prompt_handling(char *, shell_t *);
/* src/builtins.c */
int cd(char **, shell_t *);
int my_setenv(char **, shell_t *);
int my_unsetenv(char **, shell_t *);
int env(char **, shell_t *);
int my_exit(char **, shell_t *);
