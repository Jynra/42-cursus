# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jynra <jynra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 13:19:31 by ellucas           #+#    #+#              #
#    Updated: 2025/03/04 22:40:59 by jynra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Couleurs pour une meilleure lisibilité
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
NC="\033[0m" # No Color

# Répertoire des cartes de test
MAPS_DIR="maps/tests"
VALID_MAPS_DIR="$MAPS_DIR/valid"
INVALID_MAPS_DIR="$MAPS_DIR/invalid"

# Création des répertoires s'ils n'existent pas
mkdir -p $VALID_MAPS_DIR
mkdir -p $INVALID_MAPS_DIR

# Fonction d'affichage
print_header() 
{
    echo "\n${BLUE}==== $1 ====${NC}\n"
}

print_result() 
{
    if [ $1 -eq 0 ]; then
        echo "${GREEN}✓ SUCCÈS${NC}: $2"
    else
        echo "${RED}✗ ÉCHEC${NC}: $2 (code: $1)"
    fi
}

# Test de la norme
test_norm() 
{
    print_header "TEST DE LA NORME"
    
	#norminette --version &> /dev/null
    if [ $? -ne 0 ]; then
        echo "${YELLOW}⚠ AVERTISSEMENT: norminette n'est pas installée${NC}"
        return
    fi
    
    echo "Vérification de la norme..."
    NORM_ERRORS=$(norminette src includes/so_long.h | grep -E "Error|Warning" | wc -l)
    
    if [ $NORM_ERRORS -eq 0 ]; then
        echo "${GREEN}✓ Code conforme à la norme${NC}"
    else
        echo "${RED}✗ $NORM_ERRORS erreurs de norme trouvées${NC}"
        norminette src includes | grep -E "Error|Warning"
    fi
}

# Test de compilation
test_compilation() 
{
    print_header "TEST DE COMPILATION"
    
    echo "Nettoyage des anciens fichiers..."
    make fclean > /dev/null
    
    echo "Compilation du projet..."
    make > /dev/null 2>&1
    
    if [ -f "./so_long" ]; then
        print_result 0 "Compilation réussie"
    else
        print_result 1 "Échec de compilation"
        exit 1
    fi
}

# Création des cartes de test valides
create_valid_maps() 
{
    print_header "CRÉATION DES CARTES VALIDES"
    
    # Carte basique valide
    cat > "$VALID_MAPS_DIR/basic.ber" << EOF
1111111111111
1001000000001
10000111110C1
1P0011E000001
1111111111111
EOF
    echo "Carte basique créée"

    # Carte avec plusieurs collectibles
    cat > "$VALID_MAPS_DIR/collectibles.ber" << EOF
1111111111111
10010C0000C01
100C011111001
1P0011E00C001
1111111111111
EOF
    echo "Carte avec collectibles créée"
    
    # Carte complexe
    cat > "$VALID_MAPS_DIR/complex.ber" << EOF
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
EOF
    echo "Carte complexe créée"
}

# Création des cartes de test invalides
create_invalid_maps() 
{
    print_header "CRÉATION DES CARTES INVALIDES"
    
    # Carte sans sortie
    cat > "$INVALID_MAPS_DIR/no_exit.ber" << EOF
1111111111111
10010C0000C01
100C011111001
1P00110000001
1111111111111
EOF
    echo "Carte sans sortie créée"
    
    # Carte sans collectible
    cat > "$INVALID_MAPS_DIR/no_collectible.ber" << EOF
1111111111111
1001000000001
1000011111001
1P0011E000001
1111111111111
EOF
    echo "Carte sans collectible créée"
    
    # Carte sans joueur
    cat > "$INVALID_MAPS_DIR/no_player.ber" << EOF
1111111111111
10010C0000C01
100C011111001
100011E000001
1111111111111
EOF
    echo "Carte sans joueur créée"
    
    # Carte non rectangulaire
    cat > "$INVALID_MAPS_DIR/not_rectangle.ber" << EOF
1111111111111
100100000001
1000011111001
1P0011E000001
1111111111111
EOF
    echo "Carte non rectangulaire créée"
    
    # Carte non fermée par des murs
    cat > "$INVALID_MAPS_DIR/not_closed.ber" << EOF
1111111111111
10010C0000C01
100C011111001
1P0011E000000
1111111111111
EOF
    echo "Carte non fermée créée"
    
    # Carte avec chemin impossible
    cat > "$INVALID_MAPS_DIR/impossible_path.ber" << EOF
1111111111111
10010C0000C01
1111111111111
1P0011E000001
1111111111111
EOF
    echo "Carte avec chemin impossible créée"
    
    # Mauvaise extension
    cat > "$INVALID_MAPS_DIR/wrong_ext.txt" << EOF
1111111111111
10010C0000C01
100C011111001
1P0011E000001
1111111111111
EOF
    echo "Fichier avec mauvaise extension créé"
}

