#include "robot.h"
#include <stdlib.h>     /* rand */

Robot::Robot(Terrain* terrain): d_terrain{terrain},d_x{0},d_y{0},d_direction{'N'}
{
    apparait();
}

int Robot::retourneX() const
{
    return d_x;
}

int Robot::retourneY() const
{
    return d_y;
}

char Robot::direction() const
{
    return d_direction;
}

void Robot::tourneD()
{
    switch (d_direction) {
        case 'E': d_direction = 'S'; break;
        case 'O': d_direction = 'N'; break;
        case 'N': d_direction = 'E'; break;
        case 'S': d_direction = 'O'; break;
    }

    notifierObservateurs();
}

void Robot::tourneG()
{
    switch (d_direction) {
        case 'E': d_direction = 'N'; break;
        case 'O': d_direction = 'S'; break;
        case 'N': d_direction = 'O'; break;
        case 'S': d_direction = 'E'; break;
    }

    notifierObservateurs();
}

void Robot::demiTour()
{
    switch (d_direction) {
        case 'E': d_direction = 'O'; break;
        case 'O': d_direction = 'E'; break;
        case 'N': d_direction = 'S'; break;
        case 'S': d_direction = 'N'; break;
    }

    notifierObservateurs();
}

void Robot::apparait()
{
    d_x=d_terrain->getCaseDepart()->getX();
    d_y=d_terrain->getCaseDepart()->getY();
    d_direction='N';
}

bool Robot::obstacleDevant() const {
    int nouveauX = d_x, nouveauY = d_y;
    switch (d_direction) {
        case 'E': nouveauX++; break;
        case 'O': nouveauX--; break;
        case 'N': nouveauY--; break;
        case 'S': nouveauY++; break;
    }
    return d_terrain->getCase(nouveauX,nouveauY).estMur();
}

bool Robot::obstacleADroite() const {
    int nouveauX = d_x, nouveauY = d_y;
    switch (d_direction) {
        case 'E': nouveauY--; break;
        case 'O': nouveauY++; break;
        case 'N': nouveauX--; break;
        case 'S': nouveauX++; break;
    }
    return d_terrain->getCase(nouveauX,nouveauY).estMur();
}

bool Robot::obstacleAGauche() const {
    int nouveauX = d_x, nouveauY = d_y;
    switch (d_direction) {
        case 'E': nouveauY++; break;
        case 'O': nouveauY--; break;
        case 'N': nouveauX++; break;
        case 'S': nouveauX--; break;
    }
    return d_terrain->getCase(nouveauX,nouveauY).estMur();
}

bool Robot::detecteArrivee() const
{
    return (d_terrain->getCase(d_x,d_y).getType() == "Arrivée");
}

void Robot::avance()
{
    int nouveauX = d_x, nouveauY = d_y;
    // On s'adapte à la direction dans laquelle on fait face
    switch (d_direction) {
        case 'E': nouveauX++; break;
        case 'O': nouveauX--; break;
        case 'N': nouveauY--; break;
        case 'S': nouveauY++; break;
    }
    // Si la voie est libre, on avance
    if (!obstacleDevant()) {
        d_x = nouveauX;
        d_y = nouveauY;
        notifierObservateurs();
    }
}

void Robot::ajouterObservateur(std::unique_ptr<Observateur> observateur) {
    d_observateurs.push_back(std::make_unique<Observateur>(observateur));
}

void Robot::notifierObservateurs() {
    for (int i = 0; i<d_observateurs.size();i++) {
        d_observateurs[i]->notifier(d_x, d_y, d_direction);
    }
}
