#include "Sets.h"


Sety::Sety()
{}


Sety::Sety(int n)
{
	Z = new WierzcholekSetu[n];             // Tworzymy tablicê dla elementów zbiorów
}

Sety::~Sety()
{
	delete Z;                    // Usuwamy tablicê ze zbiorami
}

// Tworzy wpis w tablicy Z
void Sety::tworzSet(int poczatekKrawedzi)
{
	Z[poczatekKrawedzi].reprezentant = poczatekKrawedzi;
	Z[poczatekKrawedzi].ranga = 0;
}

// Zwraca indeks reprezentanta zbioru, w którym jest wierzcho³ek v
int Sety::znajdzSet(int poczatekKrawedzi)
{
	if (Z[poczatekKrawedzi].reprezentant != poczatekKrawedzi) Z[poczatekKrawedzi].reprezentant = znajdzSet(Z[poczatekKrawedzi].reprezentant);
	return Z[poczatekKrawedzi].reprezentant;
}

// £¹czy ze sob¹ zbiory z v i u
void Sety::laczSety(KrawedzKolejki e)
{
	int ru, rv;

	ru = znajdzSet(e.poczatekKrawedzi);             // Wyznaczamy korzeñ drzewa z wêz³em u
	rv = znajdzSet(e.koniecKrawedzi);             // Wyznaczamy korzeñ drzewa z wêz³em v
	if (ru != rv)                    // Korzenie musz¹ byæ ró¿ne
	{
		if (Z[ru].ranga > Z[rv].ranga)   // Porównujemy rangi drzew
			Z[rv].reprezentant = ru;              // ru wiêksze, do³¹czamy rv
		else
		{
			Z[ru].reprezentant = rv;              // równe lub rv wiêksze, do³¹czamy ru
			if (Z[ru].ranga == Z[rv].ranga) Z[rv].ranga++;
		}
	}
}
