#include "Towns.h"


/*Metoda znajduj¹ca rekurencyjnie wszystkie permutacje zbioru num_elements elementów*/
void Towns::liczPermutacje(int k, int * Perm, int ilosc_miast, int ** Wartosci, int * aktualnie_min, int * Wynik)
{
	/*Jeœli k == 0 to znaczy, ¿e znaleŸliœmy permutacjê zbioru*/
	if (k == 0) 
	{
		int curr_val = 0;

		for (int i = 0; i < ilosc_miast; i++)
			if (i < ilosc_miast - 1)
				curr_val += Wartosci[Perm[i]][Perm[i + 1]];

		if (curr_val < *aktualnie_min)
		{
			*aktualnie_min = curr_val;
			for (int i = 0; i < ilosc_miast; i++)
				Wynik[i] = Perm[i];
		}
	}
	else
	{
		/*Szukamy permutacji zaczynaj¹cych siê na i do k*/
		for (int i = 0; i <= k; i++)
		{
			/*Wrzucamy i na koniec, aby szukaæ permutacji zbioru, nie zawieraj¹cego i*/
			swap(Perm + i, Perm + k);

			liczPermutacje(k - 1, Perm, ilosc_miast, Wartosci, aktualnie_min, Wynik);

			/*Wracamy do stanu pocz¹tkowego*/
			swap(Perm + i, Perm + k);
		}
	}
}

Towns::Towns()
{
	macierz = nullptr;
	liczba_miast = 0;
}

Towns::~Towns()
{
	if (macierz != nullptr)
	{
		for (int i = 0; i < liczba_miast; i++)
		{
			if (macierz[i] != nullptr)
				delete[] macierz[i];
		}

		delete[] macierz;
	}
}

void Towns::loadTownsMap(std::string fileName)
{
	/* Sprawdzam, czy w nazwie pliku brakuje rozszerzenia ".txt", jeœli tak to je dodajê.*/
	if (fileName[fileName.length() - 1] != *"t" ||
		fileName[fileName.length() - 2] != *"x" ||
		fileName[fileName.length() - 3] != *"t" ||
		fileName[fileName.length() - 4] != *".")
		fileName.append(".txt");

	/* Tworzê strumieñ do odczytu danych z pliku.
	Otwieram go w trybie "std::ios::in", czyli do odczytu.*/
	std::fstream input;
	input.open(fileName, std::ios::in);

	/* Sprawdzam, czy powiod³o siê otwarcie pliku.*/
	if (!input.good())
		throw FileNotFoundException("\nNie ma takiego pliku!");

	std::string inputLine;

	getline(input, inputLine);

	std::istringstream* iss;
	iss = new std::istringstream(inputLine);

	if (macierz != nullptr)
	{
		for (int i = 0; i < liczba_miast; i++)
		{
			if (macierz[i] != nullptr)
				delete[] macierz[i];
		}

		delete[] macierz;
	}

	/* Odczytanie linii danych zawieraj¹cej informacje
	o liczbie miast*/

	try {
		*iss >> this->liczba_miast; 
	}
	catch (std::exception ex) {
		std::cerr << "Blad podczas wczytywania danych z pliku:\n" << ex.what();
		return;
	}
	delete iss;

	

	/*Utworzenie nowej macierzy s¹siedztwa*/
	macierz = new int*[liczba_miast];

	for (int i = 0; i < liczba_miast; i++)
	{
		macierz[i] = new int[liczba_miast];

		getline(input, inputLine);

		iss = new std::istringstream(inputLine);

		/*Ka¿da linia zawiera informacje o odleg³oœciach z i-tego miasta
		do pozosta³ych miast */
		for (int k = 0; k < liczba_miast; k++)
		{
			
			try {
				*iss >> macierz[i][k];
			}
			catch (std::exception ex) {
				std::cerr << "Blad podczas wczytywania danych z pliku:\n" << ex.what();
				return;
			}
		}

		delete iss;
	}
	return;
}

void Towns::loadTownsMap(int ** neigbours_matrix, int towns_num)
{
	if (neigbours_matrix == nullptr)
		return;
	
	if (macierz != nullptr)
	{
		for (int i = 0; i < liczba_miast; i++)
		{
			if (macierz[i] != nullptr)
				delete[] macierz[i];
		}

		delete[] macierz;
	}

	liczba_miast = towns_num;
	macierz = new int*[liczba_miast];

	for (int i = 0; i < liczba_miast; i++)
	{
		macierz[i] = new int[towns_num];
		memcpy(macierz[i], neigbours_matrix[i], liczba_miast*sizeof(int));
	}
	
}

