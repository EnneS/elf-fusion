#include "elf_writer.h"

int write_elf_header(FILE* file, Elf32_Ehdr* header){
    //On se place au débbut du fichier
    fseek(file, 0, SEEK_SET);
    //On ecrit le header
    if(fwrite(header, sizeof(Elf32_Ehdr), 1, file) < 1){
        return -1;
    }
    return 0;
}

int write_elf_section_table(FILE* file, Elf32_Shdr* table, size_t offset, size_t nb_entries, size_t entry_size){
    fseek(file, offset, SEEK_SET);
    if(fread(table, entry_size, nb_entries, file) < nb_entries)
        return -1;
    return 0;
}

int write_program_header_table(FILE* file, Elf32_Phdr* table, size_t offset, size_t nb_entries, size_t entry_size){
    fseek(file, offset, SEEK_SET);
    if(fread(table, entry_size, nb_entries, file) < nb_entries)
        return -1;
    return 0;
}

void write_elf_data(Elf32_data elf, FILE* file){
    // Ecriture du ELF Header
    if(write_elf_header(file, elf.e_header)){
        fprintf(stderr, "couldn't write elf header\n");
    }

    // Ecriture du program header
    if(write_program_header_table(file, elf.write_program_header_table, elf.e_header.e_phoff, elf.e_header.e_phnum, elf.e_header.e_phentsize)){
        fprintf(stderr, "couldn't write program header table\n");
    }

    // Ecriture du contenu des sections
    for(int i = 0; i < elf.e_header.e_shnum; i++){
        // Ecriture de la section
        if(fwrite(elf.sections_data[i], elf.shdr_table[i].sh_size, 1, file) < 1){
            fprintf(stderr, "couldn't write section data %d\n", i);
        }     
    }

    // Ecriture de la table des sections
    if(write_elf_section_table(file, elf.shdr_table, elf.e_header.e_shoff, elf.e_header.e_shnum, elf.e_header.e_shentsize)){
        fprintf(stderr, "couldn't write section table\n");
    }
}