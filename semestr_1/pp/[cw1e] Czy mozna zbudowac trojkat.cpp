//Napisz wyra¿enie logiczne sprawdzaj¹ce czy z odcinków a,b,c da siê zbudowaæ trójk¹t.
// Lukasz Broll
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	double a,b,c;
	printf("Wprowadz dlugosc odcinka a:\n");
	cin>>a;
	printf("Wprowadz dlugosc odcinka b:\n");
	cin>>b;
	printf("Wprowadz dlugosc odcinka c:\n");
	cin>>c;
	if(a+b>c && a+c>b && b+c>a) // Trojkat mozna utworzyc tylko wtedy, gdy suma dwoch odcinkow jest wieksza od trzeciego (sprawdzenie kazdego warunku)
		cout<<"Z tych odcinkow mozna utworzyc trojkat."<<endl;
	else
		cout<<"Z tych odcinkow nie mozna utworzyc trojkata."<<endl;
	fflush(stdin);
	getchar();
	return 0;
}

