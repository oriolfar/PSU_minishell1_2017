/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** minishell functions (header file)
*/

# ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include "my.h"
# include "structs.h"

// minishell.c
void 		minishell(shell_t *shell);
int 		main_minishell(int ac, char **av, char **env);

// utils/struct_utils.c
void 		free_all(shell_t *shell);
env_t 		*configure_env(char **env);
shell_t 	*configure(char **env);

// utils/parsing_utils.c
char 		*realloc_char(char *ptr, unsigned int size);
char 		*join_next_values(char **array);
char 		*get_next_line(int fdesc);

// builtin/exit_command.c
int 		exit_command(char *stdin,  char **arg,  shell_t *shell);

// builtin/cd_command.c
int 		cd_command(char *stdin, char **arg, shell_t *shell);

// builtin/setenv_command.c
int 		setenv_command(char *stdin, char **arg, shell_t *shell);

// builtin/unsetenv_command.c
int 		unsetenv_command(char *stdin, char **arg, shell_t *shell);

// actions/environment_actions.c
void 		env_del_variable(char *var, shell_t *shell);
void 		env_set_variable(char *var, char *content, shell_t *shell);
char 		*env_get_variable(char *var, shell_t *shell);
void 		env_check_home_change(shell_t *shell);

// managers/env_manager.c
env_t 		*new_environment_entry(char *var, char *content, env_t *env);
void 		print_environment(shell_t *shell);
void 		fill_environment(env_t *env_s, char **env);

// managers/prompt_manager.c
char 		*parse_cwd(char *buffer, shell_t *shell);
void 		display_prompt(shell_t *shell);

// managers/command_manager.c
int 		command_executor(char *stdin, shell_t *shell);

// managers/redirect_manager.c
void 		redirect_stdin(char **stdin);

# endif
