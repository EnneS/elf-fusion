#include "elf_fusion.h"


void init_new_elf(Elf32_data* result, Elf32_data* base, Elf32_data* source){
    uint16_t base_shnum = base->e_header.e_shnum;
    uint16_t shnum = base_shnum;
    int new_prog_nbr = base->progbits_nbr;

    // On compte les sections sumplémentaires qui seront ajoutées à partir du deuxième fichier (source)
    for(int i = 0; i < source->progbits_nbr; ++i){
        char* section_name = get_name(source, source->progbits_sections[i]);
        int base_section_index = hash_lookup(&base->sections_table, section_name);
        if(base_section_index == HASH_FAIL){
            shnum++;
            new_prog_nbr++;
        }
    }

    result->e_header = base->e_header;
    result->e_header.e_shnum = shnum;
    result->shdr_table = malloc(sizeof(Elf32_Shdr) * shnum);
    result->sections_data = malloc(sizeof(uint8_t*) * shnum);
    result->progbits_nbr = new_prog_nbr;
    result->progbits_sections = malloc(sizeof(uint16_t) * new_prog_nbr);

    // Copie de la shdr_table et des progbits_section depuis le fichier de base
    memcpy(result->shdr_table, base->shdr_table, sizeof(Elf32_Shdr) * base_shnum);
    memcpy(result->progbits_sections, base->progbits_sections, sizeof(uint16_t) * base->progbits_nbr);

}


void merge_str_table(Elf32_data* result, Elf32_data* base, Elf32_data* source, Section_Merge_Info* merge_table){
    // Copie de la str_table (nom des en-têtes de section)
    size_t new_str_table_size = base->str_table_size + source->str_table_size;
    result->str_table_size = new_str_table_size;
    result->sections_data[result->e_header.e_shstrndx] = malloc(new_str_table_size);
    result->str_table = (char*) result->sections_data[result->e_header.e_shstrndx];
    memcpy(result->str_table, base->str_table, base->str_table_size);
    memcpy(&result->str_table[base->str_table_size], source->str_table, source->str_table_size);
    
    // Mémorisation du numéro de la section pour la renumérotation des symboles
    merge_table[source->e_header.e_shstrndx].section_index = result->e_header.e_shstrndx;
    merge_table[source->e_header.e_shstrndx].offset = base->str_table_size;
    
}


void concat_progbits(Elf32_data* result, Elf32_data* base, Elf32_data* source, Section_Merge_Info* merge_table){

    uint16_t base_shnum = base->e_header.e_shnum;

    // On copie toutes les sections du premier, en fusionnant avec le deuxième si nécéssaire
    for(int i = 0; i < base_shnum; ++i){
        size_t base_sec_size = base->shdr_table[i].sh_size;

        //alignement
        size_t align = base->shdr_table[i].sh_addralign;
        size_t padding = 0;
        if(align > 0){
            padding = align - 1 - ((base_sec_size + align - 1) % align); //alignement sur <align> octets
        }
        
        // Pour les sections progbits
        if(base->shdr_table[i].sh_type == SHT_PROGBITS){
            // On regarde si la section existe dans le deuxième fichier
            char* section_name = get_name(base, i);
            int source_section_index = hash_lookup(&source->sections_table, section_name);
            // Si c'est le cas on les fusionne, sinon on copie simplement la première
            if(source_section_index != HASH_FAIL){
                size_t source_sec_size = source->shdr_table[source_section_index].sh_size;
                size_t sec_size = base_sec_size + source_sec_size + padding;
                result->shdr_table[i].sh_size = sec_size;
                result->sections_data[i] = malloc(sec_size);
                memcpy(result->sections_data[i], base->sections_data[i], base_sec_size);
                memset(&result->sections_data[i][base_sec_size], 0, padding);
                memcpy(&result->sections_data[i][base_sec_size+padding], source->sections_data[source_section_index], source_sec_size);

                merge_table[source_section_index].section_index = i;
                merge_table[source_section_index].offset = base_sec_size+padding;

            } else {
                result->sections_data[i] = malloc(base_sec_size);
                memcpy(result->sections_data[i], base->sections_data[i], base_sec_size);
            }
        } else {
            // La section n'est pas de type progbits, on recopie simplement la section du premier fichier
            result->sections_data[i] = malloc(base_sec_size);
            memcpy(result->sections_data[i], base->sections_data[i], base_sec_size);
        }
    }

    size_t j = 0;
    // Ajoute les sections supplémentaires du deuxième fichier
    for(int i = 0; i < source->progbits_nbr; ++i){
        size_t idx = source->progbits_sections[i];
        size_t source_sec_size = source->shdr_table[idx].sh_size;

        char* section_name = get_name(source, idx);
        int source_section_index = hash_lookup(&base->sections_table, section_name);

        // Si la section ne fait pas partie du premier fichier, on l'ajoute
        if(source_section_index == HASH_FAIL){
            size_t res_idx = base_shnum + j;
            result->sections_data[res_idx] = malloc(source_sec_size);
            result->shdr_table[res_idx] = source->shdr_table[idx];
            result->progbits_sections[base->progbits_nbr + j] = res_idx;

            result->shdr_table[res_idx].sh_name += base->str_table_size;

            memcpy(result->sections_data[res_idx], source->sections_data[idx], source_sec_size);

            merge_table[source_section_index].section_index = res_idx;
            merge_table[source_section_index].offset = 0;

            j++;
        }
    }
}