void Towns::saveToFile(std::string fileName)
{
	if (fileName[fileName.length() - 1] != *"t" ||
		fileName[fileName.length() - 2] != *"x" ||
		fileName[fileName.length() - 3] != *"t" ||
		fileName[fileName.length() - 4] != *".")
		fileName.append(".txt");
	std::fstream output;
	output.open(fileName, std::ios::app);

	output << *this;
	output.close();
	return;
}

int* Towns::greedy(int start)
{
	if (start < 0 || start >= liczba_miast)
		throw new IndexOutOfBoundsException("\nNie ma miasta o takim numerze!\n");

	/*Tablica odwiedzonych*/
	bool* visited = new bool[liczba_miast];
	/*Tablica na wynik*/
	int* result = new int[liczba_miast];
	
	for (int i = 0; i < liczba_miast; i++)
	{
		visited[i] = false;
		result[i] = -1;
	}
	

	visited[start] = true;
	result[0] = start;

	int currentTown = start;
	
	/*W co najwy¿ej N-1 krokach dostaniemy rozwi¹zanie*/
	for (int i = 1; i < liczba_miast; i++)
	{
		
		int shortest_dist = INT_MAX;
		int next_town = -1;
		

		for (int k = 0; k < liczba_miast; k++)
		{
			if (currentTown == k || visited[k] == true)
				continue;

			if (macierz[currentTown][k] < shortest_dist)
			{
				next_town = k;
				shortest_dist = macierz[currentTown][k];
			}
		}

		visited[next_town] = true;
		currentTown = next_town;
		result[i] = currentTown;
	}

	/*Sprawdzenie, czy wszystkie miasta odwiedzone*/
	for (int i = 0; i < liczba_miast; i++)
	{
		if (!visited[i])
			return nullptr;
	}
	int sum_dist = 0;
	for (int i = 0; i < liczba_miast - 1; i++)
		sum_dist += macierz[result[i]][result[i + 1]];
	int* buf = new int[liczba_miast];
	memcpy(buf, result, liczba_miast*sizeof(int));
	delete[] result;
	result = new int[liczba_miast + 2];
	result[0] = liczba_miast;
	result[1] = sum_dist;
	memcpy(result + 2, buf, liczba_miast*sizeof(int));
	delete[] buf;
	return result;
}

int * Towns::brute_force()
{
	if (liczba_miast > 19)
	{
		std::cout << "Zbyt wiele miast! (max 12)\n";
		return nullptr;
	}
	int* result = new int[liczba_miast];

	/*Tabela z indeksami do robienia permutacji*/
	int* permutations = new int[liczba_miast];

	for (int i = 0; i < liczba_miast; i++)
		permutations[i] = i;

	/*Bêdzie przechowywa³o informacje o aktualnie najlepszym wyniku*/
	int minValue = INT_MAX;

	liczPermutacje(liczba_miast - 1, permutations, liczba_miast, macierz, &minValue, result);

	int sum_dist = 0;
	for (int i = 0; i < liczba_miast - 1; i++)
		sum_dist += macierz[result[i]][result[i + 1]];
	int* buf = new int[liczba_miast];
	memcpy(buf, result, liczba_miast*sizeof(int));
	delete[] result;
	result = new int[liczba_miast + 2];
	result[0] = liczba_miast;
	result[1] = sum_dist;
	memcpy(result + 2, buf, liczba_miast*sizeof(int));
	delete[] buf;
	return result;
}


std::string Towns::toString()
{
	std::string text = "";
	std::ostringstream oss;

	if (macierz == nullptr)
	{
		text.append("\nMapa odleglosci miedzy miastami jest pusta!\n");
		return text;
	}

	text.append("\nLiczba miast : ");
	oss << liczba_miast << "\nMapa odleglosci miedzy miastami :\n";
	
	text.append(oss.str());
	oss.str(std::string());

	for (int i = 0; i < liczba_miast+1; i++)
	{

		for (int k = 0; k < liczba_miast + 1; k++)
		{
			if (k == 0 && i == 0)
			{
				oss.width(4);
				oss << "nr\\nr" << std::right;
				continue;
			}

			if (i == 0 && k > 0)
			{
				oss.width(4);
				oss << k - 1 << ":" << std::right;
				continue;
			}

			if (k == 0)
			{
				oss.width(4);
				oss << i-1 << ":" << std::right;
				continue;
			}

			oss.width(5);
			oss << macierz[i-1][k - 1] << std::right;

		}

		oss << std::endl;	
	}

	text.append(oss.str());
	return text;
}

std::ostream & operator<<(std::ostream & output, Towns & mapa)
{
	output << mapa.toString();
	return output;
}
