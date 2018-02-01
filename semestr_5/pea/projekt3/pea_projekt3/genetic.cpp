#include "stdafx.h"
#include "genetic.h"

int toCompareTasksAmt;
tasks* toCompareTasksT;

void genetic::initialPopulation()
{
	populationSize = 200;
	reproductionAmt = populationSize / 2;
	generationsAmt = 5000;

	populationT = new int*[populationSize];
	for (int i = 0; i < populationSize; i++)
	{
		populationT[i] = shuffleGenotype();
	}
	countTWT(populationT[0]);
}

void genetic::printBestGenotype(int bestGenotypeTWT)
{
	cout << endl;
	for (int i = 0; i < tasksAmt; i++)
		cout << bestGenotype[i] << " ";

	cout << endl << "Suma opoznienia:" << bestGenotypeTWT;
}

int * genetic::shuffleGenotype()
{
	int* temp = new int[tasksAmt];
	vector<int> genotypeV = vector<int>();
	for (int i = 0; i < tasksAmt; i++)
		genotypeV.push_back(i);

	for (int i = 0; i < tasksAmt; i++)
	{
		int idx = rand() % genotypeV.size();
		temp[i] = genotypeV[idx];
		genotypeV.erase(genotypeV.begin() + idx, genotypeV.begin() + idx + 1);
	}
	return temp;
}

void genetic::printGenotype(string tittle, int * genotype)
{
	cout << endl << tittle << endl;
	for (int i = 0; i < tasksAmt; i++) {
		cout << genotype[i] << ", ";
	}
}

int countTWTComparator(const int* anyTasksArray) {
	int twt = 0;
	int sumProcessingTime = 0, deltaTime;

	for (int i = 0; i < toCompareTasksAmt; i++) {
		int index = anyTasksArray[i];
		sumProcessingTime += toCompareTasksT[index].getTime();
		deltaTime = sumProcessingTime - toCompareTasksT[index].getDate();
		if (deltaTime > 0)
			twt += deltaTime * toCompareTasksT[index].getWeight();
	}
	return twt;
}

int fenotypeComparator(const void *first, const void *second)
{
	int l = countTWTComparator(*(int**)first);
	int r = countTWTComparator(*(int**)second);
	return l - r;
}

int genetic::countTWT(const int * anyTasksArray)
{
	int twt = 0,
		sumProcessingTime = 0,
		deltaTime;
	/*
	do sumProcessingTime sumowany jest czas wykonywania kolejnych zadan
	w deltaTime przechowywana jest róznica miedzy sum¹ czasów zadan, a czasem wykonania ostatniego
	jeœli obliczone deltaTime > 0 to zwróci karê za opóŸnienie, czyli ilocznym deltaTime iter wagi zadania
	*/
	for (int i = 0; i < tasksAmt; i++) {
		int index = anyTasksArray[i];
		sumProcessingTime += tasksT[index].getTime();
		deltaTime = sumProcessingTime - tasksT[index].getDate();
		if (deltaTime > 0)
			twt += deltaTime * tasksT[index].getWeight();
	}
	return twt;
}

void genetic::crossoverOrderOne(int * firstParent, int * secondParent)
{
	int randIdx = (rand() % (tasksAmt - 1)) + 1;
	int *firstChildT, *secondChildT, firstChildIdx, secondChildIdx;
	firstChildT = new int[tasksAmt];
	secondChildT = new int[tasksAmt];

	//zapelnienie pierwszej polowy genotypu dziecka
	for (int i = 0; i < randIdx; i++) {
		firstChildT[i] = firstParent[i];
		secondChildT[i] = secondParent[i];
	}

	firstChildIdx = secondChildIdx = randIdx;
	//zapelnienie drugeij polowy genotypu dziecka brakujacymi zadaniami
	for (int i = 0; i < tasksAmt; i++) {
		if (!isInNewGenotype(randIdx, firstParent[i], secondParent)) {
			secondChildT[secondChildIdx++] = firstParent[i];
		}
		if (!isInNewGenotype(randIdx, secondParent[i], firstParent)) {
			firstChildT[firstChildIdx++] = secondParent[i];
		}
	}
	firstParent = firstChildT;
	secondParent = secondChildT;
	delete[] secondChildT;
	delete[] firstChildT;
}

