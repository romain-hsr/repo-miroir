/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** put all word of char * in char **
*/

#include "../include/mini_shell.h"

static int is_alphanum(char c)
{
    int int_charact = c;

    if ((int_charact == 46))
        return 1;
    if ((int_charact >= 65) && (int_charact <= 90))
        return 1;
    if ((int_charact >= 97) && (int_charact <= 122))
        return 1;
    if ((int_charact >= 47) && (int_charact <= 57))
        return 1;
    if ((int_charact == 45))
        return 1;
    else
        return 0;
}

static int size_str(char *str, int i)
{
    int count = 0;

    while (is_alphanum(str[i]) == 1) {
        count++;
        i++;
    }
    return count;
}

static int count_word(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        while ((is_alphanum(str[i]) == 1) && (is_alphanum(str[i + 1]) == 1)) {
                i++;
        }
        if (is_alphanum(str[i]) == 1)
            count++;
        i++;
    }
    return count;
}

static char *creat_word(char *str, int *i)
{
    int j = 0;
    int size_word = size_str(str, *i);
    char *word = malloc(sizeof(char) * (size_word + 1));

    if (word == NULL)
        return NULL;
    while (str[*i] != '\0' && is_alphanum(str[*i]) == 1) {
            word[j] = str[*i];
            (*i)++;
            j++;
    }
    word[j] = '\0';
    return word;
}

char **str_word_array(char *str)
{
    int i = 0;
    int x = 0;
    int total_word = count_word(str);
    char *word;
    char **final_str;

    final_str = malloc(sizeof(char *) * (total_word + 1));
    while (str[i] != '\0') {
        if (is_alphanum(str[i]) == 1) {
            word = creat_word(str, &i);
            final_str[x] = word;
            x++;
        } else
            i++;
    }
    final_str[x] = NULL;
    return final_str;
}

char **str_to_word_array(char *str, char *delimiter)
{
    int i = 0;
    char **array = malloc(sizeof(char *) * 1024);
    char *token = strtok(str, delimiter);

    while (token != NULL) {
        array[i] = my_strdup(token);
        token = strtok(NULL, delimiter);
        i++;
    }
    array[i] = NULL;
    return array;
}
