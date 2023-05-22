#include "Character.hpp"

using namespace std;

namespace ariel{
    
    Character::Character(string name, const Point& location, int hp):
    _name(name), _location(location), _hp(hp){
        _team_player = false;
    }

    bool Character::isAlive(){
        if(_hp > 0){
            return true;
        }
        return false;
    }

    double Character::distance(Character* other){
        double distance = _location.distance(other->getLocation());
        return distance;
    }

    void Character::hit(int damage){
        if(damage < 0){
            throw std::invalid_argument("hit damage must not be negative");
        }
        if(_hp > 0){
            _hp -= damage;
            if(_hp < 0){
                _hp = 0;
            }
        }
        else{
            throw runtime_error("Character is dead");
        }
    }
}