#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int i,k;
    char tekst[]="    Programowanie   ";
    size_t m= strlen(tekst);
    while(tekst[0]==' ')             // znaki spacji na poczatku
    {
        i=0;
        for(k=1;k<m;k++)
        {
            tekst[i]=tekst[k];                   
            i++;                                
        }
    }
    
    for(i = strlen(tekst)-1;tekst[i]==' ';i--)       //znaki spacji na koncu
    tekst[i]=0;
	                          
    std::cout<<tekst<<".";         
    getchar();
}

