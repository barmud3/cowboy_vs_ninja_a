#include "Ninja.hpp"

Ninja::Ninja(string name , Point& location , int lifelevel ,int speed):
    Character(name,location ,lifelevel) , speed(speed)
{
    
}

void Ninja::move(Character* enemy)
{
    this->setLocation(enemy->getLocation());
}

void Ninja::slash(Character* enemy)
{
    enemy->hit(20);
}
 Ninja* Ninja::clone(const Ninja* copyFigure) 
 {
    return new Ninja(*this);
 }