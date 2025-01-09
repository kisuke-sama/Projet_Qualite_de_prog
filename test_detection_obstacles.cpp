#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "observateur.h"

TEST_CASE("Test des méthodes de rotation") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test.txt");
    Robot robot{&terrain};

    SUBCASE("Test tourneD") {
        // Initialement, le robot est orienté vers le nord ('N')
        REQUIRE_EQ(robot.direction(), 'N');

        // Tourner à droite (N -> E)
        robot.tourneD();
        REQUIRE_EQ(robot.direction(), 'E');

        // Tourner à droite (E -> S)
        robot.tourneD();
        REQUIRE_EQ(robot.direction(), 'S');

        // Tourner à droite (S -> O)
        robot.tourneD();
        REQUIRE_EQ(robot.direction(), 'O');

        // Tourner à droite (O -> N)
        robot.tourneD();
        REQUIRE_EQ(robot.direction(), 'N');
    }

    SUBCASE("Test tourneG") {
        // Initialement, le robot est orienté vers le nord ('N')
        REQUIRE_EQ(robot.direction(), 'N');

        // Tourner à gauche (N -> O)
        robot.tourneG();
        REQUIRE_EQ(robot.direction(), 'O');

        // Tourner à gauche (O -> S)
        robot.tourneG();
        REQUIRE_EQ(robot.direction(), 'S');

        // Tourner à gauche (S -> E)
        robot.tourneG();
        REQUIRE_EQ(robot.direction(), 'E');

        // Tourner à gauche (E -> N)
        robot.tourneG();
        REQUIRE_EQ(robot.direction(), 'N');
    }

    SUBCASE("Test demiTour") {
        // Initialement, le robot est orienté vers le nord ('N')
        REQUIRE_EQ(robot.direction(), 'N');

        // Faire demi-tour (N -> S)
        robot.demiTour();
        REQUIRE_EQ(robot.direction(), 'S');

        // Faire demi-tour (S -> N)
        robot.demiTour();
        REQUIRE_EQ(robot.direction(), 'N');

        // Tourner à droite (N -> E)
        robot.tourneD();
        REQUIRE_EQ(robot.direction(), 'E');

        // Faire demi-tour (E -> O)
        robot.demiTour();
        REQUIRE_EQ(robot.direction(), 'O');

        // Faire demi-tour (O -> E)
        robot.demiTour();
        REQUIRE_EQ(robot.direction(), 'E');
    }
}

TEST_CASE("Test des méthodes de détection d'obstacles") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test2.txt");

    SUBCASE("Test obstacleDevant") {
        Robot robot{&terrain};
        // Assurez-vous que le robot est initialisé à une position où il n'y a pas d'obstacle devant
        REQUIRE_EQ(robot.obstacleDevant(), false);

        // Faites avancer le robot jusqu'à ce qu'il rencontre un obstacle
        while (!robot.obstacleDevant()) {
            robot.avance();
        }
        REQUIRE_EQ(robot.obstacleDevant(), true);
    }

    SUBCASE("Test obstacleADroite") {
        Robot robot{&terrain};
        // Assurez-vous que le robot est initialisé à une position où il n'y a pas d'obstacle à droite
        REQUIRE_EQ(robot.obstacleADroite(), false);

        // Tournez le robot à droite jusqu'à ce qu'il rencontre un obstacle
        while (!robot.obstacleADroite()) {
            robot.tourneD();
        }
        REQUIRE_EQ(robot.obstacleADroite(), true);
    }

    SUBCASE("Test obstacleAGauche") {
        Robot robot{&terrain};
        // Assurez-vous que le robot est initialisé à une position où il n'y a pas d'obstacle à gauche
        REQUIRE_EQ(robot.obstacleAGauche(), false);

        // Tournez le robot à gauche jusqu'à ce qu'il rencontre un obstacle
        while (!robot.obstacleAGauche()) {
            robot.tourneG();
        }
        REQUIRE_EQ(robot.obstacleAGauche(), true);
    }
}
