#include "Heap.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>


bool Heap::loadFromFile(string FileName)
{
	ifstream plik;
	int size;
	plik.open(FileName.c_str());
	if (!plik.good()) return 0;

	else if (plik.good())
	{
		plik >> size;
		cnt = 0;
		delete []tab;
		tab = new int[size + 20];

		for (int i=0; i < size; i++)
		{
			plik >> tab[i];
			addValue(tab[i]);
		}
		plik.close();
	}
	return 1;
}

bool Heap::IsValueIn(int val)
{
	if (tab) {
		for (int i = 0; i < cnt; i++) {
			if (tab[i] == val) return true;

		}
	}
	else if (!tab) cout << "Kopiec jest pusty lub ";
	return false;

}
void Heap::addValue(int val)
{
	if(!tab) tab = new int[20];
	cnt++;
	tab[cnt - 1] = val;
	int newElemPoz = cnt - 1;  // indeks elementu
	int succ = (newElemPoz - 1) / 2;  // przodek elementu
	while ((tab[succ] < val) && (newElemPoz > 0))  // sprawdzamy czy nowy element jest niewiêkszy od swojego rodzica
	{
		//zamieniamy rodzica z synem az do spelnienia warunku
		tab[newElemPoz] = tab[succ];
		newElemPoz = succ;
		succ = (newElemPoz - 1) / 2;
	}
	tab[newElemPoz] = val;
}
void Heap::deleteValue(int val)
{
	{
		int i = 0;
		//iterowanie do szukanego elementu
		for (i; i < cnt; i++)
		{
			if (tab[i] == val)
				break;
		}
		//odlaczenie jesli to ostatni element
		if (i == cnt - 1)
		{
			cnt--;
			tab[cnt] = NULL;
		}
		//jesli nie jest na koncu
		if (i < cnt - 1)
		{
			// w miejsce usuwanego wstawia ostatni element
			tab[i] = tab[cnt - 1];
			//usuwa ostatni
			tab[cnt - 1] = NULL;
			cnt--;
			// procedura sprawdzania warunku kopca
			// jesli nowy element jest wiêkszy od przodka
			if (tab[i] > tab[(i - 1) / 2])
			{
				//dopóki element jest wiekszy od przodka
				while (i > 0 && tab[i] > tab[(i - 1) / 2])
				{
					if (tab[i] > tab[(i - 1) / 2])
					{
						//zamien miejscami przodka i element
						int zmienna = tab[(i - 1) / 2];
						tab[(i - 1) / 2] = tab[i];
						tab[i] = zmienna;
					}
					i = (i - 1) / 2;
				}
			}
			//jesli nowy element jest mniejszy od przodka
			else
			{
				//sprawdznie warunku w dó³
				while (i < cnt - 1 / 2)
				{
					//sprawdzanie czy nowy element jest mniejszy od lewego lub prawego syna
					if ((tab[i] < tab[2 * i + 1]) || (tab[i] < tab[2 * i + 2]))
					{
						//jesli lewy syn jest wiekszy od prawego , to trzeba go zamienic z ojcem
						//poniewaz ojciec musi byc 'pomiedzy' nimi
						if (tab[2 * i + 1] > tab[2 * i + 2])
						{
							int zmienna = tab[i];
							tab[i] = tab[2 * i + 1];
							tab[2 * i + 1] = zmienna;
							i = 2 * i + 1;
						}
						// to samo w drug¹ strone
						else
						{
							int zmienna = tab[i];
							tab[i] = tab[2 * i + 2];
							tab[2 * i + 2] = zmienna;
							i = 2 * i + 2;
						}
					}
					else break;
				}
			}
		}


	}

}
void Heap::display(string sp, string sn, int value)
{
	string s;
	string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	if (value < cnt)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		display(s + cp, cr, 2 * value + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << tab[value] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		display(s + cp, cl, 2 * value + 1);
	}

}
void Heap::display()
{
	if (cnt == NULL)
		cout << "Kopiec nie zawiera ¿adnych elementów" << endl;
	else
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << tab[i] << " ";  // wyœwietla kolejne elementy tablicy
		}
	}
	cout << endl;
	display("", "", 0);

}

void Heap::generate(int size)
{
	cnt = size;
	if (tab) delete[] tab;
	if (cnt <= 0) cout << "Z³y rozmiar!" << endl;
	else {
		tab = new int[cnt + 10];
		for (int i = 0; i < cnt; i++) {
			//tab[i] = (rand() % RAND_MAX) - RAND_MAX / 2;
			tab[i] = (rand() % 30) - 15 / 2;
			addValue(tab[i]);
		}
	}
}
void Heap::tests(int cnt, string FileName)
{
}
void Heap::setCnt(int cnt) {
	this->cnt = cnt;
}
int Heap::getCnt() {
	return cnt;
}