void add_symbol(Elf32_Sym* table, Elf32_Sym sym, size_t* index){
    table[*index] = sym;
    (*index)++;
}

int is_symbol_undefined(Elf32_Sym sym){
    return sym.st_shndx == SHN_UNDEF;
}

int should_relocate_symbol(Elf32_Sym sym){
    return sym.st_shndx != SHN_UNDEF && sym.st_shndx != SHN_ABS;
}

char* get_symbol_name(Elf32_data* elf, Elf32_Sym sym){
    return &elf->sm_str_table[sym.st_name];
}

size_t add_to_sm_str_table(char** result_sm_str_table, size_t* result_sm_str_size, char* name){
    size_t length = strlen(name) + 1;
    size_t str_offset = *result_sm_str_size;
    (*result_sm_str_size) += length;
    (*result_sm_str_table) = realloc(*result_sm_str_table, *result_sm_str_size);
    strcpy(&(*result_sm_str_table)[str_offset], name);
    return str_offset;
}

void merge_symbol_table(Elf32_data* result, Elf32_data* base, Elf32_data* source, Section_Merge_Info* merge_table, uint32_t* base_srt, uint32_t* source_srt){
    Elf32_Sym* base_st = base->symbol_table;
    size_t base_st_size = base->symbol_table_size;
    Elf32_Sym* source_st = source->symbol_table;
    size_t source_st_size = source->symbol_table_size;

    size_t result_st_size = 0;

    // Création des hash tables des symboles
    hash_t base_symbols; // hash table des symboles globaux de base
    hash_init(&base_symbols, 64);
    hash_t source_symbols; // hash table des symboles globaux de source
    hash_init(&source_symbols, 64);

    hash_t local_symbols; // hash table des noms de symboles locaux (clé) et de leur offset dans la str table
    hash_init(&local_symbols, 32);
    
    // Initialisation de la string table
    size_t result_sm_str_size = 0;
    char* result_sm_str_table = NULL;

    // Comptage des symboles locaux et ajout de ceux-ci à la string table
    for(int i = 0; i < base_st_size; i++){
        Elf32_Sym symbol = base_st[i];
        if(ELF32_ST_BIND(symbol.st_info) == STB_LOCAL){
            // Il s'agit d'un symbole local
            result_st_size++;
            char* name = get_symbol_name(base, symbol);
            // Vérifier qu'il n'a pas déjà été ajouté à la string table
            if(hash_lookup(&local_symbols, name) == HASH_FAIL){
                // Sinon l'ajouter en mémorisant son offset
                size_t str_offset = add_to_sm_str_table(&result_sm_str_table, &result_sm_str_size, name);
                hash_insert(&local_symbols, name, str_offset);
            }
        } else {
            // Symbole global, l'ajouter à notre hash table
            hash_insert(&base_symbols, get_symbol_name(base, symbol), i);
        }
    }
    for(int i = 0; i < source_st_size; i++){
        Elf32_Sym symbol = source_st[i];
        if(ELF32_ST_BIND(symbol.st_info) == STB_LOCAL){
            result_st_size++;
            char* name = get_symbol_name(source, symbol);
            if(hash_lookup(&local_symbols, name) == HASH_FAIL){
                size_t str_offset = add_to_sm_str_table(&result_sm_str_table, &result_sm_str_size, name);
                hash_insert(&local_symbols, name, str_offset);
            }
        } else {
            hash_insert(&source_symbols, get_symbol_name(source, symbol), i);
        }
    }

    // Allocation de la table des symboles resultat (pour ajouter les symboles locaux)
    result->symbol_table = malloc(result_st_size * sizeof(Elf32_Sym));
    size_t idx = 0;

    // Ajout des symboles locaux à la table des symboles résultat
    for(int i = 0; i < base_st_size; i++){
        Elf32_Sym sym = base_st[i];
        if(ELF32_ST_BIND(sym.st_info) == STB_LOCAL){
            // Màj du nom du symbole en fonction de la nouvelle string table
            sym.st_name = hash_lookup(&local_symbols, get_symbol_name(base, sym));
            base_srt[i] = idx;
            add_symbol(result->symbol_table, sym, &idx);
        }
    }
    for(int i = 0; i < source_st_size; i++){
        Elf32_Sym sym = source_st[i];
        if(ELF32_ST_BIND(sym.st_info) == STB_LOCAL){
            // Il s'agit d'un symbole local
            if(should_relocate_symbol(sym)){
                // Le symbol doit être relocalisé
                sym.st_shndx = merge_table[sym.st_shndx].section_index;
            }

            sym.st_name = hash_lookup(&local_symbols, get_symbol_name(source, sym));
            source_srt[i] = idx;
            add_symbol(result->symbol_table, sym, &idx);
        }
    }

    // Ajout des symboles globaux
    // Base
    for(int i = 0; i < base_st_size; i++){
        Elf32_Sym base_sym = base_st[i];
        if(ELF32_ST_BIND(base_sym.st_info) == STB_GLOBAL){
            char* base_sym_name = get_symbol_name(base, base_sym);
            int source_sym_idx = hash_lookup(&source_symbols, base_sym_name);

            if(source_sym_idx == HASH_FAIL) {
                // Le symbole n'existe pas dans la seconde table de symboles

                // Reallocation de la table résultat
                result_st_size++;
                result->symbol_table = realloc(result->symbol_table, result_st_size * sizeof(Elf32_Sym));

                // Ajout du symbole
                base_sym.st_name = add_to_sm_str_table(&result_sm_str_table, &result_sm_str_size, base_sym_name);
                base_srt[i] = idx;
                add_symbol(result->symbol_table, base_sym, &idx);
            } else {
                // Le symbole existe dans les deux tables
                Elf32_Sym source_sym = source_st[source_sym_idx];

                if(is_symbol_undefined(source_sym) || is_symbol_undefined(base_sym)){
                    // Un des deux symboles n'est pas défini (sinon echec de l'édition de liens)

                    // Reallocation de la table résultat (on va devoir ajouter un symbole quoiqu'il arrive)
                    result_st_size++;
                    result->symbol_table = realloc(result->symbol_table, result_st_size * sizeof(Elf32_Sym));

                    if(!is_symbol_undefined(source_sym) && is_symbol_undefined(base_sym)){
                        // Base est indéfini, l'autre non

                        if(should_relocate_symbol(source_sym)){
                            source_sym.st_shndx = merge_table[source_sym.st_shndx].section_index;
                        }

                        // Ajout du symbole
                        source_sym.st_name = add_to_sm_str_table(&result_sm_str_table, &result_sm_str_size, base_sym_name);
                        base_srt[i] = idx;
                        source_srt[source_sym_idx] = idx;
                        add_symbol(result->symbol_table, source_sym, &idx);
                    } else if(!is_symbol_undefined(base_sym)){
                        // Source est indéfini

                        if(should_relocate_symbol(base_sym)){
                            base_sym.st_shndx = merge_table[base_sym.st_shndx].section_index;
                        }

                        // Ajout du symbole
                        base_sym.st_name = add_to_sm_str_table(&result_sm_str_table, &result_sm_str_size, base_sym_name);
                        base_srt[i] = idx;
                        source_srt[source_sym_idx] = idx;
                        add_symbol(result->symbol_table, base_sym, &idx);
                    } else {
                        // Aucun des deux n'est défini

                        // Ajout du symbole (base ou source pas d'importance, ici on choisit base)
                        base_sym.st_name = add_to_sm_str_table(&result_sm_str_table, &result_sm_str_size, base_sym_name);
                        base_srt[i] = idx;
                        source_srt[source_sym_idx] = idx;
                        add_symbol(result->symbol_table, base_sym, &idx);
                    }
                } else {
                    printf("Multiple definitions: '%s'\n", base_sym_name);
                    exit(-1);
                }
            }
        }
    }
    // Source (il ne manque qu'à ajouter les symboles de source non présents dans base)
    for(int i = 0; i < source_st_size; i++){
        Elf32_Sym source_sym = source_st[i];
        if(ELF32_ST_BIND(source_sym.st_info) == STB_GLOBAL){
            char* source_sym_name = get_symbol_name(source, source_sym);
            int base_sym_idx = hash_lookup(&base_symbols, get_symbol_name(source, source_sym));
            if(base_sym_idx == HASH_FAIL){
                // Le symbole n'existe pas dans la seconde table de symboles

                // Reallocation de la table résultat
                result_st_size++;
                result->symbol_table = realloc(result->symbol_table, result_st_size * sizeof(Elf32_Sym));
                // Ajout du symbole

                source_sym.st_name = add_to_sm_str_table(&result_sm_str_table, &result_sm_str_size, source_sym_name);
                base_srt[base_sym_idx] = idx;
                source_srt[i] = idx;
                add_symbol(result->symbol_table, source_sym, &idx);
            }     
        }
    }

    // Màj de la string table désormais complétée
    size_t sm_str_table_index = hash_lookup(&result->sections_table, ".strtab");
    result->sections_data[sm_str_table_index] = (uint8_t*) result_sm_str_table; // Maj des données
    result->sm_str_table = (char*) result->sections_data[sm_str_table_index]; // pointeur sur les données
    result->shdr_table[sm_str_table_index].sh_size = result_sm_str_size;
    result->sm_str_table_size = result_sm_str_size;
    
    result->symbol_table_size = result_st_size;
    result->shdr_table[hash_lookup(&result->sections_table, ".symtab")].sh_size = sizeof(Elf32_Sym) * result_st_size;
}

