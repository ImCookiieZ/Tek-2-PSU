/*
** EPITECH PROJECT, 2021
** B_PSU_400_BER_4_1_my_nmobjdump_karl_erik_stoerzel
** File description:
** error_handling.c
*/

#include "../include/error_handling.h"

void check_elf(int fd, const char *path)
{
    char buf[5];
    read(fd, buf, 4);
    buf [4] = 0;
    if (strcmp(buf, "\177ELF") == 0)
        return;
    fprintf(stderr, "my_nm: %s: file format not recognized\n", path);
    exit(84);
}

struct stat get_stat_buffer(int fd, const char *path)
{
    struct stat buf;
    if (fd < 0)
    {
        fprintf(stderr, "my_nm: '%s': No such file\n", path);
        exit(84);
    }
    if (fstat(fd, &buf) < 0)
    {
        close(fd);
        exit(84);
    }
    return buf;
}

void check_truncated_file(int fd, const char *path, elf_s *elf, struct stat buf)
{
    if (elf->len < sizeof(Elf64_Ehdr))
    {
        fprintf(stderr, "my_nm: %s: file truncated\n", path);
        close(fd);
        exit(84);
    }
    if ((elf->ehdr = (Elf64_Ehdr *) mmap(NULL, buf.st_size, PROT_READ,
        MAP_SHARED, fd, 0)) == (Elf64_Ehdr *)-1)
    {
        fprintf(stderr, "my_nm: %s: file truncated\n", path);
        close(fd);
        exit(84);
    }
}

void check_file_format(elf_s *elf, int fd, const char *path)
{
    if ((elf->ehdr->e_type != ET_EXEC && elf->ehdr->e_type != ET_REL &&
    elf->ehdr->e_type != ET_DYN))
    {
        fprintf(stderr, "my_nm: %s: file format not recognized\n", path);
        close(fd);
        exit(84);
    }
}