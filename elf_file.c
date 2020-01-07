#include "elf_file.h"

char* get_name(Elf32_data* elf, size_t section_index){
    return &elf->str_table[elf->shdr_table[section_index].sh_name];
}