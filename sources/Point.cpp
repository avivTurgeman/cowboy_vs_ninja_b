#include "Point.hpp"

using namespace std;

namespace ariel{

    Point::Point(double x, double y):
    _x(x), _y(y){}

    double Point::distance(const Point& other) const{
        double otherX = other.getX();
        double otherY = other.getY();
        double x_pow = pow((otherX - _x), 2);
        double y_pow = pow((otherY - _y), 2);
        return sqrt(x_pow + y_pow);
    }

    string Point::print() const{
        return "(" +std::to_string(_x) + 
        "," + std::to_string(_y) + ")";
    }

    Point Point::moveTowards(Point src, Point dest, double dist){
        if(dist < 0){
            throw std::invalid_argument("distance must be a non-negative");
        } 
        double srcToDestDist = src.distance(dest);
        if(srcToDestDist <= dist){
            return dest;
        }
        double angle = atan2(dest.getY() - src.getY(), dest.getX() - src.getX());
        double newX = src.getX() + dist * cos(angle);
        double newY = src.getY() + dist * sin(angle);
        return Point(newX, newY);
    }
}
