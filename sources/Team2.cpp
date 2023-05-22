#include "Team2.hpp"

using namespace std;

namespace ariel{

    Team2::Team2(Character *leader) : Team(leader){}

    void Team2::attack(Team *other){
        if(other == nullptr){
            throw std::invalid_argument("cannot attack a null team");
        }
        return;
    }

    void Team2::print() const{
        return;
    }
}