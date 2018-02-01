#pragma once
#include "tasks.h"
class dynamic : tasks
{
private:
	bool *permTab; //tablica permutacji

	int *subScoresT, // tablica wynikow poœrednich przed wybraniem najlepszego z permutacji
		*ScoreOrderT, // tablica kolejnosci zadan wszystkich permutacji
		opt, //optymalny koszt zadania w permutacji
		minScoreItr, // licznik petli liczenia MinScore
		*ScoresT, // tablica wynikow kosztów perumtacji
		*OrdersT, //bliŸniacza tablica do ScoresT z kolejnoœci¹ ostatecznego rozwi¹zania
		*timeT, *weightT, *dateT; // tablice recznie dodwanych zadan

	long long int bufor = 0, // zmienna przy decToBin permutacji
		idx = 0; //indeks najmniejszego wyniku danej permutacji

	int MinScore(int idx); //obliczanie najmniejszego wyniku jednej permutacji
	void CountTasksOrder(); //liczenie optymalnej kolejnosci zadan
	void PrintTasksOrder(); //drukowanie optymalnej kolejnosci zadan

	//implementacja licznika
	double PCFreq = 0.0;
	__int64 CounterStart = 0;
	void StartCounter();
	

public:
	dynamic();
	~dynamic();
	int taskAmt; // ilosc zadan
	tasks *tasksT; //tablica zadan
	string fileName; //zmienna nazwy pliku do zapisu i odczytu danych

	void ImportData(string fileName, int wtXX); //importowanie zadan z pliku wtXX.txt
	void DynamicSolve(); //algorytm dynamiczny
	void PrintTasksT(); //drukowanie tablicy zadan
	void ResetMemory(); //czyszczenie tabel i zmiennych

	double SaveCountersTable(string SaveFileName);
};

