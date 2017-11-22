#include "gracz.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void statystyki(gracz& zawodnik)
{
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
	int wybor;
	cout << "1.Menu akcji studenta\n2.Menu glowne" << endl;

	cin >> wybor;
	system("cls");
	switch (wybor)
	{
	case 1:
		menu_studenta(zawodnik);
		break;
	case 2:
		menu_glowne(zawodnik);
		break;
	default:
		menu_glowne(zawodnik);
		break;
	}

}

void autor()
{
	system("cls");
	ifstream story("text/about.dat", ios::in);
	char znak;
	while (!story.eof())
	{
		story.get(znak);
		cout << znak;
	}
	story.close();
	cin.ignore(2);
}
void menu_glowne(gracz& zawodnik)
{
	int menu;
	system("cls");
	cout << "-----------SYMULATOR STUDENTA------------" << endl;
	cout << "1.Rozpocznij gre\n2.Pomoc\n3.Zakoncz\n";
	
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
	{
		wczytaj_gracza(zawodnik);
		if (zawodnik.etap == 0)
			story1(zawodnik);
		if (zawodnik.etap == 1)
			story2(zawodnik);
		break;
	}
	case 2:
	{
		autor();
		menu_glowne(zawodnik);
		break;
	}
	case 3:
		koniec(zawodnik);
	default:
		"Wprowadz numer jeszcze raz.";
	}

}

void koniec(gracz& zawodnik)
{
	int menu;
	system("cls");
	cout << "1.Zapisz gre i wyjdz\n2.Wyjdz bez zapisywania\n3.Powrot do menu\n";
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
	{
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
		exit(0);
		break;
	}
	case 2:
	{
		exit(0);
		break;
	}
	case 3:
	{
		menu_glowne(zawodnik);
		break;
	}
	default:
		"Wprowadz numer jeszcze raz.";
	}
}