void init_sections_table(Elf32_data* result){
    hash_init(&result->sections_table, 32);
    for(int i = 0; i < result->e_header.e_shnum; i++){
        hash_insert(&result->sections_table, get_name(result, i), i);
    }
}

void correct_reloc(Elf32_data* result, int type, size_t sec_size, size_t offset, int i, uint32_t* srt){
    if(type == SHT_REL){
        size_t last = result->rel_tables_size;
        result->rel_tables_size++;
        result->rel_tables = realloc(result->rel_tables, result->rel_tables_size);
        result->rel_tables[last].rel_table_name = result->shdr_table[i].sh_name;
        result->rel_tables[last].rel_table_size = sec_size;
        result->rel_tables[last].rel_table = (Elf32_Rel*) result->sections_data[i];

        for(int j = offset; j < sec_size; j++){
            Elf32_Rel* rel = (Elf32_Rel*) result->sections_data[i];

            rel[j].r_offset += offset;
            
            int symbol = ELF32_R_SYM(rel[j].r_info);
            int rtype = ELF32_R_TYPE(rel[j].r_info);

            if (ELF32_ST_TYPE(symbol) == STT_SECTION){
                if(rtype == R_ARM_ABS8 || rtype == R_ARM_ABS12 || rtype == R_ARM_ABS16 || rtype == R_ARM_ABS32 || rtype == R_ARM_ABS32_NOI){
                }
                else if(rtype == R_ARM_JUMP24 || rtype == R_ARM_CALL){

                }
            }
            
            rel[j].r_info = ELF32_R_INFO(srt[symbol], rtype);
        }

    } else { //SHT_RELA
        size_t last = result->rela_tables_size;
        result->rela_tables_size++;
        result->rela_tables = realloc(result->rela_tables, result->rela_tables_size);
        result->rela_tables[last].rela_table_name = result->shdr_table[i].sh_name;
        result->rela_tables[last].rela_table_size = sec_size;
        result->rela_tables[last].rela_table = (Elf32_Rela*) result->sections_data[i];

        for(int j = offset; j < sec_size; j++){
            Elf32_Rela* rela = (Elf32_Rela*) result->sections_data[i];

            rela[j].r_offset += offset;

            int symbol = ELF32_R_SYM(rela[j].r_info);
            int rtype = ELF32_R_TYPE(rela[j].r_info);
            
            if (ELF32_ST_TYPE(symbol) == STT_SECTION){
                if(rtype == R_ARM_ABS8 || rtype == R_ARM_ABS12 || rtype == R_ARM_ABS16 || rtype == R_ARM_ABS32 || rtype == R_ARM_ABS32_NOI){
                    
                }
                else if(rtype == R_ARM_JUMP24 || rtype == R_ARM_CALL){

                }
            }

            rela[j].r_info = ELF32_R_INFO(srt[symbol], rtype);
        }
    }
}

