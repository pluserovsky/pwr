#include <iostream>
using namespace std;

class Figura
{
	private:
		double pole, obwod;
		
		double * tablica = new double[licznik];
	public:
		int licznik;
		Figura();
		void setBoki();
		void getBoki();
		~Figura();
};
Figura::Figura()
{

	cout << "Podaj ilosc bokow: ";
	cin >> licznik;

}
void Figura::setBoki()
{
	for (int i = 0; i < licznik; i++)
	{
		cout << "Podaj " << i << ". bok: ";
		cin >> tablica[i];
		obwod = obwod + tablica[i];
		cout << endl;
	}
	if (licznik == 3)
	{
		if (tablica[0] + tablica[1]>tablica[2] && tablica[1] + tablica[2] > tablica[0] && tablica[0] + tablica[2] > tablica[0])
		{
			
			//pole = (1 / 2 * obwod)(1 / 2 * obwod - tablica[0])(1 / 2 * obwod - tablica[1])(1 / 2 * obwod - tablica[2]);

		}
	}
}
void Figura::getBoki()
{
	for (int i = 0; i < licznik; i++)
	{
		cout << i << ". bok: "<< tablica[i];
		cout << endl;
	}
}

Figura::~Figura()
{
	delete[]tablica;
}
int main()
{
	Figura t;
	t.setBoki;
	t.getBoki;
	return(0);
}


