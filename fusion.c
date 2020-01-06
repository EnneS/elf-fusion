#include "stdio.h"
#include "getopt.h"
#include "elf_reader.h"
#include "affichage_elf.h"

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

    //print_elf_header(elf1_data.e_header);
    print_section_header_table(elf1_data.shdr_table, elf1_data.e_header.e_shoff, elf1_data.e_header.e_shnum, elf1_data.str_table);

    print_symbol_table(elf1_data.symbol_table, elf1_data.symbol_table_size, elf1_data.sm_str_table);

    //print_section_data(elf1_data.shdr_table, elf1_data.str_table, elf1_data.sections_data, 6);
    print_relocation_table(elf1_data.rel_tables, elf1_data.rel_tables_size, elf1_data.rela_tables, elf1_data.rela_tables_size, elf1_data.str_table, elf1_data.symbol_table, elf1_data.shdr_table);
    free_elf_data(elf1_data);

    fclose(elf1);
    fclose(elf2);

    (void)elf2;
    (void)elf2_data;
    return 0;
}