/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel
** File description:
** bestfitalgo.c
*/

#include "../include/malloc_structs.h"

extern node_t *alloc_start;

node_t *find_best_fit(size_t size)
{
    node_t *itt = alloc_start;
    node_t *best_fitt_size = NULL;
    for (; itt; itt = itt->next)
    {
        if (itt->isUsed == false && itt->size >= size)
        {
            if (itt->size == size)
                return itt;
            if (!best_fitt_size || best_fitt_size->size < itt->size)
                best_fitt_size = itt;
        }
    }
    return best_fitt_size;
}