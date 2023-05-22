#include "Cowboy.hpp"

using namespace std;
namespace ariel{
    Cowboy::Cowboy(std::string name, const Point &location):
    Character(name, location, 110), _balls_amount(6){}

    void Cowboy::shoot(Character* other){
        if(other == this){
            throw std::runtime_error("no self harm");
        }

        if((this->isAlive()) && (this->hasboolets())){
            other->hit(10);
            _balls_amount -=1;
        }
        else if (!(this->isAlive())){
            throw std::runtime_error("this Cowboy is dead");
        }
    }

    bool Cowboy::hasboolets(){
        return _balls_amount > 0;
    }

    void Cowboy::reload(){
        if (!(this->isAlive())){
            throw std::runtime_error("this Cowboy is dead");
        }
        _balls_amount = 6;
    }

    string Cowboy::print(){
        string rv;
        if(isAlive()){
            return  "Name: " + _name + 
            "\nHP: " + std::to_string(_hp) + 
            "\nPoint: " + _location.print() + "\n";
        }
        return "C(" + _name + ")\n";
    }
}