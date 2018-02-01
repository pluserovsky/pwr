#include "gracz.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wczytaj_gracza(gracz& zawodnik)
{
	int wybor;
	cout << "1. Dodaj nowego gracza.\n2. Wczytaj zapis.\n3. Wyjdz do menu" << endl;
	cout << "UWAGA! Utowrzenie nowego gracza usunie istniejacy zapis gry!\n";
	cin >> wybor;
	system("cls");
	switch (wybor)
	{
	case 1:
		nowy_gracz(zawodnik);
		break;
	case 2:
		wczytaj_zapis(zawodnik);
		break;
	case 3:
		menu_glowne(zawodnik);
		break;
	default:
		wczytaj_gracza(zawodnik);
		break;
	}
}


void nowy_gracz(gracz& zawodnik)
{
	cout << "---Tworzenie profilu gracza---\n";
	cout << "Nazwa: ";
	cin >> zawodnik.nazwa;
	cout << "Kierunek: ";
	cin >> zawodnik.kierunek;
	cout << "Wiek: ";
	cin >> zawodnik.wiek;
	cout << "Utworzono profil gracza " << zawodnik.nazwa << ". Powodzenia!\n";
	getchar();

	ofstream plik("zawodnik.dat", ios::out | ios::trunc);
	plik << zawodnik.nazwa << "\n";
	plik << zawodnik.kierunek << "\n";
	plik << zawodnik.wiek << "\n";
	plik << zawodnik.zdrowie << "\n";
	plik << zawodnik.wiedza << "\n";
	plik << zawodnik.morale << "\n";
	plik << zawodnik.etap << "\n";
	plik << zawodnik.licz_impr << "\n";
	plik << zawodnik.licz_nauk << "\n";
	plik << zawodnik.licz_sen << "\n";
	plik << zawodnik.licz_dni << "\n";
	plik.close();


}

void wczytaj_zapis(gracz& zawodnik)
{

	ifstream plik("zawodnik.dat", ios::in);
	plik >> zawodnik.nazwa;
	plik >> zawodnik.kierunek;
	plik >> zawodnik.wiek;
	plik >> zawodnik.zdrowie;
	plik >> zawodnik.wiedza;
	plik >> zawodnik.morale;
	plik >> zawodnik.etap;
	plik >> zawodnik.licz_impr;
	plik >> zawodnik.licz_nauk;
	plik >> zawodnik.licz_sen;
	plik >> zawodnik.licz_dni;

	cout << "Wczytano zapis gracza " << zawodnik.nazwa << endl;
	plik.close();

	system("cls");
	cout << "--------------------------------" << endl;
	cout << "Profil gracza:" << zawodnik.nazwa;
	cout << "\nKierunek:" << zawodnik.kierunek;
	cout << "\nWiek: " << zawodnik.wiek;
	cout << "\nZdrowie wynosi " << zawodnik.zdrowie;
	cout << "\nWiedza wynosi " << zawodnik.wiedza;
	cout << "\nMorale wynosza " << zawodnik.morale;
	cout << "\n--------------------------------" << endl;
	cin.ignore(2);
}

