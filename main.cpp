#include <iostream>
#include <fstream>
#include <memory>
#include "algo.h"

void execute() {
    int mode;
    std::string nomFichierIn;
    Terrain terrainCourant{};

    // Demander le nom du fichier contenant le labyrinthe
    std::cout << "Attention : les labyrinthes que vous entrez doivent impérativement être muni d'une entrée et d'une sortie ACCESSIBLE!" << std::endl;
    std::cout << "Entrez le nom du fichier contenant le labyrinthe : " << std::endl;
    std::cin >> nomFichierIn;

    // Charger le terrain depuis le fichier
    try {
        terrainCourant.chargerDepuisFichier(nomFichierIn);
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du chargement du fichier : " << e.what() << std::endl;
        return;
    }

    // Créer le robot et ajouter un observateur
    Robot robotCourant{&terrainCourant};
    auto observeur = std::make_unique<ObservateurConsole>();
    robotCourant.ajouterObservateur(std::move(observeur));

    // Demander la méthode de résolution du labyrinthe
    std::cout << "Quelle méthode le robot doit utiliser pour résoudre le labyrinthe ? :\n"
              << "1 - Algorithme de la 'Main Droite'\n"
              << "2 - Algorithme de Pledge" << std::endl;
    std::cin >> mode;

    // Vérifier que l'utilisateur a entré une option valide
    if (mode != 1 && mode != 2) {
        std::cerr << "Option invalide. Veuillez entrer 1 ou 2." << std::endl;
        return;
    }

    // Exécuter l'algorithme choisi
    if (mode == 1) {
        std::cout << "Attention : cet algorithme ne résoudra pas le labyrinthe s'il comporte des îlots. Relancer le programme si c'est le cas." << std::endl;
        try {
            algorithmes::mainDroite(robotCourant);
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de l'exécution de l'algorithme de la 'Main Droite' : " << e.what() << std::endl;
        }
    } else if (mode == 2) {
        try {
            algorithmes::pledge(robotCourant);
        } catch (const std::exception& e) {
            std::cerr << "Erreur lors de l'exécution de l'algorithme de Pledge : " << e.what() << std::endl;
        }
    }
}


void testerTerrain(){
    try {
        // Créer une instance de Terrain
        Terrain terrain;

        // Charger le terrain depuis un fichier
        std::cout << "Chargement du terrain depuis 'labyrinthe.txt'...\n";
        terrain.chargerDepuisFichier("labyrinthe.txt");

        // Afficher le terrain
        std::cout << "Affichage du terrain :\n";
        terrain.afficher();

        // Sauvegarder le terrain dans un fichier
        std::cout << "Sauvegarde du terrain dans 'terrain_sauvegarde.txt'...\n";
        terrain.sauvegarderDansFichier("terrain_sauvegarde.txt");

        std::cout << "Programme terminé avec succès.\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << "\n";
    }
}

int main() {

    //execute();
    testerTerrain();
    return 0;
}
