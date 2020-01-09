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

char * SYMBOL_TYPE[13] = {
    "NOTYPE","OBJECT","FUNC",
    "SECTION","FILE","COMMON",
    "TLS","NUM","LOOS",
    "GNU_IFUNC","HIOS","LOPROC",
    "HIPROC"
};

char * SYMBOL_LIEN[21] = {
    "LOCAL","GLOBAL","WEAK",
    "NUM"," "," ",
    " "," "," ",
    " "," ","LOOS"," "
    "HIOS","LOPROC"," ",
    "HIPROC"
};

char * SYMBOL_VISIBILITY[4] = {
    "DEFAULT ","INTERNAL","HIDDEN",
    "PROTECTED"
};

void print_elf_header(Elf32_data elf){
    Elf32_Ehdr header = elf.e_header;
    printf("En tête ELF :\n");
    printf("Magique : ");
    for (int i = 0; i < 16; i++)
    {
        printf("%.2x ", header.e_ident[i]);
    }
    printf("\n");

    printf("Classe : ");
    if (header.e_ident[4] == 2)
    {
        printf("ELF64");
    }
    else
    {
        printf("ELF32");
    }
    printf("\n");

    if (header.e_ident[5] == 1)
    {
        printf("Données : 2's complement, little endian");
    }
    else
    {
        printf("Données : 2's complement, big endian");
    }

    printf("\n");

    
    printf("OS/ABI : %s\n", OS_ABI[header.e_ident[7]]);
    
    printf("Vesrsion ABI: 0x%x\n",header.e_ident[8]);    
    
    printf("Type : ");
    int type = header.e_type;
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

    // printf("\n");

    printf("Version : ");
    switch (header.e_version)
    {
    case 0:
        printf("autre que l'original");
        break;
    case 1:
        printf("1 (current)");
        break;
    default:
        printf("Default");
        break;
    }

    printf("\n");

    printf("Adresse du point d'entrée: 0x%.1x\n",header.e_entry);    
    printf("Début des en-têtes de programme: %d (octet dans le fichier)\n",header.e_phoff);    
    printf("Début des en-têtes de sections: %d (octet dans le fichier)\n",header.e_shoff);    
    printf("Fanions : 0x%x\n",header.e_flags);    
    printf("Taille de cet en-tête : 52 (octet)\n");    
    printf("Taille de l'en-tête du programme: %d (octet)\n",header.e_phentsize);    
    printf("Nombre d'en-tête du programme: %d\n",header.e_phnum);    
    printf("Taille des en-têtes de section: %d (octet)\n",header.e_shentsize);    
    printf("Nombre d'en-têtes de section:  %d (octet)\n",header.e_shnum);    
    printf("Table d'indexes des chaînes d'en-tête de section: %d\n",header.e_shstrndx);    
}

void print_section_header_table(Elf32_data elf){
    Elf32_Shdr* shdr_table = elf.shdr_table;
    size_t offset_sections = elf.e_header.e_shoff;
    size_t nb_sections = elf.e_header.e_shnum;
    char* str_table = elf.str_table;
    printf("Il y a %ld en-tête de sections, commençant au décalage 0x%lx\n\n", nb_sections, offset_sections);
    printf("En-têtes de section:\n");
    printf("  [No] Nom                Type         Addr     Deca   Taille ES Flg Ln Inf Al\n");
    for(int i = 0; i < nb_sections; i++){
        //ID
        printf("  [%2d]", i);

        //NOM
        printf(" %-18s", &str_table[shdr_table[i].sh_name]);

        //TYPE
        int type = shdr_table[i].sh_type;
        if(type < 12){
            printf(" %-12s", SECTION_TYPE[type]);
        }
        else if(type >= SHT_LOOS && type <= SHT_HIOS){
            printf(" %-12s", "OS");
        }
        else if(type >= SHT_LOPROC && type <= SHT_HIPROC){
            printf(" %-12s", "PROC");
        }
        else if(type >= SHT_LOUSER && type <= SHT_HIUSER){
            printf(" %-12s", "USER");
        } else {
            printf(" %-12s", " ");
        }
        
        // ADDR
        printf(" %8.8x", shdr_table[i].sh_addr);

        // OFFSET
        printf(" %6.6x", shdr_table[i].sh_offset);

        // TAILLE
        printf(" %6.6x", shdr_table[i].sh_size);

        // TAILLE D'UNE ENTREE
        printf(" %2.2x", shdr_table[i].sh_entsize);

        // FLAGS
        char flags[4] = "\0\0\0";
        int flag_count = 0;
        int flag = shdr_table[i].sh_flags;
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

        // LINK
        printf(" %2d", shdr_table[i].sh_link);

        // INFO
        printf(" %3d", shdr_table[i].sh_info);

        // ADDR ALIGN
        printf(" %2d", shdr_table[i].sh_addralign);

        printf("\n");
    }
    printf("Key to Flags:\n\tW (write), A (alloc), X (execute), M (merge), S (strings), I (info),\n\tL (link order), O (extra OS processing required), G (group), T (TLS), \n\tC (compressed), x (unknown), o (OS specific), E (exclude),\n\ty (purecode), p (processor specific)\n");
}

