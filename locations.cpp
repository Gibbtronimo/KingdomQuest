#include <iostream>
#include <string>

// Hi this is jesus
// Hi this is kody
using namespace std;

const int TOTAL_AREAS = 5;
const int TOTAL_LOCATIONS = 4;

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

int main()
{
	Player newPlayer;
	Loc temp = newPlayer.getLocat();
	cout << "Current area is " << temp.getName() << endl;
	while (newPlayer.getX() != 2 || newPlayer.getY() != 3 && newPlayer.getHP() != 0)
	{
		newPlayer.nextLocat();
	}
	return 0;
}