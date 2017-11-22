#include <stdio.h>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main(){
		
	int a=0,b=0,c=0,d=0;
	string s;
	cout<<"Podaj pojedynczy wyraz:"<<endl;
	cin>>s;
	int rozmiar = s.size(); //funkcja sprawdza ilosc znakow
	cout<<"Wyraz ma "<<rozmiar<<" znakow."<<endl;
	for(int i=0;i<rozmiar;i++)
	{
		int k= s.at(i); //funkcja bierze kazdy znak wyrazu osobno i po kolei sprawdza czym jest

		if(islower(k)) a++;
		if(isupper(k)) b++;
		if(isdigit(k)) c++;
		
	}

	d=rozmiar-(a+b+c); //to liczy te inne znaki, ktorych nie przypisano do niczego
	printf("Wpisales %d malych liter, %d duzych liter, %d cyfr i %d innych znakow.",a,b,c,d);
	
	
	getchar();
}