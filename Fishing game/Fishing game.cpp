#include <iostream>
#include <time.h>
#include "fishing.h"
using namespace std;
void getLake(int& n, int& m)
{
	cout << "Lenght: ";
	cin >> n;
	cout << "Width: ";
	cin >> m;
}
void illegalInput(int& input, int benchmark)
{

	if (input > benchmark) {
		bool legal = false;
		do
		{
			cout << "New input: ";
			cin >> input;
			if (input <= benchmark)
			{
				legal = true;
			}
		} while (!legal);
	}

}
void setLegalSecond(int& first, int& second) //the second input needs to be always greater then the first
{
	if (first > second)
	{
		swap(first, second);
	}
}
void proFisherman(int& sRow, int& fRow, int& sCol, int& fCol, int n, int m)
{
	cout << "Tell the pro fisher in which are of the lake to fish \n";
	cout << "Starting row: ";
	cin >> sRow;
	illegalInput(sRow, n);
	cout << "Final row: ";
	cin >> fRow;
	setLegalSecond(sRow, fRow);
	illegalInput(fRow, n);
	cout << "Starting column: ";
	cin >> sCol;
	illegalInput(sCol, m);
	cout << "Final column: ";
	cin >> fCol;
	setLegalSecond(sCol, fCol);
	illegalInput(fCol, m);
}


void print_menu()
{
	cout << "------------------------------------------------" << endl;
	cout << "1. Print Lake" << endl;
	cout << "2. Get number of species" << endl;
	cout << "3. Get occurance of every species" << endl;
	cout << "4. Get width of pond" << endl;
	cout << "5. Get lenght of pond" << endl;
	cout << "6. Ametour fisher goes fishing" << endl;
	cout << "7. Pro fisher goes fishing" << endl;
	cout << "8.Exit" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Insert the desiered command: " << endl;
}
void getComand(int& cmd)
{
	cin >> cmd;
}
void play(int n, int m)
{
	FishingPond* h = Create(0, 0);
	cout << "a. Put desired number of fish in the lake" << endl;
	cout << "b. Make a wild fishing pond" << endl;
	char Cmd;
	cin >> Cmd;
	if (Cmd == 'a')
	{
		h = Create(n, m);
		int number_of_fish;
		cout << "Number of fish: ";
		cin >> number_of_fish;
		srand(time(NULL));
		for (int i = 0; i < number_of_fish; i++)
		{
			PutFish(h, rand() % 10, rand() % 10, rand() % 101);
		}
	}
	else if (Cmd == 'b') //create a wild like, where the number of fish randomply set
	{
		h = CreateWild(n, m);
	}


	int cmd = -1;
	while (cmd != 8) {
		print_menu();
		getComand(cmd);
		switch (cmd)
		{
		case 1:
			PrintH(h);

			break;
		case 2:
			cout << "Number of species found in the pond: " << NumberOfSpecies(h) << endl;
			break;
		case 3:
			cout << "Fish species: \n";
			SpeciesOccurance(h);
			break;
		case 4:
			cout << "Pond width " << GetWidth(h) << endl;
			break;
		case 5:
			cout << "Pond lenght: " << GetLenght(h) << endl;
			break;
		case 6:
			cout << AmetourFisher(h) << endl;
			break;
		case 7:
			int sRow, fRow, sCol, fCol;
			proFisherman(sRow, fRow, sCol, fCol, n, m); //get coordinates for perimeter where, the fisher will throw the bate
			cout << "The pro fisher is throwing the bate in between rows " << sRow << " and " << fRow << " and collumns " << sCol << " and " << fCol << " and he caught a fish from species: " << ProffesionalFisher(h, sRow, fRow, sCol, fCol) << endl;
			break;
		case 8:
			Destroy(h);
			break;
			{
		default:
			break;
			}
		}
	}
}
int main()
{
	int n, m;
	getLake(n, m);
	play(n, m);
}