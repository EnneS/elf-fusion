#include "affichage_elf.h"
#include <string.h>

void print_info() {
    printf("Affichage de fichier elf\n"
                    "\tUsage : \n"
                    "\t\t ./affichage_executable [ option ] [ nom_de_fichier_elf ] [ section ]\n"
                    "\tOption : \n"
                    "\t\t --help : affiche les options d'affichage\n"
                    "\t\t -h : affiche l'en tête\n"
                    "\t\t -x : affiche le contenue d'une section\n"
                    "\t\t -s : affiche la table des symboles\n"
                    "\t\t -S : affiche la table des sections\n"
                    "\t\t -r : affiche la table de réimplémentation\n");
}

void usage() {
            printf("usage ./affichage_executable [ option ] [ nom_de_fichier_elf ] [ section ] \"./affichage_executable --help\" pour plus d'info\n");
}

int main(int argc, char ** argv) {

    // VERIFICATION ENTREE
    if( argc < 3 ) {
        if (argc == 2 && strcmp(argv[1],"--help") == 0) {
            print_info();
            return 0;
        } else {
            usage();
            return 0;
        }
    }

    FILE* elf = NULL;

    Elf32_data elf_data;

	elf = fopen(argv[2], "r");

    elf_data = read_elf_data(elf);

    //AFFICHAGE FONCTION OPTION
    if( 0 == strcmp(argv[1],"-r") ) {
        printf("relocation table");
    } else if ( 0 == strcmp(argv[1],"-s") ) {
        print_symbol_table(elf_data);
    } else if( 0 == strcmp(argv[1],"-S") ) {
        print_section_header_table(elf_data);
    } else if( 0 == strcmp(argv[1],"-x") ) {   
        if (argc < 4)  {
            usage();
            exit(1);
        }  
        if( atoi(argv[3]) >= elf_data.e_header.e_shnum )  {
            printf("Erreur nombre de section = %d\n",elf_data.e_header.e_shnum);
            exit(1);
        }
        print_section_data(elf_data, atoi(argv[3]));
    } else if( 0 == strcmp(argv[1],"-h")) {
        print_elf_header(elf_data);
    }
    fclose(elf);
    return 0;
}