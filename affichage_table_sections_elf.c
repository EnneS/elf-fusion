#include "affichage_elf.h"

int main(int argc, char ** argv) {
    FILE * input;

    Elf32_Ehdr header;
    Elf32_Shdr sections_table;
    if(NULL == (input = fopen("Examples_loader/example1.o","r"))) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }
    if(read_elf_header(input, &header)){
        fprintf(stderr, "couldn't recognize elf header\n");
    }
    if(read_elf_section_table(input, &sections_table, reverse_4(header.e_shoff), reverse_2(header.e_shnum), reverse_2(header.e_shentsize))) {
        afficher_table_sections(sections_table, header, input);        
    }

    fclose(input);
    return 0;
}