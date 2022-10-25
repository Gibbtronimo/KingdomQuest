#include <iostream>
#include <string>

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
         }
      }

      Loc getLocat()
      {
         return locations[currX][currY];
      }

      void nextLocat()
      {
         char resp;
         if(currY < 4)
         {
            cout << "Would you like to go to the next location? (Y/N)";
            cin >> resp;
            if(toupper(resp) == 'Y')
            {
               currY++;
            }
         }
      }
};

int main()
{
   Player newPlayer;
   Loc temp = newPlayer.getLocat();
   cout << "Current area is " << temp.getName() << endl;
   newPlayer.nextLocat();
   temp = newPlayer.getLocat();
   cout << "Current area is " << temp.getName() << endl;
	return 0;
}