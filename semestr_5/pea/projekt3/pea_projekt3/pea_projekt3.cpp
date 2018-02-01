// pea_projekt3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "genetic.h"
/*
Politechnika Wroclawska 2017
Wydzia³ Elektroniki, kierunek Informatyka
Projektowanie Efektywnych Algorytmów
Prowadz¹cy: dr Mariusz Makuchowski

Jednoprocesorowy problem szeregowania zadañ przy kryterium minimalizacji
wa¿onej sumy opóŸnieñ zadañ

Rozwi¹zanie problemu metod¹ programowania dynamicznego

Autor: £ukasz Broll
Nr Indeksu: 225972

*/
using namespace std;

int main() {
	genetic g;
	g.tasksAmt = 0;
		int cnt = 0,nr=0;
	char tn;
	srand(time(NULL));
	cout << "Politechnika Wroclawska 2017\nWydzial Elektroniki\nkierunek Informatyka\n" <<
		"Projektowanie Efektywnych Algorytmow\nProwadzacy: dr Mariusz Makuchowski\n"
		<< "=== Jednoprocesorowy problem szeregowania zadan przy kryterium \nminimalizacji wazonej sumy opoznien zadan ===\n\n" <<
		"== Rozwiazanie problemu metoda algorytmu genetycznego ==\n\n" <<
		"= Autor: Lukasz Broll 225972 =\n";
	do {
		cout << "\n1. Dodaj nowe zadanie\n" <<
			"2. Drukuj wszystkie zadania\n" <<
			"3. Wykonaj algorytm genetyczny\n" <<
			"4. Wczytaj przykladowe dane\n" <<
			"5. Importuj zadania z pliku\n" <<
			"6. Generuj losowe zadania\n" <<
			"7. Zresetuj pamiec\n" <<
			"8. Test wydajnosci\n" <<
			"9. O programie\n" <<
			"0. Zakoncz" << endl;

		short switch_on;
		cin >> switch_on;

		switch (switch_on)
		{
		case 1:
			int id, czas, waga, termin;
			system("cls");
			cout << "Podaj id zadania:" << endl;
			cin >> id;
			cout << "Podaj parametry zadania - czas:" << endl;
			cin >> czas;
			cout << "Podaj parametry zadania - waga:" << endl;
			cin >> waga;
			cout << "Podaj parametry zadania - termin:" << endl;
			cin >> termin;
			if (g.tasksT == NULL) g.tasksT = new tasks[50];
			g.tasksT[g.tasksAmt].add(czas, waga, termin);
			g.tasksAmt++;
			break;
		case 2:
			system("cls");
			for (int i = 0; i < g.tasksAmt; i++) {
				cout << i + 1 << ".";
				g.tasksT[i].print();
			}
			break;
		case 3:
			system("cls");
			g.GeneticSolve();

			break;
		case 4:
			system("cls");
			g.tasksAmt = 9;
			g.tasksT = new tasks[g.tasksAmt];
			g.tasksT[0].add(3, 2, 12);
			g.tasksT[1].add(5, 1, 6);
			g.tasksT[2].add(8, 3, 4);
			g.tasksT[3].add(2, 2, 2);
			g.tasksT[4].add(2, 3, 2);
			g.tasksT[5].add(2, 82, 14);
			g.tasksT[6].add(1, 12, 9);
			g.tasksT[7].add(2, 72, 32);
			g.tasksT[8].add(21, 22, 2);

			g.PrintTasksT();
			break;
		case 5:
			int wtXX;
			
			cout << "-- Format plikow zgodny z instrukcja (wtXX.txt)--" << endl;
			cout << "Nazwa pliku z danymi:";
			cin >> g.fileName;
			cout << "Rozmiar instancji (XX z nazwy pliku):";
			cin >> wtXX;
			cout << "Numer zestawu:";
			cin >> nr;
			g.ImportData(g.fileName, wtXX,nr);
			g.PrintTasksT();
			//system("cls");
			//g.GeneticSolve();
			break;
		case 6:
			cout << "Ilosc zadan:";
			cin >> g.tasksAmt;
			g.tasksT = new tasks[g.tasksAmt];
			for (int i = 0; i < g.tasksAmt; i++) {
				g.tasksT[i].add((std::rand() % 100) + 1, (std::rand() % 100) + 1, (std::rand() % 100) + 1);// liczby z przedzia³u 1-100
			}
			g.PrintTasksT();
			break;
		case 7:
			g.ResetMemory();
			break;
		case 8:
			cout << "-- Format plikow zgodny z instrukcja (wtXX.txt)--" << endl;
			//cout << "Nazwa pliku z danymi:";
			//cin >> g.fileName;
			g.fileName = "wt100.txt";
			cout << "Rozmiar instancji:";
			wtXX = stoi(g.fileName.substr(2, 3));
			cout << wtXX;
			cout << "\nNacisnij t, aby rozpoczac:";
			cin >> tn;
			if (tn == 't') {
				for (int i = 0; i < 10; i++) {
					g.ImportData(g.fileName, wtXX, cnt);
					//g.PrintTasksT();
					g.GeneticSolve();
					cout << i + 1 << ". " << g.bestGenotypeTWT << " w czasie:" << g.SaveCountersTable("bm100.txt") << endl;
					cnt++;
					//g.ResetMemory();
				}
			}
			break;
		case 9:
			system("cls");
			cout << "Politechnika Wroclawska 2017\nWydzial Elektroniki\nkierunek Informatyka\n" <<
				"Projektowanie Efektywnych Algorytmow\nProwadzacy: dr Mariusz Makuchowski\n"
				<< "=== Jednoprocesorowy problem szeregowania zadan  przy kryterium \nminimalizacji wazonej sumy opoznien zadan ===\n\n" <<
				"== Rozwiazanie problemu metoda algorytmu genetycznego ==\n\n" <<
				"= Autor: Lukasz Broll 225972 =";
			break;
		case 0:
			system("Pause");
			return 0;
		default:
			break;
		}

	} while (1);


}



