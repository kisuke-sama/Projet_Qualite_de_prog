#include "robot.h"
#include "terrain.h"
#include <iostream>

namespace algorithmes
{
    void mainDroite(Robot& robot)
    {
        std::cout << robot.direction() << std::endl;

        // Initialisation
        if (!robot.obstacleADroite())
        {
            while (!robot.obstacleDevant())
            {
                robot.avance();
                std::cout << ' ' << robot.obstacleDevant();
            }
            robot.tourneG();
        }

        // Boucle de résolution
        while (!robot.detecteArrivee())
        {
            if (!robot.obstacleADroite())
            {
                robot.tourneD();
                robot.avance();
            }
            else if (robot.obstacleDevant())
            {
                robot.tourneG();
            }
            else
            {
                robot.avance();
            }
        }
    }

    void pledge(Robot& robot)
    {
        int compteur = 0;

        // Initialisation : avancer jusqu'à rencontrer un obstacle devant
        while (!robot.obstacleDevant())
        {
            robot.avance();
        }
        robot.tourneG();
        compteur++;

        // Boucle de résolution
        while (!robot.detecteArrivee())
        {
            if (!robot.obstacleADroite())
            {
                robot.tourneD();
                compteur--;
                robot.avance();
            }
            else if (robot.obstacleDevant())
            {
                robot.tourneG();
                compteur++;
            }
            else
            {
                robot.avance();
            }

            // Si le compteur est à zéro, avancer jusqu'à rencontrer un obstacle devant
            if (compteur == 0)
            {
                while (!robot.obstacleDevant())
                {
                    robot.avance();
                }
                robot.tourneG();
                compteur++;
            }
        }
    }

} // namespace algorithmes
