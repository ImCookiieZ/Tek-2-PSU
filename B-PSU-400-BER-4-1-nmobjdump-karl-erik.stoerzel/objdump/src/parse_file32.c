/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** parse_file.c
*/

#include "../include/parse_file.h"
#include "../include/file_header32.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

elf32_s *create_elf_from_filedata32(const char *path)
{
    struct stat buf;
    elf32_s *elf = malloc(sizeof(elf32_s));
    if (elf == NULL)
        return NULL;
    int fd = open(path, O_RDONLY);
    if (fd < 0)
        return NULL;
    fstat(fd, &buf);
    elf->len = buf.st_size;
    elf->ehdr = (Elf32_Ehdr *)mmap(NULL, buf.st_size, PROT_READ,
        MAP_SHARED, fd, 0);
    elf->shdr = (Elf32_Shdr *)((void *)elf->ehdr + elf->ehdr->e_shoff);
    elf->strtab = (char *)((void *)elf->ehdr +
        elf->shdr[elf->ehdr->e_shstrndx].sh_offset);
    close(fd);
    return elf;
}

char *get_sym_table_plus_main_infos32(elf32_s *elf, size_t i)
{
    char *name_searched = NULL;
    char *tmp = elf->strtab + elf->shdr[i].sh_name;
    if (strcmp(tmp, ".symtab") == 0)
    {
        elf->sym = (Elf32_Sym *)((char *)elf->ehdr +
            (elf->shdr + i)->sh_offset);
        elf->nb_sections = (elf->shdr + i)->sh_size / sizeof(Elf32_Sym);
    }
    else if (strcmp(tmp, ".strtab") == 0)
    {
        name_searched = ((char *)elf->ehdr + (elf->shdr + i)->sh_offset);
    }
    return name_searched;
}

int parse_file32(char *path)
{
    elf32_s *elf = create_elf_from_filedata32(path);
    if (!elf)
    {
        printf("my_objdump: '%s': No such file\n", path);
        return 84;
    }
    for (size_t i = 0; i < elf->ehdr->e_shnum; i++)
    {
        get_sym_table_plus_main_infos32(elf, i);
    }
    f_flag32(elf, path);
    free(elf);
    return 0;
}