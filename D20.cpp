#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int die(int max);

int main()
{
	int num = 0;

	num = die(20);

	if(num != 8 && num != 11)
		cout << "You rolled a " << num << endl;
	else 
		cout << "You rolled an " << num << endl;
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
