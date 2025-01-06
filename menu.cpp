#include "menu.h"
#include <iostream>
#include "terrain.h"
#include "robot.h"

Menu::Menu(/* args */)
{
}

void Menu::run(){
    bool running=true;
    //run
    while (running)
    {
        //var
        bool mode;
        std::string nomFichierIn,nomFichierOut;
        Terrain d_terrain{};
        Robot robot{};

        std::cout<<"entrez le nom du fichier contenant le labyrinthe : "<<std::endl;
        std::cin>>nomFichierIn;
        std::cout<<"quelle méthode le robot doit utiliser pour résoudre le labyrinthe ? :\n 1- Algorithme de la 'Main Droite'\n2- Algorithme de Pledge"<<std::endl;
    }
}
