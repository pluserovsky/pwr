/*Napisz wyra¿enia matematyczne wyznaczaj¹ce:
- pole powierzchni i obwód ko³a o promieniu r,  
- kartezjañsk¹ odleg³oœæ pomiêdzy dwoma punktami o wspó³rzêdnych (x1,y1 ) oraz (x2,y2)
- wartoœci wyra¿eñ:  
Lukasz Broll          	    	         */
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double r,pole,ob,x1,x2,y1,y2,odl,a,b,c,d,e,f,w5,w8;
	int wybor;
	cout<<"1. Pole i obwod kola.\n2. Kartezjanska odleglosc\n3. Wyrazenie ((a*b)/(b+c))-((a*c)/(b+c))\n4. Wyrazenie (a/(b-(c/(d-(e/f)))))."<<endl<<"Wprowadz numer:";
	cin>>wybor; //wybranie opcji dzialania
	switch(wybor)
	
	{ 
		case 1:{
				cout<<("Wprowadz promien kola:\n");
				cin>>r;
				pole=M_PI*pow(r,2); //obliczenie pola i obwodu
				ob=2*M_PI*r;
				cout<<"Pole kola o promieniu "<<r<<" wynosi "<<pole<<" a, jego obwod "<<ob<<endl;
			break; }
		case 2: {
				cout<<("Wprowadz wspolrzedne pierwszego punktu:\n");
				cout<<"x1: ";
				cin>>x1;
				cout<<"y1: ";
				cin>>y1;
				cout<<("Wprowadz wspolrzedne drugiego punktu:\n");
				cout<<"x2: ";
				cin>>x2;
				cout<<"y2: ";
				cin>>y2;
				odl=sqrt(pow(x2-x1,2)+pow(y2-y1,2)); //obliczenie odl. kartezjanskiej ze wzoru
				cout<<"Kartezjanska odleglosc miedzy typi punktami wynosi "<<odl<<endl; 
			break; } 
		case 4: 
			{ cout<<("Wczytaj liczby do obliczenia wyrazenia:\n");
				cout<<"Wczytaj a: ";
				cin>>a;
				cout<<"Wczytaj b: ";
				cin>>b;
				cout<<"Wczytaj c: ";
				cin>>c;
				cout<<"Wczytaj d: ";
				cin>>d;
				cout<<"Wczytaj e: ";
				cin>>e;
				cout<<"Wczytaj f: ";
				cin>>f;
				w8=(a/(b-(c/(d-(e/f))))); //obliczenie wielomianu
				cout<<"Wartosc wyrazenia (a/(b-(c/(d-(e/f))))) wynosi "<<w8<<endl; 
			break;
		}		
		case 3: 
			{ cout<<("Wczytaj liczby do obliczenia wyrazenia:\n");
				cout<<"Wczytaj a: ";
				cin>>a;
				cout<<"Wczytaj b: ";
				cin>>b;
				cout<<"Wczytaj c: ";
				cin>>c;
				cout<<"Wczytaj d: ";
				cin>>d;
				w5=((a*b)/(b+c))-((a*c)/(b+c)); //obliczenie wielomianu
				cout<<"Wartosc wyrazenia ((a*b)/(b+c))-((a*c)/(b+c)) wynosi "<<w5<<endl; 
			break;
		}	}
		

	fflush(stdin);
	getchar();
	return 0;
}

