#ifndef __elf_data_H__
#define __elf_data_H__

typedef struct{
    Elf32_Ehdr e_header;
    Elf32_Shdr* shdr_table;
    Elf32_Sym* symbol_table;
    Elf32_Rela** rela_tables;
    size_t rela_tables_size;
    Elf32_Rel**  rel_tables;
    size_t rel_tables_size;
}Elf32_data;

#endif