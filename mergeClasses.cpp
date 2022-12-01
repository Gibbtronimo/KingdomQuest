 // Descr: This code holds the definitions for the functions that are declared
 //        in the player and enemy classes.
 // Start Date: Nov 10th, 2022
 // Final Date: Dec 1st, 2022 


#include <iostream>
#include "mergeClasses.h"

//-------------------------------------------------------------------------------------------
//Player Functions
//-------------------------------------------------------------------------------------------

// heal(): this function generates a random value to heal according to their player class
// and determines if the value heals them below or over their maximum possible health points
// if so the function sets their health to the maximum possible.

void Player::heal() 
{     
    int tempHP = 0;
    switch(getID())  // switch case checks the player class ID
    {
        case 1:     // Fighter Class
            for(int i = 0; i < getLevel(); i++)     // "rolls" a health die a number of times equal to the player level
                tempHP += die(8);
            break;

        case 2:     // Barbarian Class
            for(int i = 0; i < getLevel(); i++)     
                tempHP += die(10);
            break;

        case 3:     // Wizard Class
            for(int i = 0; i < getLevel(); i++)     
                tempHP += die(6);
            break;
    }

    if(tempHP + getHealth() <= getMaxHealth())      // checks to see if the generated number surpasses the maximum possible health points
    {
        addHealth(tempHP);                                      // adds the total generated value to their health
        cout << "\n You healed for " << tempHP << " hp!\n"; 
    }
    else           // if else
    {
        setHealth(getMaxHealth());                       // sets the player health to the maximum possible value
        cout << "\n You healed back to full hp!\n";
    }
}

// checkXP: this function checks to see if the player has reached the xp requirement
// to level up to the next level, if not nothing happens but if so then the player's
// level increases by one, their hp increases according to their class, and finally
// sets the player's health points to full.

void Player::checkXP()
{
    if(getScore() >= xpArr[getLevel()])     // check to see if the current player score is greater than the xp requirement
    {
        setLevel(getLevel() + 1);       // increase value of level by one
        switch(getID())                 // check ID to see what player class was chosen
        {
            case 1:     // Fighter Class
                setMaxHealth(getMaxHealth() + 6);   // increases the player health by a set value (fighter)
                break;

            case 2:     // Barbarian Class
                setMaxHealth(getMaxHealth() + 7);   
                break;

            case 3:     // Wizard Class
                setMaxHealth(getMaxHealth() + 4);   
                break;
        }
        setHealth(getMaxHealth());              // sets the player's health points to maximum possible
        cout << "\n You have leveled up!\n";    // displays a notification that you have leveled up
    }
}

// rollDamage(): this function is used to generate a random value for the damage 
// done by the player during a combat scenario. The function uses the player level
// to scale the damage done by a player accordingly and the display and return the 
// number generated.

int Player::rollDamage()
{ 
    int damage = 0;
    int level = getLevel();

    switch(getID())      // switch case checks the player class ID
    {

        case 1:     // Fighter Class
            for(int i = 0; i < level; i++)      // "rolls" a damage die a number of times equal to the player level
                damage += die(8);
            cout << "\n You brandish your Greatsword and swing dealing " << damage + 3 << " points of damage!\n";    
                                                // displays a message notifying yoyu of the damage dealt
            return damage + 3;                  // adds a modifier to the damage roll that is determined by player class
   
        case 2:     // Barbarian Class
            for(int i = 0; i < level; i++)      
                damage += die(10);
            cout << "\n You reel back and swing your Battle Ax dealing " << damage + 1 << " points of damage!\n";    
            return damage + 1;      
                
        case 3:     // Wizard Class
            for(int i = 0; i < level*2; i++)    
                damage += die(6);
            cout << "\n You chant and flourish your wand casting a spell that deals " << damage + 5 << " points of damage!\n";    
            return damage + 5;      

        default:
            return 0;
    }
}

// nextLocat(): this function displays different prompts for character traversal with varying options 
// dependent on the player's current location.

