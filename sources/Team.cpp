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
            _champions[_champions_count++] = champion;
            champion->setPlaying(true);
        }

        else{
            throw std::runtime_error("Team can have at most 10 champions");
        }
    }

    void Team::attack(Team *other){
        if(other == nullptr){
            throw std::invalid_argument("cannot attack a null team");
        }
        return;
    }

    int Team::stillAlive() const{
        return _champions_count;
    }
    void Team::print() const{
        return;
    }
}