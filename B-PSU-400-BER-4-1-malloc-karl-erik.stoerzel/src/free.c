/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel
** File description:
** free.c
*/

#include <stdio.h>
#include <string.h>
#include "../include/malloc_structs.h"
extern node_t *alloc_start;

void free_page_size(const node_t *node)
{
    int page_size = getpagesize() * 2;
    long tmp = page_size;
    while ((long) (node->size + sizeof(node_t)) > tmp)
        tmp += page_size;
    sbrk(tmp * -1);
}

void free_node(node_t *node)
{
    int last = false;
    node_t *prev_tmp = NULL;
    node->isUsed = false;
    memset(node->pointer, 0, node->size);
    if (!node->next)
    {
        if (node->prev)
            node->prev->next = NULL;
        else
            last = true;
        if (node->prev && node->prev->isUsed == false)
            prev_tmp = node->prev;
        free_page_size(node);
        if (prev_tmp)
            free_node(prev_tmp);
    }
    if (last)
        alloc_start = NULL;
}

void free(void *pointer)
{
    if (pointer == NULL)
        return;
    for (node_t *node = alloc_start; node; node = node->next)
    {
        if (node->pointer == pointer && node->isUsed == true)
        {
            free_node(node);
            break;
        }
    }
}