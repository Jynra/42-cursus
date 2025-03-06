#!/bin/bash

# Couleurs pour une meilleure lisibilité
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE="\033[0;34m"
NC='\033[0m' # No Color

# Fonction pour afficher les messages de test
print_header() 
{
    echo -e "\n${BLUE}==== $1 ====${NC}\n"
}

print_test()
{
    echo -e "${YELLOW}[TEST]${NC} $1"
}

# Fonction pour indiquer un succès
print_success()
{
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

# Fonction pour indiquer un échec
print_error()
{
    echo -e "${RED}[ERROR]${NC} $1"
    exit 1
}

# Test de la norme
test_norm()
{
	print_header "TEST DE LA NORME"
	if [ $? -ne 0 ]; then
		echo -e "${YELLOW}⚠ AVERTISSEMENT: norminette n'est pas installée${NC}"
		return
	fi

	echo "Vérification de la norme..."
	NORM_ERRORS=$(norminette src includes/minitalk.h | grep -E "Error|Warning" | wc -l)

	if [ $NORM_ERRORS -eq 0 ]; then
		echo -e "${GREEN}✓ Code conforme à la norme${NC}"
	else
		echo -e "${RED}✗ $NORM_ERRORS erreurs de norme trouvées${NC}"
		norminette src includes/minitalk.h | grep -E "Error|Warning"
	fi
}

# Compilation en arrière-plan
test_compilation()
{
	print_header "Compilation du projet..."
	make re > /dev/null 2>&1
	if [ $? -ne 0 ]; then
		print_error "Échec de la compilation"
	fi
	print_success "Compilation réussie"
}

# Lancer le serveur en arrière-plan
server_launch()
{
	print_header "Lancement du serveur..."
	./server &
	SERVER_PID=$!

	# Attendre que le serveur soit prêt
	sleep 1

	# Tests avec différents types de messages
	print_test "Test avec un message court..."
	./client $SERVER_PID "Hello, world !"
	sleep 1

	print_test "Test avec un message long..."
	./client $SERVER_PID "Ce message est plus long pour tester la performance du programme avec des messages de taille conséquente. On veut s'assurer que tout fonctionne correctement, même avec un grand nombre de caractères."
	sleep 1

	print_test "Test avec un message tres long..."
	./client $SERVER_PID "Take my love, take my land Take me where I cannot stand I don’t care, I’m still free You can’t take the sky from me.Take me out to the black Tell them I ain’t comin’ back Burn the land and boil the sea You can’t take the sky from me. Leave the men where they lay They’ll never see another day Lost my soul, lost my dream You can’t take the sky from me. I feel the black reaching out I hear its song without a doubt I still hear and I still see That you can’t take the sky from me. Lost my love, lost my land Lost the last place I could stand There’s no place I can be Since I’ve found Serenity And you can’t take the sky from me."
	sleep 1

	print_test "Test avec des caractères spéciaux..."
	./client $SERVER_PID "!@#$%^&*()_+{}|:<>?~"
	sleep 1

	print_test "Test avec les chiffres et les lettres..."
	./client $SERVER_PID "0123456789 abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	sleep 1

	print_test "Test avec des espaces multiples..."
	./client $SERVER_PID "Ceci    est    un    test    avec    des    espaces    multiples"
	sleep 1

	# Test avec un syntaxe invalide
	print_test "Test avec une syntaxe invalide..."
	./client $SERVER_PID
	EXIT_CODE=$?
	if [ $EXIT_CODE -eq 0 ]; then
		echo -e "${RED}[ERROR]${NC} La syntaxe est correct\n"
	else
		print_success "La syntaxe du message est incorrect\n"
	fi
	sleep 1

	# Test avec un PID invalide
	INVALID_PID=99999
	print_test "Test avec un PID invalide..."
	echo -e "PID utiliser $INVALID_PID"
	echo -e "PID server $SERVER_PID"
	./client $INVALID_PID "Ce message ne devrait pas être envoyé"
	EXIT_CODE=$?
	if [ $EXIT_CODE -eq 0 ]; then
		echo -e "${RED}[ERROR]${NC} Le client n'a pas détecté de PID invalide"
	else
		print_success "Le client a bien détecté le PID invalide"
	fi
	sleep 1
}

# Test avec Valgrind pour vérifier les fuites mémoire
test_valgrind()
{
	print_header "Test de fuite mémoire avec Valgrind..."
	# Vérifier si Valgrind est installé
	if ! command -v valgrind &> /dev/null; then
		echo -e "${YELLOW}[WARNING]${NC} Valgrind n'est pas installé. Test de fuite mémoire ignoré."
	else
		# Lancer le serveur avec Valgrind
		print_test "Lancement du serveur avec Valgrind..."
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_server.log ./server &
		SERVER_VALGRIND_PID=$!
		
		# Attendre que le serveur soit prêt
		sleep 2
		
		# Envoyer un message court
		print_test "Envoi d'un message au serveur sous Valgrind..."
		./client $SERVER_VALGRIND_PID "Test Valgrind"
		sleep 1
		
		# Tuer le serveur
		print_test "Arrêt du serveur sous Valgrind..."
		kill $SERVER_VALGRIND_PID
		sleep 1
		
		# Vérifier les résultats
		if grep -q "ERROR SUMMARY: 0 errors" valgrind_server.log && grep -q "All heap blocks were freed -- no leaks are possible" valgrind_server.log; then
			print_success "Le serveur ne présente pas de fuites mémoire ou d'erreurs a la fermeture"
		else
			echo -e "${RED}[ERROR]${NC} Des problèmes ont été détectés par Valgrind. Consultez le fichier valgrind_server.log pour plus de détails."
		fi
		
		# Test similaire pour le client
		print_test "Test du client avec Valgrind..."
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_client.log ./client $SERVER_PID "Test Valgrind Client" &
		sleep 1
		
		# Vérifier les résultats
		if grep -q "ERROR SUMMARY: 0 errors" valgrind_client.log && grep -q "All heap blocks were freed -- no leaks are possible" valgrind_client.log; then
			print_success "Le client ne présente pas de fuites mémoire ou d'erreurs."
		else
			echo -e "${RED}[ERROR]${NC} Des problèmes ont été détectés par Valgrind. Consultez le fichier valgrind_client.log pour plus de détails."
		fi
	fi
	rm valgrind_client.log valgrind_server.log
}

# Tuer le serveur à la fin des tests
kill_server()
{
	print_header "Arrêt du serveur..."
	kill $SERVER_PID > /dev/null 2>&1
	print_success "Server shutdown"

	# Nettoyage
	print_header "Nettoyage..."
	make fclean > /dev/null 2>&1
	if [ $? -ne 0 ]; then
		print_error "Échec du nettoyage"
	fi
	print_success "Nettoyage terminé\n"
}

# Execution
test_norm
test_compilation
server_launch
test_valgrind
kill_server

print_header "RÉSUMÉ DES TESTS"
echo -e "Tous les tests sont terminés."
echo -e "✅ Vérifiez les résultats ci-dessus pour vous assurer que tout est conforme."

exit 0
