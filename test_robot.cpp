#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "observateur.h"

TEST_CASE("Test des mouvement et de la détection d'obstacle") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test.txt");
    Robot robot{&terrain};
    ObservateurConsole observer;
    robot.ajouterObservateur(std::make_unique<Observateur>(observer));

    SUBCASE("Test aller à droite"){
        robot.tourneD();
        REQUIRE_EQ(robot.obstacleADroite() , true);
        REQUIRE_EQ(robot.obstacleAGauche() , false);
        REQUIRE_EQ(robot.obstacleDevant() , false);
    }
    
    SUBCASE("Test aller à gauche"){
        robot.tourneG();
        REQUIRE_EQ(robot.obstacleADroite() , false);
        REQUIRE_EQ(robot.obstacleAGauche() , true);
        REQUIRE_EQ(robot.obstacleDevant() , false);
    }

    SUBCASE("Test aller tout droit"){
        robot.avance();
        REQUIRE_EQ(robot.obstacleADroite() , false);
        REQUIRE_EQ(robot.obstacleAGauche() , false);
        REQUIRE_EQ(robot.obstacleDevant() , true);
    }

    SUBCASE("Test se retourner"){
        robot.demiTour();
        REQUIRE_EQ(robot.obstacleADroite() , false);
        REQUIRE_EQ(robot.obstacleAGauche() , false);
        REQUIRE_EQ(robot.obstacleDevant() , true);
    }
}