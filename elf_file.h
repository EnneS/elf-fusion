#ifndef __ELF_DATA_H__
#define __ELF_DATA_H__

#include "util.h"
#include "elf.h"
#include "stdlib.h"
#include "string.h"
#include "hashtable.h"

typedef struct{
    Elf32_Rela* rela_table;
    size_t rela_table_size;
    Elf32_Word rela_table_name;
    Elf32_Off rela_table_offset;
}Elf32_RelaTable;

typedef struct{
    Elf32_Rel* rel_table;
    size_t rel_table_size;
    Elf32_Word rel_table_name;
    Elf32_Off rel_table_offset;
}Elf32_RelTable;

typedef struct{
    Elf32_Ehdr e_header;
    Elf32_Shdr* shdr_table;
    uint8_t** sections_data;

    uint8_t** progbits_sections;
    size_t progbits_nbr;

    char* str_table;
    size_t str_table_size;

    Elf32_Sym* symbol_table;
    size_t symbol_table_size;

    char* sm_str_table;
    size_t sm_str_table_size;

    Elf32_RelaTable* rela_tables;
    size_t rela_tables_size;

    Elf32_RelTable*  rel_tables;
    size_t rel_tables_size;

    hash_t sections_table;
}Elf32_data;

char* get_name(Elf32_data* elf, size_t section_index);
#endif
