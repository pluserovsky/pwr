#include "gracz.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	
	srand(time(NULL));
	gracz zawodnik;
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

	plik.close();
	menu_glowne(zawodnik);
	return 1;

}