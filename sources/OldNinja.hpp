#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Ninja.hpp"

class OldNinja :virtual public Ninja{
    public:
    OldNinja(string name,Point& location);
    virtual OldNinja* clone(const OldNinja* copyFigure);
};

#endif