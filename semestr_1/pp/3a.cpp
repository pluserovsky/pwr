#include <cstdlib>
#include <iostream>
#include <cmath>
 
using namespace std;
 

void zadanie()
{
	//Napisz funkcj� przesuwaj�c� ca�� zawarto�� tablicy 50 liczb ca�kowitych
//�o jedno miejsce w g�r� (tzn. pierwszy element na drug� pozycj�,
//element o indeksie �i� na pozycj� o indeksie �i+1�,
//a element ostatni na pierwsz� pozycj� w tablicy)
	int x;
	int tab[50];
	for(int i=1;i<=50;i++)	tab[i]=i;
	for(int j=1;j<=50;j++)	cout<<tab[j]<<"\t";
	cout<<endl;
	x=tab[50];
	for(int k=50;k>=0;k--)	tab[k+1]=tab[k];
	tab[1]=x;
	for(int m=1;m<=50;m++)	cout<<tab[m]<<"\t";
}
void zadanie1()
{
	

//Napisz funkcj�, kt�ra sprawdzi czy tablica N liczb rzeczywistych
////(podawana jako parametr funkcji) ma symetryczn� zawarto��
//tzn. czy element pierwszy jest r�wny ostatniemu, drugi � przedostatniemu, itd.
	int n,k=1;
	cin>>n;
	int tab[n];
	int x=1;
	for(int m=0;m<n;m++) cin>>tab[m];
	for(int i=0;i<=n/2;i++)
	{
		if(tab[i]!=tab[n-x]) 
		{	
			k=0;
			break;
		}
		x++;
		
	}
	if(k==0) cout<<"nie jest symetryczna";
	else cout<<"jest symetryczny";
}
void zadanie2()
{
	//Napisz funkcj� otrzymuj�c� jako parametr wej�ciowy 100 -elementow�
//tablic� liczb ca�kowitych Tab. Funkcja powinna zwraca� warto�� minimaln�
//z dodatnich element�w tablicy Tab.
	int min,tab[10];
	for(int i=0;i<10;i++)	
	cin>>tab[i];
	
	for(int k=0;k<10;k++)
	{
		if(tab[k]>0)
		min=tab[k];
		
	}
	
	for(int m=0;m<10;m++)
	{
		if(tab[m]>0 && tab[m]<min)
		min=tab[m];
	}
	cout<<"Najmniejsza dodatnia liczba to "<<min;
}
int main()
{
	zadanie2();
	getchar();
}
