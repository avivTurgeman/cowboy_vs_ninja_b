#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja : public Ninja{

        public:
            //constructor
            TrainedNinja(std::string name, const Point& location);
    };
} 

#endif