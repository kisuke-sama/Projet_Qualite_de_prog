#include <iostream>
#include "doctest.h"
#include "robot.h"
#include "terrain.h"
#include "observateur.h"
#include <sstream>

class TestObservateur : public Observateur {
public:
    void notifier(int x, int y, char direction) override{
        d_log.push_back("Le robot s'est deplace a (" + std::to_string(y) + "," + std::to_string(x) + ") en direction " + std::string(1,direction));
    }
    std::string sortie() const{
        std::string log;
        for(int i=0;i<d_log.size();i++){
            log += d_log[i] + '\n';
        }
        return log;
    }
private:
    std::vector<std::string> d_log;
};

TEST_CASE("Test de la transmission des informations") {
    Terrain terrain{};
    terrain.chargerDepuisFichier("labyrinthe_test2.txt");
    Robot robot{&terrain};
    auto observer = std::make_unique<TestObservateur>();
    TestObservateur& observerRef = *observer;
    robot.ajouterObservateur(std::move(observer));

    SUBCASE("Test tourner à gauche") {
        robot.tourneG();
        REQUIRE_EQ(observerRef.sortie(), "Le robot s'est deplace a (2,3) en direction O\n");
    }
}

