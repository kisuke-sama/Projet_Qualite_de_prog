#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include <vector>
#include <string>
#include <iostream>

class Observateur {
public:
    // Méthode pour notifier un déplacement du robot
    void notifier(int x, int y, char direction);

    // Affiche la liste complète des déplacements
    void afficherDeplacements() const;

private:
    std::vector<std::string> listeDeplacements;
};

#endif // OBSERVATEUR_H
