//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Case.h"

TEST_CASE("Tests pour la classe Case") {
    // Test du constructeur
    SUBCASE("Constructeur par défaut") {
        Case c;
        CHECK(c.getType() == "Vide");
        CHECK(c.getX() == 0);
        CHECK(c.getY() == 0);
    }

    SUBCASE("Constructeur avec paramètres") {
        Case c("Mur", 2, 3);
        CHECK(c.getType() == "Mur");
        CHECK(c.getX() == 2);
        CHECK(c.getY() == 3);
    }

    // Test des accesseurs
    SUBCASE("Accès aux coordonnées") {
        Case c("Vide", 4, 5);
        CHECK(c.getX() == 4);
        CHECK(c.getY() == 5);
    }

    // Test des modificateurs
    SUBCASE("Modification du type") {
        Case c("Vide", 1, 1);
        c.setType("Mur");
        CHECK(c.getType() == "Mur");
    }

    SUBCASE("Modification des coordonnées") {
        Case c("Mur", 0, 0);
        c.setPosition(10, 15);
        CHECK(c.getX() == 10);
        CHECK(c.getY() == 15);
    }

    // Test de la méthode estMur()
    SUBCASE("Vérification de mur") {
        Case c("Mur", 0, 0);
        CHECK(c.estMur() == true);

        Case c2("Vide", 0, 0);
        CHECK(c2.estMur() == false);
    }
}
