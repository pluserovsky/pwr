#include <string>
#include <ostream>

#define N 2

struct ksiazka
{
	int ilosc;
	std::string tytul, autor;
	ksiazka();
	void wczytaj_v2();
	void wypisz_v2();
};

std::ostream& operator<< (std::ostream&, ksiazka&);
void wczytaj_v2 (ksiazka*);