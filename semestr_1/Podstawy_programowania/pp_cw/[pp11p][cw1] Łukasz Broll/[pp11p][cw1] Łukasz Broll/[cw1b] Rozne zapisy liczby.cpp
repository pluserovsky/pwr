// ConsoleApplication2.cpp : Defines the entry point for the console application.
//Lukasz Broll


#include <stdio.h>
#include <iostream>

int main()
{
	double a;
	printf("Wprowadz dowolna liczbe:\n");
	std::cin>>a;
	printf("\nLiczba %f z dokladnoscia do \ntrzeciego miejsca po przecinku to %.3f",a,a);
	printf("\nbez rozwiniecia dziesietnego liczby to %.0f",a);
	printf("\nw zapisie inzynierskim to %e",a);
	fflush(stdin);
	getchar();
	return 0;
}

