/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** main.c
*/

#include "../include/file_parse.h"
#include "../include/parser.h"
#include <stdio.h>

int run(int ret, char *const *file_names)
{
    for (int i = 0; file_names[i]; i++)
    {
        if (ret == 0)
            ret = parse_file(file_names[i], true);
        else
            parse_file(file_names[i], true);
    }
    return ret;
}

int main(int ac, char **av)
{
    int ret = 0;
    flags_t *flag_struct = flags(ac, av);
    char **file_names = files(ac, av);
    if (!flag_struct || !file_names)
        return 84;
    if (!file_names[0])
        parse_file("a.out", false);
    else if (file_names[0] && !file_names[1])
        parse_file(file_names[0], false);
    else
        ret = run(ret, file_names);
    free(flag_struct);
    for (int i = 0; file_names[i]; i++)
        free(file_names[i]);
    free(file_names);
    return ret;
}