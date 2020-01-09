#ifndef __ELF_READER_H__
#define __ELF_READER_H__

#include "stdio.h"
#include "elf.h"
#include "elf_file.h"
#include "stdlib.h"
#include "elf_file_reverse.h"
#include "util.h"

/* Ecriture d'un Elf32_data dans un fichier */

void write_elf_data(Elf32_data* elf, FILE* file);

// Ecriture du ELF Header
int write_elf_header(FILE* file, Elf32_Ehdr* header);

// Ecriture de la table des sections
int write_elf_section_table(FILE* file, Elf32_Shdr* table, size_t offset, size_t nb_entries, size_t entry_size);

int write_program_header_table(FILE* file, Elf32_Phdr* table, size_t offset, size_t nb_entries, size_t entry_size);

#endif