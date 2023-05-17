#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Point.hpp"
#include "string.h"
using namespace std;

class Character{
    private:
    string name;
    Point location;
    int lifeLevel;
    
    public:
    Character(string name, Point& location ,int lifeLevel);
    bool isAlive();
    double distance(Character* figure);
    void hit(int reduceLife);
    string getName() {return this->name;}
    Point& getLocation() {return this->location;}
    void setLocation(Point& newLocation) {this->location = newLocation;}
    string print();
    virtual Character* clone(const Character* copyFigure);
    //copy constructor
    Character(Character* charcter);
    Character& operator=(const Character& other);
    virtual ~Character();
    
};

#endif