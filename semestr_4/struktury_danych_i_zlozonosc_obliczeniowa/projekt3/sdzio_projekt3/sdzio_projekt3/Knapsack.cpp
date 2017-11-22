#include "Knapsack.h"
#include <iostream>

using namespace std;

//posortowanie elementow
void Knapsack::quickSort(Item * tab, int left, int right)
{
	if (left >= right)
		return;

	int m = partition(tab, left, right);
	quickSort(tab, left, m);
	quickSort(tab, m + 1, right);

	return;
}

int Knapsack::partition(Item * tab, int left, int right)
{
	Item pivot = tab[left];
	int l = left, r = right;
	while (true) 
	{
		
		while (tab[l].stosunek > pivot.stosunek) l++;
		while (tab[r].stosunek < pivot.stosunek) r--;

		if (l < r)
		{
			Item buf = tab[l];
			tab[l] = tab[r];
			tab[r] = buf;
			l++;
			r--;
		}
		else
		{
			if (r == right)
				r--;
			return r;
		}
	}
}

void Knapsack::packItem(Item _it)
{
	if (plecak == nullptr)
		plecak = new sackElement(_it);
	else
	{
		sackElement* ptr = plecak;

		while (ptr->next != nullptr)
			ptr = ptr->next;

		ptr->next = new sackElement(_it);
	}
	
	return;
}

Knapsack::Knapsack()
{
	Knapsack(0);
}

Knapsack::Knapsack(int _capacity)
{
	pojemnosc = _capacity;
	zapakowana_waga = 0;
	zapakowana_wartosc = 0;
	plecak = nullptr;
	przedmioty = nullptr;
}


Knapsack::~Knapsack()
{
	if (plecak != nullptr)
		delete plecak;
	if (przedmioty != nullptr)
		delete[] przedmioty;
}

void Knapsack::loadItemsSet(std::string fileName)
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

	/* Odczytanie linii danych zawieraj¹cej informacje
	o pojemnoœci plecaka i liczebnoœci zbioru przedmiotów do spakowania*/

	try {
		*iss >> this->pojemnosc; //wczytanie pojemnoœci plecaka
		*iss >> this->przedmioty_rozmiar; // oraz liczebnoœci zbioru
	}
	catch (std::exception ex) {
		std::cerr << "Blad podczas wczytywania danych z pliku:\n" << ex.what();
		return;
	}
	delete iss;

	if (plecak != nullptr) 
	{
		delete plecak;
		plecak = nullptr;
	}
		
	if (przedmioty != nullptr)
	{
		delete[] przedmioty;
		przedmioty = nullptr;
	}
		

	przedmioty = new Item[przedmioty_rozmiar];

	zapakowana_wartosc = 0;
	zapakowana_waga = 0;

	for (int i = 0; i < przedmioty_rozmiar; i++)
	{
		getline(input, inputLine);

		iss = new std::istringstream(inputLine);

		try {
			*iss >> przedmioty[i].waga;
			*iss >> przedmioty[i].wartosc;
		}
		catch (std::exception ex) {
			std::cerr << "Blad podczas wczytywania danych z pliku:\n" << ex.what();
			return;
		}

		przedmioty[i].stosunek = (double)przedmioty[i].wartosc / (double)przedmioty[i].waga;

		delete iss;
	}
	return;
}

void Knapsack::loadItemsSet(Item * items, unsigned int n)
{
	if (plecak != nullptr)
	{
		delete plecak;
		plecak = nullptr;
	}

	if (przedmioty != nullptr)
	{
		delete[] przedmioty;
		przedmioty = nullptr;
	}

	przedmioty_rozmiar = n;
	przedmioty = new Item[przedmioty_rozmiar];

	zapakowana_wartosc = 0;
	zapakowana_waga = 0;

	memcpy(przedmioty, items, przedmioty_rozmiar*sizeof(Item));

	return;
}

/*
Metoda realizuj¹ca algorytm zach³anny dla problemu plecakowego.
Wylicza wartoœæ jednostkow¹ dla ka¿dego elementu i wed³ug niej
ustawia je w kolejkê. Pakuje do plecaka kolejne elementy z kolejki,
dopóki plecak nie zostanie zape³niony.*/
bool Knapsack::greedy_pack()
{
	if (przedmioty == nullptr)
	{
		std::cout << "Blad! Najpierw musisz zaladowac dane elementow do zapakowania!";
		return false;
	}
	//sortowanie rzeczy
	quickSort(przedmioty, 0, przedmioty_rozmiar-1);
	for (int i = 0; i< przedmioty_rozmiar; i++) {
		cout << przedmioty[i].stosunek<<endl;
	}
	
	bool przedmioty_zapakowane = false;
	
	for (int i = 0; i < przedmioty_rozmiar; i++)
	{
		//jesli plecak jest zapelniony na 100%
		if (zapakowana_waga == pojemnosc)
			break;
		//jeœli jeszcze siê zmieœci
		if (przedmioty[i].waga <= pojemnosc - zapakowana_waga)
		{
			packItem(przedmioty[i]);
			zapakowana_waga += przedmioty[i].waga;
			zapakowana_wartosc += przedmioty[i].wartosc;
			przedmioty_zapakowane = true;
		}
	}
	return przedmioty_zapakowane;
}

