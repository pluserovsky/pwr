#include <iostream>

void zadanie_1a()
{
	//Napisz program wczytuj�cy 4 liczby ca�kowite i sprawdzaj�cy
	//ile jest w�r�d nich powt�rze� (dw�jek, tr�jek lub czw�rek).
	int a=0,b=0,c=0,d=0;
	for(int i=0;i<4;i++)
	{
		std::cin>>a;
		if(a==2) b++;
		if(a==3) c++;
		if(a==4) d++;
	}
		std::cout<<"Jest "<<b<<" dwojek, "<<c<<" trojek, "<<d<<" czworek.";
		
}

void zadanie_1b()
{
	//Napisz program wczytuj�cy znaki z klawiatury
	//do momentu a� da si� z nich z�o�y� s�owo � tato � .
	char a;
	int b=0,c=0,d=0;
	
	do
	{
		std::cin>>a;
		if(a=='t') b++;
		if(a=='o') c++;
		if(a=='a') d++;
	
	}
	while (b < 2 || c < 1 || d < 1);
	
		
}

void zadanie_1c()
{
	//Napisz program wczytuj�cy 4 liczby rzeczywiste i wyznaczaj�cy �redni�
	//arytmetyczn� z liczb pozosta�ych po odrzuceniu dw�ch najmniejszych warto�ci.
	float a,b,c,d,min,min2,s;
	std::cin>>a;
	min=a;
	std::cin>>b;
	if(b<min) min=b;
	std::cin>>c;
	if(c<min) min=c;
	std::cin>>d;
	if(d<min) min=d;
	
	if(a!=min) min2=a;
	if(b!=min) min2=b;
	if(c!=min) min2=c;
	if(d!=min) min2=d;
	
	if(a<min2 && a!=min) min2=a;
	if(b<min2 && b!=min) min2=b;
	if(c<min2 && c!=min) min2=c;
	if(d<min2 && d!=min) min2=d;
	
	s=(a+b+c+d-min-min2)/2;
	
	std::cout<<"Srednia po odrzuceniu "<<min<<" i "<<min2<<" wynosi "<<s;
	
		
}



int main()
{
	zadanie_1c();
	getchar;
}
