#pragma once
#include <string>
using namespace std;


class Heap
{
private:
	int cnt, //rozmiar kopca
		*tab;//tablica zawieraj¹ca elementy kopca


public:
	
	//funkcja wczytuj¹ca strukturê z pliku
	bool loadFromFile(string FileName);
	//funkcja sprawdzaj¹ca czy wartoœæ jest w strukturze
	bool IsValueIn(int val);
	//dodawanie wartoœci za wartoœci¹
	void addValue(int value);
	// usuwanie wartoœci ze struktury
	void deleteValue(int value);
	void display(string sp, string sn, int value);
	void display();
	//generowanie struktury z losowymi elmentami
	void generate(int cnt);
	// metoda tests tworzy plik i generuje do niego losowe dane, aby mo¿na by³o ³atwo importowaæ dane z pliku
	void tests(int cnt, string FileName);
	//setter i getter rozmiaru tablicy
	void setCnt(int cnt);
	int getCnt();
	

};
