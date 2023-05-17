#include "SmartTeam.hpp"

SmartTeam::SmartTeam(Character* leader):Team(leader)
{

}

//copy constructor
SmartTeam::SmartTeam(SmartTeam* team):Team(team->leader)
{

}
SmartTeam& SmartTeam::operator=(const SmartTeam& other)
{
    return *this;
}

void SmartTeam::attack(SmartTeam* enemyTeam)
{

}
void SmartTeam::print()
{
    cout << "stam";
}
SmartTeam::~SmartTeam()
{

}