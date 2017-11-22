#include "gracz.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void nauka(gracz & zawodnik)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ifstream story("text/nauka.dat", ios::in);
	if (story.good() == true)
	{
		char znak = '#';
		unsigned int buf = ((rand() % 5) + 1);
		if (zawodnik.licz_impr < buf)
		{

			int i = (rand() % 2);
			if (i == 0)
			{
				while (znak != '1')
				{
					story.get(znak);
				}
				story.get(znak);

			}
			else if (i == 1)
			{
				while (znak != '2')
				{
					story.get(znak);
				}
				story.get(znak);

			}

			switch (i)
			{
			case 0:
				while (znak != '2')
				{

					while (znak != '!')
					{
						story.get(znak);
						cout << znak;
						Sleep(30);
					}
					story.get(znak);
					story.get(znak);
					cout << endl;
					licznik();
					cout << endl;
				}

				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				cout << "Twoje morale wzrastaja z " << zawodnik.morale << " na " << zawodnik.morale + 5 << ", ";
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "jednak zdrowie spada z " << zawodnik.zdrowie << " na " << zawodnik.zdrowie - 5 << endl;
				zawodnik.zdrowie = zawodnik.zdrowie + 5;
				zawodnik.morale = zawodnik.morale + 5;
				break;
			case 1:
				while (znak != '3')
				{

					while (znak != '!')
					{
						story.get(znak);
						cout << znak;
						Sleep(30);
					}
					story.get(znak);
					story.get(znak);
					cout << endl;
					licznik();
					cout << endl;
				}

				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
				cout << "Twoje morale wzrastaja z " << zawodnik.morale << " na " << zawodnik.morale + 5 << ", ";
				cout << "a zdrowie spada z " << zawodnik.zdrowie << " na " << zawodnik.zdrowie - 5 << endl;
				zawodnik.zdrowie = zawodnik.zdrowie - 5;
				zawodnik.morale = zawodnik.morale + 5;
				break;
			}
		}
		else if (zawodnik.licz_nauk == buf)
		{
			//...zle
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		zawodnik.licz_dni++;
		zawodnik.licz_nauk++;
		menu_studenta(zawodnik);
		getchar();
	}
	else
	{
		cout << "Blad otwarcia plikow gry. Przeinstaluj gre lub napisz o tym do lukasz@broll.pl.";
		menu_glowne(zawodnik);
	}
}