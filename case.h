#ifndef CASE_H
#define CASE_H

#include <string>

class Case {
private:
    std::string d_typeCase; // Type de la case ("Mur", "Vide", etc.)
    int d_positionX, d_positionY; // Coordonnées de la case

public:
    // Constructeur
    Case(const std::string& type = "Vide", int x = 0, int y = 0);

    // Accesseurs
    std::string getType() const;
    int getX() const;
    int getY() const;

    // Modificateurs
    void setType(const std::string& nouveauType);
    void setPosition(int x, int y);

    // Vérifie si la case est un mur
    bool estMur() const;
};

#endif // CASE_H