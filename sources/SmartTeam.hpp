#ifndef SmartTEAM_HPP
#define SmartTEAM_HPP

#include "Team.hpp"

namespace ariel{
    class SmartTeam : public Team{
 
        public:
            //constructor
            SmartTeam(Character*);
            
            //Team2 methods
            void attack(Team*) override;
            void print() const override;
            Character* farthestCharacter(Cowboy *Cattacker, Team* enemy) const;
            Character* ClosestCharacterToNinja(Ninja *Nattacker, Team *enemy);

    };
}

#endif