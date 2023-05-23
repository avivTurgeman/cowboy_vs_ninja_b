#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Ninja.hpp"

namespace ariel{
    class YoungNinja : public Ninja{

        public:
            //constructor
            YoungNinja(std::string name, const Point& location);
    };
} 

#endif