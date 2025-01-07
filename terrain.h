#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <string>
#include "Case.h"

class Terrain {
private:
    int d_largeurTerrain;
    int d_hauteurTerrain;
    std::vector<std::vector<Case>> d_grilleTerrain;
    Case* d_caseDepart;
    Case* d_caseArrivee;

    // Méthodes auxiliaires
    char determinerAffichageMur(int x, int y) const;

public:
    // Constructeur
    Terrain(int largeur = 0, int hauteur = 0);

    // Méthodes principales
    void chargerDepuisFichier(const std::string& cheminFichier);
    void sauvegarderDansFichier(const std::string& cheminFichier) const;
    void afficher() const;

    // Accesseurs
    const Case* getCaseDepart() const;
    const Case* getCaseArrivee() const;
    const Case& getCase(int x, int y) const;
    int getLargeur() const;
    int getHauteur() const;
};

#endif // TERRAIN_H
