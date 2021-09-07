/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** help.c
*/

#include "../include/help.h"
#include <stdlib.h>

void check_elf(int fd, const char *path)
{
    char buf[5];
    read(fd, buf, 4);
    buf [4] = 0;
    if (strcmp(buf, "\177ELF") == 0)
        return;
    fprintf(stderr, "my_nm: %s: file format not recognized\n", path);
    exit(84);
}

void write_error(char *str)
{
    size_t i = strlen(str);
    write(2, str, i);
}

void write_help(void)
{
    FILE *fp = fopen("objdump/help.txt", "r");
    if (fp == NULL)
        return;
    char c = 0;
    while ((c = fgetc(fp)) != -1)
        printf("%c", c);
}
