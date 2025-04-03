/*
** EPITECH PROJECT, 2025
** cd.c
** File description:
** recode cd
*/

#include "../../include/mini_shell.h"

void modif_env(char *path, char **env)
{
    int i = 0;
    int j = 0;
    char *buffer = NULL;
    char *new_path = NULL;

    while (my_strncmp(env[i], "PWD=", 4) != 0)
        i++;
    buffer = malloc(sizeof(char) * (8 + my_strlen(env[i]) + 5));
    while (my_strncmp(env[j], "OLDPWD=", 7) != 0)
        j++;
    free(env[j]);
    env[j] = my_strcat(my_strcpy(buffer, "OLDPWD="), env[i] + 4);
    new_path = malloc(sizeof(char) *
        (5 + my_strlen(env[i]) + 1 + my_strlen(path) + 1));
    my_strcpy(new_path, "PWD=");
    my_strcat(new_path, env[i] + 4);
    my_strcat(new_path, "/");
    my_strcat(new_path, path);
    free(env[i]);
    env[i] = new_path;
}

int not_found(char *path, char *home)
{
    mini_printf("%s: No such file or directory.\n", path);
    free(home);
    free(path);
    return 1;
}

int my_cd(char **tab, char **env)
{
    int size_tab = len_tab(tab);
    char *home = recup_home(env);
    char *path = (size_tab > 1) ? tab[1] : NULL;
    int success = 0;

    if (size_tab == 1) {
        success = go_home(home, env);
    }
    if (success == 0 && my_strcmp(path, "..") == 0) {
        success = exit_folder(path, home, env);
    }
    if (success == 0 && chdir(path) == 0) {
        modif_env(path, env);
        free(home);
        success = 1;
    }
    if (success == 0)
        not_found(path, home);
    return 0;
}