void Player::nextLocat()
{
    string resp;
    bool invalidIn = true;
    if (currY < 3)            // checks to see if you have reached the 3rd sub-area in a major area 
    {
        currY++;                                                    // if not, it pushes you forward to the next sub-area
        cout << "\n\n Going to " << getLocat().getName() << endl;   // displays a message to describe the next area
    }
    else
    {
        currY = 0;            // checks to see if you have reached the 3rd sub-area in a major area 

        if (currX == 0) // checks to see if you are located in the Forest
        {
        while(invalidIn)
        {
            cout << "\n Which Area Would You Like to Go to Next? (1. East Town 2. Castle 3. West Town)\n\n > "; // prompts you about what area you would like to go towards next
            getline(cin, resp);             // takes in user input

            if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 4)  // input validation (isdigit in range 1 - 3)
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
                cout << " User Input is Invalid" << endl;
            }
        }
        }
        else if (currX == 1) // checks to see if you are located in the East Town
        {
        while(invalidIn)
        {
            cout << "\n Which Area Would You Like to Go to Next? (1. Forest 2. Castle 3. Mountain): ";
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
        else if (currX == 2) // checks to see if you are located in the Castle
        {
            cout << "Final Area is Special, Gotta Code the Dumb Thing to do Special Thing" << endl;
        }
        else if (currX == 3) // checks to see if you are located in the West Town
        {
        while(invalidIn)
        {
            cout << "\n Which Area Would You Like to Go to Next? (1. Forest 2. Castle 3. Mountain): ";
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
                cout << " User Input is Invalid" << endl;
            }
        }
        }
        else if (currX == 4) // checks to see if you are located in the Mountain
        {
            while(invalidIn)
            {
                cout << "\n Which Area Would You Like to Go to Next? (1. East Town 2. Castle 3. West Town): ";
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
                    cout << "\n User Input is Invalid" << endl;
                }
            }
        }

        cout << "\n Going to " << getLocat().getName() << endl;   // displays a message to describe the next area
    }
}

//-------------------------------------------------------------------------------------------
//Enemy Functions
//-------------------------------------------------------------------------------------------

// rollDamage(): this function takes the entity ID of the enemy and rolls and returns a rand
// value for damage according to the monster type.

int Enemy::rollDamage()
{ 
    int damage = 0;

    switch(getID())    // switch case checks the enemy ID
    {
        case 1:     // Goblin
            damage = die(6) + 2;    // "rolls" a damage die unique to each monster type
            return damage;          // returns the value so that damage can be dealt
            break;

        case 2:     // Ogre
            damage = die(8) + die(8);
            return damage;
            break;

        case 3:     // Cultist
            damage = die(8) + 1;
            return damage;
            break;
        
        case 4:     // Oracle
            damage = die(6) + 1;
            return damage;
            break;

        case 5:     // Troglodyte
            damage = die(6) + die(6) + 4;
            return damage;
            break;

        case 6:     // Troll
            damage = die(8) + die(8) + 2;
            return damage;
            break;

        case 7:     // Displacer Beast
            damage = die(6) + die(6) + 4;
            return damage;
            break;

        case 8:     // Stone Giant
            damage = die(8) + die(8) + die(8);
            return damage;
            break;

        case 9:     // Death Knight
            damage = die(10) + die(10) + 2;
            return damage;
            break;

        case 10:    // Volkarth Magus (Final Boss)
            damage = die(20) + die(20) + 4;
            return damage;
            break;
            
        default:
            return 0;
    }
}

//-------------------------------------------------------------------------------------------
//Regular Functions
//-------------------------------------------------------------------------------------------

// Die(): This function uses the rand library in C++ to roll a metaphorical die with x sides, 
// x being a value passed during the funtion call, and return the random value to be used
// to determine damage amongst other uses.

int die(int max)    // recieves max, max is the number of sides/highest possible number to be rolled
{
    int die;
    const int min = 1;  // min is the minimum number to rolled

    unsigned seed = time(0);
    srand(seed);

    die = (rand() % (max - min + 1)) + min;
    
    //cout << "D20: " << die << endl; // (used this to test if it worked)
    
    return die;     // returns generated number
}