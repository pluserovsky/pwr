#pragma once
#include <string>
using namespace std;

class Table
{
	int *tab, //g��wna tablica do operacji
		*buff, //tablica buforowa do kopiowania danych
		cnt; //ilo�� element�w w tablicy

public:
	//funkcja wczytuj�ca struktur� z pliku
	bool loadFromFile(string FileName);
	//funkcja sprawdzaj�ca czy warto�� jest w tablicy
	bool IsValueIn(int val);
	//dodawanie warto�ci za indeksem
	void addIndexValue(int index, int value);
	//dodawanie elementu na koniec tablicy
	void addLast(int value);
	// dodawanie na pocz�tek tablicy
	void addFirst(int value);
	// usuwanie indeksu z tablicy
	void deleteIndex(int index);
	//usuwanie ostatniego elementu tablicy
	void deleteLast();
	//usuwanie pierwszego elementu tablicy
	void deleteFirst();
	//funkcja drukuje zawarto�� tablicy w linii z oddzieleniem spacjami
	void display();
	//generowanie tablicy z losowymi elmentami
	void generate(int cnt);
	// metoda tests tworzy plik i generuje do niego losowe dane, aby mo�na by�o �atwo importowa� dane z pliku
	void tests(int cnt, string FileName);
	//setter i getter rozmiaru tablicy
	void setCnt(int cnt); 
	int getCnt();

};
