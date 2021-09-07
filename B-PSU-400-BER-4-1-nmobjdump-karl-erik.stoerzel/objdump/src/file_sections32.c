/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** file_sections.c
*/

#include "../include/file_sections32.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check_skip(char *string)
{
    if (string == NULL || string[0] == 0)
        return true;
    if (!strcmp(string, ".bss"))
        return true;
    if (!strcmp(string, ".shstrtab") || !strcmp(string, ".symtab")
    || !strcmp(string, ".strtab"))
        return true;
    if (!strcmp(string, ".rela.text") || !strcmp(string, ".rela.debug_info")
    || !strcmp(string, ".rela.debug_aranges")
    || !strcmp(string, ".rela.debug_line") || !strcmp(string, ".rela.eh_frame"))
        return true;
    if (!strcmp(string, ".tbss"))
        return true;
    if (!strcmp(string, "__libc_freeres_ptrs"))
        return true;
    return false;
}

void print_char_part32(elf32_s *elf, size_t idx, size_t shdr_nb)
{
    char tmp;
    size_t i;
    for (i = idx; i < elf->shdr[shdr_nb].sh_size && i < idx + 16; i++)
    {
        tmp = ((char *)elf->ehdr + elf->shdr[shdr_nb].sh_offset)[i];
        if (tmp > 31 && tmp < 127)
            printf("%c", tmp);
        else
            printf(".");
    }
    for (; i < idx + 16; i++)
        printf(" ");
}

void print_hex_part32(elf32_s *elf, size_t idx, size_t shdr_nb)
{
    unsigned char tmp;
    for (size_t i = idx; i < elf->shdr[shdr_nb].sh_size && i < idx + 16; i++)
    {
        tmp = ((char *)elf->ehdr + elf->shdr[shdr_nb].sh_offset)[i];
        if (i % 4 == 0 && i % 16 != 0)
            printf(" ");
        printf("%02x", tmp);
    }
}

void print_indentation32(elf32_s *elf, size_t idx, size_t shdr_nb)
{
    size_t i = idx;
    while (i < elf->shdr[shdr_nb].sh_size && i < idx + 16)
        i++;
    for (size_t k = 0; k < (idx + 16 - i) * 2 + (idx + 16 - i) / 4; k++)
    {
        printf(" ");
    }
}

void s_flag32(elf32_s *elf)
{
    for (size_t i = 0; i < elf->ehdr->e_shnum; i++)
    {
        if (check_skip(elf->strtab + elf->shdr[i].sh_name))
            continue;
        printf("Contents of section %s:\n", elf->strtab + elf->shdr[i].sh_name);
        for (size_t idx = 0; idx < elf->shdr[i].sh_size; idx += 16)
        {
            printf(" %04lx ", elf->shdr[i].sh_addr + idx);
            print_hex_part32(elf, idx, i);
            print_indentation32(elf, idx, i);
            printf("  ");
            print_char_part32(elf, idx, i);
            printf("\n");
        }
    }
}