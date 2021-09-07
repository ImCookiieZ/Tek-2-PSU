/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** file_header32.c
*/

#include "../include/file_header32.h"
#include "../include/file_header64.h"
#include "../../flags.h"
#include <stdio.h>
#include <string.h>

unsigned int get_type_flags32(const elf32_s *elf, file_flags_s *flags,
    unsigned int flagvalue)
{
    if (elf->ehdr->e_type == ET_EXEC)
    {
        flagvalue += EXEC_P + D_PAGED;
        flags->exec = true;
        flags->paged = true;
    }
    else if (elf->ehdr->e_type == ET_DYN)
    {
        flagvalue += DYNAMIC + D_PAGED;
        flags->dynamics = true;
        flags->paged = true;
    }
    else if (elf->ehdr->e_type == ET_REL)
    {
        flagvalue += HAS_RELOC;
        flags->reloc = true;
    }
    return flagvalue;
}

unsigned long get_flags32(elf32_s *elf, file_flags_s *flags)
{
    unsigned int flagvalue = 0;
    flagvalue = get_type_flags32(elf, flags, flagvalue);
    for (int i = 0; i < elf->ehdr->e_shnum; i++)
    {
        if (elf->shdr[i].sh_type == SHT_SYMTAB)
        {
            flagvalue += HAS_SYMS;
            flags->sym = true;
            break;
        }
    }
    return flagvalue;
}

void f_flag32(elf32_s *elf, char *path)
{
    Elf32_Addr start = 0;
    printf("\n%s:     file format elf32-i386\n", path);
    file_flags_s flags = {false, false, false, false, false};
    unsigned long flagsvalue = get_flags32(elf, &flags);
    printf("architecture: i386%s, flags 0x%08lx:\n", elf->ehdr->e_machine ==
    EM_386 ? "" : ":x86-32", flagsvalue);
    print_flags(flags, flagsvalue);
    for (int i = 0; i < elf->ehdr->e_shnum; i++)
    {
        if (strcmp(".text", elf->strtab + elf->shdr[i].sh_name) == 0)
            start = elf->shdr[i].sh_addr;
    }
    printf("start address 0x%016x\n\n", start ? start : 0);
}