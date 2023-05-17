#include "Team2.hpp"

Team2::Team2(Character* leader):Team(leader)
{

}

//copy constructor
Team2::Team2(Team2* team):Team(team->leader)
{

}
Team2& Team2::operator=(const Team2& other)
{
    return *this;
}

void Team2::attack(Team2* enemyTeam)
{

}
void Team2::print()
{
    cout << "stam";
}
Team2::~Team2()
{

}