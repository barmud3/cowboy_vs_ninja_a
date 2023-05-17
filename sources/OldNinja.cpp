#include "OldNinja.hpp"

OldNinja::OldNinja(string name, Point& location)
    :Ninja(name,location,150,8)
{
    
}
OldNinja* OldNinja::clone(const OldNinja* copyFigure) 
 {
    return new OldNinja(*this);
 }