#include "Sets.h"


Sety::Sety()
{}


Sety::Sety(int n)
{
	Z = new WierzcholekSetu[n];             // Tworzymy tablic� dla element�w zbior�w
}

Sety::~Sety()
{
	delete Z;                    // Usuwamy tablic� ze zbiorami
}

// Tworzy wpis w tablicy Z
void Sety::tworzSet(int poczatekKrawedzi)
{
	Z[poczatekKrawedzi].reprezentant = poczatekKrawedzi;
	Z[poczatekKrawedzi].ranga = 0;
}

// Zwraca indeks reprezentanta zbioru, w kt�rym jest wierzcho�ek v
int Sety::znajdzSet(int poczatekKrawedzi)
{
	if (Z[poczatekKrawedzi].reprezentant != poczatekKrawedzi) Z[poczatekKrawedzi].reprezentant = znajdzSet(Z[poczatekKrawedzi].reprezentant);
	return Z[poczatekKrawedzi].reprezentant;
}

// ��czy ze sob� zbiory z v i u
void Sety::laczSety(KrawedzKolejki e)
{
	int ru, rv;

	ru = znajdzSet(e.poczatekKrawedzi);             // Wyznaczamy korze� drzewa z w�z�em u
	rv = znajdzSet(e.koniecKrawedzi);             // Wyznaczamy korze� drzewa z w�z�em v
	if (ru != rv)                    // Korzenie musz� by� r�ne
	{
		if (Z[ru].ranga > Z[rv].ranga)   // Por�wnujemy rangi drzew
			Z[rv].reprezentant = ru;              // ru wi�ksze, do��czamy rv
		else
		{
			Z[ru].reprezentant = rv;              // r�wne lub rv wi�ksze, do��czamy ru
			if (Z[ru].ranga == Z[rv].ranga) Z[rv].ranga++;
		}
	}
}
