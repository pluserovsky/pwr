#include "Graph.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>

using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void Graf::StartCounter()
{
	CounterStart = 0;
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
void Graf::SaveCounter(string SaveFileName)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	cout << "Algorytm wykonal sie w czasie: " << double(li.QuadPart - CounterStart) / PCFreq << " ms \n";

}
Graf::Graf()
{
		poczatekKrawedzi = 0,	
		koniecKrawedzi = 0,	
		wagaKrawedzi = 0,	
		liczbaKrawedzi = 0,	
		liczbaWierzcholkow = 0,	
		dodaneKrawedzie = 0;
}

Graf::~Graf()
{
	for (int i = 0; i < liczbaWierzcholkow; i++)
	{
		nowaKomorka = tablica[i];
		while (nowaKomorka)
		{
			usuwacz = nowaKomorka;
			nowaKomorka = (*nowaKomorka).nastepny;
			delete usuwacz;
		}
	}
	delete[] tablica;

}

void Graf::generuj(int nodes, int gestosc)
{
	this->gestosc = gestosc;

	liczbaWierzcholkow = nodes;
	tablica = new KomorkaListy *[liczbaWierzcholkow];
	// Tablic� wype�niamy pustymi listami
	for (int i = 0; i < liczbaWierzcholkow; i++) tablica[i] = NULL;

	//  graf SKIEROWANY i SPOJNY o okreslonej gestosci
	// Obliczenie potrzebnej ilosci krawedzi (100 +/- 10)
	float stosunekKrawedzi = (float)gestosc / 100;
	int maxKrawedzi = (int)stosunekKrawedzi*((liczbaWierzcholkow*(liczbaWierzcholkow - 1)) / 2);
	int liczbaKrawedzi = 0;

	for (int i = 0; i < liczbaWierzcholkow; i++)
	{
		// Tworzenie spojnego szkieletu o duzych wagach
		int losowaWaga = (rand() % 21) + 90;
		dodajKrawedz(i, (i + 1) % liczbaWierzcholkow, losowaWaga);
		liczbaKrawedzi++;
	}

	while (liczbaKrawedzi < maxKrawedzi)
	{
		// Pozostale krawedzie o malych wagach (10 +/-10) sa tworzone losowo
		int losowaWaga = rand() % 21;
		int losowaKrawedz1 = rand() % liczbaWierzcholkow;
		int losowaKrawedz2 = rand() % liczbaWierzcholkow;
		if (losowaKrawedz1 != losowaKrawedz2) 
		// Jezeli wylosowano dwa razy ten sam wierzcholek, zamiast losowac od nowa...
		// ...drugi zwiekszamy o dwa - nie o jeden, bo takie krawedzie juz mamy...
		// ...dzieki temu powinnismy zaoszczedzic troche czasu
		losowaKrawedz2 = (losowaKrawedz2 + 2) % liczbaWierzcholkow;

		if (dodajKrawedz(losowaKrawedz1, losowaKrawedz2, losowaWaga))
			// Metoda zwraca "true", jezeli krawedz zostala dodana - wtedy zliczamy
			liczbaKrawedzi++;
	
	}

}

