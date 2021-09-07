/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** help.h
*/

#ifndef B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_HELP_H
#define B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_HELP_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define ERROR 84
#define SUCCESS 0

#define MH_MAGIC 0xfeedface
#define MH_MAGIC_64 0xfeedfacf
#define MH_CIGAM NXSwapInt(MH_MAGIC)
#define MH_CIGAM_64 NXSwapInt(MH_MAGIC_64)

void write_error(char *str);
void write_help();

#endif //B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_HELP_H
