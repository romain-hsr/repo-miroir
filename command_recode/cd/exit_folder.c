/*
** EPITECH PROJECT, 2025
** exit_folder.c
** File description:
** recode "cd .."
*/

#include "../../include/mini_shell.h"

void update_env_variables(char **env, char *pwd)
{
    int i = 0;
    int j = 0;
    char *buffer = NULL;

    while (my_strncmp(env[i], "PWD=", 4) != 0)
        i++;
    buffer = malloc(sizeof(char) * (8 + my_strlen(env[i]) + 5));
    if (buffer == NULL)
        return;
    while (my_strncmp(env[j], "OLDPWD=", 7) != 0)
        j++;
    free(env[j]);
    env[j] = my_strcat(my_strcpy(buffer, "OLDPWD="), env[i] + 4);
    free(env[i]);
    buffer = malloc(sizeof(char) * (my_strlen(pwd) + 5));
    env[i] = my_strcat(my_strcpy(buffer, "PWD="), pwd);
}

int exit_folder(char *path, char *home, char **env)
{
    char *pwd = recup_pwd(env);
    int len = my_strlen(pwd) - 1;

    if (pwd == NULL)
        return 0;
    while (pwd[len] != '/') {
        pwd[len] = '\0';
        len--;
    }
    pwd[len] = '\0';
    path = pwd;
    chdir(path);
    update_env_variables(env, pwd);
    free(path);
    free(home);
    return 1;
}
