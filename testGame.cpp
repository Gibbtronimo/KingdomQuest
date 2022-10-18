#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	Node *left;
	Node *right;
	Node *forward;
	Node *back;
	string locatType;
	string script;
	bool intersection;
	bool explored;
}

Typedef Node* nodePtr

int main()
{
	nodePtr head;
	head = headNode;
	headNode->script = "this is a sample text";
	headNode->next = NULL;

	cout << head->script << endl;

	//string line;
	
	/*
  	ifstream myfile ("gameInfo.txt");

  	if (myfile.is_open())
  	{
  		while ( getline (myfile,line) )
    		{
      			cout << line << '\n';
    		}
	}
    myfile.close();
	*/
}