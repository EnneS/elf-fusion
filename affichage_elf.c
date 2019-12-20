#include "affichage_elf.h"
#include "util.h"

<<<<<<< HEAD
void afficher_header(Elf32_Ehdr header)
{
=======
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
>>>>>>> 864bcc83a3e694dd6872ebd82fc91173eb76bae9
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
        printf("Données : Little Endian");
    }
    else
    {
        printf("Données : Big Endian");
    }

    printf("\n");

<<<<<<< HEAD
    printf("OS/ABI : ");
    switch (header.e_ident[7])
    {
    case 0x00:
        printf("System V");
        break;
    case 0x01:
        printf("HP-UX");
        break;
    case 0x02:
        printf("NetBSD");
        break;
    case 0x03:
        printf("Linux");
        break;
    case 0x04:
        printf("GNU Hurd");
        break;
    case 0x05:
        printf("Solaris");
        break;
    case 0x06:
        printf("AIX");
        break;
    case 0x07:
        printf("IRIX");
        break;
    case 0x08:
        printf("FreeBSD");
        break;
    case 0x09:
        printf("Tru64");
        break;
    case 0x0a:
        printf("Novell Modesto ");
        break;
    case 0x0b:
        printf("OpenBSD");
        break;
    case 0x0c:
        printf("OpenVMS");
        break;
    case 0x0d:
        printf("NonStop Kernel");
        break;
    case 0x0e:
        printf("AROS");
        break;
    case 0x0f:
        printf("Fenix OS ");
        break;
    case 0x10:
        printf("CloudABI");
        break;
    case 0x11:
        printf("CloudABI");
        break;
    default:
        printf("Default");
        break;
    }
    printf("\n");

    printf("Vesrsion ABI: 0x%x", header.e_ident[8]);
    printf("\n");

    printf("Type : ");
    switch (reverse_2(header.e_type))
    {
    case 0x00:
        printf("NONE");
        break;
    case 0x01:
        printf("REL");
        break;
    case 0x02:
        printf("EXEC");
        break;
    case 0x03:
        printf("DYN");
        break;
    case 0x04:
        printf("CORE");
        break;
    case 0xfe:
        printf("LOOS");
        break;
    case 0xfeff:
        printf("HIOS");
        break;
    case 0xff00:
        printf("LOPORC");
        break;
    case 0xffff:
        printf("HIPROC");
        break;
    default:
        printf("Default");
        break;
    }
    printf("\n");

    printf("Machine : 0x%.2x", reverse_2(header.e_machine));
=======
    
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
>>>>>>> 864bcc83a3e694dd6872ebd82fc91173eb76bae9

    printf("\n");

    printf("Version : ");
    switch (reverse_4(header.e_version))
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

<<<<<<< HEAD
    printf("Adresse du point d'entrée: 0x%.2x", reverse_4(header.e_entry));
    printf("\n");

    printf("Début des en-têtes de programme: %d (octet dans le fichier)", reverse_4(header.e_phoff));
    printf("\n");

    printf("Début des en-têtes de sections: %d (octet dans le fichier)", reverse_4(header.e_shoff));
    printf("\n");

    printf("Fanions : 0x%x", reverse_4(header.e_flags));
    printf("\n");

    printf("Taille de cet en-tête : 52 (octet)");
    printf("\n");

    printf("Taille de l'en-tête du programme: %d (octet)", reverse_2(header.e_phentsize));
    printf("\n");

    printf("Nombre d'en-tête du programme: %d", reverse_2(header.e_phnum));
    printf("\n");

    printf("Taille des en-têtes de section: %d (octet)", reverse_2(header.e_shentsize));
    printf("\n");

    printf("Nombre d'en-têtes de section:  %d (octet)", reverse_2(header.e_shnum));
    printf("\n");

    printf("Table d'indexes des chaînes d'en-tête de section: %d", reverse_2(header.e_shstrndx));
    printf("\n");
}

