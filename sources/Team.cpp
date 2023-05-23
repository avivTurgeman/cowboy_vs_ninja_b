#include "Team.hpp"

using namespace std;

namespace ariel{
    Team::Team(Character *team_leader){
        if(team_leader->isTeamate()){
            throw std::runtime_error("team leader already chosen"); 
        }
        _team_leader = team_leader;
        _champions.emplace_back(team_leader);
        _champions_count = 1;
        _team_leader->setPlaying(true);
    }

    void Team::add(Character *champion){
        if(champion->isTeamate()){
            throw std::runtime_error("champion already chosen"); 
        }

        if(_champions_count < 10){
            _champions.emplace_back(champion);
            champion->setPlaying(true);
            _champions_count++;
        }

        else{
            throw std::runtime_error("Team can have at most 10 champions");
        }
    }

    void Team::attack(Team *enemy){
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
                if(!victim->isAlive()){
                    enemy->champDied();
                    victim = ClosestCharacter(enemy);
                }
            }
        }

        //Ninjas attack
        for(Character *champ : _champions){
            if(victim == nullptr){
                break;
            }
            if(typeid(Cowboy) != typeid(*champ)){
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
                    if(!victim->isAlive()){
                        enemy->champDied();
                        victim = ClosestCharacter(enemy);
                    }
                }
            }
        }
    
    }

    int Team::stillAlive() const{
        return _champions_count;
    }

    void Team::print() const{
        for(Character *champ : _champions){
            if(typeid(*champ) == typeid(Cowboy)){
                cout << champ->print();
                if(champ == _team_leader){
                    cout << " (captain)\n";
                }
                else{
                    cout << endl;
                }
            }
        }
        for(Character *champ : _champions){
            if(typeid(*champ) != typeid(Cowboy)){
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

    void Team::setLeader(){
        Character *nextLeader = nullptr;
        bool first_champ = true;

        for(Character* champ : _champions){
            if(champ != _team_leader){
                if(first_champ){
                    if(champ->isAlive()){
                        nextLeader = champ;
                        first_champ = false;
                    }
                }
                else if(_team_leader->distance(champ) < _team_leader->distance(nextLeader)){
                    if(champ->isAlive()){
                        nextLeader = champ;
                    }
                }
            }
        }
        _team_leader = nextLeader;
    }

    Character* Team::ClosestCharacter(Team* team){
        bool first_champ = true;
        Character *closest = nullptr;
        vector<Character*> champions = team->getChampions();

        for(Character* champ : champions){
            if((champ != _team_leader) && (champ->isAlive())){
                if(first_champ){
                    closest = champ;
                    first_champ = false;
                }
                else if(_team_leader->distance(champ) < _team_leader->distance(closest)){
                    closest = champ;
                }
            }
        }
        return closest;
    }
}