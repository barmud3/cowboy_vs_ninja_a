#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP
#include "Ninja.hpp"

class YoungNinja : public virtual Ninja {
    public:
    YoungNinja(string name , Point location);
    //virtual YoungNinja* clone(const YoungNinja* copyFigure);
};

#endif