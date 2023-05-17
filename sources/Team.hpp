#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "vector"

class Team {
private:
vector<Character*> warriors;
Character* leader;

public:
Team();
Team(Team&& other);  // Move constructor
Team(Character* leader);
Team(Team* team);
void add(Character* newWarrior);
void attack(Team* enemyTeam);
int stillAlive();
void print();
virtual ~Team();
Team& operator=(const Team& other);
};

#endif