/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** get_type.c
*/

#include "../include/get_type.h"

char check_shdr(elf_s *elf, size_t nb)
{
    if (elf->shdr[elf->sym[nb].st_shndx].sh_type == SHT_NOBITS &&
    elf->shdr[elf->sym[nb].st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return 'B';
    if (elf->shdr[elf->sym[nb].st_shndx].sh_type == SHT_PROGBITS &&
    (elf->shdr[elf->sym[nb].st_shndx].sh_flags == SHF_ALLOC ||
    elf->shdr[elf->sym[nb].st_shndx].sh_flags == (SHF_MERGE | SHF_ALLOC)))
        return 'R';

    if ((elf->shdr[elf->sym[nb].st_shndx].sh_type == SHT_PROGBITS &&
    elf->shdr[elf->sym[nb].st_shndx].sh_flags ==
    (SHF_ALLOC | SHF_WRITE)) ||
    elf->shdr[elf->sym[nb].st_shndx].sh_type == SHT_DYNAMIC)
        return 'D';
    if ((elf->shdr[elf->sym[nb].st_shndx].sh_type == SHT_PROGBITS &&
    elf->shdr[elf->sym[nb].st_shndx].sh_flags ==
    (SHF_ALLOC | SHF_EXECINSTR)) ||
    elf->shdr[elf->sym[nb].st_shndx].sh_type == SHT_INIT_ARRAY ||
    elf->shdr[elf->sym[nb].st_shndx].sh_type == SHT_FINI_ARRAY)
        return 'T';
    return '#';
}

char get_type(elf_s *elf, size_t nb)
{

    if (ELF64_ST_BIND(elf->sym[nb].st_info) == STB_WEAK)
    {
        if (ELF64_ST_TYPE(elf->sym[nb].st_info) == STT_OBJECT)
            return 'V';
        return 'W';
    }

    if (elf->sym[nb].st_shndx == SHN_UNDEF)
        return 'U';
    if (elf->sym[nb].st_shndx == SHN_COMMON)
        return 'C';
    if (elf->sym[nb].st_shndx == SHN_ABS)
        return 'A';

    return check_shdr(elf, nb);
}