#include "elf_reader.h"

int read_elf_header(FILE* file, Elf32_Ehdr* header){
    //On se place au débbut du fichier
    fseek(file, 0, SEEK_SET);
    //On lit le header
    if(fread(header, sizeof(Elf32_Ehdr), 1, file) < 1){
        return -1;
    }
    return 0;
}

// Lecture de l'en-tête des sections
int read_elf_section_table(FILE* file, Elf32_Shdr* table, size_t offset, size_t nb_entries, size_t entry_size){
    fseek(file, offset, SEEK_SET);
    if(fread(table, entry_size, nb_entries, file) < nb_entries)
        return -1;
    return 0;
}

int read_elf_program_header_table(FILE* file, Elf32_Phdr* table, size_t offset, size_t nb_entries, size_t entry_size){
    fseek(file, offset, SEEK_SET);
    if(fread(table, entry_size, nb_entries, file) < nb_entries)
        return -1;
    return 0;
}

Elf32_data read_elf_data(FILE* file){
    Elf32_data elf_data;

    // Récupération de l'entête ELF
    if(read_elf_header(file, &elf_data.e_header)){
        fprintf(stderr, "couldn't recognize elf header\n");
    }

    // Vérification qu'il s'agit d'un fichier ELF
    if(elf_data.e_header.e_ident[0] != 0x7f) {
        fprintf(stderr, "N'est pas un fichier ELF - a les mauvais octets magiques au départ\n");
    }

    //Récupération de la table de programme
    elf_data.program_header_table = malloc(reverse_4(elf_data.e_header.e_phnum) * reverse_4(elf_data.e_header.e_phentsize));

    if(read_elf_program_header_table(file, elf_data.program_header_table, reverse_4(elf_data.e_header.e_phoff), reverse_4(elf_data.e_header.e_phnum), reverse_4(elf_data.e_header.e_phentsize))){
        fprintf(stderr, "couldn't read program table\n");
    }

    // Récupération des entêtes des sections
    elf_data.shdr_table = malloc(sizeof(Elf32_Shdr) * reverse_2(elf_data.e_header.e_shnum));
    elf_data.sections_data = malloc(sizeof(uint8_t*) * reverse_2(elf_data.e_header.e_shnum));

    if(read_elf_section_table(file, elf_data.shdr_table, reverse_4(elf_data.e_header.e_shoff), reverse_2(elf_data.e_header.e_shnum), reverse_2(elf_data.e_header.e_shentsize))){
        fprintf(stderr, "couldn't read section table\n");
    }


    // Allocation mémoire des tableaux
    size_t rela_count, rel_count, progbits_nbr;
    rela_count = rel_count = progbits_nbr = 0;
    for(int i = 0; i < reverse_2(elf_data.e_header.e_shnum); i++){
        switch(reverse_4(elf_data.shdr_table[i].sh_type)){
            // Relocation table (with addends)
            case SHT_PROGBITS: 
                progbits_nbr++; break;
            case SHT_RELA: 
                rela_count++; break;
            case SHT_REL:
                rel_count++; break;
        }
    }
    elf_data.rela_tables_size = rela_count;
    elf_data.rela_tables = malloc(rela_count * sizeof(Elf32_RelaTable));

    elf_data.rel_tables_size = rel_count;
    elf_data.rel_tables = malloc(rel_count * sizeof(Elf32_RelTable));

    elf_data.progbits_nbr = progbits_nbr;
    elf_data.progbits_sections = malloc(progbits_nbr * sizeof(size_t));

    hash_init(&elf_data.sections_table, 32);

    // Récupération des sections
    size_t rela_index, rel_index, str_index, progbits_index;
    rela_index = rel_index = progbits_index = 0;
    str_index = reverse_2(elf_data.e_header.e_shstrndx);
    Elf32_Word symbol_table_link = -1;
    for(int i = 0; i < reverse_2(elf_data.e_header.e_shnum); i++){
        size_t sh_offset = reverse_4(elf_data.shdr_table[i].sh_offset);
        size_t sh_size = reverse_4(elf_data.shdr_table[i].sh_size);
        size_t sh_type = reverse_4(elf_data.shdr_table[i].sh_type);
        size_t sh_entsize = reverse_4(elf_data.shdr_table[i].sh_entsize);
        size_t nb_entries = sh_entsize > 0 ? (sh_size / sh_entsize) : 1;

        if(sh_size == 0)
            continue;
        
        // Récupération des données de la section dans le tableau
        // On les récupères toutes => cela permet de ne devoir lire le fichier qu'une seule fois et de l'avoir en mémoire en permanence
        // De cette manière il est facile d'accéder aux données d'une section si on connait son index.
        elf_data.sections_data[i] = malloc(sh_size);
        fseek(file, sh_offset, SEEK_SET);
        if(fread(elf_data.sections_data[i], sh_size, 1, file) < 1){
            fprintf(stderr, "couldn't read section data\n");
        }       

        // Ensuite, il suffit d'assigner les pointeurs de chaque section au type voulu 
        // (en castant le pointeur au bon type)

        // String Table
        if(i == str_index){
            elf_data.str_table = (char*) elf_data.sections_data[i];
            elf_data.str_table_size = sh_size;
        }

        switch(sh_type){
            case SHT_PROGBITS:
                elf_data.progbits_sections[progbits_index] = i;
                progbits_index++;
                break;
            // Symbol Table
            case SHT_SYMTAB:
                elf_data.symbol_table = (Elf32_Sym*) elf_data.sections_data[i];
                elf_data.symbol_table_size = sh_size / sizeof(Elf32_Sym);
                symbol_table_link = elf_data.shdr_table[i].sh_link;
                break;

            // Relocation Table (with addends)
            case SHT_RELA:
                elf_data.rela_tables[rela_index].rela_table = (Elf32_Rela*) elf_data.sections_data[i];
                elf_data.rela_tables[rela_index].rela_table_size = nb_entries;
                elf_data.rela_tables[rela_index].rela_table_name = elf_data.shdr_table[i].sh_name;
                elf_data.rela_tables[rela_index].rela_table_offset = elf_data.shdr_table[i].sh_offset;
                rela_index++;
                break;
                
            // Relocation Table (without addends)
            case SHT_REL:
                elf_data.rel_tables[rel_index].rel_table = (Elf32_Rel*) elf_data.sections_data[i];
                elf_data.rel_tables[rel_index].rel_table_size = nb_entries;
                elf_data.rel_tables[rel_index].rel_table_name = elf_data.shdr_table[i].sh_name;
                elf_data.rel_tables[rel_index].rel_table_offset = elf_data.shdr_table[i].sh_offset;
                rel_index++;
                break;
        }

        // String Symbol Table
        if(reverse_4(symbol_table_link) == i) {
            elf_data.sm_str_table = (char*) elf_data.sections_data[i];
            elf_data.sm_str_table_size = sh_size;
        }
    }
    
    // Enfin, reverse les données
    reverse_elf_data(&elf_data);

    for(int i = 0; i < elf_data.e_header.e_shnum; i++){
        hash_insert(&elf_data.sections_table, get_name(&elf_data, i), i);
    }

    return elf_data;
}

void free_elf_data(Elf32_data elf){
    free(elf.shdr_table);

    if(elf.sections_data) {
        for(int i = 0; i < elf.e_header.e_shnum; i++){
                free(elf.sections_data[i]);
            
        }
        free(elf.sections_data);
    }
}