void print_section_data(Elf32_data elf, size_t num){
    Elf32_Shdr* shdr_table = elf.shdr_table;
    char* str_table = elf.str_table;
    uint8_t* section_data = elf.sections_data[num];
    size_t size = shdr_table[num].sh_size;
    char* section_name = &str_table[shdr_table[num].sh_name];
    // Si la section contient des données, l'afficher
    if(size > 0) {
        int width = 4;
        int height = size/(4*width);
        int line_length = (size*2) % (width*8);
        // Pour aligner l'affichage (nombre d'espaces nécessaire dernières lignes entre HEXA et ASCII)
        int width_to_complete = width*8 + width - line_length - line_length/8;

        printf("Dump hexadécimal de la section '%s':\n", section_name);
        // Affichage ligne par ligne en HEXA et ASCII
        for(int i = 0; i <= height; i+=1){
            // Affichage en HEXA :
            printf("  0x%.8x ", i*16);
            for(int j = 0; (j < width*4) & ((i*width*4)+j < size); j+=4){
                // On affiche octet par octet par 4 (blocs de 4 octets)
                if((i*width*4)+j < size)
                    printf("%.2x",section_data[(i*width*4)+j]);
                if((i*width*4)+j+1 < size)         
                    printf("%.2x",section_data[(i*width*4)+(j+1)]);
                if((i*width*4)+j+2 < size)
                    printf("%.2x",section_data[(i*width*4)+(j+2)]);
                if((i*width*4)+j+3 < size)
                    printf("%.2x ",section_data[(i*width*4)+(j+3)]);
            }
            // Alignement
            if(i == size/(4*width))
                printf("%*s", width_to_complete, "");
            // Affichage en ASCII
            for(int j = 0; (j < width*4) & ((i*width*4)+j < size); j++){
                // Affichage de l'octet en charactère (s'il s'agit de caractère affichable)
                if(isprint(section_data[(i*width*4)+j]))
                    printf("%c", section_data[(i*width*4)+j]);
                else
                    printf("."); // Sinon afficher un '.' à la place
            }
            printf("\n");
        }
    } else {
        printf("Section '%s' n'a pas de donnée à dump.", section_name);
    }
    printf("\n");
}