bool Knapsack::brute_force_pack()
{
	if (przedmioty == nullptr)
	{
		std::cout << "Blad! Najpierw musisz zaladowac dane elementow do zapakowania!";
		return false;
	}

	unsigned long long int kombinacje = (1 << przedmioty_rozmiar);
	
	unsigned long long int aktualnieNaj = 0;
	int aktualnie_naj_wartosc = 0;
	int aktualnie_naj_waga = 0;
	
	bool cos_pasuje = false;
	

	for (unsigned long long int i  = 0; i < kombinacje; i++) {
	/*
	Iterujemy po wszystkich mo¿liwoœciach. Ka¿dy bit zmiennej
	permutations odpowiada jednemu elementowi zbioru przedmiotów.
	Jedynka oznacza, ¿e do³¹czamy dany przedmiot, zero, ¿e nie.
	*/
		int suma_wag = 0;
		int suma_wartosci = 0;
		
		bool pasuje = false;
		unsigned long long int aktualna_permutacja;
	
		for (int k = 0; k < przedmioty_rozmiar; k++)
		{

			aktualna_permutacja = i;
			//sprawdza czy doszed³ do 1
			if (((aktualna_permutacja >> k) & 1) != 1)
				continue;

			suma_wag += przedmioty[k].waga;
			suma_wartosci += przedmioty[k].wartosc;
			
			if (suma_wag > this->pojemnosc) 
			{
				pasuje = false;
				break;
			}

			pasuje = true;
		}
		
		/*Jeœli suma wag przedmiotów kombinacji wiêksza ni¿ pojemnoœæ plecaka to sprawdzamy kolejn¹*/
		if (!pasuje)
			continue;
		
		cos_pasuje = true;

		if (suma_wartosci > aktualnie_naj_wartosc)
		{
			aktualnie_naj_wartosc = suma_wartosci;
			aktualnie_naj_waga = suma_wag;
			aktualnieNaj = i;
		}
	}

	if (!cos_pasuje)
		return false;

	/*Przechodzimy po wszystkich przedmiotach, ¿eby sprawdziæ, czy nale¿¹ do danej kombinacji*/
	for (int k = 0; k < przedmioty_rozmiar; k++)
	{
		unsigned long long int aktualna_perm = aktualnieNaj;
		
		if (((aktualna_perm >> k) & 1) != 1)
			continue;

		/*Dodajemy przedmiot do rozwi¹zania*/

		this->packItem(przedmioty[k]);
		zapakowana_waga += przedmioty[k].waga;
		zapakowana_wartosc += przedmioty[k].wartosc;
	}
	
	return true;
}

void Knapsack::printItemsSet()
{
	if (przedmioty == nullptr)
		return;
	std::cout << "Zbior przedmiotow (waga,wartosc): {";
	for (int i = 0; i < przedmioty_rozmiar; i++)
	{
		std::cout << " (" << przedmioty[i].waga << ", " << przedmioty[i].wartosc << ") " << std::endl;
	}
	std::cout << "}\n";
	return;
}

std::string Knapsack::toString()
{
	std::string text = "";
	std::ostringstream oss;
	
	sackElement* ptr = plecak;
	if (ptr == nullptr)
	{
		text.append("\nPlecak jest pusty!");
		return text;
	}
	else {	
		
		text.append("\nPlecak (wartosc = ");
		
		oss << zapakowana_wartosc << ", wypelnienie " << zapakowana_waga << "/" << pojemnosc <<"):\n";
		text.append(oss.str());
		
		oss.str(std::string());


		while (ptr != nullptr)
		{
			oss << "{waga " << ptr->it.waga << ", wartosc " << ptr->it.wartosc << "}\n";
			text.append(oss.str());

			oss.str(std::string());

			ptr = ptr->next;
		}
	}

	return text;
}

void Knapsack::saveToFile(std::string fileName)
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


std::ostream & operator<<(std::ostream & output, Knapsack & knapsack)
{
	output << knapsack.toString();
	return output;
}
