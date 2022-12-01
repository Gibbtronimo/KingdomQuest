#include <iostream>
#include <fstream>
#include <string>
#include "mergeClasses.h"

using namespace std;

void combatOccurence(Player &play)
{
    Loc currentLoc = play.getLocat();
    bool invalidIn = true;
    string resp;
    bool inCombat = true;

    Enemy enemy(currentLoc.getEnemyID());

    cout << "\n\t * You are attacked by a(n) " << enemy.getName() << ". Prepare for combat! * \n";

    //cout << "enemy health and level: " << enemy.getHealth() << " " << enemy.getLevel() << endl;
    //cout << "player health and level: " << player.getHealth() << " " << player.getLevel() << endl;
    
    while(inCombat && enemy.getHealth() > 0 && play.getHealth() > 0)
    {
        int dam = 0, choice = 0;

        cout << "\n\n " << enemy.getName() << " HP: " << enemy.getHealth() << endl << endl;
        
        cout << " Health: " << play.getHealth() << " / " << play.getMaxHealth() << endl;
        cout << "  Level: " << play.getLevel() << endl;
        cout << "     XP: " << play.getScore() << "\n";
        
        do{
            cout << "\n   > Attack  \t  > Heal\t > Flee\n";
            cout << "\n What would you like to do (1, 2, 3)?\n\n > ";
            getline(cin, resp);

            if(resp.length() == 1 && isdigit(resp[0]) && stoi(resp) > 0 && stoi(resp) < 4)
            {
                invalidIn = false;
                if (resp == "1")
                   choice = 1;
                else if (resp == "2")
                   choice = 2;
                else if (resp == "3")
                   choice = 3;
            }
            else
            {
                system("clear");
                cout << "\n Invalid Input! Try Again!" << endl;
            }
        } while(invalidIn);

        invalidIn = true;

        switch(choice) 
        {
            case 1:
                if (die(20) >= enemy.getArmorClass())
                {
                    system("clear");
                    dam = play.rollDamage();
                    enemy.setHealth(enemy.getHealth() - dam);
                }
                else
                {
                    system("clear");
                    cout << "\n You swing and miss!\n";
                }
                    
                if (die(20) >= play.getArmorClass() && enemy.getHealth() > 0)
                {
                    dam = enemy.rollDamage();
                    cout << "\n The " << enemy.getName() << " lashes out at you dealing " << dam << " points of damage!\n";
                    play.setHealth(play.getHealth() - dam);
                }
                else if(enemy.getHealth() > 0)
                    cout << "\n The " << enemy.getName() << " swung and missed!\n";
                break;

            case 2:
                system("clear");
                play.heal();
                if (die(20) >= play.getArmorClass() && enemy.getHealth() > 0)
                {
                    dam = enemy.rollDamage();
                    cout << "\n The " << enemy.getName() << " lashes out at you dealing " << dam << " points of damage!\n";
                    play.setHealth(play.getHealth() - dam);
                }
                else if(enemy.getHealth() > 0)
                    cout << "\n The " << enemy.getName() << " swung and missed!\n";
                break;

            case 3:
                system("clear");
                if (die(20) >= 14)
                    inCombat = false;
                else
                {
                    cout << "\n You failed to escape!\n";
                    dam = enemy.rollDamage();
                    play.setHealth(play.getHealth() - dam);
                    cout << "\n The " << enemy.getName() << " lashes out at you dealing " << dam << " points of damage!\n";
                }
                break;
        }
            
        if(enemy.getHealth() <= 0)
        {
            cout << "\n You have defeated the " << enemy.getName() << "!\n";
            play.addXP(enemy.getXP());
            inCombat = false;
        }
        
        if(play.getHealth() <= 0) 
        {
            cout << "\n You were defeated in battle!\n";
            cout << "\n High Score: " << play.getScore() << "\n";
            inCombat = false;
        }
    }
}

int main()
{
    bool invalidIn = true;
    int choices = 0;
    string resp;

    system("clear");
    
    cout << "\e[8;50;100t";

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
        ;

        cout << "\n   You hear the pleas in the forest and ask yourself if it is worth the effort to investigate,";
        cout << "\n to which you conclude that it is not. You lie back down and envelope yourself in the warmth";
        cout << "\n of the soil, the crater, and the moss that grows along the forest floor. Slowly, the calls";
        cout << "\n weaken and the forest falls silent. Time passes and you feel yourself growing weaker until you";
        cout << "\n succumb to your wounds. You die peacefully; undisturbed in the southern forest.\n\n";

        cout << "\n\t\t\t\t   Game Over!\n\n";

        return 0;
    }

    system("clear");

    cout << "\n\n      * You shuffle to your feet and make your way through the thickets * ";

    cout << "\n\n   In a small clearing directly in front of you, you see King Balthasar, the crowned ";
    cout << "\n king of the kingdom, sitting upright with a wound on his chest surrounded by the small ";
    cout << "\n mushroom people of the forest who are using some kind of spore magic to heal his wounds.";
    cout << "\n As you walk closer, you begin to feel rejuvinated; The wounds riddling your body begin ";
    cout << "\n to heal and you feel like a new man, ready to take on anything. ";

    cout << "\n\n   The king smiles and slowly beckons to you, then begins to explain the unfortunate series";
    cout << "\n of events that unfolded over the course of the last couple hours. Sometime around mid";
    cout << "\n day, the castle was attacked and the kingdom suffered a great loss; the royal guard was";
    cout << "\n defeated and the king's power was forcefully taken when an evil archmage named Volkarth ";
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
            system("clear");
            if (resp == "1")
            {
                cout << "\n\t\t You have chosen the Fighter Class!\n";
                choices = 1;
            }
            else if (resp == "2")
            {
                cout << "\n\t\t You have chosen the Barbarian Class!\n";
                choices = 2;
            }
            else if (resp == "3")
            {
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

    Player player(choices);

    combatOccurence(player);
    while(not(player.getX() == 2 && player.getY() == 3) && player.getHealth() > 0) //While not at final location and while players health is above zero, continue to go through locations and go through combat occurences
    {
        player.nextLocat();
        combatOccurence(player);
        player.checkXP();
    }
    
    cout << "\n\t\t\tGame Over!\n\n";
}