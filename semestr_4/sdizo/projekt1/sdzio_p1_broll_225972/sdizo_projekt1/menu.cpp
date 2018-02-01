// menu.cpp : Defines the entry point for the console application.
//
#include <conio.h>
#include <string>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>

#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "RBT.h"

using namespace std;

Table myTab;
List myList;
Heap myHeap;
RBT myRBT;

//----------------------------------------------------------
//Implementacja licznika
//----------------------------------------------------------
double PCFreq = 0.0;
__int64 CounterStart = 0;

using namespace std;

void StartCounter()
{
	CounterStart = 0;
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
void SaveCountersTable(string SaveFileName)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	fstream plik(SaveFileName, ios::app);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	plik << (myTab.getCnt() + 1) << "\t" << double(li.QuadPart - CounterStart) / PCFreq << "\n";
	plik.flush();

	plik.close();
}
void SaveCountersList(string SaveFileName)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	fstream plik(SaveFileName, ios::app);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	plik << myList.getCnt() << "\t" << double(li.QuadPart - CounterStart) / PCFreq << "\n";
	plik.flush();

	plik.close();
}
void SaveCountersHeap(string SaveFileName)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	fstream plik(SaveFileName, ios::app);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	plik << myHeap.getCnt() << "\t" << double(li.QuadPart - CounterStart) / PCFreq << "\n";
	plik.flush();

	plik.close();
}
void SaveCountersRBT(string SaveFileName)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	fstream plik(SaveFileName, ios::app);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	plik << myRBT.getCnt() << "\t" << double(li.QuadPart - CounterStart) / PCFreq << "\n";
	plik.flush();

	plik.close();
}
//------------------------------------------------------
//KONIEC IMPLEMENTACJI LICZNIKA
//------------------------------------------------------

void displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

//menu opcji dodawania i usuwania elementow struktur
void display_menuFrom(string info) {

	cout << endl;
	cout << info << endl;
	cout << "1. Wed³ug indeksu" << endl;
	cout << "2. Pocz¹tek" << endl;
	cout << "3. Koniec" << endl;
	cout << "0. Powrot do menu" << endl;
	cout << "Podaj opcje:";
}


