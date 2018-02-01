#include <stdio.h>
#include <cctype>
#include <iostream>
#include <conio.h>

int main(){
	
	char enter;
	char znak[10];
	int k=0,l=0,m=0,z=0,x=0,q=0,kod;
	for(int i=0;i<10;i++){
	
		kod = static_cast < int >( enter );
		std::cin>>znak[i];
		if(kod==13) break;
		z++;
	}
	
	while(znak[q]<z)
	{	
	if(islower(znak[q]))k++;
	if(isupper(znak[q])) l++;
	if(isdigit(znak[q])) m++;
	else x++;
	q++;
	}
	printf("Wpisales %d liter malych, %d duzych, %d cyfr i %d innych znakow.",k-1,l,m,x);
	getchar();
}
