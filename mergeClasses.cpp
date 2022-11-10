#include <iostream>
#include "mergeClasses.h"

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