void genetic::crossoverOX(int * firstToCross, int * secondToCross)
{
	int beginIdx = (rand() % (tasksAmt - 1)) + 1,
		endIdx = (rand() % (tasksAmt - beginIdx)) + beginIdx,
		sizeToTableEnd = tasksAmt - endIdx,
		toFirstAdded = 1,
		toSecondAdded = 1,
		firstIdxIter = endIdx + 1,
		secondIdxIter = endIdx + 1,
		*firstChildT,
		*secondChildT;

	firstChildT = new int[tasksAmt];
	secondChildT = new int[tasksAmt];

	//przekopiowanie wylosowanej czesci genotypu dziecka
	for (int i = 0; i < tasksAmt; i++) {
		firstChildT[i] = -1;
		secondChildT[i] = -1;
	}
	for (int i = beginIdx; i <= endIdx; i++) {
		firstChildT[i] = firstToCross[i];
		secondChildT[i] = secondToCross[i];
	}
	//printGenotype("firstToCross", firstToCross);
	//printGenotype("firstToCross", secondToCross);
	//zapelnienie pierwszego dziecka do konca
	while (toFirstAdded <= sizeToTableEnd) {
		if (firstIdxIter == tasksAmt) firstIdxIter = 0;
		if (!isInNewGenotype(tasksAmt, secondToCross[firstIdxIter], firstChildT)) {
			firstChildT[endIdx + toFirstAdded] = secondToCross[firstIdxIter];
			toFirstAdded++;
		}
		firstIdxIter++;
	}
	//zapelnienie drugiegoo dziecka do konca
	while (toSecondAdded <= sizeToTableEnd) {
		if (secondIdxIter == tasksAmt) secondIdxIter = 0;
		if (!isInNewGenotype(tasksAmt, firstToCross[secondIdxIter], secondChildT)) {
			secondChildT[endIdx + toSecondAdded] = firstToCross[secondIdxIter];
			toSecondAdded++;
		}
		secondIdxIter++;
	}
	//printGenotype("uzupelniono pierwszy genotyp do konca", firstChildT);
	//printGenotype("uzupelniono drugi genotyp do konca", secondChildT);

	//zape³nienie genotypu pierwszego od poczatku
	toFirstAdded = 0;
	toSecondAdded = 0;
	firstIdxIter--;
	secondIdxIter--;
	while (toFirstAdded < beginIdx) {
		if (firstIdxIter == tasksAmt) firstIdxIter = 0;
		if (!isInNewGenotype(tasksAmt, secondToCross[firstIdxIter], firstChildT)) {
			firstChildT[toFirstAdded] = secondToCross[firstIdxIter];
			toFirstAdded++;
		}
		firstIdxIter++;
	}
	//zape³nienie genotypu drugiego od poczatku
	while (toSecondAdded < beginIdx) {
		if (secondIdxIter == tasksAmt) secondIdxIter = 0;
		if (!isInNewGenotype(tasksAmt, firstToCross[secondIdxIter], secondChildT)) {
			secondChildT[toSecondAdded] = firstToCross[secondIdxIter];
			toSecondAdded++;
		}
		secondIdxIter++;
	}
	//printGenotype("uzupelniono pierwszy genotyp calkowicie", firstChildT);
	//printGenotype("uzupelniono drugi genotyp calkowicie", secondChildT);

	firstToCross = firstChildT;
	secondToCross = secondChildT;
	//delete secondChildT;
	//delete firstChildT;
}

bool genetic::isInNewGenotype(int idx, int task, int * tab)
{
	for (int j = 0; j < idx; j++)
		if (task == tab[j])
			return true;
	return false;
}

void genetic::reproduct()
{
	//skopiuj genotypy od najlepszego do ilosci reprodukcji
	for (int i = 0; i < reproductionAmt; i++)
	{
		if ((i + reproductionAmt) >= populationSize)
			break;
		memcpy(populationT[i + reproductionAmt], populationT[i], sizeof(int)*tasksAmt);
	}
	// pokrosuj te skopiowane genotypy
	for (int i = reproductionAmt; i < reproductionAmt + (reproductionAmt / 2) - 2; i += 2)
	{
		//crossoverOrderOne(populationT[i], populationT[i + 1]);
		crossoverOX(populationT[i], populationT[i + 1]);
	}
	//zmutuj losowe genotypy z calej populacji
	mutate();
}

void genetic::GeneticSolve()
{
	initialPopulation();
	bestGenotype = getMinimumFromPopulation();
	int iter = 0;

	StartCounter();
	while (iter < generationsAmt)
	{
		sort();
		bestGenotypeTWT = countTWT(bestGenotype);
		bestGenotypeT = getMinimumFromPopulation();
		if (countTWT(bestGenotypeT) < bestGenotypeTWT)
			bestGenotype = bestGenotypeT;
		//selection();
		reproduct();
		iter++;
		//cout << ".";
	}
	printBestGenotype(bestGenotypeTWT);

}

