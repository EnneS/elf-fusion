#ifndef __ELF_AFFICHAGE_H__
#define __ELF_AFFICHAGE_H__

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "elf_reader.h"

void print_elf_header(Elf32_Ehdr header);
void print_section_header_table(Elf32_Shdr* shdr_table, size_t offset_sections, size_t nb_sections, char* str_table);

#endif