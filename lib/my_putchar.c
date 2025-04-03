/*
** EPITECH PROJECT, 2024
** mmy_putchar.c
** File description:
** Display one char
*/

#include "../include/mini_shell.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
