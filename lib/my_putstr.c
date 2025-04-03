/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** Display char *
*/

#include "../include/mini_shell.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
