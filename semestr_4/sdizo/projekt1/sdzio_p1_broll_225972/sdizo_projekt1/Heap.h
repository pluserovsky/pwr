#pragma once
#include <string>
using namespace std;


class Heap
{
private:
	int cnt, //rozmiar kopca
		*tab;//tablica zawieraj�ca elementy kopca


public:
	
	//funkcja wczytuj�ca struktur� z pliku
	bool loadFromFile(string FileName);
	//funkcja sprawdzaj�ca czy warto�� jest w strukturze
	bool IsValueIn(int val);
	//dodawanie warto�ci za warto�ci�
	void addValue(int value);
	// usuwanie warto�ci ze struktury
	void deleteValue(int value);
	void display(string sp, string sn, int value);
	void display();
	//generowanie struktury z losowymi elmentami
	void generate(int cnt);
	// metoda tests tworzy plik i generuje do niego losowe dane, aby mo�na by�o �atwo importowa� dane z pliku
	void tests(int cnt, string FileName);
	//setter i getter rozmiaru tablicy
	void setCnt(int cnt);
	int getCnt();
	

};