int* genetic::getMinimumFromPopulation()
{
	int* minimum = populationT[0];
	for (int i = 1; i < populationSize; i++)
	{
		if (countTWT(minimum) > countTWT(populationT[i]))
			minimum = populationT[i];
	}
	return minimum;
}

void genetic::mutate()
{
	//metoda transpozycji - prawdopodobiensto mutacji 10%
	for (int i = 0; i < populationSize; i++)
	{
		if (rand() % 99 <= 10)
		{
			swap(rand() % tasksAmt, rand() % tasksAmt, populationT[i]);
		}
	}
}
void genetic::selection() {
	//metoda turniejowa
	selectionPopulationT = new int*[populationSize];
	for (int i = 0; i < populationSize; i++)
	{
		selectionPopulationT[i] = populationT[i];
	}
	for (int i = 0; i < populationSize; i++)
	{
		int n0 = rand() % populationSize,
			n1 = rand() % populationSize,
			n2 = rand() % populationSize,
			n3 = rand() % populationSize;
		int *tournament = new int[4];
		tournament[0] = countTWT(populationT[n0]);
		tournament[1] = countTWT(populationT[n1]);
		tournament[2] = countTWT(populationT[n2]);
		tournament[3] = countTWT(populationT[n3]);
		int minimum = tournament[0];
		for (int j = 0; j < 4; j++)
		{
			if (minimum < tournament[j])
				minimum = tournament[j];
		}
		if (minimum == tournament[0])
			memcpy(selectionPopulationT[i], populationT[n0], sizeof(int)*tasksAmt);
		else if (minimum == tournament[1])
			memcpy(selectionPopulationT[i], populationT[n1], sizeof(int)*tasksAmt);
		else if (minimum == tournament[2])
			memcpy(selectionPopulationT[i], populationT[n2], sizeof(int)*tasksAmt);
		else if (minimum == tournament[3])
			memcpy(selectionPopulationT[i], populationT[n3], sizeof(int)*tasksAmt);
	}
	populationT = selectionPopulationT;
}
void genetic::sort()
{
	toCompareTasksT = tasksT;
	toCompareTasksAmt = tasksAmt;
	qsort(populationT, (size_t)populationSize, sizeof(int*), fenotypeComparator);
}
void genetic::swap(int from, int to, int *anyTasksArray)
{
	int temp = anyTasksArray[to];
	anyTasksArray[to] = anyTasksArray[from];
	anyTasksArray[from] = temp;
}

genetic::genetic()
{
}


genetic::~genetic()
{
}

////////////////// IMPLEMENTACJA LICZNIKA ///////////////////////
void genetic::StartCounter()
{
	CounterStart = 0;
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double genetic::SaveCountersTable(string SaveFileName)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	fstream plik(SaveFileName, ios::app);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	double time = double(li.QuadPart - CounterStart) / PCFreq;
	plik << time << "\t" << populationSize << "\t" << generationsAmt << "\t" << bestGenotypeTWT << "\n";
	plik.flush();

	plik.close();
	return time / 1000;
}
//////////// KONIEC IMPLEMENTACJI LICZNIKA ////////////////////////

void genetic::ResetMemory()
{
	for (int i = 0; i < populationSize; i++)
		delete[] populationT[i];
	delete[] populationT;
}

void genetic::PrintTasksT()
{
	for (int i = 0; i < tasksAmt; i++) {
		cout << i + 1 << ".";
		tasksT[i].print();
	}
}

void genetic::ImportData(string fileName, int wtXX, int cnt)
{
	delete[]timeT;
	delete[]weightT;
	delete[]dateT;
	delete[]tasksT;
	//delete[] selectionPopulationT;
	delete[] bestGenotype;
	
	//	delete[]populationT;
		//		delete[] bestGenotypeT;
	bestGenotypeTWT = -1;
	tasksAmt = 0;
	timeT = new int[wtXX];
	weightT = new int[wtXX];
	dateT = new int[wtXX];
	tasksT = new tasks[wtXX];

	ifstream plik;
	plik.open(fileName.c_str());
	if (!plik.good()) cout << "Blad otwarcia pliku." << endl;

	else if (plik.good())
	{//6 dla wt40, 15 dla wt100
		for (int i = 0; i < 6 * cnt; i++) {
			//plik.ignore(10000, '\n');
			plik.ignore(400, '\n');
		}

		for (int g = 0; g < wtXX; g++) {
			plik >> timeT[g];
		}
		for (int g = 0; g < wtXX; g++) {
			plik >> weightT[g];
		}
		for (int g = 0; g < wtXX; g++) {
			plik >> dateT[g];
		}
		for (int g = 0; g < wtXX; g++) {
			tasksT[g].add(timeT[g], weightT[g], dateT[g]);
			tasksAmt++;
		}
		plik.close();
	}

}