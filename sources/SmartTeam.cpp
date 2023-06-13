#include "SmartTeam.hpp"

using namespace std;

namespace ariel{

    SmartTeam::SmartTeam(Character* leader) : Team(leader){}

    void SmartTeam::attack(Team *enemy){
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

        Character *victim;

        //Cowboys attack
        for(Character *champ : _champions){
            if(typeid(Cowboy) == typeid(*champ)){

                Cowboy *Cattacker = dynamic_cast<Cowboy*>(champ);
                
                victim = farthestCharacter(Cattacker, enemy);
                
                if(victim == nullptr){
                    break;
                }
                
                if(Cattacker->isAlive()){
                    if(Cattacker->hasboolets()){
                        Cattacker->shoot(victim);
                    }
                    else{
                        Cattacker->reload();
                    }
                }   
            } 
            else{
                Ninja *Nattacker = dynamic_cast<Ninja*>(champ);
                victim = ClosestCharacterToNinja(Nattacker, enemy);
                
                if(victim == nullptr){
                    break;
                }
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
 
    void SmartTeam::print() const{
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

    Character* SmartTeam::farthestCharacter(Cowboy *Cattacker, Team* team) const{
        bool first_champ = true;
        Character *farthest = nullptr;
        vector<Character*> champions = team->getChampions();

        for(Character* champ : champions){
            if(champ->isAlive()){
                if(first_champ){
                    farthest = champ;
                    first_champ = false;
                }
                else if(Cattacker->distance(champ) > Cattacker->distance(farthest)){
                    farthest = champ;
                }
            }
        }
        return farthest;
    }

    Character* SmartTeam::ClosestCharacterToNinja(Ninja *Nattacker, Team *enemy){
        bool first_champ = true;
        Character *closest = nullptr;
        vector<Character*> champions = enemy->getChampions();

        for(Character* champ : champions){
            if(champ->isAlive()){
                if(first_champ){
                    closest = champ;
                    first_champ = false;
                }
                else if(Nattacker->distance(champ) < Nattacker->distance(closest)){
                    closest = champ;
                }
            }
        }
        return closest;
    }

}