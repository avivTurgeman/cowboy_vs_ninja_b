#include "Team2.hpp"

using namespace std;

namespace ariel{

    Team2::Team2(Character *leader) : Team(leader){}

    void Team2::attack(Team *enemy){
        if(enemy == nullptr){
            throw std::invalid_argument("cannot attack a null team");
        }

        if(enemy == this){
            throw std::runtime_error("no self harm");
        }

        if(stillAlive() == 0){
            throw runtime_error("all of team members are dead");
        }

        if(enemy->stillAlive() == 0){
            throw std::runtime_error("all of enemy team members are dead");
        }

        if(!(_team_leader->isAlive())){
            setLeader();
        }

        Character *victim = ClosestCharacter(enemy);
        //Cowboys attack
        for(Character *champ : _champions){
            if(victim == nullptr){
                break;
            }
            if(typeid(Cowboy) == typeid(*champ)){
                // cout << "-------------------------------------------\n";
                // cout << victim->print();
                // cout << "-------------------------------------------\n\n";
                Cowboy *Cattacker = dynamic_cast<Cowboy*>(champ);
                if(Cattacker->isAlive()){
                    if(Cattacker->hasboolets()){
                        // cout << champ->getName() << " is shooting " << victim->getName() << endl;
                        Cattacker->shoot(victim);
                    }
                    else{
                        // cout << champ->getName() << " is reloading\n";
                        Cattacker->reload();
                    }
                }   
            }
            else{
                // cout << "-------------------------------------------\n";
                // cout << victim->print();
                // cout << "-------------------------------------------\n\n";
                Ninja *Nattacker = dynamic_cast<Ninja*>(champ);
                if(Nattacker->isAlive()){
                    if(Nattacker->distance(victim) < 1){
                        // cout << champ->getName() << " is slashing " << victim->getName() << endl;
                        Nattacker->slash(victim);
                    }
                    else{
                        // cout << champ->getName() << " is moving\n";
                        Nattacker->move(victim);
                    }
                }
            }
            if(!victim->isAlive()){
                enemy->champDied();
                victim = ClosestCharacter(enemy);
            }
        }
    }    

    void Team2::print() const{
        for(Character *champ : _champions){
            cout << champ->print();
            if(champ == _team_leader){
                cout << " (captain)\n";
            }
            else{
                cout << endl;
            }
        }
    }
}