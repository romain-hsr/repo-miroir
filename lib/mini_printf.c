/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** display
*/

#include "../include/mini_shell.h"

void is_pourcent(const char *format, int *i, va_list list)
{
    if (format[*i + 1] == 'c'){
        my_putchar(va_arg(list, int));
        (*i)++;
    }
    if (format[*i + 1] == 's'){
        my_putstr(va_arg(list, char *));
        (*i)++;
    }
    if (format[*i + 1] == 'i' || format[*i + 1] == 'd'){
        my_put_nbr(va_arg(list, int));
        (*i)++;
    }
    if (format[*i] == '%' && format[*i + 1] == '%'){
        my_putchar('%');
        (*i)++;
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%')
            is_pourcent(format, &i, list);
        else
            my_putchar(format[i]);
    }
    va_end(list);
    return 0;
}
