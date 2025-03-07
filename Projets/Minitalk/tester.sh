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
	./client $SERVER_PID " Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis eget sagittis quam, non tincidunt diam. Phasellus aliquet hendrerit velit, eget porttitor magna maximus nec. Quisque sed faucibus arcu. Pellentesque rhoncus ultricies tincidunt. Nunc eu condimentum mauris, at suscipit dui. Phasellus faucibus magna ut metus vestibulum, eget ornare dui imperdiet. In faucibus auctor nisi, dapibus malesuada sapien finibus varius. Quisque pretium erat velit, vitae bibendum metus hendrerit nec. Suspendisse congue scelerisque enim, a cursus enim rutrum in. Nunc malesuada sem et semper pharetra. Vestibulum magna ipsum, lobortis a orci a, euismod ornare nibh. Sed id varius nibh. Donec vitae scelerisque libero, rhoncus cursus est. Integer laoreet ipsum in risus lobortis maximus.

Duis at congue metus. Mauris sed augue a urna placerat congue. Curabitur ut sem id nisi suscipit suscipit. Sed elementum gravida eros, ac mattis augue porttitor id. In porttitor augue sed ante pharetra ornare. Maecenas dictum congue volutpat. Nunc metus velit, imperdiet sit amet posuere non, imperdiet a enim. In a orci nunc. Curabitur tempor tempus dui, non facilisis nibh egestas vel. Mauris velit purus, cursus non nunc in, finibus venenatis purus. Nunc dapibus malesuada placerat. Suspendisse ullamcorper laoreet tortor nec rhoncus. Sed a pulvinar risus. Cras finibus nulla non elit varius hendrerit. Vestibulum mattis risus augue, ac ullamcorper ante semper eu. Nullam a odio sit amet arcu lobortis imperdiet vitae et lacus.

Etiam ultricies tristique ex, id mollis mi. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean eget nisi scelerisque, laoreet nisi ut, euismod lacus. Sed accumsan urna non eleifend gravida. Curabitur imperdiet lacus vel fringilla feugiat. Nam scelerisque sodales odio id tristique. Ut gravida, leo lacinia ornare luctus, erat sapien finibus diam, sit amet viverra magna sapien vitae magna. In ullamcorper vitae sem sed auctor. Mauris dignissim sapien a dui tempor, et pharetra ante commodo. Nulla auctor orci nec fermentum viverra. Aenean at tristique turpis, vel pretium elit. Phasellus vitae elementum leo, nec pretium quam. Praesent eu ex vitae ipsum accumsan pretium vel eu ligula. Sed placerat, justo id ultrices faucibus, enim sapien bibendum ligula, nec facilisis velit enim ut arcu. In tincidunt hendrerit pulvinar. Praesent vestibulum blandit augue, sed posuere massa malesuada vitae.

Mauris euismod purus et justo placerat, ut pulvinar justo fringilla. Cras sed ligula eu sapien consequat facilisis. Suspendisse suscipit porta diam, ut vulputate leo auctor et. Sed tempor tellus nec vestibulum faucibus. Cras pretium et metus in pretium. Fusce sodales erat non lorem posuere mattis. Suspendisse odio velit, laoreet sed nisl non, iaculis cursus sem. Aliquam et suscipit tortor. Curabitur at nunc nisl. Duis quis lectus pretium, suscipit mauris ut, pretium lorem.

Curabitur quis molestie felis, ut fermentum neque. Pellentesque eu bibendum mi. In quis dui vitae erat commodo pulvinar. Vivamus at semper justo. Donec interdum, augue vel egestas gravida, mauris mauris tempus tellus, ut elementum quam leo vitae mauris. Phasellus sed bibendum urna, at viverra nisi. Nulla imperdiet, arcu eget hendrerit maximus, enim massa fringilla mauris, eu sodales neque ex non erat. Curabitur sollicitudin nisi dictum, lobortis augue sit amet, maximus ligula. Pellentesque consectetur nulla dapibus cursus placerat. Duis lobortis, ligula id volutpat lobortis, turpis nibh consequat diam, non tincidunt erat tellus ac erat.

Nam at sem tempus, fringilla sem eget, mollis tortor. In enim mi, malesuada at porttitor scelerisque, sodales sit amet purus. Cras euismod, ante sit amet tempus blandit, nisi diam rhoncus est, eget tincidunt ex purus vel erat. Ut quis ultrices neque. Duis ultricies, turpis mollis convallis elementum, felis lacus placerat metus, eget congue nunc ligula sit amet mi. Nunc placerat sit amet ante eget eleifend. Mauris feugiat leo in lacus rhoncus, a mattis ante cursus. Proin imperdiet justo ut dolor viverra faucibus sed et nunc. Suspendisse vel placerat mi, in aliquam dui. Sed euismod laoreet fermentum. Praesent facilisis dolor in leo ullamcorper, sed tincidunt ex sollicitudin. Pellentesque volutpat faucibus nisl, in interdum diam fringilla at. Nam nisi turpis, luctus sit amet ipsum vitae, lacinia condimentum enim. Proin ut neque vehicula, pretium est eu, aliquam magna.

