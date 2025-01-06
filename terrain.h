#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "Case.h"

class Terrain {
private:
    std::vector<std::vector<Case>> grille; // Grille 2D des cases
    int largeur, hauteur;                 // Dimensions du terrain
    Case* depart;                         // Pointeur vers la case de départ
    Case* arrivee;                        // Pointeur vers la case d'arrivée

public:
    // Constructeur
    Terrain(int largeur = 0, int hauteur = 0);

    // Méthodes pour charger et sauvegarder le terrain
    void chargerDepuisFichier(const std::string& fichier);
    void sauvegarderDansFichier(const std::string& fichier) const;

    // Méthode d'affichage
    void afficher() const;

    // Accesseurs
    const Case* getDepart() const;
    const Case* getArrivee() const;
    const Case& getCase(int x, int y) const;
};

#endif // TERRAIN_H