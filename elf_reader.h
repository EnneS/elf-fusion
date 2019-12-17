#ifndef __ELF_READER_H__
#define __ELF_READER_H__
#include "stdio.h"
#include "elf.h"
int read_elf_header(FILE* file, Elf32_Ehdr* header);
int read_elf_section_table(FILE* file, Elf32_Shdr* table, size_t offset, size_t nb_entries, size_t entry_size);
int read_elf_symbole_table(FILE* file, Elf32_Sym* table, size_t offset, size_t size, size_t entry_size);
int read_elf_rela_table(FILE* file, Elf32_Rela* table, size_t offset, size_t size, size_t entry_size);
int read_elf_rel_table(FILE* file, Elf32_Rel* table, size_t offset, size_t size, size_t entry_size);
#endif
