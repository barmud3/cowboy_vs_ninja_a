#include "Team.hpp"

Team::Team(Character* leader):leader(leader)
{

}
//copy constructor
Team::Team(Team* team)
{

}
Team& Team::operator=(const Team& other)
{
    return *this;
}
Team::~Team()
{
    // for (Character* warriors : this->warriors) {
    //     delete warriors;
    // }
}


void Team::add(Character* newWarrior)
{
    
}
void Team::attack(Team* enemyTeam)
{

}
int Team::stillAlive()
{
    return 0;
}
void Team::print()
{
    cout << "stam";
}