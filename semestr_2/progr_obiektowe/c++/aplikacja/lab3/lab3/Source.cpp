#include "Header.h"
#include <iostream>
#include <string>

#define M_PI 3.14159265358979323846

using namespace std;

Figura::Figura()
{
	 licznik = 1;
	ilosc++; cout << "---------------------Konstruktor obiektu nr " << ilosc << endl; //tekst dla testu
	pole = licznik*licznik;
	obwod = 4 * licznik;
	tablica = new double[licznik];
	for (unsigned int i = 0; i < licznik; i++)
		tablica[i] = 1;


}

Figura::Figura(double r)
{
	pole = M_PI*r*r;
	obwod = 2 * M_PI*r;
	licznik = 1;
	tablica = new double[licznik];
	tablica[licznik] = r;
	ilosc++;
	cout << "---------------------Konstruktor obiektu nr " << ilosc << endl; //tekst dla testu
																			 //cout<<pole<<endl<<obwod<<endl; //tekst dla testu
}
Figura::~Figura()
{
	cout << "---------------------Destruktor obiektu nr " << ilosc << endl; //tekst dla testu
																			//delete[] tablica;
	ilosc--;
}
Figura Figura::operator+(const Figura &tab)const
{
	Figura fig;
	fig.licznik = licznik > fig.licznik ? licznik : fig.licznik;
	fig.tablica = new(nothrow) double[fig.licznik];
	if (fig.tablica)
	{
		unsigned int i;
		for (i = 0; i < licznik; i++)	fig.tablica[i] = tablica[i];
		for (; i < fig.licznik; i++)	fig.tablica[i] = 0;
		for (i = 0; i < tab.licznik; i++) fig.tablica[i] += tab.tablica[i];
	}
	else fig.licznik = 0;

	return fig;
}
Figura Figura::operator-(const Figura &tab)const
{
	Figura fig;
	fig.licznik = licznik > fig.licznik ? licznik : fig.licznik;
	fig.tablica = new(nothrow) double[fig.licznik];
	if (fig.tablica)
	{
		unsigned int i;
		for (i = 0; i < licznik; i++)	fig.tablica[i] = tablica[i];
		for (; i < fig.licznik; i++)	fig.tablica[i] = 0;
		for (i = 0; i < tab.licznik; i++) fig.tablica[i] -= tab.tablica[i];
		if (tab.tablica[i] < 0) tab.tablica[i] = -1 * tab.tablica[i];
	}
	else fig.licznik = 0;
	return fig;
}

void Figura::boki(int a)
{

	licznik = a;
	tablica = new double[licznik];

}
void Figura::setBoki()
{
	obwod = 0;

	for (unsigned int i = 0; i < licznik; i++)
	{
		cout << "Podaj " << i + 1 << ". bok: ";
		cin >> tablica[i];
		obwod = obwod + tablica[i];
	}
	cout << "Obwod wynosi: " << obwod << endl;
	if (licznik == 3)
	{
		if (tablica[0] + tablica[1]>tablica[2] && tablica[1] + tablica[2] > tablica[0] && tablica[0] + tablica[2] > tablica[0])
		{
			cout << "pole trojkata wynosi: ";
			pole = sqrt((0.5 * obwod)*(0.5 * obwod - tablica[0])*(0.5 * obwod - tablica[1])*(0.5 * obwod - tablica[2]));
			cout << pole << endl;
		}
		else cout << "Boki nie spelniaja warunkow." << endl;
	}
}
void Figura::getBoki()
{
	for (unsigned int i = 0; i < licznik; i++)
	{
		cout << i + 1 << ". bok: " << tablica[i];
		cout << endl;
	}
}


unsigned int Figura::ilosc = 0;

int main()
{
	int n;
	Figura* tablica = new Figura[4];
	for (int i = 0; i < 3; i++)
	{
		cout << "Podaj ilosc bokow: ";
		cin >> n;
		tablica[i].boki(n);
		tablica[i].setBoki();
	}
	tablica[3] = tablica[0] + tablica[1] + tablica[2];
	
	
	delete tablica;
	/*
	Figura figura2;


	cout << "Podaj ilosc bokow: ";
	cin >> n;
	Figura fig;
	fig.boki(n);
	fig.setBoki();
	fig.getBoki();
	fig.~Figura();

	cout << "Podaj promien kola: ";
	cin >> k;
	Figura figura3(k);

	figura3.~Figura();
	figura2.~Figura();

	Figura* figura4 = new Figura;
	delete figura4;
	*/
	system("Pause");
	return(0);
}