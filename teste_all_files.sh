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
    ./teste_one_file.sh $file
done