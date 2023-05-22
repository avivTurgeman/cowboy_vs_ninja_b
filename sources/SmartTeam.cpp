#include "SmartTeam.hpp"

using namespace std;

namespace ariel{

    SmartTeam::SmartTeam(Character* leader) : Team(leader){}

    void SmartTeam::attack(Team *){
        return;
    }

    void SmartTeam::print() const{
        return;
    }
}