void concat_reloc(Elf32_data* result, Elf32_data* base, Elf32_data* source, Section_Merge_Info* merge_table, uint32_t* base_srt, uint32_t* source_srt){
    result->rel_tables = NULL;
    result->rel_tables_size = 0;
    result->rela_tables = NULL;
    result->rela_tables_size = 0;

    uint16_t shnum = result->e_header.e_shnum;
    // On copie toutes les sections du premier, en fusionnant avec le deuxième si nécéssaire
    for(int i = 0; i < shnum; ++i){
        size_t base_sec_size = result->shdr_table[i].sh_size;

        //alignement
        size_t align = result->shdr_table[i].sh_addralign;
        size_t padding = 0;
        if(align > 0){
            padding = align - 1 - ((base_sec_size + align - 1) % align); //alignement sur <align> octets
        }
        
        uint32_t type = result->shdr_table[i].sh_type;
        // Pour les sections rel rela
        if(type == SHT_REL || type == SHT_RELA){
            //Section associée
            uint16_t origin = result->shdr_table[i].sh_info;
            (void) origin;

            // On regarde si la section existe dans le deuxième fichier
            char* section_name = get_name(base, i);
            int source_section_index = hash_lookup(&source->sections_table, section_name);
            // Si c'est le cas on les fusionne, sinon on copie simplement la première
            if(source_section_index != HASH_FAIL){
                size_t source_sec_size = source->shdr_table[source_section_index].sh_size;
                size_t sec_size = base_sec_size + source_sec_size + padding;
                size_t offset = base_sec_size+padding;
                memset(&result->sections_data[i][base_sec_size], 0, padding);
                memcpy(&result->sections_data[i][offset], source->sections_data[source_section_index], source_sec_size);

                result->shdr_table[i].sh_size = sec_size;
                result->sections_data[i] = realloc(result->sections_data[i], sec_size);

                correct_reloc(result, type, sec_size, offset, i, base_srt);

                merge_table[source_section_index].section_index = i;
                merge_table[source_section_index].offset = offset;

            } 
        }
    }
    
    
    size_t j = 0;
    
    // Ajoute les sections supplémentaires du deuxième fichier
    for(int i = 0; i < source->e_header.e_shnum; ++i){
        uint32_t type = source->shdr_table[i].sh_type;
        if(type == SHT_REL || type == SHT_RELA){
            size_t source_sec_size = source->shdr_table[i].sh_size;

            char* section_name = get_name(source, i);
            int source_section_index = hash_lookup(&result->sections_table, section_name);

            // Si la section ne fait pas partie du premier fichier, on l'ajoute
            if(source_section_index == HASH_FAIL){
                j++;
                size_t res_idx = shnum + j;
                size_t nb_entries = source_sec_size / source->shdr_table[i].sh_entsize;
                result->sections_data = realloc(result->sections_data, res_idx * sizeof(uint8_t*));
                result->sections_data[res_idx-1] = malloc(source_sec_size);
                memcpy(result->sections_data[res_idx-1], source->sections_data[i], source_sec_size);
                
                result->shdr_table = realloc(result->shdr_table, res_idx * sizeof(Elf32_Shdr));
                result->shdr_table[res_idx-1] = source->shdr_table[i];
                result->shdr_table[res_idx-1].sh_name += base->str_table_size;

                correct_reloc(result, type, nb_entries, 0, res_idx-1, source_srt);
                
                merge_table[source_section_index].section_index = res_idx;
                merge_table[source_section_index].offset = 0;
            }
        }
    }
    result->e_header.e_shnum += j;
}

void merge(Elf32_data* result, Elf32_data* base, Elf32_data* source){
    uint32_t* base_srt = malloc(base->symbol_table_size * sizeof(uint32_t));
    uint32_t* source_srt = malloc(source->symbol_table_size * sizeof(uint32_t));
    Section_Merge_Info* merge_table = malloc(sizeof(Section_Merge_Info) * source->e_header.e_shnum);
    init_new_elf(result, base, source);
    merge_str_table(result, base, source, merge_table);
    concat_progbits(result, base, source, merge_table);
    init_sections_table(result);
    merge_symbol_table(result, base, source, merge_table, base_srt, source_srt);
    concat_reloc(result, base, source, merge_table, base_srt, source_srt);
}