/*Napisz funkcjê wyznaczaj¹c¹ sumê wartoœci liczb ca³kowitych
przechowywanych w pamiêci komputera w postaci tekstowej
(np. char* liczby = ”12   -3    64    2     78”; ) */

#include <math.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int Suma(char* text)
{
	char table[50][50];
	int t = 0;
	//PRZENIESIENIE LICZB DO TABELI
	for (int i = 0 ; i<((int)strlen(text) - 1); i++)
	{
		if (text[i] == 32)
		{
			//do nothing
		}
		else
		{
			//przenies liczbe do tablicy

			//znalezc dlugosc liczby
			int k=0; //<-dlugosc liczby
			while (text[i + k] != 32 && text[i+k] != '\0')
			{
				k++;
			}
			for (int j = 0; j < k; j++)
			{
				table[t][j] = text[i + j];
				
			}
			t++;
			i += (k-1);
		}
	}
	//PODSUMOWANIE LICZB
	int suma = 0;
	for (int i = 0; i < t; i++)
	{
		suma += atoi(table[i]);
	}
	return suma;
}

int main()
{
	char* napis = new char[];
	strcpy(napis, "12   64    2     78");

	printf("Napis: %s\n", napis);
	printf("strlen: %d\n", strlen(napis));
	printf("Suma= %d\n", Suma(napis));



	_getch();
}
