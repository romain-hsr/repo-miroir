/*
** EPITECH PROJECT, 2025
** pipe.c
** File description:
** manage pipes, execute several commands at the same time
*/

#include "include/mini_shell.h"

static int count_commands(char **commands)
{
    int num_cmds = 0;

    while (commands[num_cmds] != NULL)
        num_cmds++;
    return num_cmds;
}

static void create_pipes(int *pipes, int num_cmds)
{
    for (int i = 0; i < num_cmds - 1; i++)
        pipe(pipes + i * 2);
}

static void close_pipes_child(int *pipes, int num_cmds)
{
    for (int j = 0; j < 2 * (num_cmds - 1); j++)
        close(pipes[j]);
}

static void close_pipes_parent(int *pipes, int num_cmds)
{
    for (int i = 0; i < 2 * (num_cmds - 1); i++)
        close(pipes[i]);
}

static void redirect_io(int *pipes, int i, int num_cmds)
{
    if (i > 0)
        dup2(pipes[(i - 1) * 2], STDIN_FILENO);
    if (i < num_cmds - 1)
        dup2(pipes[i * 2 + 1], STDOUT_FILENO);
}

void execute_single_command(char *command, char **env)
{
    char **tab = str_word_array(command);

    command_recode(tab, env);
    free_tab(tab);
    exit(EXIT_FAILURE);
}

void execute_piped_commands(char *input, char **env)
{
    char **commands = str_to_word_array(input, "|");
    int num_cmds = count_commands(commands);
    int pipes[2 * (num_cmds - 1)];
    pid_t pid;

    create_pipes(pipes, num_cmds);
    for (int i = 0; i < num_cmds; i++) {
        pid = fork();
        if (pid == 0) {
            redirect_io(pipes, i, num_cmds);
            close_pipes_child(pipes, num_cmds);
            execute_single_command(commands[i], env);
        }
    }
    close_pipes_parent(pipes, num_cmds);
    for (int i = 0; i < num_cmds; i++)
        wait(NULL);
    free_tab(commands);
}
