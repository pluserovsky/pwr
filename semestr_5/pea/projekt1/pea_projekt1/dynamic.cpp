#include "dynamic.h"

//----------------------------------------------------------
//Implementacja licznika
//----------------------------------------------------------

void dynamic::StartCounter()
{
	CounterStart = 0;
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double dynamic::SaveCountersTable(string SaveFileName)
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	fstream plik(SaveFileName, ios::app);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	double time = double(li.QuadPart - CounterStart) / PCFreq;
	plik << taskAmt << "\t" << time << "\n";
	plik.flush();

	plik.close();
	return time / 1000;
}

dynamic::dynamic()
{
}

dynamic::~dynamic()
{
}

void dynamic::ImportData(string fileName, int wtXX)
{
	timeT = new int[wtXX];
	weightT = new int[wtXX];
	dateT = new int[wtXX];
	tasksT = new tasks[wtXX];

	ifstream plik;
	plik.open(fileName.c_str());
	if (!plik.good()) cout << "Blad otwarcia pliku." << endl;

	else if (plik.good())
	{
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
			taskAmt++;
		}
		plik.close();
	}

}
void dynamic::DynamicSolve() {

	//inicjalizacje tabel i zmiennych
	long long int permAmt = pow(2, taskAmt); // liczba mozliwych permutacji zadan
	int cmax = 0, // max czas wykonywania zadan
		taskIdx = 0;	// indeks zadania w permutacji
	
	// wy�apanie wyj�tku, je�li tablic nie da si� zaalokowa�
	try {
		permTab = new bool[taskAmt];
		subScoresT = new int[taskAmt];
		ScoreOrderT = new int[taskAmt];
		ScoresT = new int[permAmt];
		OrdersT = new int[permAmt];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr << "Wyjatek bad_alloc: " << ba.what() << " - prawdopodobnie za duza ilosc zadan." << '\n';
		return;
	}

	StartCounter();
	//p�tla iteruj�ca po wszystkich permutacjach zada�
	for (long long int i = 0; i < pow(2, taskAmt); i++) {
		taskIdx = 0;
		cmax = 0;
		bufor = i;
		//p�tla zamieniaj�ca dziesi�tny zapis permutacji do bitowej tablicy
		// 1 - zadanie wykonuje sie, 0 - nie wykonuje sie
		// jednoczesne obliczanie max czasu potrzebnego na wykonanie wszystkich zadan
		while (taskIdx < taskAmt) {
			if (bufor % 2 == 1) {
				permTab[taskIdx] = 1;
				cmax = cmax + tasksT[taskIdx].getTime();
			}
			else if (bufor % 2 == 0) permTab[taskIdx] = 0;

			taskIdx++;
			bufor /= 2;

		}
		taskIdx = 0;
		// p�tla iteruj�ca po obliczonej przed chwil� permutacji
		// wykonuje w�a�ciwy algorytm dynamiczny
		while (taskIdx < taskAmt) {
			//bufor = indeks tablicy wynikow bez zadania ktore ma byc policzone w iteracji
			bufor = i - pow(2, taskIdx);
			//je�li zadanie ma by� wykonane
			if (permTab[taskIdx] == 1) {
				// obliczenie kosztu wykonania zadania
				opt = tasksT[taskIdx].getWeight()*tasksT[taskIdx].getTime();
				//je�li koszt zadania i suma koszt�w reszty zadan jest mniejsza ni� max termin, to koszt op�nienia = 0
				if (opt + ScoresT[bufor] <= cmax) opt = 0;
				else {
					//je�li aktualne zadanie mie�ci si� w terminie, ale koszt op�nienia istnieje,
					//to znaczy, �e op�niona jest suma innych zada�
					if (cmax - (tasksT[taskIdx].getDate()) < 0) opt = ScoresT[bufor];
					else
						// je�li koszt op�nienia wynika r�wnie� z op�nienia liczonego zadania, to znaczy �e 
						//nale�y zsumowa� koszt innych zada� z kosztem zadania wykonywanego w tej iteracji
						opt = (cmax - tasksT[taskIdx].getDate() + ScoresT[bufor])*tasksT[taskIdx].getWeight();
				}
				//zapisanie wyniku dla akltualnie policzonego zadania
				subScoresT[taskIdx] = opt;
				//zapisanie indeksu zadania, kt�re zosta�o w�a�nie policzone
				OrdersT[i] = taskIdx;
			}
			else {
				//zapisanie -1 w tablicy sub-wynik�w, �eby algorytm liczacy najlepszy wynik 
				//nie bra� tej iteracji pod uwag�, skoro zadanie nie jest wykonywane
				subScoresT[taskIdx] = -1;

			}
			//cout << "permTab[" << i << "]:" << permTab[taskIdx] << " subScoresT:" << subScoresT[taskIdx] << " cmax:" << cmax << " sprWyniki[" << taskIdx << "]:" << ScoresT[bufor] << endl;
			taskIdx++;
		}
		//sprawdzenie najmniejszego kosztu permutacji i przepisanie go do tablicy najlepszych wynikow
		ScoresT[i] = MinScore(i);
		//cout << i + 1 << ". " << ScoresT[i] << " Wykonane zadanie:" << OrdersT[i] << endl;
	}
	cout << "Wynik:" << ScoresT[permAmt - 1] << endl;
	//liczenie kolejnosci zadan
	CountTasksOrder();
	//drukowanie kolejnosci zadan
	PrintTasksOrder();
	cout << "Zakonczono w czasie: " << SaveCountersTable("wyniki.dat") << " s." << endl;

}


int dynamic::MinScore(int idx) {

	//sprawdzenie, kt�re liczone zadanie w permutacji wygenerowa�o najmniejszy koszt
	// oraz zapisanie jego indeksu w sub-tablicy kolejnosci
	for (minScoreItr = 0; minScoreItr < taskAmt; minScoreItr++) {
		if (subScoresT[minScoreItr] > -1 && subScoresT[minScoreItr] < opt) {
			opt = subScoresT[minScoreItr];
			OrdersT[idx] = minScoreItr;
		}
	}

	return opt;
}

void dynamic::PrintTasksT()
{
	for (int i = 0; i < taskAmt; i++) {
		cout << i + 1 << ".";
		tasksT[i].print();
	}
}

void dynamic::CountTasksOrder()
{
	//liczenie od konca kolejnosci zadan z wykorzystaniem tablicy indeks�w zapisanych przy wynikach
	long long int nr = pow(2, taskAmt) - 1;
	for (int i = 0; i < taskAmt; i++) {
		ScoreOrderT[i] = OrdersT[nr] + 1;
		nr = nr - pow(2, OrdersT[nr]);
	}

}

void dynamic::PrintTasksOrder()
{
	cout << "Kolejnosc wykonywania zadan";
	for (int i = taskAmt - 1; i >= 0; i--) {
		cout << " - " << ScoreOrderT[i];
	}
	cout << endl;
}

void dynamic::ResetMemory()
{
	//system("cls");
	//cout << "Usuwanie zadan i wynikow z pamieci...";

	delete[]ScoresT;
	delete[]permTab;
	delete[]subScoresT;
	delete[]timeT;
	delete[]weightT;
	delete[]dateT;
	delete[]tasksT;
	taskAmt = 0;
	opt = 0;
	//cout << "zakonczono.\n" << endl;
}