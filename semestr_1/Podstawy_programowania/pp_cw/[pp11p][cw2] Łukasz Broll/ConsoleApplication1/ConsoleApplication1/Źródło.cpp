#include "Nag³ówek.h"
#include <iostream>
using namespace std;

#define N 2
ksiazka baza[N];

ksiazka::ksiazka()
{
	ilosc = 0;
	autor = "Anonim";
}
void ksiazka::wczytaj_v2 ()
{
	
	for(int i=0;i<N;i++)
	{
	cout << "Podaj dane o " << i+1 << " ksiazce:\n";
	cout << "Autor: "; cin >> baza[i].autor;
	cout << "Tytul: "; cin >> baza[i].tytul;
	cout << "Ilosc: "; cin >> baza[i].ilosc;
	}
}
void ksiazka::wypisz_v2 ()
{
	
	for(int i=0;i<N;i++)
	{
	cout << "Dane o " << i+1 << " ksiazce:\n";
	cout << "Autor: "; cout << baza[i].autor;
	cout << " Tytul: "; cout << baza[i].tytul;
	cout << " Ilosc: "; cout << baza[i].ilosc;
	cout<<endl<<endl;
	}
}
ostream& operator<< (ostream& rs, ksiazka& rk)
{

	cout << "Autor: " << rk.autor;
	cout << "\nTytul: " << rk.tytul;
	cout << "\nIlosc: " << rk.ilosc;
	return rs;
}

