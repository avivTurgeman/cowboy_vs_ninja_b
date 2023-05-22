#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel{
    class Team2 : public Team{

        public:
            //constructor
            Team2(Character*);

            //Team2 methods
            void attack(Team*) override;
            void print() const override;

    };
}

#endif