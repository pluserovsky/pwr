//Napisz wyra¿enie logiczne sprawdzaj¹ce czy data zapisana za pomoc¹ trzech zmiennych
//dzien_1, miesi¹c_1, rok_1 jest mniejsza od daty zapisanej za pomoc¹ trzech zmiennych
//dzien_2, miesiac_2, rok_2
//Lukasz Broll
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	double dzien_1,dzien_2,miesiac_1,miesiac_2,rok_1,rok_2;
	char koniec;
	do {
	
		printf("Wprowadz pierwsza date DD-MM-RRRR:\n");
		scanf("%lf""-" "%lf""-" "%lf",&dzien_1 , &miesiac_1 , &rok_1); //wczytanie pierwszej daty
		printf("Wprowadz druga date DD-MM-RRRR:\n");
		scanf("%lf""-" "%lf""-" "%lf",&dzien_2 , &miesiac_2 , &rok_2); //wczytanie drugiej daty
	
		if(rok_1<rok_2)	cout<<"Data pierwsza jest mniejsza."; //porownywanie lat
		
		else if(rok_1>rok_2)	cout<<"Data pierwsza jest wieksza.";
	
		else if(rok_1==rok_2)
						{ 
							if(miesiac_1>miesiac_2) cout<<"Data pierwsza jest wieksza."; //porownywanie miesiecy
							
							else if(miesiac_1<miesiac_2) cout<<"Data pierwsza jest mniejsza.";
							
				 			else if(miesiac_1=miesiac_2)
							 {
				  						if (dzien_1>dzien_2) cout<<"Data pierwsza jest wieksza."; //porownywanie dni
				  						
				  						else if (dzien_1<dzien_2) cout<<"Data pierwsza jest mniejsza.";
				  						
					  					else cout<<"Obie daty sa takie same.";
					  				}
					  			}
					  		
		printf("\nZakonczyc dzialanie programu? (t/n)");
					  		cin>>koniec;
					  	}
	while(koniec!='t');
			
	return 0;
}