bool Graf::dodajKrawedz(unsigned poczatekKrawedzi, unsigned koniecKrawedzi, unsigned wagaKrawedzi)
{

	if (wagaKrawedzi >= 1000)
		// Waga krawedzi musi byc mniejsza od 1000
		wagaKrawedzi = 900;

	else if (tablica[poczatekKrawedzi] != NULL) {
		bool juzIstnieje = false;
		KomorkaListy *nastepny = tablica[poczatekKrawedzi];
		KomorkaListy *pozycja = NULL;
		//sprawdzenie czy wierzcholek istnieje
		do
		{
			pozycja = nastepny;
			nastepny = nastepny->nastepny;
			if (pozycja->koniecKrawedzi == koniecKrawedzi)
			{
				juzIstnieje = true;
				break;
			}
		} while (nastepny != NULL);
		//dodanie wiercholka jesli nie  istnieje
		if (!juzIstnieje)
		{
			KomorkaListy *nowaKrawedz = new KomorkaListy;
			nowaKrawedz->koniecKrawedzi = koniecKrawedzi;
			nowaKrawedz->wagaKrawedzi = wagaKrawedzi;
			nowaKrawedz->nastepny = NULL;
			pozycja->nastepny = nowaKrawedz;
			return true;
		}
	}
	//jesli to pierwsza krawedz wierzcholka
	else if (tablica[poczatekKrawedzi] == NULL)
	{
		tablica[poczatekKrawedzi] = new KomorkaListy;
		tablica[poczatekKrawedzi]->koniecKrawedzi = koniecKrawedzi;
		tablica[poczatekKrawedzi]->wagaKrawedzi = wagaKrawedzi;
		tablica[poczatekKrawedzi]->nastepny = NULL;
		return true;
	}
	else return false;

	return false;
}



bool Graf::wczytajPlik(string FileName)
{

	ifstream plik;
	//otawrcie pliku
	plik.open(FileName.c_str());
	if (!plik.good()) return false;

	else if (plik.good()) {
		plik >> liczbaKrawedzi;
		plik >> liczbaWierzcholkow;

		// Tworzymy tablic� list s�siedztwa
		tablica = new KomorkaListy *[liczbaWierzcholkow];

		// Tablic� wype�niamy pustymi listami
		for (int i = 0; i < liczbaWierzcholkow; i++) tablica[i] = NULL;

		//wczytywanie kolejnych element�w w p�tli, linijka po linijce
		while (!plik.eof()) {
			for (int i = 0; i < liczbaKrawedzi; i++)
			{
				plik >> poczatekKrawedzi;
				plik >> koniecKrawedzi;
				plik >> wagaKrawedzi;
				nowaKomorka = new KomorkaListy;    // Tworzymy nowy element
				(*nowaKomorka).koniecKrawedzi = koniecKrawedzi;          // Numerujemy go jako ko�cowy
				(*nowaKomorka).nastepny = tablica[poczatekKrawedzi];    // Dodajemy go na pocz�tek listy tablica[poczatek]
				(*nowaKomorka).wagaKrawedzi = wagaKrawedzi;
				tablica[poczatekKrawedzi] = nowaKomorka;
			}
		}
		plik.close();
	}

	return true;
}
void Graf::wyswietlListe()
{

	// Wypisujemy zawarto�� tablicy list s�siedztwa
	if (tablica) {
		for (int i = 0; i < liczbaWierzcholkow; i++)
		{
			nowaKomorka = tablica[i];

			cout << "Wierzcholek " << i << ":";

			while (nowaKomorka)
			{
				cout << " " << (*nowaKomorka).koniecKrawedzi << "(" << (*nowaKomorka).wagaKrawedzi << ")";
				nowaKomorka = (*nowaKomorka).nastepny;
			}
			cout << endl;
		}

	}
	else cout << "Lista jest pusta." << endl;
}

void Graf::wyswietl()
{
	wyswietlListe();
}

void Graf::Kruskal()
{
	KrawedzKolejki krawedz;
	int i;

	Sety S(liczbaWierzcholkow);                  // Struktura zbior�w roz��cznych
	Kolejka K(liczbaKrawedzi);                     // Kolejka priorytetowa oparta na kopcu
	Drzewo D(liczbaWierzcholkow);                    // Minimalne drzewo rozpinaj�ce

	for (i = 0; i < liczbaWierzcholkow; i++)
		S.tworzSet(i);                 // Dla ka�dego wierzcho�ka tworzymy osobny zbi�r

	StartCounter();
	for (i = 0; i < liczbaWierzcholkow; i++)
	{
		nowaKomorka = tablica[i];

		while (nowaKomorka)
		{
			krawedz.poczatekKrawedzi = i;
			krawedz.koniecKrawedzi = (*nowaKomorka).koniecKrawedzi;
			krawedz.wagaKrawedzi = (*nowaKomorka).wagaKrawedzi;
			nowaKomorka = (*nowaKomorka).nastepny;
			K.dodaj(krawedz);
		}

	}

	for (i = 1; i < liczbaWierzcholkow; i++)          
	{
		do
		{
			krawedz = K.zwrocKorzen();              // Pobieramy z kolejki kraw�d�
			K.zdejmij();                    // Kraw�d� usuwamy z kolejki
		} while (S.znajdzSet(krawedz.poczatekKrawedzi) == S.znajdzSet(krawedz.koniecKrawedzi));
		D.dodajKrawedz(krawedz);                 // Dodajemy kraw�d� do drzewa
		S.laczSety(krawedz);               // Zbiory z wierzcho�kami ��czymy ze sob�
	}
	SaveCounter("MSTKruskalList");
	// Wy�wietlamy wyniki

	D.drukujDrzewo();

}

