#include <iostream>

using namespace std;
int silnia(int n);
int main()
{
	int n,w,k,p,r;
	cout<<"podaj stopien wielomianu od 0 do 12:";
	cin>>n;
	cout<<silnia(n)<<"\n";
	for(w=0;w<=n;w++)
	{
		for(k=0;k<=w;k++)
		{
		
			r=n-k;
			{
			p=silnia(n)/(silnia(k)*silnia(r));
			}
			cout<<" "<<p<<" ";
			
		}
		cout<<"\n";
		k=0;
	}

	return 0;
}
int silnia(int n)
{
	int wynik=1;
	for(int a=1;a<=n;a++)
	{
		wynik=wynik*a;
	}
	return wynik;
}