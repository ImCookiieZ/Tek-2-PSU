/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** help.c
*/

#include "../include/help.h"

void write_error(char *str)
{
    size_t i = strlen(str);
    write(2, str, i);
}

void write_help(void)
{
    FILE *fp = fopen("nm/help.txt", "r");
    if (fp == NULL)
        return;
    char c = 0;
    while ((c = fgetc(fp)) != -1)
        fprintf(stderr, "%c", c);
}
