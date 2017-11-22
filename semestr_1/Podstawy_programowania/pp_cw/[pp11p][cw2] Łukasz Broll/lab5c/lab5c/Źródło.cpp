#include <stdio.h>
#include <ctype.h>

int moje_strlen( char* tab )
{ 
	int strlen=0,i=0;

	while(tab[i])
	{
		strlen++;
		i++;
	}
	 return strlen;
}
char* moje_strupr(char* tab )
{
	
	int i=0;
	while(tab[i])
	{
		if(islower(tab[i]))
		tab[i]=toupper(tab[i]);
		i++;

	}
	
	return tab;
}

char* moje_strcpy( char* tab2, char* tab)
{
	int i=0;
	while(tab[i])
	{
		tab2[i]=tab[i];
		i++;
	}
	tab2[i]='\0';
	return tab2;
}

int main()
{
	char tab2[100];
	char tab[]="Ono ma to peja";
	printf("Strlen = %d\n",moje_strlen(tab));
	printf("Tab 2 skopiowana: %s\n",moje_strcpy(tab2,tab));
	printf("Duze litery: %s\n",moje_strupr(tab));
	

	getchar();
}
	