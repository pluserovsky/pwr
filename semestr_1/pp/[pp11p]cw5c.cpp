#include <iostream>
#include <string>
using namespace std;

int main()
{
	
	char napis[] ="Aaa    bb c dd    f";
	cout << napis;
	int dlugosc = napis.length();
	int a = 0;
	int j;
	for (int i = 0; i < dlugosc-1; i++)
	{
		while ((int)napis[i] == 32)
		{
			j = i;
			do{
				
				a++;
				j++;
			} while ((int)napis[j] == 32);
			break;
		}
		cout << a;
		if(a>0 && napis[i]!=NULL)
		napis.erase(i,a - 1);
		
		a = 0;

	}
	
}