void menu_table()
{
	int index, value, opt, i,
		opt2 = 0;
	string fileName;

	do {
		displayMenu("--- TABLICA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytywanie  tablicy z pliku
			cout << " Podaj nazwê pliku:";
			cin >> fileName;
			if (!myTab.loadFromFile(fileName))
				cout << "Plik nie istnieje lub nie mo¿na go otworzyæ.";
			else
				cout << "Wczytano tablicê z pliku.";
			myTab.display();
			break;

		case '2':
			display_menuFrom("Wybierz z której pozycji usun¹æ element:");
			cin >> opt2;
			if (opt2 == 1)
			{
				//tutaj usuwanie wybranego elemenu z tablicy
				cout << " podaj index:";
				cin >> index;
				if (index >= 0 && index < myTab.getCnt())
				{
					StartCounter();
					myTab.deleteIndex(index);
					SaveCountersTable("table_deleteIndex.txt");
					myTab.display();
				}
				else cout << "Nieprawid³owy index ( ujemny lub za du¿y). Rozmiar tablicy: " << myTab.getCnt() << ".\n";
			}
			if (opt2 == 2)
			{
				StartCounter();
				myTab.deleteFirst();
				SaveCountersTable("table_deleteFirst.txt");
				myTab.display();
			}
			if (opt2 == 3)
			{
				StartCounter();
				myTab.deleteLast();
				SaveCountersTable("table_deleteLast.txt");
				myTab.display();
			}
			if (opt2 == 1)
			{
				break;
			}
			break;
		case '3': //tutaj dodawanie elemetu do tablicy
			display_menuFrom("Wybierz na któr¹ pozycjê dodaæ element:");
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << " podaj index:";
				cin >> index;
				if (index >= 0 && index <= myTab.getCnt()) {

					cout << " podaj wartoœæ:";
					cin >> value;
					StartCounter();
					myTab.addIndexValue(index, value);
					SaveCountersTable("table_addIndexValue.txt");
					myTab.display();
				}
				else cout << "Nieprawid³owy index ( ujemny lub za du¿y). Rozmiar tablicy: " << myTab.getCnt() << ".\n";
			}
			else if (opt2 == 2)
			{
				cout << " podaj wartoœæ:";
				cin >> value;
				StartCounter();
				myTab.addFirst(value);
				SaveCountersTable("table_addFirst.txt");
				myTab.display();
			}
			else if (opt2 == 3)
			{
				cout << " podaj wartoœæ:";
				cin >> value;
				StartCounter();
				myTab.addLast(value);
				SaveCountersTable("table_addLast.txt");
				myTab.display();
			}
			else if (opt2 == 0)
			{
				break;
			}
			break;
		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartoœæ:";
			cin >> value;
			StartCounter();
			if (myTab.IsValueIn(value))
				cout << "podana wartoœæ jest w tablicy";
			else
				cout << "podanej wartoœci NIE ma w tablicy";
			SaveCountersTable("table_IsValueInTable.txt");
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj iloœæ elementów tablicy:";
			cin >> value;
			myTab.generate(value);
			myTab.display();
			break;
		case '6':  //tutaj wyœwietlanie tablicy
			myTab.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			cout << endl;
			cout << "1.deleteFirst" << endl;
			cout << "2.deleteLast" << endl;
			cout << "3.deleteIndex" << endl;
			cout << "4.addLast" << endl;
			cout << "5.addFirst" << endl;
			cout << "6.addIndex" << endl;
			cout << "7.search" << endl;
			cout << "8.generate to file" << endl;
			cout << "0.Powrot do menu" << endl;
			cout << "Podaj opcje:";
			cin >> opt2;
			switch (opt2) {

			case 1:
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(1000);
					StartCounter();
					myTab.deleteLast();
					SaveCountersTable("table1000_deleteLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(2000);
					StartCounter();
					myTab.deleteLast();

					SaveCountersTable("table2000_deleteLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(5000);
					StartCounter();
					myTab.deleteLast();

					SaveCountersTable("table5000_deleteLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(10000);
					StartCounter();
					myTab.deleteLast();

					SaveCountersTable("table10000_deleteLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(20000);
					StartCounter();
					myTab.deleteLast();

					SaveCountersTable("table20000_deleteLast.txt");
				}
				break;
			case 2:
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(1000);
					StartCounter();
					myTab.deleteFirst();
					SaveCountersTable("table1000_deleteFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(2000);
					StartCounter();
					myTab.deleteFirst();
					SaveCountersTable("table2000_deleteFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(5000);
					StartCounter();
					myTab.deleteFirst();
					SaveCountersTable("table5000_deleteFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(10000);
					StartCounter();
					myTab.deleteFirst();
					SaveCountersTable("table10000_deleteFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(20000);
					StartCounter();
					myTab.deleteFirst();
					SaveCountersTable("table20000_deleteFirst.txt");
				}
				break;
			case 3:
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(1000);
					index = rand() % 1001;
					StartCounter();
					myTab.deleteIndex(index);
					SaveCountersTable("table1000_deleteIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(2000);
					index = rand() % 2001;
					StartCounter();
					myTab.deleteIndex(index);
					SaveCountersTable("table2000_deleteIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(5000);
					index = rand() % 5001;
					StartCounter();
					myTab.deleteIndex(index);
					SaveCountersTable("table5000_deleteIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(10000);
					index = rand() % 10001;
					StartCounter();
					myTab.deleteIndex(index);
					SaveCountersTable("table10000_deleteIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(20000);
					index = rand() % 20001;
					StartCounter();
					myTab.deleteIndex(index);
					SaveCountersTable("table20000_deleteIndex.txt");
				}
				break;
			case 4:
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myTab.addLast(value);
					SaveCountersTable("table1000_addLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(2000);
					StartCounter();
					myTab.addLast(value);

					SaveCountersTable("table2000_addLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(5000);
					StartCounter();
					myTab.addLast(value);

					SaveCountersTable("table5000_addLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(10000);
					StartCounter();
					myTab.addLast(value);

					SaveCountersTable("table10000_addLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(20000);
					StartCounter();
					myTab.addLast(value);

					SaveCountersTable("table20000_addLast.txt");
				}
				break;
			case 5:
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(1000);
					StartCounter();
					myTab.addFirst(value);
					SaveCountersTable("table1000_addFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myTab.generate(2000);
					StartCounter();
					myTab.addFirst(value);
					SaveCountersTable("table2000_addFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(5000);
					StartCounter();
					myTab.addFirst(value);
					SaveCountersTable("table5000_addFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(10000);
					StartCounter();
					myTab.addFirst(value);
					SaveCountersTable("table10000_addFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(20000);
					StartCounter();
					myTab.addFirst(value);
					SaveCountersTable("table20000_addFirst.txt");
				}
				break;
			case 6:
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(1000);
					index = rand() % 1001;
					StartCounter();
					myTab.addIndexValue(index, value);

					SaveCountersTable("table1000_addIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(2000);
					index = rand() % 2001;
					StartCounter();
					myTab.addIndexValue(index, value);

					SaveCountersTable("table2000_addIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(5000);
					index = rand() % 5001;
					StartCounter();
					myTab.addIndexValue(index, value);

					SaveCountersTable("table5000_addIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(10000);
					index = rand() % 10001;
					StartCounter();
					myTab.addIndexValue(index, value);

					SaveCountersTable("table10000_addIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myTab.generate(20000);
					index = rand() % 20001;
					StartCounter();
					myTab.addIndexValue(index, value);
					SaveCountersTable("table20000_addIndex.txt");
				}
				break;
			case 7:
				i = 0;
				while (i <= 100)
				{
					myTab.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myTab.IsValueIn(value)) {
						i++;
						SaveCountersTable("table1000_IsValueInTable.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myTab.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myTab.IsValueIn(value)) {
						i++;
						SaveCountersTable("table2000_IsValueInTable.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myTab.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myTab.IsValueIn(value)) i++;
					SaveCountersTable("table5000_IsValueInTable.txt");
				}
				i = 0;
				while (i <= 100)
				{
					myTab.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myTab.IsValueIn(value)) {
						i++;
						SaveCountersTable("table10000_IsValueInTable.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myTab.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myTab.IsValueIn(value)) {
						i++;
						SaveCountersTable("table20000_IsValueInTable.txt");
					}
				}
				break;
			case 8:
				cout << " Podaj nazwê zbioru:";
				cin >> fileName;
				cout << "Podaj iloœæ elementów tablicy:";
				cin >> value;
				myTab.generate(value);
				myTab.tests(value, fileName);
				break;
			case 0:
				break;
			}
		}
	} while (opt != '0');
}

void menu_list()
{
	int index, value, opt, i,
		opt2 = 0;
	string fileName;

	do {
		displayMenu("--- LISTA ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytywanie  listy z pliku
			cout << " Podaj nazwê pliku:";
			cin >> fileName;
			if (!myList.loadFromFile(fileName))
				cout << "Plik nie istnieje lub nie mo¿na go otworzyæ." << endl;
			else
				cout << "Wczytano listê z pliku." << endl;
			myList.display();
			break;

		case '2':
			display_menuFrom("Wybierz z której pozycji usun¹æ element:");
			cin >> opt2;
			if (opt2 == 1)
			{
				//tutaj usuwanie wybranego elemenu z listy
				cout << " podaj wartoœæ:";
				cin >> value;
				StartCounter();
				if (myList.IsValueIn(value))
				{
					myList.deleteValue(value);
					SaveCountersList("list_deleteValue.txt");
					myList.display();
				}
				else cout << "Nie ma takiej wartosci w liscie." << endl;

			}
			if (opt2 == 2)
			{
				StartCounter();
				myList.deleteFirst();
				SaveCountersList("list_deleteFirst.txt");
				myList.display();
			}
			if (opt2 == 3)
			{
				StartCounter();
				myList.deleteLast();
				SaveCountersList("list_deleteLast.txt");
				myList.display();
			}
			if (opt2 == 1)
			{
				break;
			}
			break;
		case '3': //tutaj dodawanie elemetu do listy
			display_menuFrom("Wybierz na któr¹ pozycjê dodaæ element:");
			cin >> opt2;
			if (opt2 == 1)
			{
				cout << " podaj index:";
				cin >> index;
				cout << " podaj wartoœæ:";
				cin >> value;
				StartCounter();
				myList.addValue(value, index);
				SaveCountersList("list_addIndexValue.txt");
				myList.display();

			}
			else if (opt2 == 2)
			{
				cout << " podaj wartoœæ:";
				cin >> value;
				StartCounter();
				myList.addFirst(value);
				SaveCountersList("list_addFirst.txt");
				myList.setCnt(myList.getCnt() + 1);
				myList.display();
			}
			else if (opt2 == 3)
			{
				cout << " podaj wartoœæ:";
				cin >> value;
				StartCounter();
				myList.addLast(value);
				SaveCountersList("list_addLast.txt");
				myList.setCnt(myList.getCnt() + 1);
				myList.display();
			}
			else if (opt2 == 0)
			{
				break;
			}
			break;
		case '4': //tutaj znajdowanie elemetu w liscie
			cout << " podaj wartoœæ:";
			cin >> value;
			StartCounter();
			if (myList.IsValueIn(value))
				cout << "podana wartoœæ jest na liscie";
			else
				cout << "podanej wartoœci NIE ma w liscie";
			SaveCountersList("list_IsValueInTable.txt");
			break;

		case '5':  //tutaj generowanie listy
			cout << "Podaj iloœæ elementów listy:";
			cin >> value;
			myList.generate(value);
			myList.display();
			break;
		case '6':  //tutaj wyœwietlanie tablicy
			myList.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			cout << endl;
			cout << "1.deleteFirst" << endl;
			cout << "2.deleteLast" << endl;
			cout << "3.deleteIndex" << endl;
			cout << "4.addLast" << endl;
			cout << "5.addFirst" << endl;
			cout << "6.addIndex" << endl;
			cout << "7.search" << endl;
			cout << "8.generate to file" << endl;
			cout << "0.Powrot do menu" << endl;
			cout << "Podaj opcje:";
			cin >> opt2;
			switch (opt2) {

			case 1:
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(1000);
					StartCounter();
					myList.deleteLast();
					SaveCountersList("list1000_deleteLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(2000);
					StartCounter();
					myList.deleteLast();
					SaveCountersList("list2000_deleteLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(5000);
					StartCounter();
					myList.deleteLast();
					SaveCountersList("list5000_deleteLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(10000);
					StartCounter();
					myList.deleteLast();
					SaveCountersList("list10000_deleteLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(20000);
					StartCounter();
					myList.deleteLast();
					SaveCountersList("list20000_deleteLast.txt");
				}
				break;
			case 2:
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(1000);
					StartCounter();
					myList.deleteFirst();
					SaveCountersList("list1000_deleteFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(2000);
					StartCounter();
					myList.deleteFirst();
					SaveCountersList("list2000_deleteFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(5000);
					StartCounter();
					myList.deleteFirst();
					SaveCountersList("list5000_deleteFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(10000);
					StartCounter();
					myList.deleteFirst();
					SaveCountersList("list10000_deleteFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(20000);
					StartCounter();
					myList.deleteFirst();
					SaveCountersList("list20000_deleteFirst.txt");
				}
				break;
			case 3:
				i = 0;
				while (i < 100)
				{
					myList.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myList.IsValueIn(value)) {
						StartCounter();
						myList.deleteValue(value);
						SaveCountersList("list1000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i < 100)
				{
					myList.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myList.IsValueIn(value)) {
						StartCounter();
						myList.deleteValue(value);
						SaveCountersList("list2000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i < 100)
				{
					myList.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myList.IsValueIn(value)) {
						StartCounter();
						myList.deleteValue(value);
						SaveCountersList("list5000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i < 100)
				{
					myList.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myList.IsValueIn(value)) {
						StartCounter();
						myList.deleteValue(value);
						SaveCountersList("list10000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i < 100)
				{
					myList.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myList.IsValueIn(value)) {
						StartCounter();
						myList.deleteValue(value);
						SaveCountersList("list20000_deleteValue.txt");
						i++;
					}
				}
				break;
			case 4:
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addLast(value);
					SaveCountersList("list1000_addLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addLast(value);
					SaveCountersList("list2000_addLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addLast(value);
					SaveCountersList("list5000_addLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addLast(value);
					SaveCountersList("list10000_addLast.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addLast(value);
					SaveCountersList("list20000_addLast.txt");
				}
				break;
			case 5:
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addFirst(value);
					SaveCountersList("list1000_addFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addFirst(value);
					SaveCountersList("list2000_addFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addFirst(value);
					SaveCountersList("list5000_addFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addFirst(value);
					SaveCountersList("list10000_addFirst.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					myList.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myList.addFirst(value);
					SaveCountersList("list20000_addFirst.txt");
				}
				break;
			case 6:
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myList.generate(1000);
					index = rand() % 1001;
					StartCounter();
					myList.addValue(index, value);

					SaveCountersList("list1000_addIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myList.generate(2000);
					index = rand() % 2001;
					StartCounter();
					myList.addValue(index, value);

					SaveCountersList("list2000_addIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myList.generate(5000);
					index = rand() % 5001;
					StartCounter();
					myList.addValue(index, value);

					SaveCountersList("list5000_addIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myList.generate(10000);
					index = rand() % 10001;
					StartCounter();
					myList.addValue(index, value);

					SaveCountersList("list10000_addIndex.txt");
				}
				for (int i = 0; i <= 100; i++)
				{
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					myList.generate(20000);
					index = rand() % 20001;
					StartCounter();
					myList.addValue(index, value);

					SaveCountersList("list20000_addIndex.txt");
				}
				break;
			case 7:
				i = 0;
				while (i <= 100)
				{
					myList.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myList.IsValueIn(value)) {
						i++;
						SaveCountersList("list1000_IsValueInTable.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myList.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myList.IsValueIn(value)) {
						i++;
						SaveCountersList("list2000_IsValueInTable.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myList.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myList.IsValueIn(value)) {
						i++;
						SaveCountersList("list5000_IsValueInTable.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myList.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myList.IsValueIn(value)) {
						i++;
						SaveCountersList("list10000_IsValueInTable.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myList.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myList.IsValueIn(value)) {
						i++;
						SaveCountersList("list20000_IsValueInTable.txt");
					}
				}
				break;
			case 0:
				break;
			}
		}
	} while (opt != '0');
}

void menu_heap()
{
	int i = 0;
	int value, opt,
		opt2 = 0;
	string fileName;

	do {
		displayMenu("--- KOPIEC ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytywanie  listy z pliku
			cout << " Podaj nazwê pliku:";
			cin >> fileName;
			if (!myHeap.loadFromFile(fileName))
				cout << "Plik nie istnieje lub nie mo¿na go otworzyæ." << endl;
			else
				cout << "Wczytano kopiec z pliku." << endl;
			myHeap.display();
			break;

		case '2':
			//tutaj usuwanie wybranego elemenu z kopca
			cout << " podaj wartoœæ:";
			cin >> value;
			StartCounter();
			if (myHeap.IsValueIn(value))
			{
				myHeap.deleteValue(value);
				SaveCountersHeap("heap_deleteValue.txt");
				myHeap.display();
			}
			else cout << "Nie ma takiej wartosci w kopcu." << endl;

			break;
		case '3': //tutaj dodawanie elemetu do kopca
			cout << " podaj wartoœæ:";
			cin >> value;
			StartCounter();
			myHeap.addValue(value);
			SaveCountersHeap("heap_addIndexValue.txt");
			myHeap.display();

			break;
		case '4': //tutaj znajdowanie elemetu w kopcu
			cout << " podaj wartoœæ:";
			cin >> value;
			StartCounter();
			if (myHeap.IsValueIn(value))
				cout << "podana wartoœæ jest w kopcu";
			else
				cout << "podanej wartoœci NIE ma w kopcu";
			SaveCountersHeap("heap_IsValueInTable.txt");
			break;

		case '5':  //tutaj generowanie  kopca
			cout << "Podaj iloœæ elementów kopca:";
			cin >> value;
			myHeap.generate(value);
			myHeap.display();
			break;
		case '6':  //tutaj wyœwietlanie kopca
			myHeap.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			cout << endl;
			cout << "1.delete" << endl;
			cout << "2.add" << endl;
			cout << "3.search" << endl;
			cout << "8.generate to file" << endl;
			cout << "0.Powrot do menu" << endl;
			cout << "Podaj opcje:";
			cin >> opt2;
			switch (opt2) {

			case 1:
				/*i = 0;
				while (i<100)
				{
					myHeap.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myHeap.IsValueIn(value)) {
						StartCounter();
						myHeap.deleteValue(value);
						SaveCountersHeap("heap1000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i<100)
				{
					myHeap.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myHeap.IsValueIn(value)) {
						StartCounter();
						myHeap.deleteValue(value);
						SaveCountersHeap("heap2000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i<100)
				{
					myHeap.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myHeap.IsValueIn(value)) {
						StartCounter();
						myHeap.deleteValue(value);
						SaveCountersHeap("heap5000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i<30)
				{
					myHeap.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myHeap.IsValueIn(value)) {
						StartCounter();
						myHeap.deleteValue(value);
						SaveCountersHeap("heap10000_deleteValue.txt");
						i++;
					}
				}*/
				i = 0;
				while (i < 20)
				{
					myHeap.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myHeap.IsValueIn(value)) {
						StartCounter();
						myHeap.deleteValue(value);
						SaveCountersHeap("heap20000_deleteValue.txt");
						i++;
					}
				}
				break;
			case 2:
				for (int i = 0; i < 100; i++)
				{
					myHeap.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myHeap.addValue(value);
					SaveCountersHeap("heap1000_addIndex.txt");
				}
				for (int i = 0; i < 100; i++)
				{
					myHeap.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myHeap.addValue(value);
					SaveCountersHeap("heap2000_addIndex.txt");
				}
				for (int i = 0; i < 100; i++)
				{
					myHeap.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myHeap.addValue(value);
					SaveCountersHeap("heap5000_addIndex.txt");
				}
				for (int i = 0; i < 100; i++)
				{
					myHeap.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myHeap.addValue(value);
					SaveCountersHeap("heap10000_addIndex.txt");
				}
				for (int i = 0; i < 100; i++)
				{
					myHeap.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myHeap.addValue(value);
					SaveCountersHeap("heap20000_addIndex.txt");
				}
				break;
			case 3:
				/*i = 0;
				while (i <= 100)
				{
					myHeap.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myHeap.IsValueIn(value)) {
						i++;
						SaveCountersHeap("heap1000_IsValueIn.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myHeap.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myHeap.IsValueIn(value)) {
						i++;
						SaveCountersHeap("heap2000_IsValueIn.txt");
					}
				}
				i = 0;
				while (i <= 80)
				{
					myHeap.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myHeap.IsValueIn(value)) {
						i++;
						SaveCountersHeap("heap5000_IsValueIn.txt");
					}
				}
				i = 0;
				while (i <= 45)
				{
					myHeap.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myHeap.IsValueIn(value)) {
						i++;
						SaveCountersHeap("heap10000_IsValueIn.txt");
					}
				}
				}*/
				i = 0;
				while (i <= 100)
				{
					myHeap.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myHeap.IsValueIn(value)) {
						i++;
						SaveCountersHeap("heap20000_IsValueIn.txt");
					}
				}
				break;
			case 0:
				break;
			}
		}
	} while (opt != '0');
}

void menu_RBT()
{
	int value, opt, i,
		opt2 = 0;
	string fileName;

	do {
		displayMenu("--- Drzewo czerwono - czarne RBT ---");
		opt = _getche();
		cout << endl;
		switch (opt) {
		case '1': //tutaj wczytywanie  listy z pliku
			cout << " Podaj nazwê pliku:";
			cin >> fileName;
			if (!myRBT.loadFromFile(fileName))
				cout << "Plik nie istnieje lub nie mo¿na go otworzyæ." << endl;
			else
				cout << "Wczytano drzewo RBT z pliku." << endl;
			myRBT.display();
			break;

		case '2':
			//tutaj usuwanie wybranego elemenu z RB
			cout << " podaj wartoœæ:";
			cin >> value;
			StartCounter();
			if (myRBT.IsValueIn(value))
			{
				myRBT.deleteValue(value);
				SaveCountersRBT("rbt_deleteValue.txt");
				myRBT.display();
			}
			else cout << "Nie ma takiej wartosci w drzewie." << endl;

			break;
		case '3': //tutaj dodawanie elemetu do RB
			cout << " podaj wartoœæ:";
			cin >> value;
			StartCounter();
			myRBT.addValue(value);
			SaveCountersRBT("rbt_addIndexValue.txt");
			myRBT.display();
			break;
		case '4': //tutaj znajdowanie elemetu w RBT
			cout << " podaj wartoœæ:";
			cin >> value;
			StartCounter();
			if (myRBT.IsValueIn(value) != NULL)
				cout << "podana wartoœæ jest w drzewie RBT";
			else
				cout << "podanej wartoœci NIE ma w drzewie RBT";
			SaveCountersRBT("rbt_IsValueInTable.txt");
			break;

		case '5':  //tutaj generowanie  RBT
			cout << "Podaj iloœæ elementów drzewa:";
			cin >> value;
			myRBT.generate(value);
			myRBT.display();
			break;
		case '6':  //tutaj wyœwietlanie tablicy
			myRBT.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego 
				  // mo¿na sobie tu dodaæ w³asne case'y
			cout << endl;
			cout << "1.delete" << endl;
			cout << "2.add" << endl;
			cout << "3.search" << endl;
			cout << "8.generate to file" << endl;
			cout << "0.Powrot do menu" << endl;
			cout << "Podaj opcje:";
			cin >> opt2;
			switch (opt2) {

			case 1:
				i = 0;
				while (i < 100)
				{
					myRBT.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myRBT.IsValueIn(value)) {
						StartCounter();
						myRBT.deleteValue(value);
						SaveCountersRBT("rbt10000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i < 100)
				{
					myRBT.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myRBT.IsValueIn(value)) {
						StartCounter();
						myRBT.deleteValue(value);
						SaveCountersRBT("rbt20000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i < 100)
				{
					myRBT.generate(50000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myRBT.IsValueIn(value)) {
						StartCounter();
						myRBT.deleteValue(value);
						SaveCountersRBT("rbt50000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i < 100)
				{
					myRBT.generate(100000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myRBT.IsValueIn(value)) {
						StartCounter();
						myRBT.deleteValue(value);
						SaveCountersRBT("rbt100000_deleteValue.txt");
						i++;
					}
				}
				i = 0;
				while (i < 100)
				{
					myRBT.generate(200000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					if (myRBT.IsValueIn(value)) {
						StartCounter();
						myRBT.deleteValue(value);
						SaveCountersRBT("rbt200000_deleteValue.txt");
						i++;
					}
				}
				break;
			case 2:
				for (int i = 0; i < 100; i++)
				{
					myRBT.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myRBT.addValue(value);
					SaveCountersRBT("rbt1000_addIndex.txt");
				}
				for (int i = 0; i < 100; i++)
				{
					myRBT.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myRBT.addValue(value);
					SaveCountersRBT("rbt2000_addIndex.txt");
				}
				for (int i = 0; i < 100; i++)
				{
					myRBT.generate(50000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myRBT.addValue(value);
					SaveCountersRBT("rbt50000_addIndex.txt");
				}
				for (int i = 0; i < 100; i++)
				{
					myRBT.generate(100000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myRBT.addValue(value);
					SaveCountersRBT("rbt100000_addIndex.txt");
				}
				for (int i = 0; i < 100; i++)
				{
					myRBT.generate(200000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					myRBT.addValue(value);
					SaveCountersRBT("rbt200000_addIndex.txt");
				}
				break;
			case 3:
				i = 0;
				while (i <= 100)
				{
					myRBT.generate(1000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myRBT.IsValueIn(value)) {
						i++;
						SaveCountersRBT("rbt1000_IsValueIn.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myRBT.generate(2000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myRBT.IsValueIn(value)) {
						i++;
						SaveCountersRBT("rbt2000_IsValueIn.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myRBT.generate(5000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myRBT.IsValueIn(value)) {
						i++;
						SaveCountersRBT("rbt5000_IsValueIn.txt");
					}
				}
				i = 0;
				while (i <= 100)
				{
					myRBT.generate(10000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myRBT.IsValueIn(value)) {
						i++;
						SaveCountersRBT("rbt10000_IsValueIn.txt");
					}
				}

				i = 0;
				while (i <= 100)
				{
					myRBT.generate(20000);
					value = (rand() % RAND_MAX) - RAND_MAX / 2;
					StartCounter();
					if (myRBT.IsValueIn(value)) {
						i++;
						SaveCountersRBT("rbt20000_IsValueIn.txt");
					}
				}
				break;
			case 0:
				break;
			}
		}
	} while (opt != '0');
}

int main(int argc, char* argv[])
{
	//setlocale(LC_ALL, "");
	srand(time(NULL));
	char option;
	do {
		cout << endl;
		cout << "==== SDIZO P1 === Lukasz Broll 225972 ===" << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "4.Drzewo RBT" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje:";
		option = _getche();
		cout << endl;

		switch (option) {
		case '1':
			menu_table();
			break;

		case '2':
			menu_list();
			break;

		case '3':
			menu_heap();
			break;

		case '4':
			menu_RBT();
			break;
		}

	} while (option != '0');

	return 0;
}

