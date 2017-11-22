#include "Queue.h"



Kolejka::Kolejka() {};

Kolejka::Kolejka(int n)
{
	Kopiec = new KrawedzKolejki[n];           
	pozycjaKopca = 0;                       
}

Kolejka::~Kolejka()
{
//	delete[] Kopiec;
}

KrawedzKolejki Kolejka::zwrocKorzen()
{
	return Kopiec[0];
}

// Umieszcza w kopcu now¹ krawêdŸ i odtwarza strukturê kopca
void Kolejka::dodaj(KrawedzKolejki e)
{
	int i, j;

	i = pozycjaKopca++;                     // i ustawiamy na koniec kopca
	j = (i - 1) >> 1;               // Obliczamy pozycjê rodzica

	// Szukamy miejsca w kopcu dla e

	while (i && (Kopiec[j].wagaKrawedzi > e.wagaKrawedzi))
	{
		Kopiec[i] = Kopiec[j];
		i = j;
		j = (i - 1) >> 1;
	}

	Kopiec[i] = e;                    // KrawêdŸ e wstawiamy do kopca
}

// Usuwa korzeñ z kopca i odtwarza jego strukturê
void Kolejka::zdejmij()
{
	int i, j;
	KrawedzKolejki e;

	if (pozycjaKopca)
	{
		e = Kopiec[--pozycjaKopca];

		i = 0;
		j = 1;

		while (j < pozycjaKopca)
		{
			if ((j + 1 < pozycjaKopca) && (Kopiec[j + 1].wagaKrawedzi < Kopiec[j].wagaKrawedzi)) j++;
			if (e.wagaKrawedzi <= Kopiec[j].wagaKrawedzi) break;
			Kopiec[i] = Kopiec[j];
			i = j;
			j = (j << 1) + 1;
		}

		Kopiec[i] = e;
	}
}