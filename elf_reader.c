#include "elf_reader.h"

int read_elf_header(FILE* file, Elf32_Ehdr* header){
    if(fread(header, 56, 1, file) < 1){
        return -1;
    }

    return 0;
}