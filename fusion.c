#include "stdio.h"
#include "stdlib.h"
#include "getopt.h"
#include "elf_reader.h"

void usage(char *name) {
	fprintf(stderr, "Usage:\n"
		"%s [ --help ] file1 file2\n\n", name);
}

void prints(unsigned char* str, int len){
	for(int i = 0; i < len; ++i){
		printf("%c", str[i]); 
	}
}

int main(int argc, char *argv[]){
    Elf32_Ehdr header;
    FILE* elf1 = NULL;
    FILE* elf2 = NULL;

	if(argc < 2){
		usage(argv[0]);
		exit(1);
	}
	elf1 = fopen(argv[1], "r");
	elf2 = fopen(argv[2], "r");
    if(read_elf_header(elf1, &header)){
        fprintf(stderr, "couldn't recognize elf header\n");
    }
    prints(header.e_ident, 4);
    printf("%s", "\n");
    fclose(elf1);
    fclose(elf2);
    (void)elf2;
    return 0;
}