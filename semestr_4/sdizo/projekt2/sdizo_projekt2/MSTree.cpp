#include <iostream>
#include "MSTree.h"

using namespace std;


Drzewo::Drzewo() {};

Drzewo::Drzewo(int n)
{
	int i;

	tablicaDrzewo = new KomorkaDrzewa *[n];            // Tworzymy tablic� dynamiczn�
	for (i = 0; i < n; i++) tablicaDrzewo[i] = NULL; // i wype�niamy j� pustymi listami
	liczbaKomorekTablicy = n - 1;                   // Zapami�tujemy d�ugo�� tablicy
	wagaDrzewa = 0;                     // Zerujemy wag� drzewa
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
			r = p;                      // Zapami�tujemy wskazanie
			p = p->nastepny;                // Przesuwamy si� do nast�pnego elementu listy
			delete r;                   // Usuwamy element
		}
	}

	delete[] tablicaDrzewo;                    // Usuwamy tablic� list s�siedztwa
}

// Dodaje kraw�d� do drzewa

void Drzewo::dodajKrawedz(KrawedzKolejki e)
{
	KomorkaDrzewa *p;

	wagaDrzewa += e.wagaKrawedzi;             // Do wagi drzewa dodajemy wag� kraw�dzi
	p = new KomorkaDrzewa;                  // Tworzymy nowy w�ze�
	p->koniecKrawedzi = e.koniecKrawedzi;                    // Wierzcho�ek ko�cowy
	p->wagaKrawedzi = e.wagaKrawedzi;           // Waga kraw�dzi
	p->nastepny = tablicaDrzewo[e.poczatekKrawedzi];              // Dodajemy p do listy wierzcho�ka v1
	tablicaDrzewo[e.poczatekKrawedzi] = p;

	p = new KomorkaDrzewa;                  // To samo dla kraw�dzi odwrotnej
	p->koniecKrawedzi = e.poczatekKrawedzi;                    // Wierzcho�ek ko�cowy
	p->wagaKrawedzi = e.wagaKrawedzi;           // Waga kraw�dzi
	p->nastepny = tablicaDrzewo[e.koniecKrawedzi];              // Dodajemy p do listy wierzcho�ka v2
	tablicaDrzewo[e.koniecKrawedzi] = p;
}

// Zwraca wska�nik pocz�tku listy s�siad�w wierzcho�ka
KomorkaDrzewa * Drzewo::zwrocListe(int n)
{
	return tablicaDrzewo[n];
}

// Wy�wietla zawarto�� drzewa oraz jego wag�
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
