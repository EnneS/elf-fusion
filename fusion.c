#include "stdio.h"
#include "getopt.h"
#include "elf_reader.h"
#include "affichage_elf.h"
#include "elf_fusion.h"
#include "elf_writer.h"

void usage(char *name) {
	fprintf(stderr, "Usage:\n"
		"%s [ --help ] file1 file2 file_sortie\n\n", name);
}

void write_elf_data(Elf32_data* elf, FILE* file);

int main(int argc, char *argv[]){
    FILE* elf1 = NULL;
    FILE* elf2 = NULL;
    FILE* resultat_file = NULL;
    Elf32_data elf1_data;
    Elf32_data elf2_data;
    Elf32_data result;

	if(argc < 3){
		usage(argv[0]);
		exit(1);
	}
    
	elf1 = fopen(argv[1], "r");
	elf2 = fopen(argv[2], "r");
    
	resultat_file = fopen(argv[3], "w");

    printf("\n\n======== LECTURE ========\n\n");

    elf1_data = read_elf_data(elf1);
    elf2_data = read_elf_data(elf2);

    print_section_header_table(elf1_data);
    print_section_header_table(elf2_data);
    

    printf("\n\n======== MERGE ========\n\n");

    merge(&result, &elf1_data, &elf2_data);
    print_section_header_table(result);
    print_symbol_table(result);
    print_relocation_table(result);

    printf("\n\n======== ECRITURE ========\n\n");
    write_elf_data(&result, resultat_file);

    free_elf_data(elf1_data);
    free_elf_data(elf2_data);

    //free_elf_data(result);

    printf("\n\n======== FREE ========\n\n");

    fclose(elf1);
    fclose(elf2);
    fclose(resultat_file);
    return 0;
}