#include "robot.h"
#include "terrain.h"

//ne fonctionne pas si le labyrinthe possède des ilots
bool mainDroite(Robot robot){
    while (!robot.detecteArrivee())
    {
        if (!robot.obstacleADroite())
        {
            robot.tourneD();
            /*s'il n'y a pas d'obstacle à droite, on tourne.*/
        }
        else
        {
            if (robot.obstacleDevant())
            {
                /*s'il y a un obstacle devant, ...*/
                if (!robot.obstacleAGauche())
                {
                    robot.tourneG();
                    /*... et s'il n'y a pas d'obstacle à gauche, on tourne*/
                }
                else
                {
                    robot.demiTour();
                    /*... et si on a pas d'autre choix, on fait demi-tour*/
                }
            }
        }
        robot.avance();
    }
}