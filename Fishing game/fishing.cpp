#include "fishing.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

FishingPond* Create(int n, int m)
{
	FishingPond* new_halasto = new FishingPond;
	new_halasto->n = n;
	new_halasto->m = m;
	new_halasto->pond = new int* [n];
	for (int i = 0; i < n; i++)
	{
		new_halasto->pond[i] = new int[m] {0};
	}
	new_halasto->species_db = 0;
	new_halasto->db = 0;
	new_halasto->species[101];
	for (int i = 0; i < 101; i++)
	{
		new_halasto->species[i] = 0;
	}
	
	return new_halasto;
}


FishingPond* CreateWild(int n, int m)
{
	FishingPond* new_halasto = Create(n, m);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = rand()%m; j < m; j++)
		{
			new_halasto->pond[i][j] = rand() % 101;
			if (new_halasto->pond[i][j] != 0)
			{
				new_halasto->species[new_halasto->pond[i][j]]++;
				new_halasto->db++;
			}
			if (new_halasto->species[new_halasto->pond[i][j]] == 1)
			{
				new_halasto->species_db++;
			}
		}
	}
	return new_halasto;
}

void Destroy(FishingPond* tmp)
{
	for (int i = 0; i < tmp->n; i++)
	{
		delete[] tmp->pond[i];
	}
	delete[] tmp->pond;
	delete[] tmp->species;
	tmp->species_db = 0;
	tmp->db = 0;
}

void PutFish(FishingPond* h, int row, int column,int Species) 
{
	if (h->pond[row][column] != 0)
	{
		h->species[h->pond[row][column]]--;
		h->db--;
		if (h->species[h->pond[row][column]] == 0)
		{
			h->species_db--;
		}
	}
	
	
		h->pond[row][column] = Species;
		h->species[Species]++;
		if (h->species[Species] == 1)
		{
			h->species_db++;
		}
		h->db++;
	
}

int GetFish(FishingPond* h, int sor, int oszlop)
{
	return h->pond[sor][oszlop];
}
int GetNrFish(FishingPond* h)
{
	return h->db;
}
int GetWidth(FishingPond* h)
{
	return h->m;
}
int GetLenght(FishingPond* h)
{
	return h->n;
}

int NumberOfSpecies(FishingPond* h)
{
	return h->species_db;
}

void print_species(int k)
{
	cout << "Species " << k << " is found: ";
}
void SpeciesOccurance(FishingPond* h)
{
	bool printed = false;

	for (int i = 0; i < 101; i++)
	{
		bool printed = false;
		if (h->species[i] != 0)
		{
			for (int j = 0; j < h->n; j++)
			{
				for (int k = 0; k < h->m; k++)
				{
					if (h->pond[j][k] == i && h->pond[j][k] != 0)
					{
						if (!printed)
						{
							print_species(k);
							printed = true;
						}
						cout << "at coordinates: " << j << " " << k << endl;
					}
				}
			}
		}
	}
	cout << endl;
}
int isFree(FishingPond* h, int x, int y)
{
	if (h->pond[x][y] == 0)
	{
		return 1;
	}
	return 0;
}

int AmetourFisher(FishingPond* h) //the ametour fisherman will throw the bate randomly in the lake
{
	srand(time(NULL));
	bool found_fish = false;
	while (!found_fish)
	{
		int sor = rand() % h->n;
		int oszlop = rand() % h->m;
		if (h->pond[sor][oszlop] != 0)
		{
			cout << "The amatour fisher caugh a fish from species: " << h->species[h->pond[sor][oszlop]];
			found_fish = true;
		}
	}
	return 1;
}
int ProffesionalFisher(FishingPond* h, int sRow, int fRow, int sCol, int fCol) //the pro fisherman will wish in a well delimited area
{
	int range_sor = fRow - sRow + 1;
	int range_oszlop = fCol - sCol + 1;
	bool found_fish = false;
	int x, y;
	while (!found_fish)
	{
		x = (rand() % range_sor) + sRow;
		y = (rand() % range_oszlop) + sCol;
		if (h->pond[x][y] != 0)
		{
			found_fish = true;
		}
	}
	return h->pond[x][y];
}
void PrintH(FishingPond* h)
{
	for (int i = 0; i < h->n; i++)
	{
		for (int j = 0; j < h->m; j++)
		{
			cout << h->pond[i][j] << " ";
		}
		cout << endl;
	}
}