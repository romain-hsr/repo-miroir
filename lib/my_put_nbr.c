/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** Display int
*/

#include "../include/mini_shell.h"

void my_put_nbr(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if ((nb >= 0) && (nb < 10)) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}
