/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** main.c
*/

#include "../include/parser.h"
#include "../include/help.h"
#include "../include/parse_file.h"
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>

int decide_file_format(char *const *file_names, int i, int fd)
{
    int ret = 0;
    struct stat buf;
    fstat(fd, &buf);
    Elf64_Ehdr *tmp = (Elf64_Ehdr *)mmap(NULL, buf.st_size, PROT_READ,
        MAP_SHARED, fd, 0);
    if (tmp->e_ident[EI_CLASS] == ELFCLASS32)
        parse_file32(file_names[i]);
    else if (tmp->e_ident[EI_CLASS] == ELFCLASS64)
        parse_file64(file_names[i]);
    else
    {
        ret = 84;
        printf("objdump: %s: file format not recognized\n",
            file_names[i]);
    }
    return ret;
}

int run_objdump(char *const *file_names, int i)
{
    int ret;
    int fd = open(file_names[i], O_RDONLY);
    if (fd < 0)
    {
        ret = 84;
        printf("objdump: '%s': No such file\n", file_names[i]);
    }
    else
    {
        check_elf(fd, file_names[i]);
        ret = decide_file_format(file_names, i, fd);
    }
    free(file_names[i]);
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
    {
        free(file_names);
        file_names = malloc(sizeof(char *) * 2);
        file_names[0] = strdup("a.out");
        file_names[1] = NULL;
    }
    for (int i = 0; file_names[i]; i++)
    {
        ret = run_objdump(file_names, i);
    }
    free(file_names);
    free(flag_struct);
    return ret;
}