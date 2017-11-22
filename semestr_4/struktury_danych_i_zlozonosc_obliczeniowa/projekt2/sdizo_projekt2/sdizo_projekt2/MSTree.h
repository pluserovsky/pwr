#pragma once
#include "Graph.h"
#include "Queue.h"

struct KomorkaDrzewa
{
	KomorkaDrzewa * nastepny;
	int koniecKrawedzi, wagaKrawedzi;
};

class Drzewo
{
private:
	KomorkaDrzewa ** tablicaDrzewo;                
	int liczbaKomorekTablicy;                    
	int wagaDrzewa; 
public:
	Drzewo(int n);
	Drzewo();
	~Drzewo();
	void dodajKrawedz(KrawedzKolejki e);
	KomorkaDrzewa * zwrocListe(int n);
	void drukujDrzewo();
};

