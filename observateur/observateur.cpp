#include "observateur.h"

// Méthode pour notifier un déplacement du robot

void Observateur::notifier(int x, int y, char direction)
 {
    std::string message = "Le robot s'est déplacé à (" + std::to_string(x) + ", " +
                          std::to_string(y) + ") en direction " + direction;
    listeDeplacements.push_back(message);
    std::cout << message << std::endl;
}

// Méthode pour afficher tous les déplacements enregistrés

void Observateur::afficherDeplacements() const
{
    std::cout << "Liste des déplacements du robot :" << std::endl;
    for (const auto& message : listeDeplacements) {
        std::cout << message << std::endl;
    }
}