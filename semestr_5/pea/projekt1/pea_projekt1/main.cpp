#include "dynamic.h"
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
	dynamic d;
	d.taskAmt = 0;
	srand(time(NULL));
	cout << "Politechnika Wroclawska 2017\nWydzial Elektroniki\nkierunek Informatyka\n" <<
		"Projektowanie Efektywnych Algorytmow\nProwadzacy: dr Mariusz Makuchowski\n"
		<< "=== Jednoprocesorowy problem szeregowania zadan przy kryterium \nminimalizacji wazonej sumy opoznien zadan ===\n\n" <<
		"== Rozwiazanie problemu metoda programowania dynamicznego ==\n\n" <<
		"= Autor: Lukasz Broll 225972 =\n";
	do {
		cout << "\n1. Dodaj nowe zadanie\n" <<
			"2. Drukuj wszystkie zadania\n" <<
			"3. Wykonaj algorytm dynamiczny\n" <<
			"4. Wczytaj przykladowe dane\n" <<
			"5. Importuj zadania z pliku\n" <<
			"6. Generuj losowe zadania\n" <<
			"7. Zresetuj pamiec\n" <<
			"8. Test wydajnosci\n" <<
			"9. O programie\n"<<
			"0. Zakoncz" << endl;

		short switch_on;
		cin >> switch_on;

		switch (switch_on)
		{
		case 1:
			int czas, waga, termin;
			system("cls");
			cout << "Podaj parametry zadania - czas:" << endl;
			cin >> czas;
			cout << "Podaj parametry zadania - waga:" << endl;
			cin >> waga;
			cout << "Podaj parametry zadania - termin:" << endl;
			cin >> termin;
			if (d.tasksT == NULL) d.tasksT = new tasks[50];
			d.tasksT[d.taskAmt].add(czas, waga, termin);
			d.taskAmt++;
			break;
		case 2:
			system("cls");
			for (int i = 0; i < d.taskAmt; i++) {
				cout << i + 1 << ".";
				d.tasksT[i].print();
			}
			break;
		case 3:
			system("cls");
			d.DynamicSolve();
			break;
		case 4:
			system("cls");
			d.tasksT = new tasks[4];
			d.tasksT[0].add(3, 2, 12);
			d.tasksT[1].add(5, 1, 6);
			d.tasksT[2].add(8, 3, 4);
			d.tasksT[3].add(2, 2, 2);
			d.taskAmt = 4;
			d.PrintTasksT();
			break;
		case 5:
			int wtXX;
			cout << "-- Format plikow zgodny z instrukcja (wtXX.txt)--" << endl;
			cout << "Nazwa pliku z danymi:";
			cin >> d.fileName;
			cout << "Rozmiar instancji (XX z nazwy pliku):";
			cin >> wtXX;
			d.ImportData(d.fileName, wtXX);
			d.PrintTasksT();
			break;
		case 6:
			cout << "Ilosc zadan:";
			cin >> d.taskAmt;
			d.tasksT = new tasks[d.taskAmt];
			for (int i = 0; i < d.taskAmt; i++) {
				d.tasksT[i].add((std::rand() % 100) + 1, (std::rand() % 100) + 1, (std::rand() % 100) + 1);// liczby z przedzia³u 1-100
			}
			d.PrintTasksT();
			break;
		case 7:
			d.ResetMemory();
			break;
		case 8:
			for (int k = 2; k < 25; k++) {
				cout << "\nWykonywanie algorytmu dla " << k << " zadan:";
				for (int l = 0; l < 50; l++) {
					cout << ".";
					d.tasksT = new tasks[k];
					for (int i = 0; i < k; i++) {
						d.tasksT[i].add((std::rand() % 1000) + 1, (std::rand() % 1000) + 1, (std::rand() % 1000) + 1);// liczby z przedzia³u 1-100
						d.taskAmt = k;
					}
					d.DynamicSolve();

					d.fileName = "1000zadania.dat";
					d.SaveCountersTable(d.fileName);

					d.ResetMemory();
				}
			}
			break;
		case 9:
			system("cls");
			cout << "Politechnika Wroclawska 2017\nWydzial Elektroniki\nkierunek Informatyka\n"<<
				"Projektowanie Efektywnych Algorytmow\nProwadzacy: dr Mariusz Makuchowski\n"
				<<"=== Jednoprocesorowy problem szeregowania zadan  przy kryterium \nminimalizacji wazonej sumy opoznien zadan ===\n\n" <<
				"== Rozwiazanie problemu metoda programowania dynamicznego ==\n\n" <<
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

