#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "observateur.h"
#include <sstream>


TEST_CASE("Test des mouvement et de la détection d'obstacle") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test.txt");
    Robot robot{&terrain};
    ObservateurConsole observer;
    robot.ajouterObservateur(std::make_unique<Observateur>(observer));

    SUBCASE("Test aller à droite"){
        robot.tourneD();
        std::ostringstream ost{};
        REQUIRE_EQ( ost, "Le robot s'est déplacé à (12,16) en direction E");
    }
}