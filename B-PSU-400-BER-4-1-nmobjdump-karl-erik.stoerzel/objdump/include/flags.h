/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** flags.h
*/

#ifndef B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FLAGS_H
#define B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FLAGS_H

#include <stdbool.h>

typedef struct
{
    bool f;
    bool s;
} flags_t;

typedef struct
{
    bool dynamics;
    bool paged;
    bool exec;
    bool reloc;
    bool sym;
} file_flags_s;

#endif //B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_FLAGS_H
