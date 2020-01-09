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
    if(fwrite(table, entry_size, nb_entries, file) < nb_entries)
        return -1;
    return 0;
}

int write_program_header_table(FILE* file, Elf32_Phdr* table, size_t offset, size_t nb_entries, size_t entry_size){
    fseek(file, offset, SEEK_SET);
    if(fwrite(table, entry_size, nb_entries, file) < nb_entries)
        return -1;
    return 0;
}

void write_elf_data(Elf32_data* elf, FILE* file){
    reverse_elf_data(elf);

    // Laisser de la place pour l'entête ELF
    fseek(file, sizeof(Elf32_Ehdr), SEEK_SET);

    // Ecriture du program header
    if(write_program_header_table(file, elf->program_header_table, reverse_4(elf->e_header.e_phoff), reverse_2(elf->e_header.e_phnum), reverse_2(elf->e_header.e_phentsize))){
        fprintf(stderr, "couldn't write program header table\n");
    }

    // Ecriture du contenu des sections
    for(int i = 1; i < reverse_2(elf->e_header.e_shnum); i++){
        uint32_t offset = ftell(file);
        elf->shdr_table[i].sh_offset = reverse_4(offset);
        // Ecriture de la section
        if(fwrite(elf->sections_data[i], reverse_4(elf->shdr_table[i].sh_size), 1, file) < 1){
            fprintf(stderr, "couldn't write section data %d\n", i);
        }     
    }
    
    uint32_t offset = ftell(file);
    elf->e_header.e_shoff = reverse_4(offset);
    // Ecriture de la table des sections
    if(write_elf_section_table(file, elf->shdr_table, reverse_4(elf->e_header.e_shoff), reverse_2(elf->e_header.e_shnum),reverse_2(elf->e_header.e_shentsize))){
        fprintf(stderr, "couldn't write section table\n");
    }
    
    // Ecriture du ELF Header
    fseek(file, 0, SEEK_SET);
    if(write_elf_header(file, &elf->e_header)){
        fprintf(stderr, "couldn't write elf header\n");
    }
}