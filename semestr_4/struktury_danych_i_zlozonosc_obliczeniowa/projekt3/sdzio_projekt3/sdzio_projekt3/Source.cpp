#include "Knapsack.h"
#include "Towns.h"
#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

double PCFreq = 0.0;
__int64 CounterStart = 0;


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
void SaveCounter(string SaveFileName)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	fstream plik(SaveFileName, ios::app);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	plik << double(li.QuadPart - CounterStart) / PCFreq << "\n";
	plik.flush();

	plik.close();
}

using namespace std;

void run_tests_knapsack() {

	string fileName, name, space = "_", ext = ".txt";
	const int n = 5;
	const int b = 3;
	int tests = 100;

	long double bruteWynikiAvg[n][b];
	long double greedyWynikiAvg[n][b];

	int size_range = 50;
	int values_range = 50;
	int N[n] = { 5, 10, 20, 25, 30 };
	double b_ratio[b] = { 0.50, 0.25, 0.10 };
	int B[n][b];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < b; j++)
		{
			B[i][j] = (int)N[i] * size_range * b_ratio[j];
			bruteWynikiAvg[i][j] = 0;
			greedyWynikiAvg[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < b; j++)
		{
			RandKnapsackDataGen gen = *(new RandKnapsackDataGen(B[i][j], N[i], size_range, values_range));
			gen.saveToFile("knapsack_tests_input");

			Knapsack knapsack = *(new Knapsack());

			if (i == 4)
				tests = 5;
			std::cout << "\nRunning tests for " << N[i] << " elements and capacity " << B[i][j] << std::endl;
			for (int t = 0; t < tests; t++)
			{
				std::cout << ". ";
				//////// 100 tests //////////////

				knapsack.loadItemsSet("knapsack_tests_input");
				bool wynik;
				/*pomiar*/
				StartCounter();
				wynik = knapsack.greedy_pack();
				name = "knapsack_greddy_";
				fileName = name + to_string(N[i]) + space + to_string(B[i][j]) + ext;
				SaveCounter(fileName);
				/*pomiar*/
				if (!wynik) {
					throw new IndexOutOfBoundsException("Incorrect result for knapsack greedy.");
				}

				knapsack.loadItemsSet("knapsack_tests_input");
				/*pomiar*/
				StartCounter();
				wynik = knapsack.brute_force_pack();
				name = "knapsack_brute_";
				fileName = name + to_string(N[i]) + space + to_string(B[i][j]) + ext;
				SaveCounter(fileName);
				/*pomiar*/
				if (!wynik) {
					throw new IndexOutOfBoundsException("Incorrect result for salesman brute.");
				}

				//////////////////////////////////
			}
		}

	}
	///TESTING LOOP END
	return;
}
void run_tests_voyager() {

	string fileName, name, space = "_", ext = ".txt";
	const int n = 5;
	int tests = 100;

	long double bruteWynikiAvg[n];
	long double greedyWynikiAvg[n];

	int values_range = 20;
	int N_brute[n] = { 5, 10, 15 };
	int N[n] = { 10, 50, 100, 200, 500 };

	for (int i = 0; i < n; i++)
	{
		bruteWynikiAvg[i] = 0;
		greedyWynikiAvg[i] = 0;
	}

	RandGraphGen gen = *(new RandGraphGen());
	Towns towns = *(new Towns());

	for (int i = 0; i < n; i++)
	{
		if (i == 3)
			tests = 10;
		if (i == 5)
			tests = 1;

		std::cout << "\nRunning tests for " << N_brute[i] << " towns for brute_force and " << N[i] << " for greedy." << std::endl;

		gen.generate(N[i], values_range);
		gen.saveToFile("voyager_greedy_input");

		gen.generate(N_brute[i], values_range);
		gen.saveToFile("voyager_brute_input");



		for (int t = 0; t < tests; t++)
		{
			std::cout << ". ";
			//////// 100 tests //////////////
			towns.loadTownsMap("voyager_greedy_input");
			int* wynik;
			/*pomiar*/
			StartCounter();
			wynik = towns.greedy(0);
			name = "salesman_greedy_";
			fileName = name + to_string(N_brute[i]) + space + to_string(N[i]) + ext;

			SaveCounter(fileName);
			/*pomiar*/
			if (!wynik) {
				throw new IndexOutOfBoundsException("Incorrect result for salesman greedy.");
			}

			delete[] wynik;

			towns.loadTownsMap("voyager_brute_input");
			/*pomiar*/
			StartCounter();
			wynik = towns.brute_force();
			name = "salesman_brute_";
			fileName = name + to_string(N_brute[i]) + space + to_string(N[i]) + ext;
			SaveCounter(fileName);

			/*pomiar*/
			if (!wynik) {
				throw new IndexOutOfBoundsException("Incorrect result for salesman brute.");
			}
		}

	}

	///TESTING LOOP END
	return;
}

