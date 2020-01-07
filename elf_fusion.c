#include "elf_fusion.h"

Elf32_data concat_progbits(Elf32_data base, Elf32_data source){

    Elf32_data result = {0};

    int new_sec_nbr = base.e_header.e_shnum;
    int new_prog_nbr = base.progbits_nbr;

    for(int i = 0; i < source.progbits_nbr; ++i){
        char* section_name = get_name(&source, source.progbits_sections[i]);
        int base_section_index = hash_lookup(&base.sections_table, section_name);
        if(base_section_index == HASH_FAIL){
            new_sec_nbr++;
            new_prog_nbr++;
        }
    }
    result.e_header = base.e_header;
    uint16_t shnum = new_sec_nbr;
    result.e_header.e_shnum = shnum;
    result.shdr_table = malloc(sizeof(Elf32_Shdr) * shnum);
    result.sections_data = malloc(sizeof(uint8_t*) * shnum);
    result.progbits_nbr = new_prog_nbr;

    printf("\n _____A_____ \n");
    uint16_t base_shnum = base.e_header.e_shnum;

    memcpy(result.shdr_table, base.shdr_table, base_shnum);
    memcpy(result.progbits_sections, base.progbits_sections, base.progbits_nbr);
    for(int i = 0; i < base_shnum; ++i){
        printf("\n _____A1_____ \n");
        size_t base_sec_size = base.shdr_table[i].sh_size;
        printf("\n _____A2_____ \n");
        if(base.shdr_table[i].sh_type == SHT_PROGBITS){
            printf("\n _____A3_____ \n");
            char* section_name = get_name(&base, i);
            int source_section_index = hash_lookup(&source.sections_table, section_name);
            printf("\n _____A4_____ \n");
            if(source_section_index != HASH_FAIL){
                printf("\n _____A5_____ \n");
                size_t sec_size = base_sec_size + source.shdr_table[source_section_index].sh_size;
                printf("\n _____A6_____ \n");
                result.shdr_table[i].sh_size = sec_size;
                memcpy(result.sections_data[i], base.sections_data[i], base_sec_size);
                memcpy(&result.sections_data[i][base_sec_size], source.sections_data[source_section_index], source.shdr_table[source_section_index].sh_size);
                printf("\n _____A7_____ \n");
            }
            else{
                printf("\n _____A8_____ \n");
                result.sections_data[i] = malloc(base_sec_size);
                memcpy(result.sections_data[i], base.sections_data[i], base_sec_size);
                printf("\n _____A9_____ \n");
            }
        }
        else{
            printf("\n _____A10_____ \n");
            result.sections_data[i] = malloc(base_sec_size);
            memcpy(result.sections_data[i], base.sections_data[i], base_sec_size);
            printf("\n _____A11_____ \n");
        }
    }
    printf("\n _____B_____ \n");
    for(int i = 0; i < source.progbits_nbr; ++i){
        size_t idx = source.progbits_sections[i];
        size_t source_sec_size = source.shdr_table[idx].sh_size;

        char* section_name = get_name(&source, idx);
        int source_section_index = hash_lookup(&base.sections_table, section_name);

        if(source_section_index == HASH_FAIL){
            size_t res_idx = base_shnum + i;
            result.sections_data[res_idx] = malloc(source_sec_size);
            result.shdr_table[res_idx] = source.shdr_table[idx];
            result.progbits_sections[base.progbits_nbr + i] = res_idx;

            memcpy(result.sections_data[res_idx], source.sections_data[idx], source_sec_size);
        }
    }
    printf("\n _____E_____ \n");
    return result;
}

Elf32_data merge(Elf32_data base, Elf32_data source){
    Elf32_data empty = {0};
    return empty;
}
