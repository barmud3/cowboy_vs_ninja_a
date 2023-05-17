#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

class Team2 : public Team{
private:
vector<Character*> warriors;
Character* leader;

public:
Team2(Character* leader);
Team2();
void attack(Team2* enemyTeam);
void print();
virtual ~Team2();
Team2(Team2* team);
Team2& operator=(const Team2& other);
};

#endif