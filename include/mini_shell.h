/*
** EPITECH PROJECT, 2024
** mini_shell.h
** File description:
** include for mini_shell
*/

#ifndef MINI_SHELL_
    #define MINI_SHELL_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdarg.h>
    #include <ctype.h>
    #include <stdbool.h>

typedef struct TokenContext_s {
    char **result;
    char *token;
    int index;
    int token_index;
    int checker;
} TokenContext_t;

typedef struct RedirectionContext_s {
    char **tokens;
    char *command;
    char *file;
    int append;
} RedirectionContext_t;

typedef enum CommandType_s {
    SIMPLE_COMMAND,
    PIPED_COMMAND,
    REDIRECT_COMMAND
} CommandType_t;

void my_putchar(char c);
void my_put_nbr(long nb);
void my_putstr(char const *str);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int mini_printf(const char *format, ...);
bool my_isspace(char c);
char **str_word_array(char *str);
char **str_to_word_array(char *str, char *delimiter);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strncmp(const char *str1, const char *str2, size_t n);
char *my_strdup(const char *s);
void print_env(char **env);
void free_tab(char **tab);
int my_cd(char **tab, char **env);
char *recup_pwd(char **env);
char *recup_path(char **env);
char *recup_home(char **env);
int go_home(char *home, char **env);
int exit_folder(char *path, char *home, char **env);
int len_tab(char **tab);
void execute_piped_commands(char *input, char **env);
int command_recode(char **tab, char **env);
char **split_redirections(const char *input);
void execute_redirection(char *input, char **env);

#endif /* MINI_SHELL_ */
