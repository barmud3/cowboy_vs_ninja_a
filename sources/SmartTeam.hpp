#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"

class SmartTeam : public Team{
private:
vector<Character*> warriors;
Character* leader;

public:
SmartTeam(Character* leader);
SmartTeam(SmartTeam* team);
SmartTeam& operator=(const SmartTeam& other);
void attack(SmartTeam* enemyTeam);
void print();
~SmartTeam();
};

#endif