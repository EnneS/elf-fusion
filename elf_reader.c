#include "elf_reader.h"

int read_elf_header(FILE* file, Elf32_Ehdr* header){
    if(fread(header, sizeof(Elf32_Ehdr), 1, file) < 1){
        return -1;
    }

    return 0;
}
int read_elf_section_table(FILE* file, Elf32_Shdr* table, size_t offset, size_t nb_entries, size_t entry_size){
    fseek(file, offset);
    if(fread(table, entry_size, nb_entries, file) < nb_entries){
        return -1;
    }
    return 0;
}