void Graf::Prim()
{

	KrawedzKolejki krawedz;
	KomorkaDrzewa * komorkaDrzewa;
	int i, koniecKrawedzi;
	Kolejka K(liczbaKrawedzi);                     // Kolejka priorytetowa oparta na kopcu
	Drzewo D(liczbaWierzcholkow);                    // Minimalne drzewo rozpinaj�ce
	Drzewo DGraf(liczbaWierzcholkow);                    // Graf

	bool * odwiedzone = new bool[liczbaWierzcholkow];

	for (i = 0; i < liczbaWierzcholkow; i++)
		odwiedzone[i] = false;           // Inicjujemy tablic� odwiedzin

	StartCounter();
	for (i = 0; i < liczbaWierzcholkow; i++)
	{
		nowaKomorka = tablica[i];

		while (nowaKomorka)
		{
			krawedz.poczatekKrawedzi = i;
			krawedz.koniecKrawedzi = (*nowaKomorka).koniecKrawedzi;
			krawedz.wagaKrawedzi = (*nowaKomorka).wagaKrawedzi;
			nowaKomorka = (*nowaKomorka).nastepny;
			DGraf.dodajKrawedz(krawedz);
		}

	}

	// Tworzymy minimalne drzewo rozpinaj�ce

	koniecKrawedzi = 0;                          // Wierzcho�ek startowy
	odwiedzone[koniecKrawedzi] = true;              // Oznaczamy go jako odwiedzonego

	for (i = 1; i < liczbaWierzcholkow; i++)          // Do drzewa dodamy n - 1 kraw�dzi grafu
	{
		for (komorkaDrzewa = DGraf.zwrocListe(koniecKrawedzi); komorkaDrzewa; komorkaDrzewa = komorkaDrzewa->nastepny) // Przegl�damy list� s�siad�w
			if (!odwiedzone[komorkaDrzewa->koniecKrawedzi])          // Je�li s�siad jest nieodwiedzony,
			{
				krawedz.poczatekKrawedzi = koniecKrawedzi;                 // to tworzymy kraw�d�
				krawedz.koniecKrawedzi = komorkaDrzewa->koniecKrawedzi;
				krawedz.wagaKrawedzi = komorkaDrzewa->wagaKrawedzi;
				K.dodaj(krawedz);                // Dodajemy j� do kolejki priorytetowej
			}

		do
		{
			krawedz = K.zwrocKorzen();              // Pobieramy kraw�d� z kolejki
			K.zdejmij();
		} while (odwiedzone[krawedz.koniecKrawedzi]);       // Kraw�d� prowadzi poza drzewo?

		D.dodajKrawedz(krawedz);                 // Dodajemy kraw�d� do drzewa rozpinaj�cego
		odwiedzone[krawedz.koniecKrawedzi] = true;         // Oznaczamy drugi wierzcho�ek jako odwiedzony
		koniecKrawedzi = krawedz.koniecKrawedzi;
	}
	SaveCounter("MSTPrimList");

	// Wy�wietlamy wyniki

	D.drukujDrzewo();

	delete[] odwiedzone;

}



