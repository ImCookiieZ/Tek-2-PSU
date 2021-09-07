/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel
** File description:
** realocarray.c
*/

#include "../include/malloc_structs.h"
#include <string.h>
extern node_t *alloc_start;

node_t *find_node(void *ptr)
{
    node_t *tmp = alloc_start;
    for (; tmp; tmp = tmp->next)
    {
        if (tmp->isUsed && tmp->pointer == ptr)
        {
            return tmp;
        }
    }
    return NULL;
}

void *reallocarray(void *ptr, size_t number, size_t size)
{
    return realloc(ptr, number * size);
}