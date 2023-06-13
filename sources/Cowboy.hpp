#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <string>
#include "Character.hpp"

namespace ariel{
    class Cowboy : public Character{
        private: 
            int _balls_amount;

        public:
            //constructor
            Cowboy(std::string,const Point&);
            

            void shoot(Character*);
            bool hasboolets();
            void reload();
            std::string print() override;      
    };
}

#endif