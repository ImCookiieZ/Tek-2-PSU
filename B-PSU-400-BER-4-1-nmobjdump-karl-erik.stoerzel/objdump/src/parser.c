/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** parser.c
*/

#include "../include/parser.h"
#include "../include/help.h"

void write_invalid_option(char *flags)
{
    write_error("invalid option -- '");
    write_error(flags + 1);
    write_error("'\n");
    write_help();
}

int check_flag(char *flags, flags_t *flag_struct)
{
    size_t len = strlen(flags);
    if (len == 1)
    {
        write_error("invalid flag of length 1\n");
        return 84;
    }
    for (size_t i = 1; i < len; i++)
    {
        if (flags[i] == 's')
            flag_struct->s = true;
        else if (flags[i] == 'f')
            flag_struct->f = true;
        else
        {
            write_invalid_option(flags);
            return 84;
        }
    }
    return 0;
}

flags_t *flags(int ac, char **av)
{
    flags_t *ret = malloc(sizeof(flags_t));
    if (!ret)
    {
        write_error("flag struct malloc failed\n");
        return NULL;
    }
    ret->f = false;
    ret->s = false;
    for (int i = 1; i < ac; i++)
    {
        if (av[i][0] == '-')
        {
            if (check_flag(av[i], ret) == 84)
            {
                free(ret);
                return NULL;
            }
        }
    }
    return ret;
}

void free_array(char **ar)
{
    for (int i = 0; ar[i]; i++)
        free(ar[i]);
    free(ar);
}

char **files(int ac, char **av)
{
    int j = 0;
    char **ret = malloc(sizeof(char *) * ac);
    if (ret == NULL)
    {
        write_error("file array malloc failed\n");
        return NULL;
    }
    for (int i = 1; i < ac; i++)
    {
        if (av[i][0] != '-')
        {
            ret[j] = strdup(av[i]);
            if (ret[j] == NULL)
                return NULL;
            j++;
        }
    }
    ret[j] = NULL;
    return ret;
}
