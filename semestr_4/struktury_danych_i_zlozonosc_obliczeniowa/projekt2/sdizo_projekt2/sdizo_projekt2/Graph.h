#pragma once
#include <string>
#include "MSTree.h"
#include "Queue.h"
#include "Sets.h"
#include "ListCell.h"

using namespace std;

class Graf:KomorkaListy
{
private:

	int poczatekKrawedzi,	
		koniecKrawedzi,	
		wagaKrawedzi,	
		liczbaKrawedzi,
		liczbaWierzcholkow,	
		*poprzednicy,
		gestosc,	
		dodaneKrawedzie;	
	long long *tablicaKosztow; 
public:
	Graf();
	virtual ~Graf();

	void generuj(int liczbaWierzcholkow, int gestosc);
	bool dodajKrawedz(unsigned poczatekKrawedzi, unsigned koniecKrawedzi, unsigned wagaKrawedzi);

	bool wczytajPlik(string nazwaPliku);

	void wyswietlListe();
	void wyswietl();

	void Kruskal();
	void Prim();

	void StartCounter();
	void SaveCounter(string SaveFileName);
};

