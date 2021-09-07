/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel
** File description:
** realloc.c
*/

#include "../include/malloc_structs.h"
#include <string.h>
extern node_t *alloc_start;

void *realloc(void *ptr, size_t size)
{
    if (size == 0 && ptr != NULL)
    {
        free(ptr);
        return NULL;
    }
    void *new = malloc(size);
    node_t *old = find_node(ptr);
    if (new == NULL)
        return NULL;
    if (old == NULL)
        return new;
    memcpy(new, ptr, old->size < size ? old->size : size);
    free(ptr);
    return new;
}