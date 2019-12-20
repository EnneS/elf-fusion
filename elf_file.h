#ifndef __ELF_DATA_H__
#define __ELF_DATA_H__

#include "util.h"
#include "elf.h"
#include "stdlib.h"

typedef struct{
    Elf32_Ehdr e_header;
    Elf32_Shdr* shdr_table;
    uint8_t** sections_data;

    uint8_t** progbits_sections;
    size_t progbits_nbr;

    char* str_table;
    size_t str_table_size;

    Elf32_Sym* symbol_table;

    Elf32_Rela** rela_tables;
    size_t rela_tables_size;

    Elf32_Rel**  rel_tables;
    size_t rel_tables_size;
}Elf32_data;


char* get_name(Elf32_data* elf, size_t section_index);
#endif
