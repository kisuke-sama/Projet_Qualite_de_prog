#include "menu.h"
#include <iostream>
#include "terrain.h"
#include "robot.h"

Menu::Menu()
{
}

void Menu::execute(){
    bool execution=true;
    //run
    while (execution)
    {
        int mode;
        std::string nomFichierIn,nomFichierOut;
        Terrain terrainCourant{};
        std::cout<<"entrez le nom du fichier contenant le labyrinthe : "<<std::endl;
        std::cin>>nomFichierIn;
        terrainCourant.chargerDepuisFichier(nomFichierIn);
        Robot robotCourant{&terrainCourant};
        std::cout<<"quelle méthode le robot doit utiliser pour résoudre le labyrinthe ? :\n 1- Algorithme de la 'Main Droite'\n2- Algorithme de Pledge"<<std::endl;
        std::cin>>mode;
        /*if (mode == 1) {
            //mainDroite(robotCourant);
        }
        else if (mode == 2) {
            //pledge(robotCourant);
        }*/
    }
}
