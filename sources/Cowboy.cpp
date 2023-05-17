#include "Cowboy.hpp"

Cowboy::Cowboy(string name , Point location)
    :Character(name, location , 110) , numOfBullets(6)
    {

    }

void Cowboy::shoot(Character* enemy)
{
    this->numOfBullets--;
    enemy->hit(1);
}

bool Cowboy::hasboolets(){
    return true;
}

void Cowboy::reload()
{
    this->numOfBullets = 6;
}

 Cowboy* Cowboy::clone(const Cowboy* copyFigure) 
 {
    return new Cowboy(*this);
 }