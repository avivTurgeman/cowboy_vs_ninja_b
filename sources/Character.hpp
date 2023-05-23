#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"

namespace ariel{
    class Character{
        protected:
            Point _location;
            int _hp;
            std::string _name;
            bool _team_player;

        public:
            //constructor
            Character(std::string, const Point&, int hp);
            // Copy Constructor
            Character (Character&);
             // Move Constructor
            Character(Character&& ) noexcept;
            // Copy Assignment operator
            Character& operator = (const Character&); 
            // Move Assignment operator
            Character& operator = (Character&&) noexcept; 
 
            virtual ~Character() = default;

            bool isAlive();
            double distance(Character*);
            void hit(int);
            virtual std::string print() = 0;

            std::string getName(){
                return _name;
            }
            Point getLocation(){
                return _location;
            }

            void setLocation(Point location){
                _location = location;
            }

            bool isTeamate(){
                return _team_player;
            }

            void setPlaying(bool playing){
                _team_player = playing;
            }
    };
}

#endif