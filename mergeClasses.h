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

	void setName(string n)
	{
		locName = n;
	}

	string getName(void)
	{
		return locName;
	}

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

	void nextLocat()
	{
		string resp;
      bool invalidIn = true;
		if (currY < 3)
		{
			currY++;
			cout << "Going to " << getLocat().getName() << endl;
		}
		else
		{
			currY = 0;

			if (currX == 0) //Forest
			{
            while(invalidIn)
            {
               cout << "Which Area Would You Like to Go to Next? (1. East Town 2. Castle 3. West Town): ";
               getline(cin, resp);

               if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 4)
               {
                  invalidIn = false;
                  if (resp == "1")
                     currX = 1;
                  else if (resp == "2")
                     currX = 2;
                  else if (resp == "3")
                     currX = 3;
               }
               else
               {
                  cout << "User Input is Invalid" << endl;
               }
            }
			}
			else if (currX == 1) //East Town
			{
            while(invalidIn)
            {
               cout << "Which Area Would You Like to Go to Next? (1. Forest 2. Castle 3. Mountain): ";
               getline(cin, resp);

               if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 4)
               {
                  invalidIn = false;
                  if (resp == "1")
                     currX = 0;
                  else if (resp == "2")
                     currX = 2;
                  else if (resp == "3")
                     currX = 4;
               }
               else
               {
                  cout << "User Input is Invalid" << endl;
               }
            }
			}
			else if (currX == 2) //Castle
			{
				cout << "Final Area is Special, Gotta Code the Dumb Thing to do Special Thing" << endl;
			}
			else if (currX == 3) //West Town
			{
            while(invalidIn)
            {
               cout << "Which Area Would You Like to Go to Next? (1. Forest 2. Castle 3. Mountain): ";
               getline(cin, resp);

               if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 4)
               {
                  invalidIn = false;
                  if (resp == "1")
                     currX = 0;
                  else if (resp == "2")
                     currX = 2;
                  else if (resp == "3")
                     currX = 4;
               }
               else
               {
                  cout << "User Input is Invalid" << endl;
               }
            }
			}
			else if (currX == 4) //Mountain
			{
				while(invalidIn)
				{
					cout << "Which Area Would You Like to Go to Next? (1. East Town 2. Castle 3. West Town): ";
					getline(cin, resp);

					if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 4)
					{
						invalidIn = false;
						if (resp == "1")
							currX = 1;
						else if (resp == "2")
							currX = 2;
						else if (resp == "3")
							currX = 3;
					}
					else
					{
						cout << "User Input is Invalid" << endl;
					}
				}
			}

			cout << "Going to " << getLocat().getName() << endl;
		}
	}
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

void Entity::setHealth(int h){ health = h; }

int Entity::getHealth(){ return health; }

void Entity::setArmorClass(int ac){ armorClass = ac; }

int Entity::getArmorClass(){ return armorClass; }

void Entity::setSpeed(int s){ speed = s; }
        
int Entity::getSpeed(){ return speed; }

void Entity::setAttackDamage(int ad){ attackDam = ad; }
       
int Entity::getAttackDamage(){ return attackDam; }

void Entity::takeDamage(int dam){ health -= dam; }
       
int Entity::getID(){ return id; }

int Entity::getLevel(){ return level; }

int Entity::getScore(){ return xpScore; }

int Entity::getHitDie(){ return hitDie; }

int Entity::getXP(){ return xpToGive; }

int Entity::rollDamage()
{ 
    int damage = 0;

    switch(id) 
    {
        case 1:
            for(int i = 0; i < level; i++)
                damage += die(8);
            cout << "\n You brandish your Greatsword and swing dealing " << damage << " points of damage!\n";
            return damage;
   
        case 2:
            for(int i = 0; i < level; i++)
                damage += die(10);
            cout << "\n You reel back and swing your Battle Ax dealing " << damage << " points of damage!\n";
            return damage;
                
        case 3:
            for(int i = 0; i < level*2; i++)
                damage += die(6);
            cout << "\n You chant and flourish your wand casting a spell that deals " << damage << " points of damage!\n";
            return damage;
            
        case 4:
            damage = die(6) + 2;
            cout << "\n The Goblin lashes out at you dealing " << damage << " points of damage!\n";
            return damage;
            break;
            
        default:
            return 0;
    }
}

int die(int max)    //one of the die that is used for certain scenarios
{
    int die;
    const int min = 1;

    unsigned seed = time(0);
    srand(seed);

    die = (rand() % (max - min + 1)) + min;
    
    //cout << "D20: " << die << endl; // (used this to test if it worked)
    
    return die;
}