#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "algo.h"

TEST_CASE("Test de l'algorithme mainDroite") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test.txt");
    Robot robot{&terrain};
    algorithmes::mainDroite(robot);
    CHECK(robot.retourneX() == 1);
    CHECK(robot.retourneY() == 27);
}

TEST_CASE("Test de l'algorithme pledge") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test.txt");
    Robot robot{&terrain};
    algorithmes::pledge(robot);
    CHECK(robot.retourneX() == 1);
    CHECK(robot.retourneY() == 27);
}
