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
	cout << "Adres: " << (int)&a << endl;
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
int* tablica(int r)
{
	int * tab2 = new int[r];
	int i = r - 1;
	for (i; i>-1; i--)
	{
		tab2[i] = i;
	}

	return tab2;
}
void mnozenie(int **&tab, int r)
{
	tab = new int*[r];

	for (int i = 0; i < r; i++)
		tab[i] = new int[r];

	for (int i = 0; i < r; i++)

		for (int j = 0; j < r; j++)
			tab[i][j] = (i + 1) * (j + 1);
}

void pokaz(int **tab, int r)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
			cout << "\t" << tab[i][j];
		cout << endl;
	}
}void niszcz(int **tab, int r)
{
	for (int i = 0; i < r; i++)
		delete[] tab[i];
	delete[] tab;
}
int main()
{
	int r = 5;
	int a = 4, b = 3;
	int **tab;


	wartosc(a);
	referencja(a);
	wskaznik(&a);

	int *tab2 = tablica(r);
	int i = r - 1;
	for (i; i>-1; i--)
	{
		cout << tab2[i] << endl;
	}
	mnozenie(tab, r);
	pokaz(tab, r);
	niszcz(tab, r);
	delete[] tab2;
	system("pause");
	return 0;
}