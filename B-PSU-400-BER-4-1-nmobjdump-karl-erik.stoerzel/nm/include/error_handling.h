/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** error_handling.h
*/

#ifndef B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_ERROR_HANDLING_H
#define B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_ERROR_HANDLING_H


#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "file_parse.h"

struct stat get_stat_buffer(int fd, const char *path);
void check_truncated_file(int fd, const char *path, elf_s *elf, struct stat
    buf);
void check_file_format(elf_s *elf, int fd, const char *path);
void check_elf(int fd, const char *path);

#endif //B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_ERROR_HANDLING_H
