#include <iostream>
#include "MSTree.h"

using namespace std;


Drzewo::Drzewo() {};

Drzewo::Drzewo(int n)
{
	int i;

	tablicaDrzewo = new KomorkaDrzewa *[n];            // Tworzymy tablicê dynamiczn¹
	for (i = 0; i < n; i++) tablicaDrzewo[i] = NULL; // i wype³niamy j¹ pustymi listami
	liczbaKomorekTablicy = n - 1;                   // Zapamiêtujemy d³ugoœæ tablicy
	wagaDrzewa = 0;                     // Zerujemy wagê drzewa
}

Drzewo::~Drzewo()
{
	int i;
	KomorkaDrzewa *p, *r;

	for (i = 0; i <= liczbaKomorekTablicy; i++)
	{
		p = tablicaDrzewo[i];
		while (p)
		{
			r = p;                      // Zapamiêtujemy wskazanie
			p = p->nastepny;                // Przesuwamy siê do nastêpnego elementu listy
			delete r;                   // Usuwamy element
		}
	}

	delete[] tablicaDrzewo;                    // Usuwamy tablicê list s¹siedztwa
}

// Dodaje krawêdŸ do drzewa

void Drzewo::dodajKrawedz(KrawedzKolejki e)
{
	KomorkaDrzewa *p;

	wagaDrzewa += e.wagaKrawedzi;             // Do wagi drzewa dodajemy wagê krawêdzi
	p = new KomorkaDrzewa;                  // Tworzymy nowy wêze³
	p->koniecKrawedzi = e.koniecKrawedzi;                    // Wierzcho³ek koñcowy
	p->wagaKrawedzi = e.wagaKrawedzi;           // Waga krawêdzi
	p->nastepny = tablicaDrzewo[e.poczatekKrawedzi];              // Dodajemy p do listy wierzcho³ka v1
	tablicaDrzewo[e.poczatekKrawedzi] = p;

	p = new KomorkaDrzewa;                  // To samo dla krawêdzi odwrotnej
	p->koniecKrawedzi = e.poczatekKrawedzi;                    // Wierzcho³ek koñcowy
	p->wagaKrawedzi = e.wagaKrawedzi;           // Waga krawêdzi
	p->nastepny = tablicaDrzewo[e.koniecKrawedzi];              // Dodajemy p do listy wierzcho³ka v2
	tablicaDrzewo[e.koniecKrawedzi] = p;
}

// Zwraca wskaŸnik pocz¹tku listy s¹siadów wierzcho³ka
KomorkaDrzewa * Drzewo::zwrocListe(int n)
{
	return tablicaDrzewo[n];
}

// Wyœwietla zawartoœæ drzewa oraz jego wagê
void Drzewo::drukujDrzewo()
{
	int i;
	KomorkaDrzewa *p;

	cout << endl;
	cout << "Koszt calkowity: " << wagaDrzewa << endl << endl;
	for (i = 0; i < liczbaKomorekTablicy; i++)
	{
		for (p = tablicaDrzewo[i]; p; p = p->nastepny) 
		{
			cout << i << " - ";
			cout << p->koniecKrawedzi << ":" << p->wagaKrawedzi << " ";
			cout << endl;
		}
	}
}
