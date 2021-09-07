/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel
** File description:
** parser.h
*/

#ifndef B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_PARSER_H
#define B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_PARSER_H


#include <stdlib.h>
#include <string.h>
#include "../include/flags.h"

int check_flag(char *flags, flags_t *flag_struct);
flags_t *flags(int ac, char **av);
void free_array(char **ar);
char **files(int ac, char **av);

#endif //B_PSU_400_BER_4_1_NMOBJDUMP_KARL_ERIK_STOERZEL_PARSER_H
