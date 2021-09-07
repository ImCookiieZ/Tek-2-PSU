cmake_minimum_required(VERSION 3.16)
project(B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel C)

set(CMAKE_C_STANDARD 99)

add_executable(B_PSU_400_BER_4_1_malloc_karl_erik_stoerzel main.c
        include/malloc_structs.h src/malloc.c src/free.c src/realloc.c
        src/calloc.c src/reallocarray.c src/bestfitalgo.c)