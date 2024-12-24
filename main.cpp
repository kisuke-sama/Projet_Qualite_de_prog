#include <iostream>
#include "terrain/terrain.h"
#include "robot/robot.h"

int main() {
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

    return 0;
}
