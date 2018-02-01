#pragma once
#include <string>
using namespace std;

class Table
{
	int *tab, //g³ówna tablica do operacji
		*buff, //tablica buforowa do kopiowania danych
		cnt; //iloœæ elementów w tablicy

public:
	//funkcja wczytuj¹ca strukturê z pliku
	bool loadFromFile(string FileName);
	//funkcja sprawdzaj¹ca czy wartoœæ jest w tablicy
	bool IsValueIn(int val);
	//dodawanie wartoœci za indeksem
	void addIndexValue(int index, int value);
	//dodawanie elementu na koniec tablicy
	void addLast(int value);
	// dodawanie na pocz¹tek tablicy
	void addFirst(int value);
	// usuwanie indeksu z tablicy
	void deleteIndex(int index);
	//usuwanie ostatniego elementu tablicy
	void deleteLast();
	//usuwanie pierwszego elementu tablicy
	void deleteFirst();
	//funkcja drukuje zawartoœæ tablicy w linii z oddzieleniem spacjami
	void display();
	//generowanie tablicy z losowymi elmentami
	void generate(int cnt);
	// metoda tests tworzy plik i generuje do niego losowe dane, aby mo¿na by³o ³atwo importowaæ dane z pliku
	void tests(int cnt, string FileName);
	//setter i getter rozmiaru tablicy
	void setCnt(int cnt); 
	int getCnt();

};
