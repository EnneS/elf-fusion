#include "elf_fusion.h"

Elf32_data concat_all_sections(Elf32_data base, Elf32_data source){

    //int* 
    for(int i = 0; i < source.progbits_nbr; ++i){
        char* section_name = get_name(&source, i);
        for(int j = 0; j < base.progbits_nbr; ++j){
            if(!strcmp(get_name(&base, j), section_name)){

            }
        }
    }
    Elf32_data empty = {0};
    return empty;
}

Elf32_data merge(Elf32_data base, Elf32_data source){
    Elf32_data empty = {0};
    return empty;
}
