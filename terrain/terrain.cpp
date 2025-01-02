#include "Terrain.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "Terrain.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Constructeur
Terrain::Terrain(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur), depart(nullptr), arrivee(nullptr) {}

// Charger le terrain depuis un fichier
void Terrain::chargerDepuisFichier(const std::string& fichier) {
    std::ifstream fichierEntree(fichier);
    if (!fichierEntree.is_open()) {
        throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier.");
    }

    fichierEntree >> hauteur >> largeur;
    grille.resize(hauteur, std::vector<Case>(largeur));

    char symbole;
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            fichierEntree >> symbole;
            switch (symbole) {
                case 'X':
                    grille[i][j] = Case("Mur", i, j);
                    break;
                case '.':
                    grille[i][j] = Case("Vide", i, j);
                    break;

                case 'E':
                    grille[i][j] = Case("Arrivée", i, j);
                    arrivee = &grille[i][j];
                    break;
                default:
                    throw std::invalid_argument("Caractère invalide dans le fichier.");
            }
        }
    }

    fichierEntree.close();
}

// Sauvegarder le terrain dans un fichier
void Terrain::sauvegarderDansFichier(const std::string& fichier) const {
    std::ofstream fichierSortie(fichier);
    if (!fichierSortie.is_open()) {
        throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier.");
    }

    fichierSortie << hauteur << " " << largeur << "\n";
    for (const auto& ligne : grille) {
        for (const auto& c : ligne) {
            if (c.getType() == "Mur")
                fichierSortie << 'X';
            else if (c.getType() == "Vide")
                fichierSortie << '.';
            else if (c.getType() == "Arrivée")
                fichierSortie << 'E';
        }
        fichierSortie << "\n";
    }
}

void Terrain::afficher() const {

    // Contenu du terrain
    for (int i = 0; i < hauteur; ++i) {
        //std::cout << "|"; // Bord gauche
        for (int j = 0; j < largeur; ++j) {
            if (&grille[i][j] == arrivee) {
                std::cout << "E"; // Arrivée
            } else if (grille[i][j].getType() == "Mur") {
                // Gérer les coins et les murs
                bool murHaut = (i > 0 && grille[i - 1][j].getType() == "Mur");
                bool murBas = (i < hauteur - 1 && grille[i + 1][j].getType() == "Mur");
                bool murGauche = (j > 0 && grille[i][j - 1].getType() == "Mur");
                bool murDroite = (j < largeur - 1 && grille[i][j + 1].getType() == "Mur");

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
const Case* Terrain::getDepart() const { return depart; }
const Case* Terrain::getArrivee() const { return arrivee; }
const Case& Terrain::getCase(int x, int y) const { return grille[x][y]; }