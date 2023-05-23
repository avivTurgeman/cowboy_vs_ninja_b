#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel{
    class Ninja : public Character{
        protected:
            int _speed;
 
        public:
            //constructor
            Ninja(std::string name, const Point& location, int hp, int speed);

            //Ninja methods
            void move(Character*);
            void slash(Character*);
            std::string print() override;
    };
}

#endif