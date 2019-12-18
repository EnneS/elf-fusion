#ifndef __ELF_READER_H__
#define __ELF_READER_H__

#include "stdio.h"
#include "elf.h"
#include "elf_file.h"
#include "stdlib.h"
#include "util.h"

int read_elf_header(FILE* file, Elf32_Ehdr* header);
int read_elf_section_table(FILE* file, Elf32_Shdr* table, size_t offset, size_t nb_entries, size_t entry_size);
void* read_elf_special_table(FILE* file, size_t offset, size_t size, size_t entry_size);

Elf32_data read_elf_data(FILE* file);
void free_elf_data(Elf32_data file);
#endif