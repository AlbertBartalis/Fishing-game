#pragma once
#ifndef HALASTO_H_INCLUDED
#define HALASTO_H_INCLUDED


typedef struct {
    int n, m;
    int** pond;  
    int db;  //number of fish in the pond
    int species_db; //species number
    int species[101]; //distribution of species
} FishingPond;

///Letrehozas
FishingPond* Create(int, int);  
FishingPond* CreateWild(int, int);  
void Destroy(FishingPond*);

///Muveletek
void PutFish(FishingPond*, int, int, int); 
int GetFish(FishingPond*, int, int);  
int GetWidth(FishingPond*);
int GetNrFish(FishingPond* h);
int GetLenght(FishingPond*);
int NumberOfSpecies(FishingPond*);
void SpeciesOccurance(FishingPond*);
int isFree(FishingPond*, int, int);

int AmetourFisher(FishingPond*);  
int ProffesionalFisher(FishingPond*, int, int, int, int); 
void PrintH(FishingPond*);

#endif // HALASTO_H_INCLUDED
