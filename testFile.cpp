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

int main()
{
	cout << "\n\n\t\t\t     * KINGDOM QUEST * ";

	cout << "\n\n  You awaken deep in the forest laying in a crater surrounded by what appears to ";
	cout << "\nbe splatters of human blood and scorched earth. The woods all around you extend ";
	cout << "\ndeep and seemingly disappear into a cozy darkness. For some reason you cannot ";
	cout << "\nrecall the events that lead you to this place; In the distance, you hear a familiar ";
	cout << "\nvoice call to you. ";

	cout << "\n\n   * You shuffle to your feet and make your way through the thickets * ";

	cout << "\n\n  In a small clearing directly in front of you, you see King Balthasar, the crowned ";
	cout << "\nking of the kingdom, sitting upright with a wound on his chest surrounded by small ";
	cout << "\nmushroom people using some kind of magic to heal his wound. He beckons to you and ";
	cout << "\nexplains the events that unfolded over the course of the last couple hours. Sometime ";
	cout << "\naround mid day, the castle was attacked and the king suffered a great loss, his royal ";
	cout << "\nguards and his claim to the throne; when an evil archmage named Volkarth attacked and ";
	cout << "\nseized control of the castle. ";

	cout << "\n\n  The guards fought valiantly but could not defeat Volkarth ";
	cout << "\nand his magic; Having reached the king’s chambers, Volkarth then attempted to kill the ";
	cout << "\nking and claim the throne for himself but, before he could, someone intervened. With ";
	cout << "\nhis dying words, Aerowynn, the king’s mage, cast a spell to eject all surviving members ";
	cout << "\nof the king’s guard, and the king himself, to the safety of the southern forest. ";
	cout << "\nYou are all that remains of my guards, you must travel across the land and defeat Volkarth. ";
	cout << "\nHowever, it is dangerous to go alone! Take this!";

	cout << "\n\n   * King Balthasar pulls out three weapons and lays them at your feet *";

    cout << "\n\n   * Before you lie three weapons: A Greatsword, A Battle Ax, and a Magic Wand  *";

    cout << "\n\n Which do you choose: ";

    bool inCombat = true;

    Entity player(002);
    Entity enemy(004);

    cout << "\n\n   You are attacked, Prepare for combat!!!\n\n";

    while(inCombat)
    {
        int dam = 0, choice = 0;

        cout << "Current Health: " << player.getHealth() << "\t" << "Enemy HP: " << enemy.getHealth() << endl;
                                
        cout << "\nWhat would you like to do?\n";
        cout << "1. Fight      2. Flee\n\n";

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


