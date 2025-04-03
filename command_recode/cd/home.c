/*
** EPITECH PROJECT, 2025
** home.c
** File description:
** change directory to home
*/

#include "../../include/mini_shell.h"

int go_home(char *home, char **env)
{
    int i = 0;
    int j = 0;
    char *buffer = NULL;

    chdir(home);
    while (my_strncmp(env[i], "PWD=", 4) != 0)
        i++;
    buffer = malloc(sizeof(char) * (8 + my_strlen(env[i]) + 5));
    while (my_strncmp(env[j], "OLDPWD=", 7) != 0)
        j++;
    free(env[j]);
    env[j] = my_strcat(my_strcpy(buffer, "OLDPWD="), env[i] + 4);
    free(env[i]);
    env[i] = my_strdup("PWD=/home/hanser-romain");
    free(home);
    return 1;
}