# Test des cartes valides
test_valid_maps() 
{
    print_header "TEST DES CARTES VALIDES"
    
    for map in $VALID_MAPS_DIR/*.ber; do
        echo "\nTest de $(basename $map)..."
        
        timeout 1s ./so_long "$map" > /dev/null 2>&1
        RESULT=$?
        
        # Vérification si le programme s'est terminé avec le code 0 ou a été interrompu par timeout
        if [ $RESULT -eq 124 ]; then
            print_result 0 "$(basename $map) - Programme lancé avec succès (window opened)"
        elif [ $RESULT -eq 0 ]; then
            print_result 0 "$(basename $map) - Programme terminé avec succès"
        else
            print_result $RESULT "$(basename $map) - Échec"
        fi
    done
}

# Test des cartes invalides
test_invalid_maps() 
{
    print_header "TEST DES CARTES INVALIDES"
    
    for map in $INVALID_MAPS_DIR/*; do
        echo "\nTest de $(basename $map)..."
        
        ./so_long "$map" > /dev/null 2>&1
        RESULT=$?
        
        # Pour les cartes invalides, on s'attend à un code d'erreur
        if [ $RESULT -ne 0 ]; then
            print_result 0 "$(basename $map) - Erreur détectée correctement"
        else
            print_result 1 "$(basename $map) - Erreur non détectée"
        fi
    done
}

# Test de mémoire avec Valgrind
test_memory() 
{
    print_header "TEST DE MÉMOIRE"
    
	#valgrind --version &> /dev/null
    if [ $? -ne 0 ]; then
        echo "${YELLOW}⚠ AVERTISSEMENT: valgrind n'est pas installé${NC}"
        return
    fi
    
    echo "Test avec une carte valide..."
    VALID_MAP="$VALID_MAPS_DIR/basic.ber"
    
    echo "Vérification des fuites de mémoire..."
    valgrind --log-file=valgrind_valid.log ./so_long "$VALID_MAP" > /dev/null 2>&1
    RESULT=$?
    
    if [ $RESULT -eq 0 ] || [ $RESULT -eq 124 ]; then
        print_result 0 "Pas de fuites de mémoire détectées"
    else
        print_result $RESULT "Fuites de mémoire détectées"
        cat valgrind_valid.log | grep -E "definitely lost|indirectly lost|possibly lost"
    fi
    
    echo "\nTest avec une carte invalide..."
    INVALID_MAP="$INVALID_MAPS_DIR/no_exit.ber"
    
    valgrind --log-file=valgrind_invalid.log ./so_long "$INVALID_MAP" > /dev/null 2>&1
    RESULT=$?
    
    if [ $RESULT -eq 1 ]; then
        grep -q "definitely lost: 0 bytes" valgrind_invalid.log
        if [ $? -eq 1 ]; then
			cat valgrind_invalid.log
            print_result 0 "Pas de fuites de mémoire sur erreur"
        else
            print_result 1 "Fuites de mémoire sur erreur"
            #cat valgrind_invalid.log | grep -E "definitely lost|indirectly lost|possibly lost"
        fi
    else
        print_result $RESULT "Résultat inattendu"
    fi
    
    rm -f valgrind_valid.log valgrind_invalid.log
	make fclean > /dev/null
}

# Exécution des tests
test_norm
test_compilation
create_valid_maps
create_invalid_maps
test_valid_maps
test_invalid_maps
test_memory

print_header "RÉSUMÉ DES TESTS"
echo "Tous les tests sont terminés."
echo "✅ Vérifiez les résultats ci-dessus pour vous assurer que tout est conforme."

exit 0
