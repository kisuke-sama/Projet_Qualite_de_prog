#ifndef ROBOT_H
#define ROBOT_H
#include "observateur.h"
#include "terrain.h"
#include "case.h"
#include <memory>

class Robot
{
    public:
        Robot(Terrain* terrain = nullptr);

        //Accesseurs
        int retourneX() const;
        int retourneY() const;
        char direction() const;

        //Tourne a droite ou a gauche
        void tourneD();
        void tourneG();

        //Se retourner
        void demiTour();

        // Fait apparaitre un robo dans le terrain Tx ,Ty avec un sens al�atoire
        void apparait();

        // Vérifier s'il y a un obstacle
        bool obstacleDevant() const;
        bool obstacleADroite() const;
        bool obstacleAGauche() const;

        // Vérifie si on est sorti du labyrinthe
        bool detecteArrivee() const;

        // Avance si la case est vide
        void avance();


        // M�thodes pour g�rer les observateurs
        void ajouterObservateur(std::unique_ptr<Observateur> observateur);
        void notifierObservateurs();

    private:
        int d_x,d_y;
        char d_direction,d_affichage;
        // Pointeur sur le terrain
        Terrain* d_terrain;
        // Liste des observateurs
        std::vector<std::unique_ptr<Observateur>> d_observateurs;
};

#endif // ROBOT_H
