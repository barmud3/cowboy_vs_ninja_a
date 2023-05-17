#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;

namespace ariel{};


class Point{
    private:
    double posX;
    double posY;

    public:
    Point(double posX , double posY);
    double distance(Point& point);
    void print();
    Point moveTowards(Point& source , double distance);
};

#endif