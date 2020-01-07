#ifndef __ELF_AFFICHAGE_H__
#define __ELF_AFFICHAGE_H__

#include <stdint.h>
#include <ctype.h>
#include "elf_reader.h"

/* Affichage d'un fichier ELF */

// Affichage du header ELF
void print_elf_header(Elf32_data);

// Affichage de la table des en-têtes de section
void print_section_header_table(Elf32_data);

// Affichage des données d'une section donnée
void print_section_data(Elf32_data, size_t num);

// Affichage de la table des symboles
void print_symbol_table(Elf32_data);

// Affichage de la table des relocations (avec et sans addends)
void print_relocation_table(Elf32_data);
#endif