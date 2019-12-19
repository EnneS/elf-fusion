#include "affichage_elf.h"
#include "util.h"

char* OS_ABI[17] = {
    "System V", "HP-UX", "NetBSD", 
    "Linux", "GNU Hurd", "Solaris", 
    "AIX", "IRIX","FreeBSD",
    "Tru64", "Novell Modesto","OpenBSD",
    "OpenVMS","NonStop Kernel","AROS",
    "Fenix OS", "CloudABI"
};
char* HEADER_TYPE[5] = {
    "NONE","REL","EXEC","DYN","CORE"
};
char* SECTION_TYPE[20] = {
    "NULL", "PROGBITS", "SYMTAB",
    "STRTAB", "RELA", "HASH",
    "DYNAMIC", "NOTE", "NOBITS",
    "REL", "SHLIB", "DYNSYM",
    " ", " ", "INIT_ARRAY",
    "FINI_ARRAY", "PREINIT_ARRAY", "GROUP",
    "SYMTAB_SHNDX", "NUM" 
};

void print_elf_header(Elf32_Ehdr header) {
    printf("En tête ELF :\n");
    printf("Magique : ");
    for(int i = 0; i < 16; i++) {
        printf("%.2x ",header.e_ident[i]);
    }
    printf("\n"); 

    printf("Classe : ");
    if(header.e_ident[4] == 2) {
        printf("ELF64");
    } else {
        printf("ELF32");
    }
    printf("\n");

    if(header.e_ident[5] == 1) {
        printf("Données : Little Endian"); 
    } else  {
        printf("Données : Big Endian"); 
    }
    
    printf("\n");

    
    printf("OS/ABI : %s\n", OS_ABI[header.e_ident[7]]);
    
    printf("Vesrsion ABI: 0x%x\n",header.e_ident[8]);    
    
    printf("Type : ");
    int type = reverse_2(header.e_type);
    (void)type;
    if(type <= 4){
        printf("%s\n", HEADER_TYPE[type]);
    }
    else if(type >= 0xfe && type <= 0xfeff){
        printf("OS\n");
    }
    else if(type >= 0xff00 && type <= 0xffff){
        printf("PROC\n");
    }    

    printf("Machine : 0x%.2x",reverse_2(header.e_machine));
   
    printf("\n");

    printf("Version : ");
    switch(reverse_4(header.e_version)) {
        case 0:
            printf("autre que l'original");
            break; 
        case 1:
            printf("1 (current)");
            break; 
        default :
            printf("Default");
            break;
    }

    printf("\n");

    printf("Adresse du point d'entrée: 0x%.2x\n",reverse_4(header.e_entry));    
    printf("Début des en-têtes de programme: %d (octet dans le fichier)\n",reverse_4(header.e_phoff));    
    printf("Début des en-têtes de sections: %d (octet dans le fichier)\n",reverse_4(header.e_shoff));    
    printf("Fanions : 0x%x\n",reverse_4(header.e_flags));    
    printf("Taille de cet en-tête : 52 (octet)\n");    
    printf("Taille de l'en-tête du programme: %d (octet)\n",reverse_2(header.e_phentsize));    
    printf("Nombre d'en-tête du programme: %d\n",reverse_2(header.e_phnum));    
    printf("Taille des en-têtes de section: %d (octet)\n",reverse_2(header.e_shentsize));    
    printf("Nombre d'en-têtes de section:  %d (octet)\n",reverse_2(header.e_shnum));    
    printf("Table d'indexes des chaînes d'en-tête de section: %d\n",reverse_2(header.e_shstrndx));    
}

void print_section_header_table(Elf32_Shdr* shdr_table, size_t offset_sections, size_t nb_sections, char* str_table){
    printf("Il y a %ld en-tête de sections, commençant au décalage 0x%lx\n\n", nb_sections, offset_sections);
    printf("En-têtes de section:\n");
    printf("[No] Nom                Type     Addr     Deca   Taille ES Flg Ln Inf Al\n");
    for(int i = 0; i < nb_sections; i++){
        //ID
        printf("[%2d]", i);
        //NOM
        printf(" %-18s", &str_table[reverse_4(shdr_table[i].sh_name)]);
        //TYPE
        int type = reverse_4(shdr_table[i].sh_type);
        if(type < 12){
            printf(" %-8s", SECTION_TYPE[type]);
        }
        else if(type >= 0x60000000 && type <= 0x6fffffff){
            printf(" %-8s", "OS");
        }
        else if(type >= 0x70000000 && type <= 0x7fffffff){
            printf(" %-8s", "PROC");
        }
        else if(type >= 0x80000000 && type <= 0xffffffff){
            printf(" %-8s", "USER");
        } else {
            printf(" %-8s", " ");
        }
        

        // ADDR
        printf(" %8.8x", reverse_4(shdr_table[i].sh_addr));

        // OFFSET
        printf(" %6.6x", reverse_4(shdr_table[i].sh_offset));

        // TAILLE
        printf(" %6.6x", reverse_4(shdr_table[i].sh_size));

        // TAILLE D'UNE ENTREE
        printf(" %2.2x", reverse_4(shdr_table[i].sh_entsize));

        char flags[4] = "\0\0\0";
        int flag_count = 0;
        int flag = reverse_4(shdr_table[i].sh_flags);

        if(flag & SHF_WRITE) {flags[flag_count] = 'W'; flag_count++;}
        if(flag & SHF_ALLOC) {flags[flag_count] = 'A'; flag_count++;} 
        if(flag & SHF_EXECINSTR) {flags[flag_count] = 'X'; flag_count++;}
        if(flag & SHF_MERGE) {flags[flag_count] = 'M'; flag_count++;} 
        if(flag & SHF_STRINGS) {flags[flag_count] = 'S'; flag_count++;}
        if(flag & SHF_INFO_LINK) {flags[flag_count] = 'I'; flag_count++;}
        if(flag & SHF_LINK_ORDER) {flags[flag_count] = 'L'; flag_count++;}
        if(flag & SHF_OS_NONCONFORMING) {flags[flag_count] = 'O'; flag_count++;}
        if(flag & SHF_COMPRESSED) {flags[flag_count] = 'C'; flag_count++;}
        if(flag & SHF_GROUP) {flags[flag_count] = 'G'; flag_count++;}
        if(flag & SHF_TLS) {flags[flag_count] = 'T'; flag_count++;}
        if(flag & SHF_MASKOS) {flags[flag_count] = 'o'; flag_count++;}
        if(flag & SHF_MASKPROC) {flags[flag_count] = 'p'; flag_count++;}
        printf(" %3s", flags);

        printf(" %2d", reverse_4(shdr_table[i].sh_link));
        printf(" %3d", reverse_4(shdr_table[i].sh_info));
        printf(" %2d", reverse_4(shdr_table[i].sh_addralign));

        printf("\n");

    }
    printf("Key to Flags:\n\tW (write), A (alloc), X (execute), M (merge), S (strings), I (info),\n\tL (link order), O (extra OS processing required), G (group), T (TLS), \n\tC (compressed), x (unknown), o (OS specific), E (exclude),\n\ty (purecode), p (processor specific)\n");

}
