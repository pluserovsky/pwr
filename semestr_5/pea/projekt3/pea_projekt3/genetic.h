#pragma once
#include "tasks.h"

class genetic :
	public tasks
{
private:
	int *timeT, *weightT, *dateT,  // tablice recznie dodwanych zadan
		populationSize,		// rozmiar populacji
		generationSize,		// liczba pokolen ( iteracji)
		reproductionAmt,	//liczba genotypow branych pod uwage przy kolejnym pokoleniu
		generationsAmt; //ilosc generacji (powtorzen algorytmu)
	int **populationT, //macierz genotypów, czyli populacja
		**selectionPopulationT, //kopia populacji do selekcji turnijowej
		*bestGenotype, //najlepszy genotyp
		* bestGenotypeT; //tablica najlepszych genotypów
	void initialPopulation(); // generowanie populacji pocz¹tkowej
	void printBestGenotype(int bestGenotypeTWT);
	int * shuffleGenotype(); // mieszaj genotypy
	void printGenotype(string tittle, int * genotype);
	int countTWT(const int *tab); //liczenie sumy opóŸnieñ
	void crossoverOrderOne(int * firstParent, int * secondParent); //funkcja krzyzowania
	void crossoverOX(int * firstParent, int * secondParent);
	bool isInNewGenotype(int idx, int task, int* tab); // sprawdzenie czy zadanie jest juz w nowym dziecku
	//int countTWTComparator(const int* tab);
	//int fenotypeComparator(const void *left, const void *right);
	void swap(int from, int to, int *anyTasksArray); //swap mutacja
	void sort(); //selekcja ranogwa uproszczona do twt
	void reproduct(); //tworzenie noych pokolen
	int * getMinimumFromPopulation();
	void mutate();
	void selection(); //selekcja turniejowa
public:
	genetic();
	~genetic();
	int bestGenotypeTWT;
	int tasksAmt;
	tasks *tasksT; //tablica zadan
	string fileName; //zmienna nazwy pliku do zapisu i odczytu danych
	void ResetMemory();
	void PrintTasksT(); //drukowanie tablicy zadan
	void ImportData(string fileName, int wtXX,int cnt); //importowanie zadan z pliku wtXX.txt
	void GeneticSolve(); //algorytm dynamiczny
	//void ResetMemory(); //czyszczenie tabel i zmiennych
	
	//implementacja licznika
	double PCFreq = 0.0;
	__int64 CounterStart = 0;
	void StartCounter();
	double SaveCountersTable(string SaveFileName);
	//koniec implementacji licznika
};

