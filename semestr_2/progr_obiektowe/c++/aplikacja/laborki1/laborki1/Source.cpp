#include <iostream>
using namespace std;

void wartosc(int a)
{
	cout << "----Wartosc----" << endl;
	cout << "Wartosc: " << a << endl;
	cout << "Adres: " << (int)&a << endl;
	a++;
	cout << "Wartosc: " << a << endl;
	cout << "Adres: " << (int)&a << endl;
	
}
void wskaznik(int *a)
{
	cout << "----Wskaznik----" << endl;
	cout << "Wartosc: " << *a << endl;
	cout << "Adres: " << (int) &a << endl;
	++*a;
	cout << "Wartosc: " << *a << endl;
	cout << "Adres: " << (int)&a << endl;
}
void referencja(int &a)
{
	cout << "----Referencja----" << endl;
	cout << "Wartosc: " << a << endl;
	cout << "Adres: " << (int)&a << endl;
	a++;
	cout << "Wartosc: " << a << endl;
	cout << "Adres: " << (int)&a << endl;
}
int tablica(int rozmiar)
{
	int * tab = new int[rozmiar];
	int i = rozmiar;
	while (i >= 0)
	{
		tab[i] = i;
		i--;
	}
	while (rozmiar >= 0)
	{
		cout << tab[rozmiar] << endl;
		rozmiar--;
	}
	return *tab;
}
int mnozenie(int b)
{
	int ** tab2 = new int *[b];
	for (int i = 0; i <= b; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			tab2[i][j] = (i + 1)*(j + 1);
		}
	}
	return ** tab2;
}
int main()
{
	int rozmiar = 5;
	int a = 4, b = 3;
	
	wartosc(a);
	referencja(a);
	wskaznik(&a);
	tablica(rozmiar);
	
	system("pause");

	return 0;
}