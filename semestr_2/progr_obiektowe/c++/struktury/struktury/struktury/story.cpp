#include "gracz.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
void licznik()
{
	
	unsigned int czas = (rand() % 20) + 30;

	for (unsigned int i = 0; i<=czas; i++)
	{
		cout << "-" << i << "/" << czas << "-";
		Sleep(1000);
		cout << "\r";
	}

}

void story1(gracz& zawodnik) //zapisy do systemu
{
	system("cls");
	ifstream story("text/story1.dat", ios::in);
	if (story.good() == true)
	{
		char znak;
		while (!story.eof())
		{
			story.get(znak);
			cout << znak;
			Sleep(30);
		}
		cout << endl;
		story.close();
		cout << "Do Twoich zapisow pozostalo: " << endl;
		licznik();
		cout << endl;
		zapisy(zawodnik);
		cin.ignore(1);
	}
	else
	{
		cout << "Blad otwarcia plikow gry. Przeinstaluj gre lub napisz o tym do lukasz@broll.pl.";
			menu_glowne(zawodnik);
	}
}

void zapisy(gracz& zawodnik)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	zawodnik.etap = 1;
	zawodnik.licz_dni++;
	unsigned int wybor = 0;
	wybor = (rand() % 3);
	if (wybor == 0)
	{

		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << "Gratulacje! Wszystkie Twoje grupy byly wolne i masz idealny plan!" << endl;
		cout << "Przez udane zapisy Twoje morale wzrastaja z " << zawodnik.morale << " na " << zawodnik.morale + 10 << endl;
		zawodnik.morale = zawodnik.morale + 10;

	}
	else if (wybor == 1)
	{

		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		cout << "Co za pech! System wylosowal Ci ostatni czas zapisow i masz najgorszy plan!" << endl;
		cout << "Przez nieudane zapisy Twoje morale spadaja z " << zawodnik.morale << " na " << zawodnik.morale - 10 << endl;
		zawodnik.morale = zawodnik.morale - 10;
	}
	else if (wybor == 2)
	{
		
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "Nie wszystkie grupy byly wolne, wiec Twoj plan nie jest idealny, ale nie ma najgorzej!\n" << endl;

	}
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	getchar();
}

void story2(gracz& zawodnik) //studiowanie
{
	system("cls");
	ifstream story("text/story2.dat", ios::in);
	if (story.good() == true)
	{
		char znak;
		while (!story.eof())
		{
			story.get(znak);
			cout << znak;
			Sleep(30);
		}
		story.close();
		cout << endl;
		menu_studenta(zawodnik);
	}
	else
	{
		cout << "Blad otwarcia plikow gry. Przeinstaluj gre lub napisz o tym do lukasz@broll.pl.";
		menu_glowne(zawodnik);
	}
}

void menu_studenta(gracz& zawodnik)
{
	int menu;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n1.Imprezujemy!\t2.Dzisiaj nauka...\t3.Czas odetchnac :)\n";
	cout << "4.Statystyki\t5.Koniec gry\n";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "\nUWAGA! Zamkniecie okna gry na krzyzyk nie zapisuje postepu gry!\n";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
		if (zawodnik.zdrowie > 0 && zawodnik.morale < 100 && zawodnik.wiedza > 0)
			imprezujemy(zawodnik);
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "************************************************************" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "Nie masz juz sily na imprezy, zrob cos innego.\n";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "************************************************************" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			menu_studenta(zawodnik);
		}
		break;
	case 2:
		if (zawodnik.zdrowie > 0 && zawodnik.morale > 0 && zawodnik.wiedza < 100)
			nauka(zawodnik);
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "************************************************************" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "Masz mroczki przed oczami od nauki, lepiej zajmij sie czym innym.\n";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "************************************************************" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			menu_studenta(zawodnik);
		}
		break;
	case 3:
		if (zawodnik.zdrowie < 100 && zawodnik.morale > 0 && zawodnik.wiedza > 0)
			sen(zawodnik);
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "************************************************************" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "Juz nie masz ochoty na odpoczynek, zrob cos innego.\n";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "************************************************************" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			menu_studenta(zawodnik);
		}
		break;
	case 4:
		statystyki(zawodnik);
		break;
	case 5:
		koniec(zawodnik);
		break;
	default:
		"Wprowadz numer jeszcze raz.";
	}
	
}



