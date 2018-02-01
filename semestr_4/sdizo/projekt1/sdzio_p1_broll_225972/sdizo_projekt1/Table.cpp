#include "Table.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;


bool Table::loadFromFile(string FileName)
{
	ifstream plik;
	//otawrcie pliku
	plik.open(FileName.c_str());
	if (!plik.good()) return 0;

	else if (plik.good()) {
		//wczytanie rozmiaru z pierwszej linii
		plik >> cnt;
		//wyzerowanie tablicy, je�li by�a u�ywana
		delete[]tab;
		tab = new int[cnt];
		//wczytywanie kolejnych element�w w p�tli, linijka po linijce
		for (int i = 0; i < cnt; i++) {
			plik >> tab[i];
		}
		plik.close();
	}
	return 1;
}

bool Table::IsValueIn(int val)
{
	//po doj�ciu do szukanego elementu zwraca true
	for (int j = 0; j < cnt; j++) {
		if (tab[j] == val) return true;
	}
	return false;
}

void Table::addIndexValue(int index, int value)
{
	if (index == 0)addFirst(value);
	else if (index == cnt) addLast(value);
	else {
		buff = new int[cnt + 1];
		int i;
		// kopiowanie element�w do nowego indeksu
		for (i = 0; i < index; i++) {
			buff[i] = tab[i];
		}
		buff[i] = value; //dodanie nowej warto�ci w danym miejscu
		//kopiowanie reszty warto�ci do bufora
		i = i + 1;
		for (i; i < cnt + 1; i++) {
			buff[i] = tab[i - 1];
		}

		// relokacja nowej tablicy
		tab = new int[cnt++];
		for (i = 0; i < cnt + 1; i++) {
			tab[i] = buff[i];
		}
	}
}

void Table::addLast(int value)
{
	buff = new int[cnt + 1];
	int i;
	// kopiowanie element�w do nowego indeksu
	for (i = 0; i < cnt; i++) {
		buff[i] = tab[i];
	}
	//dodanie nowej warto�ci w danym miejscu
	buff[cnt] = value;
	// relokacja nowej tablicy
	tab = new int[cnt++];

	for (i = 0; i < cnt; i++) {
		tab[i] = buff[i];
	}
}

void Table::addFirst(int value)
{
	buff = new int[cnt + 1];

	//dodanie nowej warto�ci w danym miejscu
	buff[0] = value;
	// kopiowanie element�w do nowego indeksu
	for (int i = 1; i < cnt + 1; i++) {
		buff[i] = tab[i - 1];
	}
	// relokacja nowej tablicy
	tab = new int[cnt++];

	for (int i = 0; i < cnt + 1; i++) {
		tab[i] = buff[i];
	}
}

void Table::deleteIndex(int index)
{
	buff = new int[cnt - 1];
	int i;
	// kopiowanie element�w do indeksu przed usunieciem
	for (i = 0; i <= index; i++) {
		buff[i] = tab[i];
	}
	i = i - 1;
	//przeskok ponad element do usuniecia
	for (i; i < cnt - 1; i++) {
		buff[i] = tab[i + 1];
	}

	// relokacja nowej tablicy
	tab = new int[cnt--];
	for (i = 0; i < cnt; i++) {
		tab[i] = buff[i];
	}
}

void Table::deleteLast()
{
	buff = new int[cnt - 1];
	int i;
	// kopiowanie element�w do indeksu przed usunieciem
	for (i = 0; i < cnt - 1; i++) {
		buff[i] = tab[i];
	}
	// relokacja nowej tablicy
	tab = new int[cnt--];
	for (i = 0; i < cnt; i++) {
		tab[i] = buff[i];
	}
}

void Table::deleteFirst()
{

	buff = new int[cnt - 1];
	int i;
	// kopiowanie element�w bez pierwszego
	for (i = 1; i < cnt; i++) {
		buff[i - 1] = tab[i];
	}
	// relokacja nowej tablicy
	tab = new int[cnt--];
	for (i = 0; i < cnt; i++) {
		tab[i] = buff[i];
	}
}

void Table::display()
{

	for (int i = 0; i < cnt; i++) {
		cout << tab[i] << " ";
	}
}

void Table::generate(int size)
{
	cnt = size;
	tab = new int[cnt];
	for (int i = 0; i < cnt; i++) {
		tab[i] = (rand() % RAND_MAX) - RAND_MAX / 2;
	}
}

void Table::tests(int cnt, string FileName)
{

	fstream plik(FileName, ios::out);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	plik << cnt << "\n";
	for (int i = 0; i < cnt; i++)
	{
		plik << (rand() % RAND_MAX) - RAND_MAX / 2 << "\n";
		plik.flush();
	}
	plik.close();
}

void Table::setCnt(int cnt) {
	this->cnt = cnt;
}
int Table::getCnt() {
	return cnt;
}