#include "robot.h"
#include "terrain.h"

namespace algorithmes
{
    void mainDroite(Robot& robot)
{
    // initialisation
    if(robot.obstacleADroite() == false)
    {
        while(robot.obstacleDevant() == true)
        {
            robot.avance();
        }
        robot.tourneG();
    }
    // boucle de resolution

    while(!robot.detecteArrivee())
    {
        if(robot.obstacleADroite()== false)
        {
            robot.tourneD();
            robot.avance();
        }
        if(robot.obstacleDevant() == false)
        {
            robot.tourneG();
        }
        else
        {
            robot.avance();
        }
    }

}

void pledge (Robot& robot)
{
    int conteur = 0 ;
    // initialisation
    while(robot.obstacleDevant() == true)
    {
        robot.avance();
    }
    robot.tourneG();
    conteur++;

    // boucle de resolution

    while(!robot.detecteArrivee())
    {
        while(conteur != 0)
        {
            if(robot.obstacleADroite()== false)
            {
                robot.tourneD();
                conteur -- ;
                robot.avance();
            }
            if(robot.obstacleDevant() == false)
            {
                robot.tourneG();
                conteur ++ ;
            }
            else
            {
                robot.avance();
            }
        }
        if(conteur == 0)
        {
            while(robot. obstacleDevant() == true)
            {
                robot.avance();
            }
        }
    }
}

} // namespace algorithmes
