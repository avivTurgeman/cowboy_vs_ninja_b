#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>

namespace ariel{
    class Point{
        private:
            double _x;
            double _y;

        public:
            
            Point(double x, double y);

            double distance(const Point& other) const;

            std::string print() const;
             
            static Point moveTowards(Point, Point, double);
            
            double getX() const{
                return _x;
            }
            double getY() const{
                return _y;
            }
    };
}

#endif