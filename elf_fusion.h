#ifndef __ELF_FUSION_H__
#define __ELF_FUSION_H__

#include "elf_file.h"
#include "string.h"

Elf32_data merge(Elf32_data base, Elf32_data source);
Elf32_data concat_progbits(Elf32_data base, Elf32_data source);

#endif
