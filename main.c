/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** mini shell
*/

#include "include/mini_shell.h"

int execute(char *cmd, char **tab, char **env)
{
    pid_t pid = fork();
    int status;



    
    if (pid == -1) {
        perror("fork");
        return 84;
    }
    if (pid == 0) {
        execve(cmd, tab, env);
        exit(EXIT_FAILURE);
    }
    if (waitpid(pid, &status, 0) == -1)
        perror("waitpid");
    return 0;
}

static void my_free(char *path, char *path_copy, char *cmd)
{
    free(path);
    free(path_copy);
    free(cmd);
}

static int which_command(char **tab, char **env)
{
    char *cmd = malloc(1024);
    char *path = recup_path(env);
    char *path_copy = my_strdup(path);
    char *strToken = strtok(path_copy, ":");
    int i = 0;

    while (strToken != NULL) {
        my_strcpy(cmd, strToken);
        my_strcat(cmd, "/");
        my_strcat(cmd, tab[0]);
        if (access(cmd, F_OK) == 0) {
            execute(cmd, tab, env);
            i = 1;
            break;
        }
        strToken = strtok(NULL, ":");
    }
    my_free(path, path_copy, cmd);
    return i;
}

int command_recode(char **tab, char **env)
{
    if (my_strcmp(tab[0], "env") == 0) {
        print_env(env);
        return 0;
    }
    if (my_strcmp(tab[0], "cd") == 0) {
        my_cd(tab, env);
        return 0;
    }
    if (my_strcmp(tab[0], "exit") == 0) {
        return 0;
    }
    if (which_command(tab, env) == 1) {
        return 0;
    } else {
        mini_printf("%s: Command not found.\n", tab[0]);
    }
    return 0;
}

void split(char **tab, char **commands, int i, char **env)
{
    tab = str_word_array(commands[i]);
    if (tab[0] != NULL)
        command_recode(tab, env);
    free_tab(tab);
}

int parse(char *input, char **env)
{
    char **commands = str_to_word_array(input, ";");
    char **tab = NULL;

    for (int i = 0; commands[i] != NULL; i++) {
        if (strchr(commands[i], '|') != NULL) {
            execute_piped_commands(commands[i], env);
            break;
        }
        if (strchr(commands[i], '>') || strchr(commands[i], '<')) {
            execute_redirection(commands[i], env);
        } else {
            split(tab, commands, i, env);
        }
    }
    free_tab(commands);
    return 0;
}

static char **copy_env(char **env)
{
    char **buffer = NULL;
    int i = 0;

    while (env[i])
        i++;
    buffer = malloc(sizeof(char *) * (i + 1));
    if (buffer == NULL)
        return NULL;
    for (i = 0; env[i] != NULL; i++) {
        buffer[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        if (buffer[i] == NULL) {
            free(buffer);
            return NULL;
        }
        my_strcpy(buffer[i], env[i]);
    }
    buffer[i] = NULL;
    return buffer;
}

int main(int argc, char **argv, char **env)
{
    char *input = NULL;
    ssize_t read;
    size_t len = 0;
    char **buffer = copy_env(env);

    if (isatty(0) == 0)
        mini_printf("$> ");
    while (my_strcmp(input, "exit\n") != 0) {
        if (isatty(STDIN_FILENO))
            mini_printf("$> ");
        read = getline(&input, &len, stdin);
        if (read == -1)
            break;
        parse(input, buffer);
    }
    free(input);
    free_tab(buffer);
    return 0;
}
