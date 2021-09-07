/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** file_parse.c
*/

#include <stdlib.h>
#include <ctype.h>
#include "../include/file_parse.h"
#include "../include/sort.h"
#include "../include/get_type.h"
#include "../include/error_handling.h"

elf_s *create_elf_from_filedata(const char *path)
{
    elf_s *elf = malloc(sizeof(elf_s));
    if (elf == NULL)
        exit(ERROR);
    int fd = open(path, O_RDONLY);
    struct stat buf = get_stat_buffer(fd, path);
    check_elf(fd, path);
    if (!S_ISREG(buf.st_mode))
    {
        fprintf(stderr, "my_nm: Warning: '%s' is not an ordinary file\n", path);
        close(fd);
        exit(84);
    }
    elf->len = buf.st_size;
    check_truncated_file(fd, path, elf, buf);
    check_file_format(elf, fd, path);
    elf->shdr = (Elf64_Shdr *)((void *)elf->ehdr + elf->ehdr->e_shoff);
    elf->strtab = (char *)((void *)elf->ehdr +
        elf->shdr[elf->ehdr->e_shstrndx].sh_offset);
    close(fd);
    return elf;
}

char *get_sym_table_plus_main_infos(elf_s *elf, size_t i)
{
    char *name_searched = NULL;
    char *tmp = elf->strtab + elf->shdr[i].sh_name;
    if (strcmp(tmp, ".symtab") == 0)
    {
        elf->sym = (Elf64_Sym *)((char *)elf->ehdr +
            (elf->shdr + i)->sh_offset);
        elf->nb_sections = (elf->shdr + i)->sh_size / sizeof(Elf64_Sym);
    }
    else if (strcmp(tmp, ".strtab") == 0)
    {
        name_searched = ((char *)elf->ehdr + (elf->shdr + i)->sh_offset);
    }
    return name_searched;
}

symbol_t *create_symbols(elf_s *elf, char *start_of_names)
{
    symbol_t *symbols = malloc(sizeof(symbol_t) * (elf->nb_sections + 1));
    size_t j = 0;
    for (size_t i = 0; i < elf->nb_sections; i++)
    {
        if ((start_of_names + elf->sym[i].st_name)[0])
        {
            symbols[j].value = elf->sym[i].st_value;
            symbols[j].name = start_of_names + elf->sym[i].st_name;
            symbols[j].type = get_type(elf, i);
            if (ELF64_ST_BIND(elf->sym[i].st_info) == STB_LOCAL ||
            ((symbols[j].type == 'W' ||
            symbols[j].type == 'V') && elf->sym[i].st_shndx == SHN_UNDEF))
                symbols[j].type = tolower(symbols[j].type);
            j++;
        }
    }
    elf->nb_sections = j;
    return symbols;
}

void print_symbols(const elf_s *elf, const symbol_t *symbols)
{
    for (size_t k = 0; k < elf->nb_sections; k++)
    {
        if (symbols[k].value || symbols[k].type == 't' || symbols[k].type == 'n'
        || symbols[k]
        .type == 'T')
            printf("%016zx %c %s\n", symbols[k].value, symbols[k].type,
                symbols[k].name);
        else if (symbols[k].type == 'U' || symbols[k].type == 'w')
            printf("\t\t %c %s\n", symbols[k].type, symbols[k].name);
    }
}

int parse_file(char *path, bool more_than_one)
{
    elf_s *elf = create_elf_from_filedata(path);
    char *start_of_names;
    char *tmp = NULL;
    if (more_than_one)
        printf("\n%s:\n", path);
    for (size_t i = 0; i < elf->ehdr->e_shnum; i++)
    {
        tmp = get_sym_table_plus_main_infos(elf, i);
        if (tmp) start_of_names = tmp;
    }
    if (!start_of_names)
    {
        fprintf(stderr, "my_nm: %s: no symbols\n", path);
        exit(0);
    }
    symbol_t *symbols = create_symbols(elf, start_of_names);
    sort(symbols, elf->nb_sections);
    print_symbols(elf, symbols);
    free(symbols);
    free(elf);
    return 0;
}