#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int die(int max);

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

int main()
{
    bool invalidIn = true;
    int choices = 0;
    string resp;

    cout << "\n\n\t\t\t      * KINGDOM QUEST * ";

    cout << "\n\n   You awaken deep in the forest laying in a crater surrounded by what appears to ";
    cout << "\n be splatters of human blood and scorched earth. The woods all around you extend ";
    cout << "\n deep and seemingly disappear into a cozy darkness. For some reason you cannot ";
    cout << "\n recall the events that lead you to this place; In the distance, you hear a familiar ";
    cout << "\n voice call to you. \n\n";

    cout << "\n\t    > Investigate the voice            > Ignore the voice \n\n";

    do{
        cout << "\n Which do you choose (1, 2)?" << endl;
        cout << "\n > ";
        getline(cin, resp);

        if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 3)
        {
            invalidIn = false;
            if (resp == "1")
               choices = 1;
            else if (resp == "2")
               choices = 2;
        }
        else
        {
            cout << "\n Invalid Input! Try Again!" << endl;
        }
    } while(invalidIn);

    invalidIn = true;

    if(choices == 2)
    {
        cout << "\n   You hear the pleas in the forest and ask yourself if it is worth the effort to investigate";
        cout << "\n to which you conclude that it is not. You lie back down and envelope yourself in the warmth";
        cout << "\n of the soil in the crater and the moss that grows along the forest floor. Slowly, the calls";
        cout << "\n weaken and the forest falls silent. Time passes and you feel yourself growing weaker until you";
        cout << "\n succumb to your wounds. You die peacefully; undisturbed in the southern forest.\n\n";

        cout << "\n\t\t\t\t   Game Over!\n\n";

        return 0;
    }

    cout << "\n\n    * You shuffle to your feet and make your way through the thickets * ";

    cout << "\n\n   In a small clearing directly in front of you, you see King Balthasar, the crowned ";
    cout << "\n king of the kingdom, sitting upright with a wound on his chest surrounded by the small ";
    cout << "\n mushroom people of the forest who are using some kind of spore magic to heal his wounds.";
    cout << "\n As you walk closer, you begin to feel rejuvinated; The wounds riddling your body begin ";
    cout << "\n to heal and you feel like a new man, ready to take on anything. ";

    cout << "\n\n   The king smiles and slowly beckons to you, then begins to explain the unfortunate series";
    cout << "\n of events that unfolded over the course of the last couple hours. Sometime around mid";
    cout << "\n day, the castle was attacked and the kingdom suffered a great loss; the royal guard was";
    cout << "\n defeated and the king's power was forecfully taken when an evil archmage named Volkarth ";
    cout << "\n attacked and seized control of the castle. ";

    cout << "\n\n   The guards fought valiantly but could not defeat Volkarth and his magic. Having";
    cout << "\n reached the king's chambers, Volkarth then attempted to kill the king and claim the";
    cout << "\n throne for himself, however, before he could someone intervened. With his dying words,";
    cout << "\n Aerowynn, the king's trusted mage, cast a spell to eject all surviving members of the  ";
    cout << "\n king's guard, and the king himself, to the safety of the southern forest. ";

    cout << "\n\n You are all that remains of my guards, you must travel across the land and defeat Volkarth. ";
    cout << "\n\t\t However, it is dangerous to go alone! Take this!";

    cout << "\n\n        * King Balthasar pulls out weapons and lays them at your feet *";

    cout << "\n\n   * Before you lie three weapons: A Greatsword, A Battle Ax, and a Magic Wand *\n";

    choices = 0;

    do{
        cout << "\n Which do you choose (1, 2, 3)?" << endl;
        cout << "\n > ";
        getline(cin, resp);

        if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 4)
        {
            invalidIn = false;
            if (resp == "1"){
                cout << "\n\t\t You have chosen the Fighter Class!\n";
                choices = 1;
            }
            else if (resp == "2"){
                cout << "\n\t\t You have chosen the Barbarian Class!\n";
                choices = 2;
            }
            else if (resp == "3"){
                cout << "\n\t\t You have chosen the Wizard Class!\n";
                choices = 3;
            }
        }
        else
        {
            cout << "\n Invalid Input! Try Again!" << endl;
        }
    } while(invalidIn);

    invalidIn = true;

    Entity player(00 + choices);

    bool inCombat = true;

    Entity enemy(004);

    // cout << "\n\n   ";
    // cout << "\n     ";
    // cout << "\n     ";
    // cout << "\n     ";
    // cout << "\n     ";
    // cout << "\n     ";

    cout << "\n\t * You are attacked by a Goblin; Prepare for combat! * \n";

    while(inCombat && enemy.getHealth() > 0 && player.getHealth() > 0)
    {
        int dam = 0, choice = 0;

        cout << "\n Goblin HP: " << enemy.getHealth() << endl << endl;
        
        cout << " Player HP: " << player.getHealth() << endl;
        
        do{
            cout << "\n   > Fight  \t  > Flee\n";
            cout << "\n What would you like to do (1, 2)?\n";
            cout << "\n > ";
            getline(cin, resp);

            if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 3)
            {
                invalidIn = false;
                if (resp == "1")
                   choice = 1;
                else if (resp == "2")
                   choice = 2;
            }
            else
            {
                cout << "\n Invalid Input! Try Again!" << endl;
            }
        } while(invalidIn);

        invalidIn = true;

        switch(choice) 
        {
            case 1:
                if (die(20) >= enemy.getArmorClass())
                {
                    dam = player.rollDamage();
                    enemy.setHealth(enemy.getHealth() - dam);
                }
                else
                    cout << "\n You swing and miss!\n";
                    
                if (die(20) >= player.getArmorClass() && enemy.getHealth() > 0)
                {
                    dam = enemy.rollDamage();
                    player.setHealth(player.getHealth() - dam);
                }
                else if(enemy.getHealth() > 0)
                    cout << "\n The enemy swung and missed!\n";
                break;

            case 2:
                if (die(20) >= 14)
                    inCombat = false;
                else
                {
                    cout << "\n You failed to escape!\n";
                    dam = enemy.rollDamage();
                    player.setHealth(player.getHealth() - dam);
                    cout << "\n The Goblin lashes out at you dealing " << dam << " points of damage!\n";
                }
                break;
        }
            
        if(enemy.getHealth() <= 0)
        {
            cout << "\n You have defeated the enemy!\n";
            inCombat = false;
        }
        
        if(player.getHealth() <= 0) {
            cout << "\n You were defeated in battle!\n";
            inCombat = false;
        }
    }
    cout << "\n\t\t\tGame Over!\n\n";
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


//  g++ -o combat testFile.cpp
