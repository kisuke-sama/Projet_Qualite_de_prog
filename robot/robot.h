#ifndef ROBOT_H
#define ROBOT_H
#include "observateur/observateur.h"
#include "terrain/case.h"

class robot
{
    public:
        robot(int tailleTx,int tailleTY);
        int retournX() const;
        int retournY() const;
        char sens() const;

        //Tourne a droite ou a gauche
        void tourneD();
        void tourneG();

        // Fait apparaitre un robo dans le terrain Tx ,Ty avec un sens aléatoire
        void apparait(int tailleTx,int tailleTY);

        // Avance si la case est vide
        void avance();

        //Affiche la direction dans le terrain
        char affichage();

        // Méthodes pour gérer les observateurs
        void ajouterObservateur(Observateur* observateur);
        void notifierObservateurs();

    private:
        int d_x,d_y;
        char d_direction,d_affichage;
        Case d_caseCourante;

    // Liste des observateurs
    std::vector<Observateur*> observateurs;
};

#endif // ROBOT_H