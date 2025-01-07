#include "Case.h"

// Constructeur
Case::Case(const std::string& type, int x, int y) : d_typeCase(type), d_positionX(x), d_positionY(y) {}

// Accesseurs
std::string Case::getType() const { return d_typeCase; }
int Case::getX() const { return d_positionX; }
int Case::getY() const { return d_positionY; }

// Modificateurs
void Case::setType(const std::string& nouveauType) { d_typeCase = nouveauType; }
void Case::setPosition(int x, int y) {
    d_positionX = x;
    d_positionY = y;
}

// Vérifie si la case est un mur
bool Case::estMur() const { return d_typeCase == "Mur"; }
