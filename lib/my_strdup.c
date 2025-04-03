/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** Will give a new pointer with the good allocate mem
*/

#include "../include/mini_shell.h"

char *my_strdup(const char *s)
{
    size_t len;
    char *dup;

    if (s == NULL)
        return NULL;
    len = my_strlen(s) + 1;
    dup = malloc(len);
    if (dup == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++)
        dup[i] = s[i];
    return dup;
}