int main() {

	RandGraphGen gen = *(new RandGraphGen());
	Towns town = *(new Towns());
	Knapsack knapsack = *(new Knapsack());


	cout << ("== SDIZO PROJEKT 3 == Lukasz Broll 225972 \n= MENU GLOWNE =") << endl;
	cout << ("\n= PROBLEM PLECAKOWY =") << endl;
	cout << ("1. Wygeneruj dane.") << endl;
	cout << ("2. Algorytm zachlanny.") << endl;
	cout << ("3. Przeglad zupelny.") << endl;
	cout << ("\n =PROBLEM KOMIWOJAZERA =") << endl;
	cout << ("4. Wygeneruj dane.") << endl;
	cout << ("5. Algorytm zachlanny.") << endl;
	cout << ("6. Przeglad zupelny.") << endl;
	cout << ("\n7. Testy.") << endl;


	bool end = false;
	bool bad_command = false;
	while (!end) {

		bool badInsideCommand = false;
		std::cin.clear();
		std::cin.sync();
		char decision;

		if (bad_command)
		{
			std::cout << "Bledny numer opcji! Twoj wybor-> ";
			bad_command = false;

			std::cin >> decision;
		}
		else {
			std::cout << "\nTwoj wybor -> ";
			std::cin >> decision;
		}


		switch (decision) {


			//Generowanie przedmiot�w do plecaka
		case '1': {

			int t = 2;
			char* teksty[] = { "pojemnosc plecaka", "liczbe przedmiotow" };

			int* val = new int[t];
			bool blad = false;
			for (int i = 0; i < t; i++)
			{
				std::cout << "Podaj " << teksty[i] << ": ";

				std::cin >> val[i];

				if (val[i] <= 0)
				{
					std::cout << "BLAD! Pojemnosc nie moze przyjac takiej wartosci!\n";
					blad = true;
					break;
				}
			}
			if (blad)
				break;

			int wagi = (int)(val[0] * 0.75);
			int wartosci = 50;

			RandKnapsackDataGen knapgen = *(new RandKnapsackDataGen(val[0], val[1], wagi, wartosci));
			std::cout << "Podaj nazwe pliku do zapisu:  ";
			std::string nazwa;
			std::cin >> nazwa;

			try {
				knapgen.saveToFile(nazwa);
			}
			catch (std::runtime_error err) {
				std::cout << "ZAPIS NIEUDANY! " << err.what() << std::endl;
				break;
			}
			std::cout << "Zapis udany!\n";

			break;
		}
				  //Algorytm zach�anny plecak
		case '2': {

			std::cout << "Podaj nazwe pliku do odczytu zbioru przedmiotow:  ";
			std::string nazwa;
			std::cin >> nazwa;

			try {
				knapsack.loadItemsSet(nazwa);
			}
			catch (std::runtime_error err) {
				std::cout << "Odczyt nieudany!\n";
				std::cout << err.what();
				break;
			}
			std::cout << "Odczyt udany!\n";
			knapsack.printItemsSet();
			std::cout << "Uruchamiam algorytm zachlanny!\n";
	

			if (knapsack.greedy_pack())
				std::cout << "Wynik:\n" << knapsack;
			break;
		}
				  //Przegl�d zupe�ny plecak
		case '3': {
			std::cout << "Podaj nazwe pliku do odczytu zbioru przedmiotow:  ";
			std::string nazwa;
			std::cin >> nazwa;

			try {
				knapsack.loadItemsSet(nazwa);
			}
			catch (std::runtime_error err) {
				std::cout << "Odczyt nieudany!\n";
				std::cout << err.what();
				break;
			}
			std::cout << "Odczyt udany!\n";
			knapsack.printItemsSet();
			std::cout << "Uruchamiam przeglad zupelny!\n";
			 if (knapsack.brute_force_pack())
				std::cout << "Wynik:\n" << knapsack;
			break;
		}
				  //Generowanie mapy miast
		case '4': {

			int N;
			std::cout << "Podaj liczbe miast: ";

			std::cin >> N;

			if (N <= 0)
			{
				std::cout << "BLAD! Pojemnosc nie moze przyjac takiej wartosci!\n";
				break;
			}

			gen.generate(N, 2 * N);

			std::cout << "Podaj nazwe pliku do zapisu:  ";
			std::string nazwa;
			std::cin >> nazwa;

			try {
				gen.saveToFile(nazwa);
			}
			catch (std::runtime_error err) {
				std::cout << "ZAPIS NIEUDANY! " << err.what() << std::endl;
				break;
			}
			std::cout << "Zapis udany!\n";
			break;
		}
				  //Algorytm zach�anny komi
		case '5': {
			std::cout << "Podaj nazwe pliku do odczytu mapy miast:  ";
			std::string nazwa;
			std::cin >> nazwa;

			try {
				town.loadTownsMap(nazwa);
			}
			catch (std::runtime_error err) {
				std::cout << "Odczyt nieudany!\n";
				std::cout << err.what();
				break;
			}
			std::cout << "Odczyt udany!" << town << "\nUruchamiam algorytm zachlanny!\n";
			std::cout << "Wynik:\n";
		
			int* wynik = town.greedy(0);
			if (wynik) {
				std::cout << "Wynik:\n";
				for (int i = 2; i < wynik[0] + 2; i++)
				{
					if (i < wynik[0] + 1)
						std::cout << wynik[i] << " -> ";
					else
						std::cout << wynik[i] << std::endl;
				}
				std::cout << "Koszt = " << wynik[1] << std::endl;
			}
			else
				std::cout << "Blad algorytmu!\n";

			break;
		}
				  //Przegl�d zupe�ny komi
		case '6': {
			std::cout << "Podaj nazwe pliku do odczytu mapy miast:  ";
			std::string nazwa;
			std::cin >> nazwa;

			try {
				town.loadTownsMap(nazwa);
			}
			catch (std::runtime_error err) {
				std::cout << "Odczyt nieudany!\n";
				std::cout << err.what();
				break;
			}
			std::cout << "Odczyt udany!" << town << "\nUruchamiam przeglad zupelny!\n";
			std::cout << "Wynik:\n";
		
			
			int* wynik = town.brute_force();
			if (wynik) {
				std::cout << "Wynik:\n";

				for (int i = 2; i < wynik[0] + 2; i++)
				{
					if (i < wynik[0] + 1)
						std::cout << wynik[i] << " -> ";
					else
						std::cout << wynik[i] << std::endl;
				}
				std::cout << "Koszt = " << wynik[1] << std::endl;
			}
			else
				std::cout << "Blad algorytmu!\n";

			break;
		}
		case '7':

			run_tests_voyager();
			break;
		case 'k': {
			end = true;
			break;
		}

		default:
			bad_command = true;

		}
	}

	return 0;
}