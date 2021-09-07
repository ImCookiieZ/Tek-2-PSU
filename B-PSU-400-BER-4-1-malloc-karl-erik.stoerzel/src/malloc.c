/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel
** File description:
** malloc.c
*/

#include <string.h>
#include <stdio.h>
#include "../include/malloc_structs.h"
node_t *alloc_start = NULL;

void *allocate_address(size_t size)
{
    node_t *node = NULL;
    int page_size = getpagesize() * 2;
    long tmp = page_size;
    while ((long) (size + sizeof(node_t)) > tmp)
        tmp += page_size;
    node = sbrk(tmp);
    if (node == (void *)-1)
        return NULL;
    node->size = size;
    node->next = NULL;
    node->prev = NULL;
    node->pointer = (void *)node + sizeof(node_t);
    node->isUsed = true;
    return node;
}

node_t *find_space(size_t size)
{
    node_t *node = find_best_fit(size);
    if (node)
        node->isUsed = true;
    else
    {
        for (node = alloc_start; node->next; node = node->next);
        node->next = allocate_address(size);
        node->next->prev = node;
        node = node->next;
    }
    return node;
}

void *malloc(size_t size)
{
    node_t *node = NULL;
    if (size == 0)
        return NULL;
    if (alloc_start == NULL)
    {
        node = allocate_address(size);
        alloc_start = node;
    }
    else
    {
        node = find_space(size);
    }
    if (node == NULL)
        return NULL;
    return node->pointer;
}