/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel
** File description:
** calloc.c
*/

#include "../include/malloc_structs.h"
#include <string.h>

void *calloc(size_t array_number, size_t memory_size)
{
    void *ret = malloc(memory_size * array_number);
    if (!ret)
        return NULL;
    memset(ret, 0, memory_size * array_number);
    return ret;
}