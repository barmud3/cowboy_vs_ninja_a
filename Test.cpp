#include "doctest.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "sources/Team.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Point work as needed")
{
    Point a(1,2),b(4,6);
    CHECK(a.distance(b) == b.distance(a));
    Point newA = a.moveTowards(b,6);
    //a and b at the same point.
    CHECK(newA.distance(b) == 0);

    Point c(0,0),d(5,0);
    Point newC = c.moveTowards(d,3);
    CHECK(c.distance(d) == 2);
}

TEST_CASE("Cowboy")
{
    Point a(0,0),b(5,0);
    Cowboy *zrubavel = new Cowboy("zrubavel", a);
    Cowboy *menhaem = new Cowboy("menhaem", b);
    CHECK(zrubavel->distance(menhaem) == 5);

    for (int i = 0; i < 5; i++)
    {
        zrubavel->shoot(menhaem);
    }

    CHECK(zrubavel->hasboolets() == true);
    zrubavel->shoot(menhaem);
    CHECK(zrubavel->hasboolets() == false);
    zrubavel->reload();
    CHECK(zrubavel->hasboolets() == true);


    CHECK(zrubavel->isAlive() == true);
    zrubavel->hit(110);
    CHECK(zrubavel->isAlive() == false);
    //zrubavel is dead
    CHECK_THROWS(zrubavel->reload());
    CHECK_THROWS(zrubavel->shoot(menhaem));
    CHECK_THROWS(zrubavel->setLocation(b));

    free(zrubavel);
    free(menhaem);
}


TEST_CASE("Ninja is dead")
{
    Point a(0,0),b(5,0);
    OldNinja *ninja1 = new OldNinja("LastWish", a);
    OldNinja *ninja2 = new OldNinja("plzNot", b);
    ninja2->hit(150); // ninja is dead
    CHECK(ninja2->isAlive() == false);
    CHECK_THROWS(ninja2->move(ninja1));
    CHECK_THROWS(ninja2->setLocation(a));
    CHECK_THROWS(ninja2->hit(20));
    CHECK_THROWS(ninja2->distance(ninja1));
    CHECK_THROWS(ninja2->slash(ninja1));

    free(ninja1);
    free(ninja2);
}

TEST_CASE("slash reduce exactly 40 points")
{
    Point a(0,0),b(0.5,0);
    OldNinja *ninja1 = new OldNinja("LastWish", a);
    OldNinja *ninja2 = new OldNinja("plzNot", b);
    ninja2->hit(110); // ninja left only with 40 life points
    CHECK(ninja2->isAlive());
    ninja1->slash(ninja2); //slash reduce 40 life points if distance < 1 meter
    CHECK(ninja2->isAlive() == false); // the distance is more than meter.

    free(ninja1);
    free(ninja2);
}

TEST_CASE("Slash work on <= 1 meter")
{
    Point a(0,0),b(1.0001,0);
    OldNinja *ninja1 = new OldNinja("LastWish", a);
    OldNinja *ninja2 = new OldNinja("plzNot", b);
    ninja2->hit(110); // ninja left only with 40 life points
    ninja1->slash(ninja2); //slash reduce 40 life points if distance < 1 meter
    CHECK(ninja2->isAlive()); // the distance is more than meter.
    Point newLocation = Point(1,0);
    ninja2->setLocation(newLocation);
    ninja1->slash(ninja2);
    CHECK(ninja2->isAlive() == false);
    
    free(ninja1);
    free(ninja2);
}

TEST_CASE("YoungNinja have 100 life points and speed of 14")
{
    //Check life points
    Point a(0,0),b(14,0);
    YoungNinja *ninja1 = new YoungNinja("LastWish", a);
    CHECK(ninja1->isAlive() == true);
    ninja1->hit(99);
    CHECK(ninja1->isAlive() == true);
    ninja1->hit(1); // ninja is dead
    CHECK(ninja1->isAlive() == false);

        //Check speed
    OldNinja *ninja2 = new OldNinja("LastWish2", a);
    OldNinja *ninja3 = new OldNinja("LastWish3", b);
    ninja2->move(ninja3);
    CHECK(ninja2->distance(ninja3) == 0);

    free(ninja1);
    free(ninja2);
    free(ninja3);
}

TEST_CASE("TrainedNinja have 120 life points and speed of 12")
{
    //Check life points
    Point a(0,0),b(12,0);
    TrainedNinja *ninja1 = new TrainedNinja("LastWish", a);
    CHECK(ninja1->isAlive() == true);
    ninja1->hit(119);
    CHECK(ninja1->isAlive() == true);
    ninja1->hit(1); // ninja is dead
    CHECK(ninja1->isAlive() == false);

    //Check speed
    OldNinja *ninja2 = new OldNinja("LastWish2", a);
    OldNinja *ninja3 = new OldNinja("LastWish3", b);
    ninja2->move(ninja3);
    CHECK(ninja2->distance(ninja3) == 0);

    free(ninja1);
    free(ninja2);
    free(ninja3);
}

TEST_CASE("OldNinja have 150 life points and speed of 8")
{
    //Check life points
    Point a(0,0),b(8,0);
    OldNinja *ninja1 = new OldNinja("LastWish", a);
    CHECK(ninja1->isAlive() == true);
    ninja1->hit(149);
    CHECK(ninja1->isAlive() == true);
    ninja1->hit(1); // ninja is dead
    CHECK(ninja1->isAlive() == false);

    //Check speed
    OldNinja *ninja2 = new OldNinja("LastWish2", a);
    OldNinja *ninja3 = new OldNinja("LastWish3", b);
    ninja2->move(ninja3);
    CHECK(ninja2->distance(ninja3) == 0);

    free(ninja1);
    free(ninja2);
    free(ninja3);
}

TEST_CASE("Team get null pointer")
{
    Point a(0,0);
    Character* nullCharacter = nullptr;
    CHECK_THROWS(Team(nullCharacter));
}