void afficher_table_sections(Elf32_Shdr sections, Elf32_Ehdr header, FILE * input)
{   
    uint32_t idx;
    char *SectNames;
    SectNames = malloc(sections.sh_size);

    fseek(input, sections.sh_offset, SEEK_SET);
    fread(SectNames, 1, sections.sh_size, input);

    // read all section headers
    for (idx = 0; idx < header.e_shnum; idx++)
    {
        const char *name = "";

        fseek(input, header.e_shoff + idx * sizeof(sections), SEEK_SET);
        fread(&sections, 1, sizeof(sections), input);

        // print section name
        if (sections.sh_name)
            ;
        name = SectNames + sections.sh_name;
        printf("%2u %s\n", idx, name);
    }
}
=======
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
    printf("  [No] Nom                Type         Addr     Deca   Taille ES Flg Ln Inf Al\n");
    for(int i = 0; i < nb_sections; i++){
        //ID
        printf("  [%2d]", i);

        //NOM
        printf(" %-18s", &str_table[reverse_4(shdr_table[i].sh_name)]);

        //TYPE
        int type = reverse_4(shdr_table[i].sh_type);
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
        printf(" %8.8x", reverse_4(shdr_table[i].sh_addr));

        // OFFSET
        printf(" %6.6x", reverse_4(shdr_table[i].sh_offset));

        // TAILLE
        printf(" %6.6x", reverse_4(shdr_table[i].sh_size));

        // TAILLE D'UNE ENTREE
        printf(" %2.2x", reverse_4(shdr_table[i].sh_entsize));

        // FLAGS
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

        // LINK
        printf(" %2d", reverse_4(shdr_table[i].sh_link));

        // INFO
        printf(" %3d", reverse_4(shdr_table[i].sh_info));

        // ADDR ALIGN
        printf(" %2d", reverse_4(shdr_table[i].sh_addralign));

        printf("\n");
    }
    printf("Key to Flags:\n\tW (write), A (alloc), X (execute), M (merge), S (strings), I (info),\n\tL (link order), O (extra OS processing required), G (group), T (TLS), \n\tC (compressed), x (unknown), o (OS specific), E (exclude),\n\ty (purecode), p (processor specific)\n");
}

void print_section_data(Elf32_Shdr* shdr_table, char* str_table, uint8_t** sections_data, size_t num){
    uint8_t* section_data = sections_data[num];
    size_t size = reverse_4(shdr_table[num].sh_size);
    char* section_name = &str_table[reverse_4(shdr_table[num].sh_name)];
    if(size > 0) {
        int width = 4;
        int height = size/(4*width);
        int line_length = (size*2) % (width*8);
        int width_to_complete = width*8 + width - line_length - line_length/8;
        printf("Dump hexadécimal de la section '%s':\n", section_name);
        for(int i = 0; i <= height; i+=1){
            // HEXA
            printf("  0x%.8x ", i*16);
            for(int j = 0; (j < width*4) & ((i*width*4)+j < size); j+=4){
                if((i*width*4)+j < size)
                    printf("%.2x",section_data[(i*width*4)+j]);
                if((i*width*4)+j+1 < size)         
                    printf("%.2x",section_data[(i*width*4)+(j+1)]);
                if((i*width*4)+j+2 < size)
                    printf("%.2x",section_data[(i*width*4)+(j+2)]);
                if((i*width*4)+j+3 < size)
                    printf("%.2x ",section_data[(i*width*4)+(j+3)]);
            }
            if(i == size/(4*width))
                printf("%*s", width_to_complete, "");
            // ASCI
            for(int j = 0; (j < width*4) & ((i*width*4)+j < size); j++){
                if(isprint(section_data[(i*width*4)+j]))
                    printf("%c", section_data[(i*width*4)+j]);
                else
                    printf(".");
            }
            printf("\n");
        }
    } else {
        printf("Section '%s' n'a pas de donnée à dump.", section_name);
    }
    printf("\n");
}
>>>>>>> 864bcc83a3e694dd6872ebd82fc91173eb76bae9
