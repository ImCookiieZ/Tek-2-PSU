/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** sort.c
*/

#include "../include/sort.h"
#include <ctype.h>

void swap(symbol_t *a, symbol_t *b)
{
    symbol_t tmp = *a;
    *a = *b;
    *b = tmp;
}

int check_inloop(symbol_t a, symbol_t b, int *i, int *j)
{
    if (!isalnum(a.name[*i]))
    {
        ++*i;
        return -1;
    }
    if (!isalnum(b.name[*j]))
    {
        ++*j;
        return -1;
    }
    if (tolower(a.name[*i]) > tolower(b.name[*j]))
        return 1;
    else if (tolower(a.name[*i]) < tolower(b.name[*j]))
        return 0;
    ++*i;
    ++*j;
    return -2;
}

int check_bigger(symbol_t a, symbol_t b)
{
    int i = 0;
    int j = 0;
    while (a.name[i] && b.name[j])
    {
        switch (check_inloop(a, b, &i, &j))
        {
            case 1: return 1;
            case 0: return 0;
            default: break;
        }
    }
    if (!a.name[i] && !b.name[j])
    {
        if (a.value > b.value)
            return 1;
        return 0;
    }
    else if (a.name[i])
        return 1;
    return 0;
}

symbol_t *sort(symbol_t *ar, size_t size)
{
    size_t i = 0;
    size_t j = 0;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (check_bigger(ar[j], ar[j + 1]))
                swap(&ar[j], &ar[j + 1]);
        }
    }
    return ar;
}
