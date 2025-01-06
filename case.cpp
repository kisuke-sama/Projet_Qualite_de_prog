#include "Case.h"

// Constructeur
Case::Case(const std::string& type, int x, int y) : type(type), x(x), y(y) {}

// Accesseurs
std::string Case::getType() const { return type; }
int Case::getX() const { return x; }
int Case::getY() const { return y; }

// Modificateurs
void Case::setType(const std::string& newType) { type = newType; }
void Case::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

// Vérifie si la case est un mur
bool Case::estMur() const { return type == "Mur"; }
