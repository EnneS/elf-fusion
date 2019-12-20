#ifndef __ELF_AFFICHAGE_H__
#define __ELF_AFFICHAGE_H__

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "elf_reader.h"

/**
 * Affiche le contenue de l'en tête d'un fichier elf
 */
void afficher_header(Elf32_Ehdr header);

/**
 * Affiche le contenue de la table des sections
 */
void afficher_table_sections(Elf32_Shdr sections, Elf32_Ehdr header, FILE * input);

#endif