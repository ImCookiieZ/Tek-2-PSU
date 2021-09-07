/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** file_header.h
*/

#ifndef B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FILE_HEADER64_H
#define B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FILE_HEADER64_H

#include "parse_file.h"
#include "flags.h"

void f_flag64(elf64_s *elf, char *path);
void print_flags(file_flags_s flags, unsigned long flagsvalue);
bool print_file_related(bool printed, file_flags_s flags);

#endif //B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FILE_HEADER64_H
