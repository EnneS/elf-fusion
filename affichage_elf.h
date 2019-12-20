#ifndef __ELF_AFFICHAGE_H__
#define __ELF_AFFICHAGE_H__

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "elf_reader.h"

void print_elf_header(Elf32_Ehdr header);
void print_section_header_table(Elf32_Shdr* shdr_table, size_t offset_sections, size_t nb_sections, char* str_table);
void print_section_data(Elf32_Shdr* shdr_table, char* str_table, uint8_t** sections_data, size_t num);
void print_symbol_table(Elf32_Sym * symbol, size_t taille, char* sm_str_table);
void print_relocation_table(Elf32_Rel** rel_tables, size_t rel_tables_size, Elf32_Rela** rela_tables, size_t rela_tables_size, char* str_table);
#endif