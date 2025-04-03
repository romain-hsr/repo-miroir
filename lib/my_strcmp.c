/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Will give the the difference of two pointer
*/

#include "../include/mini_shell.h"

int my_strcmp(char const *s1, char const *s2)
{
    int nb = 0;
    int lim = 0;

    if (s1 == NULL || s2 == NULL)
        return 84;
    if (my_strlen(s1) < my_strlen(s2))
        lim = my_strlen(s1);
    if (my_strlen(s1) > my_strlen(s2))
        lim = my_strlen(s2);
    for (int i = 0; i <= lim; i++) {
        if (s1[i] == s2[i])
            nb += 0;
        if (s1[i] < s2[i])
            nb += (s1[i] - s2[i]);
        if (s1[i] > s2[i])
            nb += (s1[i] - s2[i]);
    }
    return nb;
}
