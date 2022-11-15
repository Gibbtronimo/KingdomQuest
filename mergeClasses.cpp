#include <iostream>
#include "mergeClasses.h"

//-------------------------------------------------------------------------------------------
//Player Functions
//-------------------------------------------------------------------------------------------

int Player::rollDamage()
{ 
    int damage = 0;
    int level = getLevel();

    switch(getID()) 
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
            
        default:
            return 0;
    }
}

void Player::nextLocat()
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

//-------------------------------------------------------------------------------------------
//Enemy Functions
//-------------------------------------------------------------------------------------------

int Enemy::rollDamage()
{ 
    int damage = 0;

    switch(getID()) 
    {
        case 1:
            damage = die(6) + 2;
            cout << "\n The Goblin lashes out at you dealing " << damage << " points of damage!\n";
            return damage;
            break;
            
        default:
            return 0;
    }
}

//-------------------------------------------------------------------------------------------
//Regular Functions
//-------------------------------------------------------------------------------------------

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