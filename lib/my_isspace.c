/*
** EPITECH PROJECT, 2025
** my_isspace.c
** File description:
** return true if the character is space
*/

#include "../include/mini_shell.h"

bool my_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
        c == '\v' || c == '\f')
        return true;
    return false;
}
