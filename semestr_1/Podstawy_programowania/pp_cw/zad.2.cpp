#include <iostream>

using namespace std;
int silnia(int n)
{
	int wynik=1;
	for(int a=1;a<=n;a++)
	{
		wynik=wynik*a;
	}
	return wynik;
}
int main()
{
	int n=0,w=0,k=0,g=0;
	cout<<"podaj stopien wielomianu od 0 do 12:";
	cin>>n;
	if(n<0)
	{
		cout<<"podales zly stopien wielomianu";
	}
	else if(n>12)
	{
		cout<<"podales zly stopien wielomianu";
	}
	else if(n>=0 &&n <=12)
	{
		
	for(w=0;w<=n;w++)
	{
		for(g=n-w;g>=0;g--)
		{
			cout<<"   ";
		}
		for(k=0;k<=w;k++)
		{
		cout.width( 6 );	
		cout<<internal<<silnia(w)/(silnia(k)*silnia(w-k));
		}
		cout<<"\n";
		k=0;
	}
	}

	return 0;
}
