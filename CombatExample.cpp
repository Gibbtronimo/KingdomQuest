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

public:
	Entity()   				// Default Constructor
   { 
       health = 0; 
       armorClass = 0; 
       attackDam = 0; 
       speed = 0; 
       id = 000; 
       
   }

    Entity(int entityID)   				// Constructor
   {
       switch(entityID) 
   	    {   case 004:		 // goblin
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
   	    }
   
    }
    };
   ~Entity();  			// Destructor
   void setHealth(int h)
   { health = h; }
   int getHealth()
   { return health; }
   void setArmorClass(int ac)
   { armorClass = ac; }
   int getArmorClass()
   { return armorClass; }
   void setSpeed(int s)
   { speed = s; }
   int getSpeed()
   { return speed; }
   void setAttackDamage(int ad)
   { attackDam = ad; }
   int getAttackDamage()
   { return attackDam; }
   void takeDamage(int dam)
   { health -= dam; }
   int getID()
   { return id; }
};

/*
		Player Child Class
		-------------------

		The class below acts
		as a child class to
		the player of our game. 
		It includes setter and
		getter functions for 
		variables used by the
		player like health, armor
		class, attack damage, and 
		speed.

*/

class Player : public Entity       // Player child class
{
private:
   int level;
   int xpScore;
   int hitDie;

public:
   Player(int entityID)             // Constructor
   { 
       xpScore = 0; 
       level = 1; 
   }
   ~Player();           // Destructor

   int rollDamage(int entityID)
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
  		}
        return 0;
  	}
  	
    
   void setLevel();
   int getLevel()
   { return level; }
   void setScore();
   int getScore()
   { return xpScore; }
   void setHitDie();
   int getHitDie()
   { return hitDie; }
   
   
};

/*
		Goblin Enemy Child Class
		------------------------

		The class is the child class
		to all goblin enemies in the 
		game, it includes, xp given
		upon defeat, damage value, and 
		the enemy id.

*/

class Goblin : public Entity       // goblin child class
{
private:
   int xpToGive;
   int enemyID;

public:
   Goblin(int id)             // Constructor
   { 
       xpToGive = 50; 
       enemyID = id;
   }

   ~Goblin();           // Destructor
   
   int getXP()
   { return xpToGive; }

   int rollDamage()
   { return d6() + 2; }
   
};

/*
		Main (Combat Example)
		---------------------

		Main runs through the 
		motions of a single
		monster encounter.

*/

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

int main()
{
	bool inCombat = true;

	Player player(002);
	Goblin enemy(004);

	while(inCombat)
	{
		int dam = 0, choice = 0;

		cout << "You are attacked, Prepare for combat!!!\n\n";

		cout << "What would you like to do?\n";
		cout << "1. Fight      2. Flee\n\n";

		cout << "Health: " << player.getHealth() << "\t\t" << "Enemy HP: " << enemy.getHealth() << endl;

		cin >> choice;

		switch(choice) 
		{
  			case 1:
    			if (d20() >= enemy.getArmorClass())
    			{
    				dam = player.rollDamage(player.getID());
    				enemy.takeDamage(dam);
    			}
    			else
    				cout << "You swing and miss!\n";
    			break;

   			case 2:
    			if (d20() > 14)
    				inCombat = false;
    			else
    			{
    				cout << "You failed to escape!\n";
    				dam = enemy.rollDamage();
    				player.takeDamage(dam);
    			}

    			break;
    	}

		if(player.getHealth() == 0 || enemy.getHealth() == 0)
			inCombat = false;
	}

	cout << "Combat has ended!\n\n";
}
