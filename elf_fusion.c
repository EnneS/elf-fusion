#include "elf_fusion.h"

Elf32_data concat_all_sections(Elf32_data base, Elf32_data source){

    int* conflicts = malloc(sizeof(int) * source.progbits_nbr * 2);
    int conflict_nbr = 0;
    int* new_sections = malloc(sizeof(int) * source.progbits_nbr);
    int newsec_nbr = 0;

    for(int i = 0; i < source.progbits_nbr; ++i){
        char* section_name = get_name(&source, i);
        uint8_t match = 0;
        for(int j = 0; j < base.progbits_nbr; ++j){
            if(!strcmp(get_name(&base, j), section_name)){
                match = 1;
                conflicts[2*conflict_nbr] = j;
                conflicts[2*conflict_nbr+1] = i;
                conflict_nbr++;
                break;
            }
        }
        if(!match){
            new_sections[newsec_nbr] = i;
            newsec_nbr++;
        }
    }

    Elf32_data result = {0};

    result.e_header = base.e_header;
    uint16_t shnum = reverse_2(result.e_header.e_shnum) + newsec_nbr;
    result.e_header.e_shnum = reverse_2(shnum);
    result.shdr_table = malloc(sizeof(Elf32_Shdr) * shnum);
    result.sections_data = malloc(sizeof(uint8_t*) * shnum);
    
    return result;
}

Elf32_data merge(Elf32_data base, Elf32_data source){
    Elf32_data empty = {0};
    return empty;
}
