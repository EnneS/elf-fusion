#include "affichage_elf.h"

int main(int argc, char ** argv) {
    FILE * input;

    Elf32_Ehdr header;
    if(NULL == (input = fopen("Examples_loader/example1.o","r"))) {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }
    if(read_elf_header(input, &header)){
        fprintf(stderr, "couldn't recognize elf header\n");
    }
    print_elf_header(header);

    fclose(input);
    return 0;
}