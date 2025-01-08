#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class Observateur {
public:
    // Méthode pour notifier un déplacement du robot
    virtual void notifier(int x, int y, char direction) = 0;
};

class ObservateurConsole : public Observateur {
public:
    void notifier(int x, int y, char direction) override;
    std::ostringstream& getOutput();

private:
    std::ostringstream d_ost;
};

#endif // OBSERVATEUR_H
