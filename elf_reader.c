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

void* read_elf_special_table(FILE* file, size_t offset, size_t size, size_t entry_size){
    fseek(file, offset, SEEK_SET);
    void* table = malloc(size);
    int nb_entries = 1;
    int size_to_read = size;
    // If the section has entries
    if(entry_size > 0) {
        nb_entries = size / entry_size;
        size_to_read = entry_size;
    }
    if(fread(table, size_to_read, nb_entries, file) < nb_entries){
        return NULL;
    }
    return table;
}

Elf32_data read_elf_data(FILE* file){
    Elf32_data elf_data;

    // Récupération de l'entête ELF
    if(read_elf_header(file, &elf_data.e_header)){
        fprintf(stderr, "couldn't recognize elf header\n");
    }

    // Récupération des entêtes des sections
    elf_data.shdr_table = malloc(sizeof(Elf32_Shdr) * reverse_2(elf_data.e_header.e_shnum));
    if(read_elf_section_table(file, elf_data.shdr_table, reverse_4(elf_data.e_header.e_shoff), reverse_2(elf_data.e_header.e_shnum), reverse_2(elf_data.e_header.e_shentsize))){
        fprintf(stderr, "couldn't read section table\n");
    }

    // Allocation mémoire des tableaux
    size_t rela_count, rel_count;
    rela_count = rel_count = 0;
    for(int i = 0; i < reverse_2(elf_data.e_header.e_shnum); i++){
        switch(reverse_4(elf_data.shdr_table[i].sh_type)){
            // Relocation table (with addends)
            case 4: 
                rela_count++; break;
            case 9:
                rel_count++; break;
        }
    }
    elf_data.rela_tables_size = rela_count;
    elf_data.rela_tables = malloc(rela_count * sizeof(Elf32_Rela*));

    elf_data.rel_tables_size = rel_count;
    elf_data.rel_tables = malloc(rel_count * sizeof(Elf32_Rel*));

    // Récupération des sections
    size_t rela_index, rel_index, str_index;
    rela_index = rel_index = 0;
    str_index = reverse_2(elf_data.e_header.e_shstrndx);
    for(int i = 0; i < reverse_2(elf_data.e_header.e_shnum); i++){
        size_t sh_offset = reverse_4(elf_data.shdr_table[i].sh_offset);
        size_t sh_size = reverse_4(elf_data.shdr_table[i].sh_size);
        size_t sh_entsize = reverse_4(elf_data.shdr_table[i].sh_entsize);
        size_t sh_type = reverse_4(elf_data.shdr_table[i].sh_type);

        // String Table
        if(i == str_index){
            elf_data.str_table = read_elf_special_table(file, sh_offset, sh_size, sh_entsize);
            elf_data.str_table_size = sh_size;
            if(!elf_data.str_table){
                fprintf(stderr, "couldn't read string table\n");
            }
        }

        switch(sh_type){
            // Symbole Table
            case 2:
                elf_data.symbol_table = read_elf_special_table(file, sh_offset, sh_size, sh_entsize);
                if(!elf_data.symbol_table){
                    fprintf(stderr, "couldn't read symbole table\n");
                }
                break;

            // Relocation Table (with addends)
            case 4:
                elf_data.rela_tables[rela_index] = read_elf_special_table(file, sh_offset, sh_size, sh_entsize);
                if(!elf_data.rela_tables[rela_index]){
                    fprintf(stderr, "couldn't read relocation table (with addends)\n");
                }
                break;
                rela_index++;
                
            // Relocation Table (without addends)
            case 9:
                elf_data.rel_tables[rel_index] = read_elf_special_table(file, sh_offset, sh_size, sh_entsize);
                if(!elf_data.rel_tables[rel_index]){
                    fprintf(stderr, "couldn't read relocation table (without addends)\n");
                }
                break;
                rel_index++;
        }
    }
    return elf_data;
}

void free_elf_data(Elf32_data elf){
    free(elf.shdr_table);
    free(elf.symbol_table);

    for(int i = 0; i < elf.rela_tables_size; i++){
        free(elf.rela_tables[i]);
    }
    free(elf.rela_tables);

    for(int i = 0; i < elf.rel_tables_size; i++){
        free(elf.rel_tables[i]);
    }
    free(elf.rel_tables);
    free(elf.str_table);
}