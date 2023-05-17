#include "Character.hpp"

Character::Character(string name, Point& location, int lifeLevel)
    :name(name), location(location), lifeLevel(lifeLevel)
{

}

bool Character::isAlive()
{
    return true;
}

double Character::distance(Character* figure)
{
    return 5.5;
}

void Character::hit(int reduceLife)
{
    this->lifeLevel -= reduceLife;
}

string Character::print()
{
    return "Just regualr print for now";
}

 Character* Character::clone(const Character* copyFigure) 
 {
    return new Character(*this);
 }

//copy constructor
Character::Character(Character* character)
    : name(character->name), location(character->location), lifeLevel(character->lifeLevel)
{
}
Character& Character::operator=(const Character& other)
{
    return *this;
}
Character::~Character()
{

}