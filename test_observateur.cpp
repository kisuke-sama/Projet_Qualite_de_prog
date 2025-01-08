#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "observateur.h"
#include <sstream>


TEST_CASE("Test des mouvement et de la détection d'obstacle") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test.txt");
    Robot robot{&terrain};
    auto observer = std::make_unique<ObservateurConsole>();
    robot.ajouterObservateur(std::move(observer));

    SUBCASE("Test aller à droite"){
        robot.tourneD();
        std::ostringstream ost{};
        REQUIRE_EQ( ost.str(), "Le robot s'est déplacé à (11, 15) en direction E");
    }
}
