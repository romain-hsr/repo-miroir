/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** Will give the the difference of two pointer at the pos n
*/

#include "../include/mini_shell.h"

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    for (; n > 0; n--) {
        if (*str1 != *str2) {
            return (unsigned char)(*str1) - (unsigned char)(*str2);
        }
        if (*str1 == '\0' || *str2 == '\0') {
            break;
        }
        str1++;
        str2++;
    }
    return 0;
}
