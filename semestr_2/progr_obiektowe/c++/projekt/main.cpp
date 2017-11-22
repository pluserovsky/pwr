// projekt.cpp : Defines the entry point for the console application.

#include "klasy.h"

#include "klasy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector <stacjonarny*> tabS;
vector <notebook*> tabN;
vector <systemOperacyjny*> tabSO;
vector <pakietBiurowy*> tabPB;
vector <antywirus*> tabAW;
vector <akcesoria*> tabA;

void autor()
{
	system("cls");
	ifstream story("about.txt", ios::in);
	char znak;
	while (!story.eof())
	{
		story.get(znak);
		cout << znak;
	}
	story.close();
	cin.ignore(2);
}
void koniec()
{
	int menu;
	system("cls");
	cout << "-----------INWENTARZ SPRZETOWY: WYJSCIE------------" << endl;
	cout << "1. Potwierdz wyjscie\n0. Anuluj\n";
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
	{
		exit(0);
		break;
	}
	case 0:
	{
		menuGlowne();
		break;
	}
	default:
		"Wprowadz numer jeszcze raz.";
	}
}
void systemWprowadzania()
{
	int menu;
	system("cls");
	cout << "-----------SYSTEM WPROWADZANIA------------" << endl;
	cout << "1. Dodaj przedmiot\n2. Wyswietl liste \n0. Zakoncz\n";

	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
	{
		dodajPrzedmiot();
		break;
	}
	case 2:
	{
		wyswietlListe();
		menuGlowne();
		break;
	}
	case 0:
		koniec();
	default:
		"Wprowadz numer jeszcze raz.";
	}

}
void menuGlowne()
{
	int menu;
	system("cls");
	cout << "-----------INWENTARZ SPRZETOWY------------" << endl;
	cout << " 1. System wprowadzania\n 2. Pomoc\n 0. Zakoncz\n";

	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
	{
		systemWprowadzania();
		break;
	}
	case 2:
	{
		autor();
		menuGlowne();
		break;
	}
	case 0:
		koniec();
	default:
		"Wprowadz numer jeszcze raz.";
	}

}
void wyswietlListe()
{
	int menu;
	system("cls");
	cout << "---LISTY INWENTARZA---\n";
	cout << "Wybierz typ:\n";
	cout << " 1. Komputery stacjonarne\n 2. Notebooki\n";
	cout << " 3. Systemy operacyjne\n 4. Pakiety biurowe\n 5. Antywirusy\n";
	cout << " 6. Akcesoria\n 7. Wyswietl wszystko\n 8. Wedlug pomieszczen\n 9. Porownaj \n 0. Wyjscie\n";
	cin >> menu;
	switch (menu)
	{
	case 1:
	{
		system("cls");
		int i = 1;
		for (vector <stacjonarny*>::iterator nX = tabS.begin(); nX != tabS.end(); nX++)
		{
			cout << "---KOMPUTER NR [" << i << "]---\n";
			(*nX)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		getchar();
		wyswietlListe();

		break;
	}
	case 2:
	{

		system("cls");
		int i = 1;
		for (vector <notebook*>::iterator nN = tabN.begin(); nN != tabN.end(); nN++)
		{
			cout << "---NOTEBOOK NR [" << i << "]---\n";
			(*nN)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		getchar();
		wyswietlListe();
		break;
	}
	case 3:
	{
		system("cls");
		int i = 1;
		for (vector <systemOperacyjny*>::iterator nSO = tabSO.begin(); nSO != tabSO.end(); nSO++)
		{
			cout << "---SYSTEM OPERACYJNY NR [" << i << "]---\n";
			(*nSO)->getInwentarz();
			i++;
			cout << endl;
			getchar();

		}
		getchar();
		wyswietlListe();
		break;
	}
	case 4:
	{
		system("cls");
		int i = 1;
		for (vector <pakietBiurowy*>::iterator nPB = tabPB.begin(); nPB != tabPB.end(); nPB++)
		{
			cout << "---PAKIET BIUROWY NR [" << i << "]---\n";
			(*nPB)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		getchar();
		wyswietlListe();
		break;
	}
	case 5:
	{
		system("cls");
		int i = 1;
		for (vector <antywirus*>::iterator nAW = tabAW.begin(); nAW != tabAW.end(); nAW++)
		{
			cout << "---ANTYWIRUS NR [" << i << "]---\n";
			(*nAW)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		getchar();
		wyswietlListe();
		break;
	}
	case 6:
	{
		system("cls");
		int i = 1;
		for (vector <akcesoria*>::iterator nA = tabA.begin(); nA != tabA.end(); nA++)
		{
			cout << "---AKCESORIUM NR [" << i << "]---\n";
			(*nA)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		getchar();
		wyswietlListe();
		break;
	}
	case 7:
	{
		int i = 1;
		for (vector <stacjonarny*>::iterator nX = tabS.begin(); nX != tabS.end(); nX++)
		{
			cout << "---KOMPUTER NR [" << i << "]---\n";
			(*nX)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		i = 1;
		for (vector <notebook*>::iterator nN = tabN.begin(); nN != tabN.end(); nN++)
		{
			cout << "---NOTEBOOK NR [" << i << "]---\n";
			(*nN)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		i = 1;
		for (vector <systemOperacyjny*>::iterator nSO = tabSO.begin(); nSO != tabSO.end(); nSO++)
		{
			cout << "---SYSTEM OPERACYJNY NR [" << i << "]---\n";
			(*nSO)->getInwentarz();
			i++;
			cout << endl;
			getchar();

		}
		i = 1;
		for (vector <pakietBiurowy*>::iterator nPB = tabPB.begin(); nPB != tabPB.end(); nPB++)
		{
			cout << "---PAKIET BIUROWY NR [" << i << "]---\n";
			(*nPB)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		i = 1;
		for (vector <antywirus*>::iterator nAW = tabAW.begin(); nAW != tabAW.end(); nAW++)
		{
			cout << "---ANTYWIRUS NR [" << i << "]---\n";
			(*nAW)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		i = 1;
		for (vector <akcesoria*>::iterator nA = tabA.begin(); nA != tabA.end(); nA++)
		{
			cout << "---AKCESORIUM NR [" << i << "]---\n";
			(*nA)->getInwentarz();
			i++;
			cout << endl;
			getchar();
		}
		cout << "\nZakonczono wyswietlanie list."<<endl;
		getchar();
		wyswietlListe();
		break;
	}
	case 8:
	{
		int i;
		system("cls");
		cout << "Numer pomieszczenia: ";
		cin >> i;
		for (vector <stacjonarny*>::iterator nX = tabS.begin(); nX != tabS.end(); nX++)
		{
			if ((*nX)->getNr() == i)
			{
				cout << "---KOMPUTER W POMIESZCZENIU NR [" << i << "]---\n";
				(*nX)->getInwentarz();
				cout << endl;
				getchar();
			}
		}
		for (vector <notebook*>::iterator nN = tabN.begin(); nN != tabN.end(); nN++)
		{
			if ((*nN)->getNr() == i)
			{
				cout << "---NOTEBOOK W POMIESZCZENIU NR [" << i << "]---\n";
				(*nN)->getInwentarz();
				cout << endl;
				getchar();
			}
		}
		for (vector <systemOperacyjny*>::iterator nSO = tabSO.begin(); nSO != tabSO.end(); nSO++)
		{
			if ((*nSO)->getNr() == i)
			{
				cout << "---SYSTEM OPERACYJNY W POMIESZCZENIU NR [" << i << "]---\n";
				(*nSO)->getInwentarz();
				cout << endl;
				getchar();
			}

		}
		for (vector <pakietBiurowy*>::iterator nPB = tabPB.begin(); nPB != tabPB.end(); nPB++)
		{
			if ((*nPB)->getNr() == i)
			{
				cout << "---PAKIET BIUROWY W POMIESZCZENIU NR [" << i << "]---\n";
				(*nPB)->getInwentarz();
				cout << endl;
				getchar();
			}
		}
		for (vector <antywirus*>::iterator nAW = tabAW.begin(); nAW != tabAW.end(); nAW++)
		{
			if ((*nAW)->getNr() == i)
			{
				cout << "---ANTYWIRUS W POMIESZCZENIU NR [" << i << "]---\n";
				(*nAW)->getInwentarz();
				cout << endl;
				getchar();
			}
		}
		for (vector <akcesoria*>::iterator nA = tabA.begin(); nA != tabA.end(); nA++)
		{
			if ((*nA)->getNr() == i)
			{
				cout << "---AKCESORIUM W POMIESZCZENIU NR [" << i << "]---\n";
				(*nA)->getInwentarz();
				cout << endl;
				getchar();
			}
		}
		cout << "\nZakonczono wyswietlanie list." << endl;
		getchar();
		wyswietlListe();
		break;
	}
	case 9:
	{
		porownaj();
		break;
	}
	case 0:
	{
		systemWprowadzania();
	}
	default:
	{
		"Niepoprawny typ - wprowadz numer jeszcze raz.";
		wyswietlListe();
	}
	}
}
void dodajKomputer()
{

	int typ;
	system("cls");
	cout << "-----------DODAJ PRZEDMIOT: KOMPUTER------------" << endl;
	cout << "Wybierz typ:\n 1. Stacjonarny\n 2. Notebook\n 0. Anuluj\n";
	
	cin >> typ;
	if (typ == 1)
	{
		stacjonarny obiekt = stacjonarny();
		tabS.push_back(&obiekt);
		(&obiekt)->setInwentarz();
		cout << "\nWprowadzono dane, nacisnij dowolny przycisk, aby przejsc dalej.\n";
		getchar();
		getchar();
		dodajPrzedmiot();
		
	}
	else if (typ == 2)
	{
		notebook obiekt = notebook();
		tabN.push_back(&obiekt);
		(&obiekt)->setInwentarz();
		cout << "\nWprowadzono dane, nacisnij dowolny przycisk, aby przejsc dalej.\n";
		getchar();
		getchar();
		dodajPrzedmiot();

	}
	else if (typ == 0) dodajPrzedmiot();
	else {
		cout << "\nWprowadzono niepoprawny typ. Sprobuj ponownie!" << endl;
		dodajKomputer();
	}
}
void dodajLicencje()
{
	int typ;
	system("cls");
	cout << "-----------DODAJ PRZEDMIOT: LICENCJA------------" << endl;
	cout << "Wybierz typ:\n 1. System operacyjny\n 2. Pakiet biurowy\n 3. Antywirus\n 0. Anuluj\n";
	cin >> typ;
	if (typ == 1)
	{
		systemOperacyjny obiekt = systemOperacyjny();
		tabSO.push_back(&obiekt);
		(&obiekt)->setInwentarz();
		cout << "\nWprowadzono dane, nacisnij dowolny przycisk, aby przejsc dalej.\n";
		getchar();
		getchar();
		dodajPrzedmiot();
	}
	else if (typ == 2)
	{
		pakietBiurowy obiekt = pakietBiurowy();
		tabPB.push_back(&obiekt);
		(&obiekt)->setInwentarz();
		cout << "\nWprowadzono dane, nacisnij dowolny przycisk, aby przejsc dalej.\n";
		getchar();
		getchar();
		dodajPrzedmiot();
	}
	else if (typ == 3)
	{
		antywirus obiekt = antywirus();
		tabAW.push_back(&obiekt);
		(&obiekt)->setInwentarz();
		cout << "\nWprowadzono dane, nacisnij dowolny przycisk, aby przejsc dalej.\n";
		getchar();
		getchar();
		dodajPrzedmiot();
	}
	else if (typ == 0) dodajPrzedmiot();
	else {
		cout << "\nWprowadzono niepoprawny typ. Sprobuj ponownie!" << endl;
		dodajKomputer();
	}
}
void dodajAkcesorium()
{
	int typ;
	system("cls");
	cout << "-----------DODAJ PRZEDMIOT: AKCESORIUM------------" << endl;
	cout << "Wybierz typ:\n 1. Dodaj\n 0. Anuluj\n";
	cin >> typ;
	if (typ == 1)
	{
		akcesoria obiekt = akcesoria();
		tabA.push_back(&obiekt);
		(&obiekt)->setInwentarz();
		cout << "\nWprowadzono dane, nacisnij dowolny przycisk, aby przejsc dalej.\n";
		getchar();
		getchar();
		dodajPrzedmiot();
		
	}
	else if (typ == 0) dodajPrzedmiot();
	else {
		cout << "\nWprowadzono niepoprawny typ. Sprobuj ponownie!" << endl;
		dodajKomputer();
	}
}
void dodajPrzedmiot()
{
	int menu;
	system("cls");
	cout << "-----------DODAJ PRZEDMIOT------------" << endl;
	cout << "Wybierz typ:\n 1. Komputer\n 2. Licencje \n 3. Akcesorium\n 0. Zakoncz\n";

	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
	{
		dodajKomputer();
		break;
	}
	case 2:
	{
		dodajLicencje();
		break;
	}
	case 3:
	{
		dodajAkcesorium();
		break;
	}
	case 0:
		systemWprowadzania();
	default:
		"\nWprowadzono niepoprawny typ. Sprobuj ponownie!";
	}
}
void porownaj()
{
	int x;
	system("cls");
	cout << "---POROWNAJ---\n";
	cout << "Wybierz typ:\n";
	cout << " 1. Komputery stacjonarne\n 2. Notebooki\n";
	cout << " 3. Systemy operacyjne\n 4. Pakiety biurowe\n 5. Antywirusy\n";
	cout << " 6. Akcesoria\n 0. Wyjscie\n";
	cin >> x;
	system("cls");
	switch (x)
	{
	case 1:
	{
		stacjonarny A, B;
		A.setInwentarz();
		cout << "\nWprowadz drugi przedmiot tego samego typu:" << endl;
		B.setInwentarz();
		if (A < B) cout << "\nJest wiecej komputerow stacjonarnych drugiego typu.\n";
		else if(A>B) cout << "\nJest wiecej komputerow stacjonarnych pierwszego typu.\n";
		else cout << "\nJest tyle samo przedmiotow pierwszego i drugiego typu.\n";
		getchar();
		getchar();
		break;
	}
	case 2:
	{
		notebook A, B;
		A.setInwentarz();
		cout << "\nWprowadz drugi przedmiot tego samego typu:" << endl;
		B.setInwentarz();
		if (A < B) cout << "\nJest wiecej notebookow drugiego typu.\n";
		else if(A>B) cout << "\nJest wiecej notebookow pierwszego typu.\n";
		else cout << "\nJest tyle samo przedmiotow pierwszego i drugiego typu.\n";
		getchar();
		getchar();
		break;
	}
	case 3:
	{
		systemOperacyjny A, B;
		A.setInwentarz();
		cout << "\nWprowadz drugi przedmiot tego samego typu:" << endl;
		B.setInwentarz();
		if (A < B) cout << "\nJest wiecej systemow operacyjnych drugiego typu.\n";
		else if (A>B) cout << "\nJest wiecej systemow operacyjnych pierwszego typu.\n";
		else cout << "\nJest tyle samo przedmiotow pierwszego i drugiego typu.\n";
		getchar();
		getchar();
		break;
	}
	case 4:
	{
		pakietBiurowy A, B;
		A.setInwentarz();
		cout << "\nWprowadz drugi przedmiot tego samego typu:" << endl;
		B.setInwentarz();
		if (A < B) cout << "\nJest wiecej pakietow biurowych drugiego typu.\n";
		else if (A>B) cout << "\nJest wiecej pakietow biurowych pierwszego typu.\n";
		else cout << "\nJest tyle samo przedmiotow pierwszego i drugiego typu.\n";
		getchar();
		getchar();
		break;
	}
	case 5:
	{
		antywirus A, B;
		A.setInwentarz();
		cout << "\nWprowadz drugi przedmiot tego samego typu:" << endl;
		B.setInwentarz();
		if (A < B) cout << "\nJest wiecej antywirusow drugiego typu.\n";
		else if (A>B) cout << "\nJest wiecej antywirusow pierwszego typu.\n";
		else cout << "\nJest tyle samo przedmiotow pierwszego i drugiego typu.\n";
		getchar();
		getchar();
		break;
	}
	case 6:
	{
		akcesoria A, B;
		A.setInwentarz();
		cout << "\nWprowadz drugi przedmiot tego samego typu:" << endl;
		B.setInwentarz();
		if (A < B) cout << "\nJest wiecej akcesoriow drugiego typu.\n";
		else if (A>B) cout << "\nJest wiecej akcesoriow pierwszego typu.\n";
		else cout << "\nJest tyle samo przedmiotow pierwszego i drugiego typu.\n";
		getchar();
		getchar();
		break;
	}
	case 0:
	{
		wyswietlListe();
		break;
	}
	}
}
int main()
{
	menuGlowne();
	return 0;
}

