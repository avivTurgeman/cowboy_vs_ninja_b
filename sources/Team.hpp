#ifndef TEAM_HPP
#define TEAM_HPP

#include <vector>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Ninja.hpp"
#include "Character.hpp"

namespace ariel{
    class Team{
        protected:
            std::vector<Character*> _champions;
            Character* _team_leader;
            int _champions_count;

        public:
            //constructor
            Team(Character*);

            //Team methods
            void add(Character*);
            virtual void attack(Team*);
            int stillAlive() const;
            virtual void print() const;
            Character* ClosestCharacter(Team* team);
            void setLeader();
            
            void champDied(){
                _champions_count -=1;
            } 

            std::vector<Character*> getChampions(){
                return _champions;
            }

    };
}

#endif