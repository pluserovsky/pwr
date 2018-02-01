#include <stdio.h>

int main()
{
	char * wsk_char;
	int * wsk_int;
	float * wsk_float;
	double * wsk_double;
	 
	printf("W systemie dziesietnym:");
	printf("\n Wartosc bajtu char: %u",&wsk_char);
	printf("\n Wartosc bajtu int: %u",&wsk_int);
	printf("\n Wartosc bajtu float: %u",&wsk_float);
	printf("\n Wartosc bajtu double: %u",&wsk_double);
	
	printf("\nW systemie szestnastkowym:");
	printf("\n Wartosc bajtu char: %x",&wsk_char);
	printf("\n Wartosc bajtu int: %x",&wsk_int);
	printf("\n Wartosc bajtu float: %x",&wsk_float);
	printf("\n Wartosc bajtu double: %x",&wsk_double);
	/* Do wyswietlania binarnego mozna uzyc tej funkcji:
	long dec;
	string bin = "";
	do
	{
		if ((dec % 2) == 1)
			bin = '1'+bin;
		else
			bin = '0'+bin;
		dec /= 2;
	}while (dec != 0)
	*/
	getchar();
}
