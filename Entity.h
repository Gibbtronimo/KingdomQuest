//******************************************************************* 
// Game Project: Kingdom Quest
// Date: October 7th, 2022
// Program description: This program is a game entity inheritance h file
//******************************************************************* 

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int d20();
int d10();
int d8();
int d6();

/*
	Entity Parent Class
	-------------------
	The class below acts
	as a parent class to
	all entities in our 
	game. It includes 
	setter and getter func-
	tions for variables used
	by all entities like
	health, armor class, 
	attack damage, and 
	speed.
*/


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
	Entity()   				// Default Constructor
	{ 
	    health = 0; 
	    armorClass = 0; 
	    attackDam = 0; 
	    speed = 0; 
	    id = 000; 
	}

    Entity(int entityID)   		// Constructor
    {
        switch(entityID) 
   	    {   
   	    	case 004:		 // goblin
   			   	health = 7; 
    			armorClass = 10; 
    		    attackDam = d6() + 2; 
    	    	speed = d20();
    	    	id = entityID;
    	    	break;

   		    case 001:
    	    	health = 24; 
    	    	armorClass = 12; 
        		attackDam = d8(); 
    	    	speed = d20(); 
    	    	id = entityID;
   		    	break;

   		    case 002:
    		    health = 29; 
    		    armorClass = 10; 
    		    attackDam = d10(); 
    		    speed = d20(); 
    		    id = entityID;
   			    break;
   			    
   			case 003:
    		    health = 16; 
    		    armorClass = 9; 
    	    	attackDam = 2 * d6(); 
    	    	speed = d20(); 
    	    	id = entityID;
   		    	break;

   		    xpScore = 0; 
    	   	level = 1; 
    	   	xpToGive = 50; 
   	    }
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

void Entity::setHealth(int h)
{ 
	health = h; 
}

int Entity::getHealth()
{ 
	return health; 
}

void Entity::setArmorClass(int ac)
{ 
	armorClass = ac; 
}

int Entity::getArmorClass()
{
	return armorClass;
}

void Entity::setSpeed(int s)
{ 
	speed = s; 
}
        
int Entity::getSpeed()
{ 
	return speed; 
}

void Entity::setAttackDamage(int ad)
{ 
	attackDam = ad; 
}
       
int Entity::getAttackDamage()
{ 
	return attackDam; 
}

void Entity::takeDamage(int dam)
{ 
	health -= dam; 
}
       
int Entity::getID()
{ 
	return id; 
}

int Entity::getLevel()
{ 
    return level; 
}

int Entity::getScore()
{ 
    return xpScore; 
}

int Entity::getHitDie()
{ 
	return hitDie; 
}

int Entity::getXP()
{ 
	return xpToGive; 	
}

int Entity::rollDamage()
{  	
    return d6() + 2; 
}

int Entity::rollDamage(int entityID)
{ 
   	int damage = 0;

   	switch(entityID) 
   	{
  		case 001:
    		for(int i = 0; i < level; i++)
    		damage += d8();
    		return damage;
   
   		case 002:
    		for(int i = 0; i < level; i++)
    		damage += d10();
    		return damage;
   				
   		case 003:
    		for(int i = 0; i < level*2; i++)
    		damage += d6();
    		return damage;
    				
    	default:
    		return 0;
  	}
}


int d20()	//one of the die that is used for certain scenarios
{
	int die;
	const int min = 1, max = 20;

	unsigned seed = time(0);
	srand(seed);

	die = (rand() % (max - min + 1)) + min;
	
	//cout << "D20: " << die << endl; // (used this to test if it worked)
	
	return die;
}

int d10()	//one of the die that is used for certain scenarios
{
	int die;
	const int min = 1, max = 10;

	unsigned seed = time(0);
	srand(seed);

	die = (rand() % (max - min + 1)) + min;
	
	//cout << "D10: " << die << endl; // (used this to test if it worked)
	
	return die;
}

int d8()	//one of the die that is used for certain scenarios
{
	int die;
	const int min = 1, max = 8;

	unsigned seed = time(0);
	srand(seed);

	die = (rand() % (max - min + 1)) + min;
	
	//cout << "D8: " << die << endl; // (used this to test if it worked)
	
	return die;
}

int d6()	//one of the die that is used for certain scenarios
{
	int die;
	const int min = 1, max = 6;

	unsigned seed = time(0);
	srand(seed);

	die = (rand() % (max - min + 1)) + min;
	
	//cout << "D6: " << die << endl; // (used this to test if it worked)
	
	return die;
}

#endif
