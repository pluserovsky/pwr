#pragma once
#include <string>
using namespace std;

// klasa pojedynczego elementu listy
class ListsCell
{
public:
	ListsCell *next, *prev; //kolejny i poprzedni elemnt listy
	int value; //wartosc

};

class List
{
private:
	ListsCell *head, *tail; // pocz�tek i ogon listy
	int cnt, //rozmiar listy
		buff; //bufor danych
public:
	//funkcja wczytuj�ca struktur� z pliku
	bool loadFromFile(string FileName);
	//funkcja sprawdzaj�ca czy warto�� jest w strukturze
	bool IsValueIn(int val);
	//dodawanie warto�ci za warto�ci�
	void addValue(int value, int index);
	//dodawanie elementu na koniec struktury
	void addLast(int value);
	// dodawanie na pocz�tek struktury
	void addFirst(int value);
	// usuwanie warto�ci ze struktury
	void deleteValue(int value);
	//usuwanie ostatniego elementu struktury
	void deleteLast();
	//usuwanie pierwszego elementu struktury
	void deleteFirst();
	//funkcja drukuje zawarto�� listy 
	//w linii z oddzieleniem spacjami od pocz�tku i od ko�ca
	void display();
	//generowanie struktury z losowymi elmentami
	void generate(int cnt);
	// metoda tests tworzy plik i generuje do niego losowe dane, aby mo�na by�o �atwo importowa� dane z pliku
	void tests(int cnt, string FileName);
	//setter i getter rozmiaru tablicy
	void setCnt(int cnt);
	int getCnt();
	};

