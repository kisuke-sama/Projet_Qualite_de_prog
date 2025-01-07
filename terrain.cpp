#include "Terrain.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Constructeur
Terrain::Terrain(int largeur, int hauteur)
    : d_largeurTerrain(largeur), d_hauteurTerrain(hauteur), d_caseDepart(nullptr), d_caseArrivee(nullptr)
{}

// Charger le terrain depuis un fichier
void Terrain::chargerDepuisFichier(const std::string& cheminFichier) {
    std::ifstream fichierEntree(cheminFichier);
    if (!fichierEntree.is_open()) {
        throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier.");
    }

    fichierEntree >> d_hauteurTerrain >> d_largeurTerrain;

    if (d_hauteurTerrain <= 0 || d_largeurTerrain <= 0) {
        throw std::invalid_argument("Dimensions invalides dans le fichier.");
    }

    d_grilleTerrain.resize(d_hauteurTerrain, std::vector<Case>(d_largeurTerrain));

    char symbole;
    for (int i = 0; i < d_hauteurTerrain; ++i) {
        for (int j = 0; j < d_largeurTerrain; ++j) {
            fichierEntree >> symbole;
            switch (symbole) {
                case 'X':
                    d_grilleTerrain[i][j] = Case("Mur", i, j);
                    break;
                case '.':
                    d_grilleTerrain[i][j] = Case("Vide", i, j);
                    break;
                case 'E': // Départ
                    d_grilleTerrain[i][j] = Case("Départ", i, j);
                    d_caseDepart = &d_grilleTerrain[i][j];
                    break;
                case 'S': // Arrivée
                    d_grilleTerrain[i][j] = Case("Arrivée", i, j);
                    d_caseArrivee = &d_grilleTerrain[i][j];
                    break;
                default:
                    throw std::invalid_argument("Caractère invalide dans le fichier : " + std::string(1, symbole));
            }
        }
    }

    fichierEntree.close();
}

// Sauvegarder le terrain dans un fichier
void Terrain::sauvegarderDansFichier(const std::string& cheminFichier) const {
    std::ofstream fichierSortie(cheminFichier);
    if (!fichierSortie.is_open()) {
        throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier.");
    }

    fichierSortie << d_hauteurTerrain << " " << d_largeurTerrain << "\n";

    for (const auto& ligne : d_grilleTerrain) {
        for (const auto& c : ligne) {
            if (c.getType() == "Mur") fichierSortie << '#';
            else if (c.getType() == "Vide") fichierSortie << '.';
            else if (c.getType() == "Arrivée") fichierSortie << 'S';
            else if (c.getType() == "Départ") fichierSortie << 'E';
        }
        fichierSortie << "\n";
    }
}

// Afficher le terrain
void Terrain::afficher() const {

    // Contenu du terrain
    for (int i = 0; i < d_hauteurTerrain; ++i) {
        //std::cout << "|"; // Bord gauche
        for (int j = 0; j < d_largeurTerrain; ++j) {
            if (&d_grilleTerrain[i][j] == d_caseArrivee) {
                std::cout << "E"; // Arrivée
            } else if (d_grilleTerrain[i][j].getType() == "Mur") {
                // Gérer les coins et les murs
                bool murHaut = (i > 0 && d_grilleTerrain[i - 1][j].getType() == "Mur");
                bool murBas = (i < d_hauteurTerrain - 1 && d_grilleTerrain[i + 1][j].getType() == "Mur");
                bool murGauche = (j > 0 && d_grilleTerrain[i][j - 1].getType() == "Mur");
                bool murDroite = (j < d_largeurTerrain - 1 && d_grilleTerrain[i][j + 1].getType() == "Mur");

                 if ((murHaut && murGauche) || (murHaut && murDroite) || (murBas && murGauche) || (murBas && murDroite)) {
                    std::cout << "+"; // Coin
                } else if (murHaut || murBas) {
                    std::cout << "|"; // Mur vertical
                } else if (murGauche || murDroite) {
                    std::cout << "-"; // Mur horizontal
                } else {
                    std::cout << " "; // Vide
                }
            } else {
                std::cout << "."; // Case vide
            }
        }
        std::cout << "\n"; // Bord droit
    }

}

// Accesseurs
const Case* Terrain::getCaseDepart() const {
    return d_caseDepart;
}

const Case* Terrain::getCaseArrivee() const {
    return d_caseArrivee;
}

const Case& Terrain::getCase(int x, int y) const {
    if (x < 0 || x >= d_hauteurTerrain || y < 0 || y >= d_largeurTerrain) {
        throw std::out_of_range("Coordonnées hors limites.");
    }
    return d_grilleTerrain[x][y];
}

int Terrain::getLargeur() const {
    return d_largeurTerrain;
}

int Terrain::getHauteur() const { 
    return d_hauteurTerrain;
}