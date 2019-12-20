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

int read_elf_section_table(FILE* file, Elf32_Shdr* table, size_t offset, size_t nb_entries, size_t entry_size){
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
    elf_data.rela_tables = malloc(rela_count * sizeof(Elf32_Rela*));

    elf_data.rel_tables_size = rel_count;
    elf_data.rel_tables = malloc(rel_count * sizeof(Elf32_Rel*));

    elf_data.progbits_nbr = progbits_nbr;
    elf_data.progbits_sections = malloc(progbits_nbr * sizeof(uint8_t*));

    // Récupération des sections
    size_t rela_index, rel_index, str_index, progbits_index;
    rela_index = rel_index = progbits_index = 0;
    str_index = reverse_2(elf_data.e_header.e_shstrndx);
    for(int i = 0; i < reverse_2(elf_data.e_header.e_shnum); i++){
        size_t sh_offset = reverse_4(elf_data.shdr_table[i].sh_offset);
        size_t sh_size = reverse_4(elf_data.shdr_table[i].sh_size);
        size_t sh_type = reverse_4(elf_data.shdr_table[i].sh_type);

        if(sh_size == 0)
            continue;
        
        elf_data.sections_data[i] = malloc(sh_size);
        fseek(file, sh_offset, SEEK_SET);
        if(fread(elf_data.sections_data[i], sh_size, 1, file) < 1){
            fprintf(stderr, "couldn't read section data\n");
        }       
        

        // String Table
        if(i == str_index){
            elf_data.str_table = (char*) elf_data.sections_data[i];
            elf_data.str_table_size = sh_size;
        }

        switch(sh_type){
            case SHT_PROGBITS:
                elf_data.progbits_sections[progbits_index] = elf_data.sections_data[i];
                progbits_index++;
                break;
            // Symbol Table
            case SHT_SYMTAB:
                elf_data.symbol_table = (Elf32_Sym*) elf_data.sections_data[i];
                break;

            // Relocation Table (with addends)
            case SHT_RELA:
                elf_data.rela_tables[rela_index] = (Elf32_Rela*) elf_data.sections_data[i];
                rela_index++;
                break;
                
            // Relocation Table (without addends)
            case SHT_REL:
                elf_data.rel_tables[rel_index] = (Elf32_Rel*) elf_data.sections_data[i];
                rel_index++;
                break;
        }
    }
    return elf_data;
}

void free_elf_data(Elf32_data elf){
    free(elf.shdr_table);

    for(int i = 0; i < reverse_2(elf.e_header.e_shnum); i++){
        free(elf.sections_data[i]);
    }
    free(elf.sections_data);
}

