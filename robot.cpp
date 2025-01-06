#include "robot.h"
#include <stdlib.h>     /* rand */


Robot::Robot()
{
    apparait();
}

int Robot::retournX() const
{
    return d_x;
}

int Robot::retournY() const
{
    return d_y;
}

char Robot::sens() const
{
    return d_direction;
}

void Robot::tourneD()
{
    if (d_direction == 'N') d_direction = 'E';
    else if (d_direction == 'E') d_direction = 'S';
    else if (d_direction == 'S') d_direction = 'O';
    else if (d_direction == 'O') d_direction = 'N';

    notifierObservateurs();
}

void Robot::tourneG()
{
    if (d_direction == 'N') d_direction = 'O';
    else if (d_direction == 'E') d_direction = 'N';
    else if (d_direction == 'S') d_direction = 'E';
    else if (d_direction == 'O') d_direction = 'S';

    notifierObservateurs();
}

void Robot::apparait()
{
    d_x=d_terrain.getDepart().getX();
    d_y=d_terrain.getDepart().getY();
    d_direction='N';
}

void Robot::avance()
{
    if (d_direction == 'N' && d_terrain.getCase(d_x, d_y -1)!= '-' )
    {
    --d_y;
    notifierObservateurs();
    }
    else if (d_direction == 'E' && d_terrain.getCase(d_x +1, d_y)!= '-')
    {
    ++d_x;
    notifierObservateurs();
    }
    else if (d_direction == 'S' && d_terrain.getCase(d_x, d_y +1)!= '-')
    {
    ++d_y;
    notifierObservateurs();
    }
    else if(d_direction == 'O' && d_terrain.getCase(d_x -1, d_y)!= '-')
    {
    --d_x;
    notifierObservateurs();
    }
}

/*
Pas sûr de garder cette fonction car on n'est pas censé afficher le labyrinth
en temps réel
*/
char Robot::affichage()
{
    if (d_direction == 'N' )
    {return d_affichage = '^';}

    else if (d_direction == 'E' )
    {return d_affichage = '>';}

    else if (d_direction == 'S' )
    {return d_affichage = 'v';}

    else if (d_direction == 'O' )
    {return d_affichage = '<';}
}

void Robot::ajouterObservateur(Observateur* observateur) {
    d_observateurs.push_back(observateur);
}

void Robot::notifierObservateurs() {
    for (Observateur* observateur : d_observateurs) {
        observateur->notifier(d_x, d_y, d_direction);
    }
}
