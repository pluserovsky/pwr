#include <stdio.h>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL)); //zapobieganie powtorzen w losowaniu na podstawie aktualnej godziny
	int n;
	scanf("%d", &n); //pobieranie ilosci znakow wczytywanyh do tabicy
	int tab[n];
	
	for(int i=0;i<n;i++){
	
	tab[i]=(rand()%80)-30; //losowanie liczb do tablicy
	}
	for(int k=0;k<n;k++) {
	
	printf("%d,",tab[k]); //drukowanie liczb na ekran
	
	}	
	
	getchar();
	return 0;
}
