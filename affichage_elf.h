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

#endif