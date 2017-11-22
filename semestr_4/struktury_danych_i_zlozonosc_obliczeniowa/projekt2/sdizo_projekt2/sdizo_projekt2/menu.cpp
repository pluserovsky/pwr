// menu.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>

#include "Graph.h"

using namespace std;

const int testIloscWierzcholkow[5] = { 25, 50, 100, 200, 400 };
// Gestosci dla automatycznych pomiarow [%]
const int testGestosc[4] = { 25, 50, 75, 99 };

Graf mojGraf;

//menu opcji dodawania i usuwania elementow struktur
void menu_mst(string info)
{
	char wybor;
	string nazwaPliku;
	int liczbaWierzcholkow,			// iloœæ wierzcho³ków 
		gestosc;		// gêstoœæ
	do {

		cout << endl;
		cout << info << endl;
		cout << "1. Wczytaj z pliku" << endl;
		cout << "2. Wygeneruj losowy graf" << endl;
		cout << "3. Wyswietl" << endl;
		cout << "4. Algorytm Prima" << endl;
		cout << "5. Algorytm Kruskala" << endl;
		cout << "0. Powrot do menu" << endl;
		cout << "Podaj opcje:";
		cin >> wybor;
		switch (wybor)
		{
		case '1': //wczytywanie grafu z pliku
			cout << " Podaj nazwe pliku:";
			cin >> nazwaPliku;
			if (!mojGraf.wczytajPlik(nazwaPliku))
				cout << "Plik nie istnieje lub nie mozna go otworzyc.";
			else{
				cout << "Wczytano graf z pliku.";
			mojGraf.wyswietl();
		}
			break;
		case '2':  //tutaj generowanie grafu
			cout << "Podaj liczbe wierzochlkow:";
			cin >> liczbaWierzcholkow;
			cout << "Podaj gestosc grafu (%):";
			cin >> gestosc;
			mojGraf.generuj(liczbaWierzcholkow, gestosc);
			mojGraf.wyswietl();
			break;
		case '3':  //tutaj wyœwietlanie grafu
			mojGraf.wyswietl();
			break;

		case '4':  //tutaj algorytm prima
			cout << endl << "Wynik wykonania algorytmu Prima na liscie sasiedztwa:" << endl;
			mojGraf.Prim();
			break;

		case '5':  //tutaj algorytm kruskala
			cout << endl << "Wynik wykonania algorytmu Kruskala na liscie sasiedztwa:" << endl;
			mojGraf.Kruskal();
			break;
		}

	} while (wybor != '0');
}


int main(int argc, char* argv[])
{
	menu_mst("-MST- Minimalne drzewo rozpinajace");
		
	return 0;
}