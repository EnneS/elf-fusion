#include "stdio.h"
#include "getopt.h"
#include "elf_reader.h"

void usage(char *name) {
	fprintf(stderr, "Usage:\n"
		"%s [ --help ] file1 file2\n\n", name);
}

int main(int argc, char *argv[]){
    FILE* elf1 = NULL;
    FILE* elf2 = NULL;
    Elf32_data elf1_data;
    Elf32_data elf2_data;

	if(argc < 2){
		usage(argv[0]);
		exit(1);
	}
	elf1 = fopen(argv[1], "r");
	elf2 = fopen(argv[2], "r");

    elf1_data = read_elf_data(elf1);
    free_elf_data(elf1_data);

    fclose(elf1);
    fclose(elf2);
    
    (void)elf2;
    (void)elf2_data;
    return 0;
}