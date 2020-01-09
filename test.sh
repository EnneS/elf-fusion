#FONCTION TRIM PERMET DE RETIRER LES ESPACES EN DEBUT ET EN FIN DE CHAINE DE CARACTERE SOURCE : https://stackoverflow.com/questions/369758/how-to-trim-whitespace-from-a-bash-variable
trim() {
    local var="$*"
    # remove leading whitespace characters
    var="${var#"${var%%[![:space:]]*}"}"
    # remove trailing whitespace characters
    var="${var%"${var##*[![:space:]]}"}"   
    echo -n "$var"
}

#ON TESTE LES DIFFERENCES POUR CHAQUE FICHIERS TESTE .O PRESENT DANS EXEMPLES_LOADER
for file in Examples_loader/*.o
do

    echo "/************** Debut teste sur le fichier $file *******************/"

    echo "/************** Debut teste arm-eabi-readelf -h *******************/"
    echo " "

    #ON EXECUTE ARM-EABI-READELF AFIN DE LE COMPARER A NOTRE AFFICHAGE
    texte=$(arm-none-eabi-readelf -h $file)
    # SAUVEGARDE DE IFS
    OLD_IFS=$IFS
    IFS=$'\n'
    idx=0
    for line in $texte
    do 
        line=$(echo $line | cut -d: -f2)

        #ON REGARDE LA LIGNE A L'AQUELLE ON EST
        if [ $idx -eq 1 ] 
        then 
            magic=$(trim $line)
        elif [ $idx -eq 2 ] 
        then
            class=$(trim $line)
        elif [ $idx -eq 3 ] 
        then
            data=$(trim $line)
        elif [ $idx -eq 4 ] 
        then
            version=$(trim $line)
        elif [ $idx -eq 5 ] 
        then
            os=$(trim $line)
        elif [ $idx -eq 6 ] 
        then
            abi=$(trim $line)
        elif [ $idx -eq 7 ] 
        then
            type=$(trim $line)
            type=$(echo $type | cut -d' ' -f1)
        elif [ $idx -eq 8 ] 
        then
            machine=$(trim $line)
        elif [ $idx -eq 9 ] 
        then
            versionHexa=$(trim $line)
        elif [ $idx -eq 10 ] 
        then
            entry=$(trim $line)
        elif [ $idx -eq 11 ] 
        then
            stProgramHeader=$(trim $line)
            stProgramHeader=$(echo $stProgramHeader | cut -d' ' -f1)
        elif [ $idx -eq 12 ] 
        then
            stSectionHeader=$(trim $line | cut -d' ' -f1)
        elif [ $idx -eq 13 ] 
        then
            flags=$(trim $line)
            flags=$(echo $flags | cut -d, -f1)
        elif [ $idx -eq 14 ] 
        then
            szHeader=$(trim $line | cut -d' ' -f1)
        elif [ $idx -eq 15 ] 
        then
            szProgramHeader=$(trim $line)
            szProgramHeader=$(echo  $szProgramHeader | cut -d' ' -f1)  
        elif [ $idx -eq 16 ] 
        then
            nbProgramHeader=$(trim $line | cut -d' ' -f1)
        elif [ $idx -eq 17 ] 
        then
            szSectionHeader=$(trim $line)
            szSectionHeader=$(echo $szSectionHeader | cut -d' ' -f1 )
        elif [ $idx -eq 18 ] 
        then
            nbSectionHeader=$(trim $line)
        elif [ $idx -eq 19 ] 
        then
            idxStringTable=$(trim $line)
        fi
        idx=$((idx + 1))
    done

    #ON EXECUTE NOTRE AFFICHAGE  AFIN DE LE COMPARER AU VARIABLE STOCKER DE ARM-EABI-READELF
    texte=$(./affichage_executable -h $file)
    idx=0
    for line in $texte
    do 
        line=$(echo $line | cut -d: -f2)
        line=$(trim $line)
        #ON REGARDE LA LIGNE A L'AQUELLE ON EST
        if [ $idx -eq 1 ] 
        then 
            if [ $magic != $line ]
            then 
                echo "Différence sur Magique :'"$magic"' '"$line"'"
            fi
        elif [ $idx -eq 2 ] 
        then
            if [ $class != $line ]
            then 
                echo "Différence sur Classe :'"$class"' '"$line"'"
            fi
        elif [ $idx -eq 3 ] 
        then
            if [ $data != $line ]
            then 
                echo "Différence sur données :'"$data"' '"$line"'"
            fi
        # elif [ $idx -eq 4 ] 
        # then
        #     version=$line
        elif [ $idx -eq 4 ] 
        then
            if [ $os != $line ]
            then 
                echo "Différence sur OS/ABI :'"$os"' '"$line"'"
            fi
        elif [ $idx -eq 5 ] 
        then
            if [ $versionHexa != $line ]
            then 
                echo "Différence sur Version :'"$versionHexa"' '"$line"'"
            fi
        elif [ $idx -eq 6 ] 
        then
            if [ $type != $line ]
            then 
                echo "Différence sur Type :'"$type"' '"$line"'"
            fi
        elif [ $idx -eq 7 ] 
        then
            if [ "$version" != $line ]
            then 
                echo "Différence sur Version :'"$version"' '"$line"'"
            fi
        elif [ $idx -eq 8 ] 
        then
            if [ $entry != $line ]
            then 
                echo "Différence sur adresse point entré :'"$entry"' '"$line"'"
            fi
        elif [ $idx -eq 9 ] 
        then
            line=$(echo $line | cut -d' ' -f1)
            if [ $stProgramHeader != $line ]
            then 
                echo "Différence sur début en-tête de programme :'"$stProgramHeader"' '"$line"'"
            fi
        elif [ $idx -eq 10 ] 
        then
            line=$(echo $line | cut -d' ' -f1)
            if [ $stSectionHeader != $line ]
            then 
                echo "Différence sur début en-tête de section :'"$stSectionHeader"' '"$line"'"
            fi
        elif [ $idx -eq 11 ] 
        then
            if [ $flags != $line ]
            then 
                echo "Différence sur fanions :'"$flags"' '"$line"'"
            fi
        elif [ $idx -eq 12 ] 
        then
            line=$(echo $line | cut -d' ' -f1)
            if [ $szHeader != $line ]
            then 
                echo "Différence sur taille de cet en-tête :'"$szHeader"' '"$line"'"
            fi
        elif [ $idx -eq 13 ] 
        then
            line=$(echo $line | cut -d' ' -f1)
            if [ $szProgramHeader != $line ]
            then 
                echo "Différence sur taille en-tête de programme :'"$szProgramHeader"' '"$line"'"
            fi
        elif [ $idx -eq 14 ] 
        then
            if [ $nbProgramHeader != $line ]
            then 
                echo "Différence sur nombre en-tête de programme :'"$nbProgramHeader"' '"$line"'"
            fi
        elif [ $idx -eq 15 ] 
        then
            line=$(echo $line | cut -d' ' -f1)
            if [ $szSectionHeader != $line ]
            then 
                echo "Différence sur taille des en-tête de section :'"$szSectionHeader"' '"$line"'"
            fi
        elif [ $idx -eq 16 ] 
        then
            if [ $nbSectionHeader != $(echo $line | cut -d' ' -f1) ]
            then 
                echo "Différence sur nombre d'en-tête de section :"$nbSectionHeader"' '"$(echo $line | cut -d' ' -f1)"'"
            fi
        elif [ $idx -eq 17 ] 
        then
            if [ "$idxStringTable" != $line ]
            then 
                echo "Différence sur index table des chaines :'"$idxStringTable"' '"$line"'"
            fi
        fi
        idx=$((idx + 1))
    done


    #ON RESTAURE IFS
    IFS=$OLD_IFS

    echo " "
    echo "/************** Debut teste arm-eabi-readelf -x *******************/"
    echo " "

    i=0

    #ON EXECUTE UNE COMPARAISON SUR CHAQUE SECTION AVEC L'OPTION -X DE READELF
    while [ $i -lt $nbSectionHeader ]
    do

        texte=$(arm-none-eabi-readelf -x $i $file)
        texteCut=$(echo $texte | cut -d':' -f2)
        #L'AFFICHAGE DE ARM-EABI PRODUIT PARFOIS UNE NOTE QUE NOTRE AFFICHAGE NE PRODUIT PAS, ON VERIFIE S'IL ELLE Y EST ET ON LA RETIRE SI C'EST LE CAS
        if [ "$texteCut" == " NOTE" ] 
        then 
            texteCut=$(echo $texte | sed "s/NOTE: This section has relocations against it, but these have NOT been applied to this dump.//g")
            texteCut=$(echo $texteCut | cut -d':' -f2)
        fi
        
        texte2=$(./affichage_executable -x $file $i)
        texte2=$(echo $texte2 | cut -d':' -f2)

        if [ "$texte2" != "$texteCut" ]
        then
            echo " "
            echo "/**************** Section $i *************************/"
            echo "Différence d'affichage"
            echo "texte arm-eabi-readelf :"
            echo $texteCut
            echo "texte programme :"
            echo $texte2
        fi
        i=$((i+1))
    done
    echo " "
done




