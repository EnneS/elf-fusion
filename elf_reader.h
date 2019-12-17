#ifndef __ELF_READER_H__
#define __ELF_READER_H__
#include "stdio.h"
#include "elf.h"
int read_elf_header(FILE* file, Elf32_Ehdr* header);

#endif
