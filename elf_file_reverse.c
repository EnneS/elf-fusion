#include "elf_file_reverse.h"

void reverse_elf_data(Elf32_data* elf_data){
    reverse_elf_ehdr(&elf_data->e_header);
    for(int i = 0; i < elf_data->e_header.e_shnum; i++){
        reverse_elf_shdr(&elf_data->shdr_table[i]);
    }
    for(int i = 0; i < elf_data->symbol_table_size; i++){
        reverse_elf_sym(&elf_data->symbol_table[i]);
    }
    for(int i = 0; i < elf_data->rela_tables_size; i++){
        Elf32_RelaTable* rt = &elf_data->rela_tables[i];
        rt->rela_table_name = reverse_4(rt->rela_table_name);
        rt->rela_table_offset = reverse_4(rt->rela_table_offset);
        for(int j = 0; j < rt->rela_table_size; j++){
            reverse_elf_rela(&rt->rela_table[j]);
        }
    }
    for(int i = 0; i < elf_data->rel_tables_size; i++){
        Elf32_RelTable* rt = &elf_data->rel_tables[i];
        rt->rel_table_name = reverse_4(rt->rel_table_name);
        rt->rel_table_offset = reverse_4(rt->rel_table_offset);
        for(int j = 0; j < rt->rel_table_size; j++){
            reverse_elf_rel(&rt->rel_table[j]);
        }
    }
}


void reverse_elf_ehdr(Elf32_Ehdr* elf_hdr){
    elf_hdr->e_type = reverse_2(elf_hdr->e_type);
    elf_hdr->e_machine = reverse_2(elf_hdr->e_machine);
    elf_hdr->e_version = reverse_4(elf_hdr->e_version);
    elf_hdr->e_entry = reverse_4(elf_hdr->e_entry);
    elf_hdr->e_phoff = reverse_4(elf_hdr->e_phoff);
    elf_hdr->e_shoff = reverse_4(elf_hdr->e_shoff);
    elf_hdr->e_flags = reverse_4(elf_hdr->e_flags);
    elf_hdr->e_ehsize = reverse_2(elf_hdr->e_ehsize);
    elf_hdr->e_phentsize = reverse_2(elf_hdr->e_phentsize);
    elf_hdr->e_phnum = reverse_2(elf_hdr->e_phnum);
    elf_hdr->e_shentsize = reverse_2(elf_hdr->e_shentsize);
    elf_hdr->e_shnum = reverse_2(elf_hdr->e_shnum);
    elf_hdr->e_shstrndx = reverse_2(elf_hdr->e_shstrndx);
}

void reverse_elf_shdr(Elf32_Shdr* elf_shdr){
    elf_shdr->sh_name = reverse_4(elf_shdr->sh_name);
    elf_shdr->sh_type = reverse_4(elf_shdr->sh_type);
    elf_shdr->sh_flags = reverse_4(elf_shdr->sh_flags);
    elf_shdr->sh_addr = reverse_4(elf_shdr->sh_addr);
    elf_shdr->sh_offset = reverse_4(elf_shdr->sh_offset);
    elf_shdr->sh_size = reverse_4(elf_shdr->sh_size);
    elf_shdr->sh_link = reverse_4(elf_shdr->sh_link);
    elf_shdr->sh_info = reverse_4(elf_shdr->sh_info);
    elf_shdr->sh_addralign = reverse_4(elf_shdr->sh_addralign);
    elf_shdr->sh_entsize = reverse_4(elf_shdr->sh_entsize);
}

void reverse_elf_sym(Elf32_Sym* elf_sym){
    elf_sym->st_name = reverse_4(elf_sym->st_name);
    elf_sym->st_value = reverse_4(elf_sym->st_value);
    elf_sym->st_size = reverse_4(elf_sym->st_size);
    elf_sym->st_shndx = reverse_2(elf_sym->st_shndx);
}

void reverse_elf_rel(Elf32_Rel* elf_rel){
    elf_rel->r_offset = reverse_4(elf_rel->r_offset);
    elf_rel->r_info = reverse_4(elf_rel->r_info);
}

void reverse_elf_rela(Elf32_Rela* elf_rela){
    elf_rela->r_offset = reverse_4(elf_rela->r_offset);
    elf_rela->r_info = reverse_4(elf_rela->r_info);
    elf_rela->r_addend = reverse_4(elf_rela->r_addend);
}