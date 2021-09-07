cmake_minimum_required(VERSION 3.16)
project(B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel C)

set(CMAKE_C_STANDARD 99)

add_executable(B_PSU_400_BER_4_1_nmobjdump_karl_erik_stoerzel nm/src/main.c nm/src/parser.c
        nm/include/flags.h nm/include/parser.h nm/src/help.c nm/include/help.h nm/src/file_parse.c
        nm/include/file_parse.h nm/src/sort.c nm/include/sort.h nm/src/get_type.c
        nm/include/get_type.h
        objdump/src/parser.c objdump/include/parser.h
        objdump/src/main.c objdump/src/help.c objdump/src objdump/include/help.h
        objdump/include/flags.h objdump/src/parse_file32.c
        objdump/src/parse_file64.c
        objdump/include/parse_file.h objdump/src/file_header64.c objdump/include/file_header64.h nm/src/error_handling.c nm/include/error_handling.h objdump/src/file_sections64.c objdump/include/file_sections64.h tmp/flag.h)