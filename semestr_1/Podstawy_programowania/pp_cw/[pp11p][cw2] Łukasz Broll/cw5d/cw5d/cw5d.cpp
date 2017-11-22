#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#define ROZMIAR 3

void WCZYTAJ( int tab[])
{
	int *wsk;
	for(wsk=tab;wsk<tab+ROZMIAR;wsk++)
		scanf("%d",wsk);
}

void WYSWIETL(int tab[])
{
	int *wsk;
	for(wsk=tab;wsk<tab+ROZMIAR;wsk++)
		printf("%d, ",*wsk);
}

float SREDNIA(int tab[])
{
	int *wsk;
	int suma=0;
	for(wsk=tab;wsk<tab+ROZMIAR;wsk++)
		suma=suma+(*wsk);
	int srednia=suma/ROZMIAR;
	return srednia;
}

int main()
{ 
	int tab[ROZMIAR];
	WCZYTAJ(tab);
	WYSWIETL(tab);
	printf("Srednia = %f",SREDNIA(tab));

	getchar();
	getchar();
}
