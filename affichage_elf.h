#ifndef __ELF_AFFICHAGE_H__
#define __ELF_AFFICHAGE_H__

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "elf_reader.h"

void lire_header(Elf32_Ehdr header);

#endif