#ifndef __ELF_FILE_REVERSE_H__
#define __ELF_FILE_REVERSE_H__

#include "elf_file.h"

void reverse_elf_data(Elf32_data* elf_data);
void reverse_elf_ehdr(Elf32_Ehdr* elf_hdr);
void reverse_elf_shdr(Elf32_Shdr* elf_shdr);
void reverse_elf_sym(Elf32_Sym* elf_sym);
void reverse_elf_rel(Elf32_Rel* elf_rel);
void reverse_elf_rela(Elf32_Rela* elf_rela);

#endif