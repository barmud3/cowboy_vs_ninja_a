#include "Point.hpp"


Point::Point(double posX , double posY) : posX(posX) , posY(posY)
{

}

double Point::distance(Point& point)
{
    return 5.5;
}

void Point::print()
{
    cout << "Stam Print";
}

Point Point::moveTowards(Point& source , double distance)
{
    return Point(5.5,3.5);
}
