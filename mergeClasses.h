#ifndef ENTITY_H
#define ENTITY_H

#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TOTAL_AREAS = 5;
const int TOTAL_LOCATIONS = 4;

int die(int max);

class Loc
{
private:
	string locName;
	int combOccur;
	string enemName;

public:
	Loc()
	{
		locName = "";
		combOccur = 0;
		enemName = "monster";
	}

	void setName(string n) { locName = n; }

	string getName(void) { return locName; }

	int getComb() { return combOccur; }

	string getEnemName() { return enemName; }

	//Overload equals operator
};

class Player
{
private:
	int currX;
	int currY;
	int healthPoints;
	Loc locations[TOTAL_AREAS][TOTAL_LOCATIONS];

public:
	Player()
	{
		healthPoints = 20;
		currX = 0;
		currY = 0;
		for (int i = 0; i < TOTAL_LOCATIONS; i++)
		{
			locations[0][i].setName("clearing" + to_string(i));
			locations[1][i].setName("eastTown" + to_string(i));
			locations[2][i].setName("castle" + to_string(i));
			locations[3][i].setName("westTown" + to_string(i));
			locations[4][i].setName("mountain" + to_string(i));
		}
	}

	int getX() { return currX; }

	int getY() { return currY; }

	int getHP() { return healthPoints; }

	Loc getLocat() { return locations[currX][currY]; }

	void nextLocat();
};


//-----------------------------------------------

class Entity         // entity parent class
{
private:
    int health;
    int armorClass;
    int attackDam;
    int speed;
    int id;
    int level;
    int xpScore;
    int hitDie;
    int xpToGive;
    int enemyID;

public:
    Entity()                // Default Constructor
    { 
        health = 0; 
        armorClass = 0; 
        attackDam = 0; 
        speed = 0; 
        id = 000; 
    }

    Entity(int entityID)        // Constructor
    {
        switch(entityID) 
        {   
            case 004:        // goblin
                health = 23; 
                armorClass = 7; 
                attackDam = die(6) + 2; 
                speed = die(20);
                id = entityID;
                break;

            case 001:
                health = 24; 
                armorClass = 12; 
                attackDam = die(8); 
                speed = die(20); 
                id = entityID;
                break;

            case 002:
                health = 29; 
                armorClass = 10; 
                attackDam = die(10); 
                speed = die(20); 
                id = entityID;
                break;
                
            case 003:
                health = 16; 
                armorClass = 9; 
                attackDam = 2 * die(6); 
                speed = die(20); 
                id = entityID;
                break;
        }
        xpScore = 0; 
        level = 1; 
        xpToGive = 50; 
    }
    void setHealth(int h);
    int getHealth(); 
    void setArmorClass(int ac);
    int getArmorClass();
    void setSpeed(int s); 
    int getSpeed(); 
    void setAttackDamage(int ad); 
    int getAttackDamage(); 
    void takeDamage(int dam); 
    int getID(); 
    int rollDamage(int entityID);
    int getLevel(); 
    int getScore(); 
    int getHitDie(); 
    int getXP();
    int rollDamage();
};

#endif