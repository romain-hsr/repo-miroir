/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** Will concatenaite the str and dest
*/

#include "../include/mini_shell.h"

char *my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}
