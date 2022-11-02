#include <iostream>
#include <string>

// Hi this is jesus

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
      Loc locations[TOTAL_AREAS][TOTAL_LOCATIONS];
   
   public:
      Player()
      {
         currX = 0;
         currY = 0;
         for(int i = 0; i < TOTAL_LOCATIONS; i++)
         {
            locations[0][i].setName("clearing" + to_string(i)); 
            locations[1][i].setName("eastTown" + to_string(i)); 
            locations[2][i].setName("castle" + to_string(i)); 
            locations[3][i].setName("westTown" + to_string(i)); 
            locations[4][i].setName("mountain" + to_string(i)); 
         }
      }

      Loc getLocat()
      {
         return locations[currX][currY];
      }

      void nextLocat()
      {
         int resp;
         if(currY < 3)
         {
            currY++;
            cout << "Going to " << getLocat().getName() << endl;
         }
         else
         {
            currY = 0;
            cout << "Which Area Would You Like to Go to Next? (1. East Town 2. Castle 3. West Town): ";
            cin >> resp;
            currX = resp;
            cout << "Going to " << getLocat().getName() << endl;
         }
      }
};

int main()
{
   Player newPlayer;
   Loc temp = newPlayer.getLocat();
   cout << "Current area is " << temp.getName() << endl;
   newPlayer.nextLocat();
   newPlayer.nextLocat();
   newPlayer.nextLocat();
   newPlayer.nextLocat();
   newPlayer.nextLocat();
	return 0;
}