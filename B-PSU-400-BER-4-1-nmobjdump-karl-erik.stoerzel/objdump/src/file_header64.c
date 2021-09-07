/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** file_header64.c
*/

#include "../include/file_header64.h"
#include "../../flags.h"
#include "../include/flags.h"
#include <stdio.h>
#include <string.h>

unsigned int get_type_flags64(const elf64_s *elf, file_flags_s *flags,
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

unsigned long get_flags64(elf64_s *elf, file_flags_s *flags)
{
    unsigned int flagvalue = 0;
    flagvalue = get_type_flags64(elf, flags, flagvalue);
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

bool print_file_related(bool printed, file_flags_s flags)
{
    if (flags.exec)
    {
        printf("EXEC_P");
        printed = true;
    }
    if (flags.dynamics)
    {
        printf("%sDYNAMIC", printed ? ", " : "");
        printed = true;
    }
    if (flags.reloc)
    {
        printf("%sHAS_RELOC", printed ? ", " : "");
        printed = true;
    }
    return printed;
}

void print_flags(file_flags_s flags, unsigned long flagsvalue)
{
    bool printed = false;
    if (flagsvalue == 0)
        printf("BFD_NO_FLAGS");
    printed = print_file_related(printed, flags);
    if (flags.sym)
    {
        printf("%sHAS_SYMS", printed ? ", " : "");
        printed = true;
    }
    if (flags.paged)
    {
        printf("%sD_PAGED", printed ? ", " : "");
        printed = true;
    }
    printf("\n");
}

void f_flag64(elf64_s *elf, char *path)
{
    Elf64_Addr start = (Elf64_Addr) NULL;
    printf("\n%s:     file format elf64-x86-64\n", path);
    file_flags_s flags = {false, false, false, false, false};
    unsigned long flagsvalue = get_flags64(elf, &flags);
    printf("architecture: i386%s, flags 0x%08lx:\n", elf->ehdr->e_machine ==
    EM_386 ? "" : ":x86-64", flagsvalue);
    print_flags(flags, flagsvalue);
    for (int i = 0; i < elf->ehdr->e_shnum; i++)
    {
        if (strcmp(".text", elf->strtab + elf->shdr[i].sh_name) == 0)
            start = elf->shdr[i].sh_addr;
    }
    printf("start address 0x%016lx\n\n", start ? start : 0);
}