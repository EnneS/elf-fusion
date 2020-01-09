#ifndef __ELF_FUSION_H__
#define __ELF_FUSION_H__

#include "elf_file.h"
#include "string.h"
#include "stdio.h"
#include "util.h"

/*
*  Fusion de deux fichiers ELF
*/

// Fusionne deux fichiers ELF donnés en entrée 
void merge(Elf32_data* result, Elf32_data* base, Elf32_data* source);

/*
*  Fusion et rénumérotation des sections 
*/

// Structure afin de mémoriser les offsets des sections à changer.
typedef struct{
    size_t offset;
    uint16_t section_index;
}Section_Merge_Info;

// Initialisation de la structure Elf32_data résultat
void init_new_elf(Elf32_data* result, Elf32_data* base, Elf32_data* source);

// Fusion de la string table des noms de section
void merge_str_table(Elf32_data* result, Elf32_data* base, Elf32_data* source, Section_Merge_Info* merge_table);

// Fusion des sections ce type PROGBITS
void concat_progbits(Elf32_data* result, Elf32_data* base, Elf32_data* source, Section_Merge_Info* merge_table);

// Initialisation de la hastable des sections de result
void init_sections_table(Elf32_data* result);

/*
*  Fusion de la table des symboles
*/

// Fusion de deux tables des symboles en entrées et rénumérotation deux ceux-ci
void merge_symbol_table(Elf32_data* result, Elf32_data* base, Elf32_data* source, Section_Merge_Info* merge_table, uint32_t* base_srt, uint32_t* source_srt);

void correct_reloc(Elf32_data* result, int type, size_t sec_size, size_t offset, int i, uint32_t* srt);

void concat_reloc(Elf32_data* result, Elf32_data* base, Elf32_data* source, Section_Merge_Info* merge_table, uint32_t* base_srt, uint32_t* source_srt);

// Ajout d'un symbole dans une table des symboles
void add_symbol(Elf32_Sym* table, Elf32_Sym sym, size_t* index);

// Un symbole est indéfini lorsque son bind vaut SHN_UNDEF
int is_symbol_undefined(Elf32_Sym sym);

// Un symbole est à relocaliser (màj de st_shndx) lorsqu'il n'est ni défini (SHN_UNDEF) ni absolu (SHN_ABS)
int should_relocate_symbol(Elf32_Sym sym);

// Récupération du nom du symbole dans la string table des symboles
char* get_symbol_name(Elf32_data* elf, Elf32_Sym sym);

// Ajoute un nom d'un symbole à la string table des symboles et retourne son offset dans celle-ci
size_t add_to_sm_str_table(char** result_sm_str_table, size_t* result_sm_str_size, char* name);

#endif
