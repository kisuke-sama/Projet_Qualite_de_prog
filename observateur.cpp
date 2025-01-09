#include "observateur.h"

// Méthode pour notifier un déplacement du robot

void ObservateurConsole::notifier(int x, int y, char direction)
{
    std::cout << "Le robot s'est deplace a (" << x << ", " << y << ") en direction " << std::string(1,direction) << std::endl;
}

std::ostringstream& ObservateurConsole::getOutput() {
    return d_ost;
}
