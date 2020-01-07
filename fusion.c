#include "stdio.h"
#include "getopt.h"
#include "elf_reader.h"
#include "affichage_elf.h"
#include "elf_fusion.h"

void usage(char *name) {
	fprintf(stderr, "Usage:\n"
		"%s [ --help ] file1 file2\n\n", name);
}

int main(int argc, char *argv[]){
    FILE* elf1 = NULL;
    FILE* elf2 = NULL;
    Elf32_data elf1_data;
    Elf32_data elf2_data;
    Elf32_data result;

	if(argc < 2){
		usage(argv[0]);
		exit(1);
	}
	elf1 = fopen(argv[1], "r");
	elf2 = fopen(argv[2], "r");

    elf1_data = read_elf_data(elf1);
    elf2_data = read_elf_data(elf2);

    print_elf_header(elf1_data);
    printf("\n _____1_____ \n");
    print_section_header_table(elf1_data);
    printf("\n _____2_____ \n");
    print_symbol_table(elf1_data);

    print_section_data(elf1_data, 6);
    print_relocation_table(elf1_data);
    
    printf("\n _____3_____ \n");
    result = concat_progbits(elf1_data, elf2_data);
    printf("\n _____4_____ \n");

    print_section_data(result, 6);
    
    free_elf_data(elf1_data);
    free_elf_data(elf2_data);
    free_elf_data(result);

    fclose(elf1);
    fclose(elf2);

    return 0;
}