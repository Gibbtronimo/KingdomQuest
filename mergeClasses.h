 // Descr: This code holds the funtions that are called whenever the player
 //        is entered into a combat scenario and that executes the start of
 //        the game.
 // Start Date: Nov 10th, 2022
 // Final Date: Dec 1st, 2022 

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
    int speed;
    int level;
    int hitDie;
    int entityID;
    int maxHealth;

public:
    Entity()                // Default Constructor
    { 
        health = 0; 
        armorClass = 0; 
        speed = 0; 
        level = 1;
    }

    void setHealth(int h) { health = h; }
    void addHealth(int h) { health += h; }
    void setMaxHealth(int h) { maxHealth = h; }
    int getMaxHealth() { return maxHealth; }
    int getHealth() { return health; }
    void setArmorClass(int ac){ armorClass = ac; }
    int getArmorClass(){ return armorClass; }
    void setSpeed(int s){ speed = s; } 
    int getSpeed() { return speed; }
    void takeDamage(int dam) { health -= dam; }
    void setLevel(int l) { level = l; }
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
		enemyID = 1;
	}

    Loc(string n, int c, int enem)
    {
        locName = n;
        combOccur = c;
        enemyID = enem;
    }

	void setName(string n) { locName = n; }

	string getName(void) { return locName; }

    void setComb(int c) { combOccur = c; }

	int getComb() { return combOccur; }

    void setEnemyID(int enem) { enemyID = enem; }

	int getEnemyID() { return enemyID; }

	//Overload equals operator
};

class Player: public Entity
{
private:
    int xpScore = 0;
    const int xpArr[11] = {0, 150, 650, 1200, 2800, 3900, 5900, 9500, 12500, 20000, 999999};
	
    int currX;
	int currY;
    Loc locations[TOTAL_AREAS][TOTAL_LOCATIONS];

public:
	Player(int playerID)
	{
        int hp;
        int armor;
        int spd;
        
        switch(playerID)
        {
            case 1:
                hp = 24; 
                setMaxHealth(24);
                armor = 12; 
                spd = die(20);
                setID(playerID);
                break;

            case 2:
                hp = 29; 
                setMaxHealth(29);
                armor = 10; 
                spd = die(20); 
                setID(playerID);
                break;
                
            case 3:
                hp = 16; 
                setMaxHealth(16);
                armor = 9; 
                spd = die(20); 
                setID(playerID);
                break;
        };
		
        setHealth(hp);
        setArmorClass(armor);
        setSpeed(spd);
        
        xpScore = 0;

		currX = 0;
		currY = 0;
		
        locations[0][0] = Loc("Clearing", 5, 1); //Goblins
        locations[0][1] = Loc("Forest Temple", 5, 1);
        locations[0][2] = Loc("Goblin Camp", 15, 1);
        locations[0][3] = Loc("Clearing", 20, 2); //Ogre


        locations[1][0] = Loc("Town Square", 0, 3); //Cultists
        locations[1][1] = Loc("Creepy Alley", 17, 3);
        locations[1][2] = Loc("Shopping District", 8, 3);
        locations[1][3] = Loc("Festival Square", 20, 7); //Oracle


        locations[2][0] = Loc("Portico", 10, 9); //Death Knights
        locations[2][1] = Loc("White Hall", 19, 9);
        locations[2][2] = Loc("Courtyard", 19, 9);
        locations[2][3] = Loc("Throne Room", 20, 10); //Volkarth


        locations[3][0] = Loc("Town Square", 4, 6); //Displacer Beasts
        locations[3][1] = Loc("Creepy Alley", 17, 6);
        locations[3][2] = Loc("Shopping District", 17, 6);
        locations[3][3] = Loc("Market Square", 20, 8); //Stone Giant


        locations[4][0] = Loc("Base", 10, 4); //Troglodyte
        locations[4][1] = Loc("Cave", 16, 4);
        locations[4][2] = Loc("Cliffside", 13, 4);
        locations[4][3] = Loc("Peak", 20, 5); //Troll

	}

    void heal();

    int getX() { return currX; }

	int getY() { return currY; }

	Loc getLocat() { return locations[currX][currY]; }

	void nextLocat();

    int getScore() { return xpScore; } 

    void addXP(int xp){ xpScore += xp; }

    int rollDamage();

    void checkXP();
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
        int spd;
        
        enemName = "";

        // This switch statement creates different enemy types determined by an enemy id and 
        // gives every type unique values for health, armor, and experience points to give

        switch(enemyID) 
        {   
            case 1:        // Goblin
                enemName = "Goblin";
                hp = 14; 
                armor = 7; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 50;
                break;

            case 2:        // Ogre 
                enemName = "Ogre";
                hp = 38; 
                armor = 12; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 250;
                break;
            
            case 3:        // Cultist
                enemName = "Cultist";
                hp = 28; 
                armor = 12; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 150;
                break;

            case 4:        // Troglodyte
                enemName = "Troglodyte";
                hp = 23; 
                armor = 11; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 150;
                break;

            case 5:        // Troll
                enemName = "Troll";
                hp = 59; 
                armor = 13; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 250;
                break;

            case 6:        // Displacer Beast
                enemName = "Displacer Beast";
                hp = 34; 
                armor = 13; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 550;
                break;

            case 7:        // Oracle
                enemName = "Oracle";
                hp = 60; 
                armor = 14; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 650;
                break;

            case 8:        // Stone Giant
                enemName = "Stone Giant";
                hp = 67; 
                armor = 15; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 1200;
                break;
            
            case 9:        // Death Knight
                enemName = "Death Knight";
                hp = 42; 
                armor = 15; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 1250;
                break;

            case 10:        // Volkarth Magus
                enemName = "Darth Mage (Volkarth Magus)";
                hp = 100; 
                armor = 17; 
                spd = die(20);
                setID(enemyID);
                xpToGive = 5000;
                break;
        }
        setHealth(hp);
        setArmorClass(armor);
        setSpeed(spd);
    }

    string getName() { return enemName; }

    int getXP(){ return xpToGive; }

    int rollDamage();
};

#endif