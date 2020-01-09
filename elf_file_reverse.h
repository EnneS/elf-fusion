#ifndef __ELF_FILE_REVERSE_H__
#define __ELF_FILE_REVERSE_H__

#include "elf_file.h"

/* Reverse des structures :
    Elf32_data
    Elf32_Ehdr
    Elf32_Shdr
    Elf32_Phdr
    ELf32_Symb
    Elf32_Rel
    Elf32_Rela
*/

void reverse_elf_data(Elf32_data* elf_data);

void reverse_elf_ehdr(Elf32_Ehdr* elf_hdr);
void reverse_elf_shdr(Elf32_Shdr* elf_shdr);
void reverse_elf_phdr(Elf32_Phdr* elf_phdr);
void reverse_elf_sym(Elf32_Sym* elf_sym);
void reverse_elf_rel(Elf32_Rel* elf_rel);
void reverse_elf_rela(Elf32_Rela* elf_rela);

#endif