#include "robot.h"
#include <stdlib.h>     /* rand */


robot::robot(int tailleTx,int tailleTY)
{
    apparait(tailleTx,tailleTY);
}


int robot::retournX() const
{
    return d_x;
}


int robot::retournY() const
{
    return d_y;
}


char robot::sens() const
{
    return d_direction;
}


void robot::tourneD()
{
    if (d_direction == 'N') d_direction = 'E';
    else if (d_direction == 'E') d_direction = 'S';
    else if (d_direction == 'S') d_direction = 'O';
    else if (d_direction == 'O') d_direction = 'N';

    notifierObservateurs();
}


void robot::tourneG()
{
    if (d_direction == 'N') d_direction = 'O';
    else if (d_direction == 'E') d_direction = 'N';
    else if (d_direction == 'S') d_direction = 'E';
    else if (d_direction == 'O') d_direction = 'S';

    notifierObservateurs();
}


void robot::apparait(int tailleTx,int tailleTy)
{
    d_x=rand()% tailleTx;
    d_y=rand()% tailleTy;
    int sensPossible = rand()%4;
    switch (sensPossible) {
    case 0:
        d_direction='N';
        break;

    case 1:
        d_direction='E';
        break;

    case 2:
        d_direction='S';
        break;

    case 3:
        d_direction='O';
        break;

    default:
        std::cout << "Direction impossible" << std::endl;
        break;
    }
}

/*
    A revoir :

    - gestion des mouvements : est-ce que le robot possède une variable 'd_terrain' pour se déplacer ou est-ce que les cases communiquent entre elles
    pour savoir si on rencontre un mur ou non ?
*/
void robot::avance()
{
    if (d_direction == 'N' /*&& d_caseCourante.estVide(x, y - 1)*/)
    {
    --d_y;
    notifierObservateurs();
    }
    else if (d_direction == 'E' /*&& d_caseCourante.estVide(x + 1, y)*/)
    {
    ++d_x;
    notifierObservateurs();
    }
    else if (d_direction == 'S' /*&& d_caseCourante.estVide(x, y + 1)*/)
    {
    ++d_y;
    notifierObservateurs();
    }
    else if(d_direction == 'O' /*&& d_caseCourante.estVide(x - 1, y)*/)
    {
    --d_x;
    notifierObservateurs();
    }
    else {std::cout<<"ne peut pas avancer car il y a un mur" << std::endl;}

}

char robot::affichage()
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


void robot::ajouterObservateur(Observateur* observateur) {
    observateurs.push_back(observateur);
}

void robot::notifierObservateurs() {
    for (Observateur* observateur : observateurs) {
        observateur->notifier(d_x, d_y, d_direction);
    }
}
