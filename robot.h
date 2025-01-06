#ifndef ROBOT_H
#define ROBOT_H
#include "observateur.h"
#include "terrain.h"

class Robot
{
    public:
        Robot();

        //Accesseurs
        int retournX() const;
        int retournY() const;
        char direction() const;

        //Tourne a droite ou a gauche
        void tourneD();
        void tourneG();

        // Fait apparaitre un robo dans le terrain Tx ,Ty avec un sens aléatoire
        void apparait();

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
        // Pointeur sur le terrain
        Terrain* d_terrain;
        // Liste des observateurs
        std::vector<Observateur*> d_observateurs;
};

#endif // ROBOT_H
