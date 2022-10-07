//******************************************************************* 
// Game Project: Kingdom Quest
// Date: October 7th, 2022
// Program description: This program tests a linked list system to 
// keep track of a players place in a game world map.
//******************************************************************* 

#ifndef ENTITY_H
#define ENTITY_H

class Entity         // entity parent class
{
private:
   int health;
   int armorClass;
   int attackDam;
   int speed;
   string name;

public:
	Entity()   				// Constructor
   { health = 0; armorClass = 0; attackDam = 0; speed = 0; name = ''; }
   ~Entity();  			// Destructor

   void setHealth(int);
   int getHealth()
   { return health; }
   void setArmorClass(int);
   int getArmorClass()
   { return armorClass; }
   void setSpeed(int);
   int getSpeed()
   { return speed; }
   void setAttackDamage(int);
   int getAttackDamage()
   { return attackDam; }
   
};

class Player : public Entity       // goblin child class
{
private:
   int level;
   int xpScore;
   int hitDie;

public:
   Player()             // Constructor
   { xpToGive = 0; }
   ~Player();           // Destructor
   void setLevel();
   void getLevel()
   { return level; }
   void setScore();
   void getScore()
   { return xpScore; }
   void setHitDie();
   void getHitDie()
   { return hitDie; }
   
};

class Goblin : public Entity       // goblin child class
{
private:
   int xpToGive;
   int enemyID;

public:
   Goblin()             // Constructor
   { xpToGive = 0; }

   ~Goblin();           // Destructor
   void getXP()
   { return xpToGive; }
   
};

class Ogre : public Entity       // ogre child class
{
private:
   int xpToGive;
   int enemyID;

public:
   Ogre()             // Constructor
   { xpToGive = 0; }
   ~Ogre();           // Destructor
   void getXP()
   { return xpToGive; }
   
};

class Bandit : public Entity       // bandit child class
{
private:
   int xpToGive;
   int enemyID;

public:
   Bandit()             // Constructor
   { xpToGive = 0; }
   ~Bandit();           // Destructor
   void getXP()
   { return xpToGive; }
   
};

class Cultist : public Entity       // cultist child class
{
private:
   int xpToGive;
   int enemyID;

public:
   Cultist()             // Constructor
   { xpToGive = 0; }
   ~Cultist();           // Destructor
   void getXP()
   { return xpToGive; }
   
};

class Beast : public Entity       // harpy child class
{
private:
   int xpToGive;
   int enemyID;

public:
   Beast()             // Constructor
   { xpToGive = 0; }
   ~Beast();           // Destructor
   void getXP()
   { return xpToGive; }
   
};

class Giant : public Entity       // giant child class
{
private:
   int xpToGive;
   int enemyID;

public:
   Giant()             // Constructor
   { xpToGive = 0; }
   ~Giant();           // Destructor
   void getXP()
   { return xpToGive; }

};

class DeathKight : public Entity       // death knight child class
{
private:
   int xpToGive;
   int enemyID;

public:
   DeathKight()             // Constructor
   { xpToGive = 0; }
   ~DeathKight();           // Destructor
   void getXP()
   { return xpToGive; }
   
};

class Gilgamesh : public Entity       // gilgamesh child class
{
private:
   int xpToGive;
   int enemyID;

public:
   Gilgamesh()             // Constructor
   { xpToGive = 0; }
   ~Gilgamesh();           // Destructor
   void getXP()
   { return xpToGive; }
   
};

#endif