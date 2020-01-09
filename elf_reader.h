#ifndef __ELF_READER_H__
#define __ELF_READER_H__

#include "stdio.h"
#include "elf.h"
#include "elf_file.h"
#include "stdlib.h"
#include "util.h"
#include "hashtable.h"
#include "elf_file_reverse.h"

/* Lecture d'un fichier ELF */

// Lecture de l'en-tête d'un fichier ELF
int read_elf_header(FILE* file, Elf32_Ehdr* header);

// Lecture de l'en-tête des sections
int read_elf_section_table(FILE* file, Elf32_Shdr* table, size_t offset, size_t nb_entries, size_t entry_size);

// Lecture de l'en-tête des program table
int read_elf_program_header_table(FILE* file, Elf32_Phdr* table, size_t offset, size_t nb_entries, size_t entry_size);

// Lecture d'un fichier ELF
Elf32_data read_elf_data(FILE* file);

// Libération la mémoire d'une structure Elf32_data
void free_elf_data(Elf32_data elf);
#endif