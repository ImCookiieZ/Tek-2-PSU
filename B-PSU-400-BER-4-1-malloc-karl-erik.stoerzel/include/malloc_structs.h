/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel
** File description:
** malloc_structs.h
*/

#ifndef B_PSU_400_BER_4_1_MALLOC_KARL_ERIK_STOERZEL_MALLOC_STRUCTS_H
#define B_PSU_400_BER_4_1_MALLOC_KARL_ERIK_STOERZEL_MALLOC_STRUCTS_H

#include <unistd.h>
#define true 1
#define false 0
#define error 84
#define success 0

typedef struct allocated_list_node
{
    struct allocated_list_node *next;
    struct allocated_list_node *prev;
    unsigned long size;
    void *pointer;
    short isUsed;
} node_t;

//malloc
void *malloc(size_t size);
node_t *find_space(size_t size);
void *allocate_address(size_t size);

//free
void free_node(node_t *node);
void free(void *pointer);

//realloc
void *realloc(void *ptr, size_t size);

//calloc
void *calloc(size_t array_number, size_t memory_size);

//reallocarray
node_t *find_node(void *ptr);
void *reallocarray(void *ptr, size_t number, size_t size);

//bestfitalgo.c
node_t *find_best_fit(size_t size);
#endif //B_PSU_400_BER_4_1_MALLOC_KARL_ERIK_STOERZEL_MALLOC_STRUCTS_H
