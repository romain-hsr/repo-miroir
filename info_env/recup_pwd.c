/*
** EPITECH PROJECT, 2025
** recup_pwd.c
** File description:
** recup the path PWD
*/

#include "../include/mini_shell.h"

char *recup_pwd(char **env)
{
    char *buffer = NULL;
    size_t size = 256;

    buffer = malloc(sizeof(char) * size);
    if (buffer == NULL)
        return NULL;
    if (getcwd(buffer, size) == NULL) {
        free(buffer);
        return NULL;
    }
    return buffer;
}
