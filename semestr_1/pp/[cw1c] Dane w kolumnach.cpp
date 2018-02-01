// cw1c.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	string nazwisko_1, nazwisko_2, imie_1, imie_2, urodzony_1, urodzony_2;
	float staz_1, staz_2, stawka_1, stawka_2;
	cout<<"Przygotuj dane pierwszego pracownika:"<<endl;		//Pobranie danych
	cout<<"Wprowadz nazwisko:";
	cin>>nazwisko_1;
	cout<<"Wprowadz imie:";
	cin>>imie_1;
	cout<<"Wprowadz date urodzenia:";
	cin>>urodzony_1;
	cout<<"Wprowadz staz (w latach):";
	cin>>staz_1;
	cout<<"Wprowadz stawke (zl/godz):";
	cin>>stawka_1;
	cout<<"Przygotuj dane drugiego pracownika:"<<endl;
	cout<<"Wprowadz nazwisko:";
	cin>>nazwisko_2;
	cout<<"Wprowadz imie:";
	cin>>imie_2;
	cout<<"Wprowadz date urodzenia:";
	cin>>urodzony_2;
	cout<<"Wprowadz staz (w latach):";
	cin>>staz_2;
	cout<<"Wprowadz stawke (zl/godz):";
	cin>>stawka_2;
	cout<<"Nazwisko: "<<nazwisko_1<<"\tImie: "<<imie_1<<"\tUrodzony: "<<urodzony_1<<" Staz: "<<staz_1<<" lata"<<" Stawka: "<<stawka_1<<" zl/godz"<<endl;  //Wypisanie danych z tabulatorami
	cout<<"Nazwisko: "<<nazwisko_2<<"\tImie: "<<imie_2<<"\tUrodzony: "<<urodzony_2<<" Staz: "<<staz_2<<" lata"<<" Stawka: "<<stawka_2<<" zl/godz"<<endl;
	system("Pause");

	return 0;
}