void print_symbol_table(Elf32_data elf){
    Elf32_Sym * symbols = elf.symbol_table;
    size_t size = elf.symbol_table_size;
    char* sm_str_table = elf.sm_str_table;
    printf("La table de symboles « .symtab » contient %ld entrées :\n",size);
    printf("   Num:    Valeur Tail Type    Lien   Vis      Ndx Nom\n");
    Elf32_Sym symbol;
    
    // Affichage de la table des symboles
    for(int i = 0; i < size; i++)  {
        symbol = symbols[i];
        printf("%6d:",i); // Numéro
        printf("%10.8x",symbol.st_value); // Valeur du symbole
        printf("%5d ",symbol.st_size); // Taille
        // Type du symbole
        int idx_type = ELF32_ST_TYPE(symbol.st_info);
        switch(idx_type) {
            case 0x10:
                idx_type = 8;
                break;
            case 0x12 :
                idx_type = 9;
                break;
            case 0x13:
                idx_type = 10;
                break;
            case 0x15:
                idx_type = 11;
                break;
            default:
                break;
        }
        printf("%-8s",SYMBOL_TYPE[idx_type]);
        // Link
        printf("%-7s",SYMBOL_LIEN[ELF32_ST_BIND(symbol.st_info)]);
        // Visibilité
        printf("%-8s",SYMBOL_VISIBILITY[ELF32_ST_VISIBILITY(symbol.st_other)]);

        // Index
        int ndx = symbol.st_shndx;
        ndx == 0 ? printf("%4s", "UND") : printf("%4d", ndx);
        // Affichage du symbole
        printf("%5s",&sm_str_table[symbol.st_name]);
        printf("\n");

    }
}

void print_relocation_table(Elf32_data elf){
    Elf32_RelTable* rel_tables = elf.rel_tables;
    size_t rel_tables_size = elf.rel_tables_size;
    Elf32_RelaTable* rela_tables = elf.rela_tables;
    size_t rela_tables_size = elf.rela_tables_size;
    char* str_table = elf.str_table;
    Elf32_Sym* symbol_table = elf.symbol_table;
    Elf32_Shdr* shdr_table = elf.shdr_table;

    // Affichage des tables de relocations (sans addends)
    for(int i = 0; i < rel_tables_size; i++){
        Elf32_RelTable rel_table = rel_tables[i];
        Elf32_Off offset = rel_table.rel_table_offset;
        size_t nb_entries = rel_table.rel_table_size;
        printf("Section de réadressage '%s' à l'adresse de décalage 0x%x contient %ld entrées:\n", &str_table[rel_table.rel_table_name], offset, nb_entries);
        printf(" Décalage   Info   Type  Val.-sym  Noms-symboles\n");
        // Affichage de toutes les relocations pour cette section
        for(int j = 0; j < rel_table.rel_table_size; j++){
            Elf32_Rel rel = rel_table.rel_table[j];
            printf("%-10.8x", rel.r_offset); // Offset
            printf("%-9.8x", rel.r_info); // Info
            int type = ELF32_R_TYPE(rel.r_info); // Type
            printf("%4d ", type);
            int symbol = ELF32_R_SYM(rel.r_info); // Symbole
            printf("%9.8x ", symbol);
            int section_index = symbol_table[symbol].st_shndx;
            printf("%14s", &str_table[shdr_table[section_index].sh_name]); // Nom de la section correspondante
            printf("\n");
        }
        printf("\n");
    }

    // Idem pour les relocations tables avec addends
    for(int i = 0; i < rela_tables_size; i++){
        Elf32_RelaTable rela_table = rela_tables[i];
        Elf32_Off offset = rela_table.rela_table_offset;
        size_t nb_entries = rela_table.rela_table_size;
        printf("Section de réadressage '%s' à l'adresse de décalage 0x%x contient %ld entrées:\n", &str_table[rela_table.rela_table_name], offset, nb_entries);
        printf(" Décalage   Info   Type  Val.-sym  Noms-symboles\n");
        for(int j = 0; j < rela_table.rela_table_size; j++){
            Elf32_Rela rela = rela_table.rela_table[j];
            printf("%-10.8x", rela.r_offset);
            printf("%-9.8x", rela.r_info);
            int type = ELF32_R_TYPE(rela.r_info);
            printf("%4d ", type);
            int symbol = ELF32_R_SYM(rela.r_info);
            printf("%-8.8x", symbol);
            int section_index = symbol_table[symbol].st_shndx;
            printf("%-12s", &str_table[shdr_table[section_index].sh_name]);
            printf("\n");
        }
    }
}