Nullam tempor, ex vel consequat auctor, lacus turpis rhoncus elit, eget maximus metus nibh eget eros. Nunc a nisl aliquam, aliquam justo et, fringilla mauris. Praesent lobortis placerat aliquam. Aenean eu mauris sapien. Aliquam non metus a risus malesuada tempus. Phasellus efficitur, nunc et tempus malesuada, metus ipsum facilisis ipsum, non porttitor lectus neque ac nisl. Pellentesque sollicitudin blandit purus non maximus. Integer at dui dui.

Etiam tempus pellentesque tortor quis feugiat. Sed ut orci sit amet eros dictum ullamcorper. Aliquam sed sodales est. Ut erat felis, tristique vitae sapien eu, semper malesuada est. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Vivamus ac ipsum a magna ornare tristique. Phasellus laoreet euismod semper. Quisque magna est, malesuada a facilisis a, ultricies sit amet tellus. Nullam pharetra eleifend aliquam. Cras volutpat euismod fermentum. Nullam in bibendum tellus, sed ullamcorper lectus.

Nam pellentesque enim orci. Suspendisse cursus ante non urna viverra dictum. Donec condimentum, velit a tincidunt pretium, nisl orci laoreet nulla, id tempor nisi ipsum eu justo. Morbi convallis nunc eget commodo tincidunt. Cras blandit pretium tellus nec sodales. Etiam erat risus, dapibus eget tincidunt ut, auctor at magna. Ut fermentum arcu sed velit consequat faucibus. Phasellus in nibh ornare, molestie mi ut, semper enim.

Cras vel velit tempor mauris ornare interdum. Duis mauris mauris, feugiat a tristique et, aliquet eget libero. Maecenas ut massa ac neque tempor ultrices a condimentum lorem. Integer at efficitur purus. In lacus velit, lobortis eget eros sit amet, vestibulum gravida sem. Sed vel interdum dui, scelerisque pulvinar libero. Suspendisse iaculis nulla a accumsan molestie.

Aenean vitae magna tellus. Aliquam et ex eu ipsum fermentum rhoncus ac et ex. Nullam non est et ante mollis mattis. Nullam vitae lorem pulvinar, semper felis vel, ullamcorper justo. Nam volutpat euismod gravida. Curabitur euismod massa ac felis feugiat pharetra. In dictum molestie quam vel iaculis. Nunc elementum urna mollis ligula tincidunt, auctor suscipit nisl vehicula. Nam feugiat lacus sit amet ultrices scelerisque. In molestie semper mi, at aliquam elit. Fusce orci enim, pellentesque non porta vel, ultrices vel arcu. Maecenas eleifend auctor risus, sit amet dictum eros dapibus ac. Aliquam nec aliquet ex. Phasellus et nisl ultrices, ultricies tortor et, facilisis nisi. Phasellus eu dolor lorem. Vivamus molestie ante eget augue auctor, a condimentum velit scelerisque.

Donec viverra nulla quis nibh mollis dignissim. Vestibulum vitae egestas felis. Nullam vitae blandit erat. Nullam a hendrerit diam. Suspendisse iaculis aliquam laoreet. Ut eleifend lorem et ultricies pellentesque. Pellentesque consequat ante in convallis tempus. Morbi elit enim, commodo a ex at, euismod euismod est. Curabitur blandit nec dui vel commodo. Curabitur lobortis, elit nec pretium tristique, ipsum augue euismod risus, auctor sollicitudin odio urna ut erat. Vivamus eu fringilla felis, vel ornare risus. Phasellus venenatis ullamcorper dignissim. Praesent rhoncus maximus nunc. Etiam commodo neque eu volutpat elementum. In finibus at massa vel ullamcorper. Integer nulla urna, faucibus nec massa ut, pharetra aliquam turpis.

Quisque ac molestie nisl. In volutpat condimentum faucibus. In hac habitasse platea dictumst. Vivamus vulputate lobortis lectus non luctus. Sed ligula ante, suscipit a euismod vitae, hendrerit non turpis. Cras pellentesque et tortor ut dignissim. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Praesent nulla tortor, gravida sed eleifend a, egestas a lectus. Maecenas suscipit velit sit amet lacinia tempor.

