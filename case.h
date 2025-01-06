#ifndef CASE_H
#define CASE_H

#include <string>

class Case {
private:
    std::string type; // Type de la case : "Mur", "Vide", "Départ", "Arrivée"
    int x, y;         // Position de la case

public:
    // Constructeur
    Case(const std::string& type = "Vide", int x = 0, int y = 0);

    // Accesseurs
    std::string getType() const;
    int getX() const;
    int getY() const;

    // Modificateurs
    void setType(const std::string& newType);
    void setPosition(int newX, int newY);

    // Vérifie si la case est un mur
    bool estMur() const;
};

#endif // CASE_H