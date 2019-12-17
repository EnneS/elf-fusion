#include "affichage_elf.h"
#include "util.h"

void lire_header(Elf32_Ehdr header) {
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

    printf("OS/ABI : ");
    switch(header.e_ident[7]) {
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
        default :
            printf("Default");
            break;
    }
    printf("\n");

    printf("Vesrsion ABI: 0x%x",header.e_ident[8]);    
    printf("\n");

    printf("Type : ");
    switch(reverse_2(header.e_type)) {
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
        default :
            printf("Default");
            break;
    }
    printf("\n");

    

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

    printf("Adresse du point d'entrée: 0x%.2x",reverse_4(header.e_entry));    
    printf("\n");

    printf("Début des en-têtes de programme: %d (octet dans le fichier)",reverse_4(header.e_phoff));    
    printf("\n");

    printf("Début des en-têtes de sections: %d (octet dans le fichier)",reverse_4(header.e_shoff));    
    printf("\n");

    printf("Fanions : 0x%x",reverse_4(header.e_flags));    
    printf("\n");


    printf("Taille de cet en-tête : 52 (octet)");    
    printf("\n");

    printf("Taille de l'en-tête du programme: %d (octet)",reverse_2(header.e_phentsize));    
    printf("\n");

    printf("Nombre d'en-tête du programme: %d",reverse_2(header.e_phnum));    
    printf("\n");

    printf("Taille des en-têtes de section: %d (octet)",reverse_2(header.e_shentsize));    
    printf("\n");

    printf("Nombre d'en-têtes de section:  %d (octet)",reverse_2(header.e_shnum));    
    printf("\n");

    printf("Table d'indexes des chaînes d'en-tête de section: %d",reverse_2(header.e_shstrndx));    
    printf("\n");
}