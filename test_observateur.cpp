#include <iostream>
#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "observateur.h"
#include <sstream>

TEST_CASE("Test de la transmission des informations") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test2.txt");
    Robot robot{&terrain};
    auto observer = std::make_unique<ObservateurConsole>();
    ObservateurConsole& observerRef = *observer;
    robot.ajouterObservateur(std::move(observer));

    SUBCASE("Test tourner à gauche") {
        robot.tourneG();
        //REQUIRE_EQ(observerRef.getOutput().str(), "Le robot s'est deplace a (3,2) en direction O");
    }
}