Cras ut magna scelerisque, efficitur odio nec, gravida eros. Cras sem ex, ultricies eu tempus at, sodales id libero. Cras aliquam massa at gravida sollicitudin. Duis ut finibus arcu. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut at pharetra nunc. Pellentesque egestas congue sollicitudin. In feugiat molestie sollicitudin. Sed ut felis rhoncus nunc tempor vulputate. Maecenas feugiat venenatis mauris laoreet dignissim. Aenean luctus neque id erat interdum faucibus. Pellentesque sodales risus ut vestibulum laoreet. Pellentesque gravida urna nec auctor finibus. Morbi vitae interdum libero. Etiam nec massa vitae elit semper viverra nec eget quam.

Fusce at mauris rutrum, condimentum enim vitae, eleifend eros. Donec nisi magna, euismod eget mi sollicitudin, pulvinar scelerisque purus. Suspendisse tristique quam ut hendrerit dapibus. Curabitur facilisis erat ut nisi tincidunt, quis efficitur arcu vestibulum. Fusce vel varius nulla. Sed vestibulum eleifend neque eget vulputate. Cras tincidunt commodo finibus. Curabitur fermentum, velit varius viverra mattis, felis sem condimentum dui, at cursus diam est eu arcu. Nullam elementum fermentum blandit. Phasellus lacinia lacus sit amet enim ultrices, nec posuere mi ultricies. Pellentesque tempor, nunc vestibulum ullamcorper fringilla, risus quam ultrices neque, bibendum dapibus nibh tortor sit amet mi. Duis auctor, velit ac tincidunt porttitor, diam eros maximus metus, nec fermentum ante mauris vitae tellus. Etiam ac tortor quam. Duis quis nisi ultrices, malesuada urna ac, pharetra turpis.

Donec vel nibh ante. Sed pharetra dolor ac odio sagittis, ut interdum ligula malesuada. Vestibulum at consectetur nisl. Phasellus risus erat, vestibulum et laoreet pretium, hendrerit non felis. Morbi maximus, enim sit amet dignissim tempus, leo tortor sollicitudin lectus, nec egestas sem magna non nisi. Etiam volutpat dictum quam id malesuada. Vestibulum a mauris vel orci blandit volutpat varius sed nisi. Duis at odio tincidunt, convallis orci vel, convallis arcu. Duis consequat id orci sit amet pretium. Praesent sagittis neque orci, non egestas enim tristique vitae. Maecenas pulvinar justo a turpis efficitur auctor ut et felis. Praesent vel faucibus lacus, id malesuada dui. Maecenas malesuada orci vitae neque tempor volutpat.

Etiam sollicitudin accumsan ex, nec euismod purus aliquam a. Curabitur ut erat ligula. In nisl eros, sagittis quis massa in, consequat dictum magna. Pellentesque volutpat nisi vitae felis laoreet congue. Aliquam iaculis lorem quis metus dictum dapibus. Pellentesque et felis quis nisl tempor facilisis. Duis scelerisque dapibus semper. Donec lacinia laoreet dictum. Fusce in nisl aliquet, rutrum enim non, vestibulum magna.

Cras in tincidunt sem. Nunc arcu risus, interdum quis consectetur vitae, tincidunt ac sapien. Ut viverra blandit elit eu tristique. Nam pellentesque porttitor risus eleifend aliquam. Morbi risus ligula, vestibulum vel nisi ac, imperdiet vulputate sem. Nam pharetra tempor diam. Vestibulum ut ante et massa pretium blandit.

Sed auctor pulvinar pellentesque. Duis pharetra posuere interdum. Duis quis euismod augue. Praesent efficitur id purus sit amet commodo. Aliquam quis magna porttitor, eleifend ligula at, consequat enim. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Etiam sollicitudin justo massa, laoreet ornare nibh congue ac. Praesent lacus libero, mollis et ante nec, auctor pulvinar magna. Curabitur est augue, blandit et luctus et, mollis a lectus. Maecenas semper accumsan enim, in egestas ipsum gravida id. Nulla dignissim, leo a euismod vulputate, justo justo malesuada libero, sed volutpat augue nisl a erat. Phasellus enim velit, interdum id laoreet eget, sagittis in ante. Sed ultrices urna maximus pretium venenatis.

In vestibulum enim a enim convallis molestie a id odio. Curabitur quam purus, imperdiet vel nulla sed, scelerisque fermentum orci. Proin odio nunc, commodo eu dui scelerisque, malesuada ullamcorper ipsum. Proin mollis lectus vel justo finibus aliquet. Mauris vel purus accumsan velit ullamcorper interdum eu et purus. Ut in sapien nibh. Proin ac rutrum mi. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec ut lorem nibh. Pellentesque non nulla dignissim, sodales ipsum id, molestie nisl. Praesent vestibulum euismod risus, quis molestie dolor pretium at. Cras vestibulum orci sit amet auctor blandit. Curabitur lobortis, nisi non aliquam scelerisque, sem mi malesuada elit, sed molestie orci arcu nec mauris. "
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
