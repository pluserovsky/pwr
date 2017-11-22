#include <iostream>
#include <cstdlib>
#define rozmiar 100
using namespace std;

char tekst[rozmiar]={};
int licznik=0, pozycja=0, ilosc=0;

int licz_spacje()
{
 do
 {
		 ilosc++, pozycja++;
 }
 while(tekst[pozycja]==' ');
 return ilosc-1;

}
void przesun(int N)
{
	for(int k=pozycja;k<pozycja+N;k++)
	{
		tekst[k-1]=tekst[k];
	}
}
int main()
{
	cin.getline(tekst,rozmiar);
	
	for(int i=0;i<rozmiar;i++)
	{
		if(tekst[i]=' ')
		{
			pozycja=i;
			licz_spacje();
			przesun(ilosc);
			ilosc=0;
		}
	}
	
	for(int l=0;l<rozmiar;l++)
	{
	cout << tekst[l];
	}
	system("pause");
}
