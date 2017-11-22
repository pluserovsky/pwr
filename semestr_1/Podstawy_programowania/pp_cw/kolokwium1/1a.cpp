#include <iostream>

void zadanie_1a()
{
	//Napisz program wczytuj¹cy 4 liczby ca³kowite i sprawdzaj¹cy
	//ile jest wœród nich powtórzeñ (dwójek, trójek lub czwórek).
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
	//Napisz program wczytuj¹cy znaki z klawiatury
	//do momentu a¿ da siê z nich z³o¿yæ s³owo “ tato ” .
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
	//Napisz program wczytuj¹cy 4 liczby rzeczywiste i wyznaczaj¹cy œredni¹
	//arytmetyczn¹ z liczb pozosta³ych po odrzuceniu dwóch najmniejszych wartoœci.
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
