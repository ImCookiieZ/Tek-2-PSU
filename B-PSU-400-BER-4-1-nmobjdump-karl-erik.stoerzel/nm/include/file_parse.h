/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** file_parse.h
*/

#ifndef B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FILE_PARSE_H
#define B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FILE_PARSE_H

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <elf.h>
#include "../include/help.h"
#include "flags.h"

typedef struct {
    size_t value;
    char type;
    char *name;
}symbol_t;

typedef struct
{
    size_t len;
    size_t nb_sections;
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    Elf64_Sym *sym;
    char *strtab;
}elf_s;

int parse_file(char *path, bool more_than_one);
elf_s *create_elf_from_filedata(const char *path);

#endif //B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FILE_PARSE_H
