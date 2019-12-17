#include "stdio.h"
#include "stdlib.h"
#include "getopt.h"
#include "elf_reader.h"
#include "util.h"

void usage(char *name) {
	fprintf(stderr, "Usage:\n"
		"%s [ --help ] file1 file2\n\n", name);
}

int main(int argc, char *argv[]){
    FILE* elf1 = NULL;
    FILE* elf2 = NULL;
    Elf32_Ehdr e_header;
    Elf32_Shdr* s_table;

	if(argc < 2){
		usage(argv[0]);
		exit(1);
	}
	elf1 = fopen(argv[1], "r");
	elf2 = fopen(argv[2], "r");

    // Récupération de l'entête ELF
    if(read_elf_header(elf1, &e_header)){
        fprintf(stderr, "couldn't recognize elf header\n");
    }

    // Récupération des entêtes des sections
    s_table = malloc(sizeof(Elf32_Shdr) * reverse_2(e_header.e_shnum));
    if(read_elf_section_table(elf1, s_table, reverse_4(e_header.e_shoff), reverse_2(e_header.e_shnum), reverse_2(e_header.e_shentsize))){
        fprintf(stderr, "couldn't read section table\n");
    }

    // Récupération des sections
    for(int i = 0; i < reverse_2(e_header.e_shnum); i++){
        switch(reverse_4(s_table[i].sh_type)){
            // Symbole Table
            case 2: {
                Elf32_Sym* sym_table;
                sym_table = malloc(reverse_4(s_table[i].sh_size));
                if(read_elf_symbole_table(elf1, sym_table, reverse_4(s_table[i].sh_offset), reverse_4(s_table[i].sh_size), reverse_4(s_table[i].sh_entsize))){
                    fprintf(stderr, "couldn't read symbole table\n");
                }
                free(sym_table);
                break;
            }
            // Relocation Table (with addends)
            case 4: {
                Elf32_Rela* rela_table;
                rela_table = malloc(reverse_4(s_table[i].sh_size));
                if(read_elf_rela_table(elf1, rela_table, reverse_4(s_table[i].sh_offset), reverse_4(s_table[i].sh_size), reverse_4(s_table[i].sh_entsize))){
                    fprintf(stderr, "couldn't read relocation table (with addends)\n");
                }
                free(rela_table);
                break;
            }
            // Relocation Table (without addends)
            case 9: {
                Elf32_Rel* rel_table;
                rel_table = malloc(reverse_4(s_table[i].sh_size));
                if(read_elf_rel_table(elf1, rel_table, reverse_4(s_table[i].sh_offset), reverse_4(s_table[i].sh_size), reverse_4(s_table[i].sh_entsize))){
                    fprintf(stderr, "couldn't read symbole table\n");
                }
                free(rel_table);
                break;
            }
        }
    }
    free(s_table);

    fclose(elf1);
    fclose(elf2);
    (void)elf2;
    return 0;
}