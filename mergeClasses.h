#ifndef ENTITY_H
#define ENTITY_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

const int TOTAL_AREAS = 5;
const int TOTAL_LOCATIONS = 4;

int die(int max);

class Entity         // entity parent class
{
private:
    int health;
    int armorClass;
    int attackDam;
    int speed;
    int level;
    int hitDie;
    int entityID;

public:
    Entity()                // Default Constructor
    { 
        health = 0; 
        armorClass = 0; 
        attackDam = 0; 
        speed = 0; 
        level = 1;
    }

    void setHealth(int h) { health = h; }
    int getHealth() { return health; }
    void setArmorClass(int ac){ armorClass = ac; }
    int getArmorClass(){ return armorClass; }
    void setSpeed(int s){ speed = s; } 
    int getSpeed() { return speed; }
    void setAttackDamage(int ad) { attackDam = ad; }
    int getAttackDamage() { return attackDam; }
    void takeDamage(int dam) { health -= dam; }
    int getLevel() { return level; }
    int getHitDie(){ return hitDie; }
    void setID(int id) { entityID = id; }
    int getID() { return entityID; }
};

//----------------------------------------------------------------------

class Loc
{
private:
	string locName;
	int combOccur;
	int enemyID;

public:
	Loc()
	{
		locName = "";
		combOccur = 0;
		enemyID = 001;
	}

	void setName(string n) { locName = n; }

	string getName(void) { return locName; }

	int getComb() { return combOccur; }

    void setEnemyID(int passID) { enemyID = passID; }

	int getEnemyID() { return enemyID; }

	//Overload equals operator
};

class Player: public Entity
{
private:
    int xpScore;
	
    int currX;
	int currY;
    Loc locations[TOTAL_AREAS][TOTAL_LOCATIONS];

public:
	Player(int playerID)
	{
        int hp;
        int armor;
        int atk;
        int spd;
        
        switch(playerID)
        {
            case 1:
                hp = 24; 
                armor = 12; 
                atk = die(8); 
                spd = die(20);
                setID(playerID);
                break;

            case 2:
                hp = 29; 
                armor = 10; 
                atk = die(10); 
                spd = die(20); 
                setID(playerID);
                break;
                
            case 3:
                hp = 16; 
                armor = 9; 
                atk = 2 * die(6); 
                spd = die(20); 
                setID(playerID);
                break;
        };
		
        setHealth(hp);
        setArmorClass(armor);
        setAttackDamage(atk);
        setSpeed(spd);
        
        xpScore = 0;

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

	Loc getLocat() { return locations[currX][currY]; }

	void nextLocat();

    int getScore() { return xpScore; } 

    int rollDamage();
};


class Enemy: public Entity
{
private:
    string enemName;
    int xpToGive;

public:
    Enemy(int enemyID)
    {
        int hp;
        int armor;
        int atk;
        int spd;
        
        enemName = "";
        xpToGive = 50;

        switch(enemyID) 
        {   
            case 1:        // goblin
                enemName = "Goblin";
                hp = 23; 
                armor = 7; 
                atk = die(6) + 2; 
                spd = die(20);
                setID(enemyID);
                break;
        }
        setHealth(hp);
        setArmorClass(armor);
        setAttackDamage(atk);
        setSpeed(spd);
    }

    int getXP(){ return xpToGive; }

    int rollDamage();
};

#endif