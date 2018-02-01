#include <iostream>

using namespace std;

double tab[10];

void wczytaj(){
	
	for(int i=0;i<=9;i++)
	{
		cout<<"Tab["<<i+1<<"]=";
		cin>>tab[i];
	}
	cout<<endl;	
}

void wyswietl(){
	
	for(int k=0;k<=9;k++) cout<<"Tab["<<k+1<<"]="<<tab[k]<<endl;
}

void suma(){
	
	double s=0;
	for(int k=0;k<=9;k++)
	{
		s=s+tab[k];
	}
	cout<<endl<<"Suma wynosi "<<s<<endl;
	cout<<"Srednia wynosi "<<s/10<<endl;
}
	
void blad()
{
	double s=0,ss=0;
	for(int k=0;k<=9;k++)
	{
		s=s+tab[k];
	}
	
	for(int i=0;i<=9;i++)
	{
		ss=ss+(((s/10)-tab[i])*((s/10)-tab[i]));
	}
	
	cout<<"Blad sredniokwadratowy wynosi "<<ss/10<<endl;
	
}

void ekstrema()
{
	double min=tab[0],max=min;
	
	for(int i=0;i<=9;i++)
	{
		if(tab[i]<min) min=tab[i];	
		if(tab[i]>max) max=tab[i];
	}
	
	cout<<"Min="<<min<<", max="<<max<<endl;
}

void zliczanie()
{
	int x=0,y=0,z=0;
	
	for(int i=0;i<=9;i++)
	{
		if(tab[i]<0) x++;	
		if(tab[i]>0) y++;
		if(tab[i]==0) z++;
	}
	
	cout<<"Ujemnych = "<<x<<", dodatnich = "<<y<<", zerowych = "<<z<<endl;
}
int main(){
	
	wczytaj();
	wyswietl();
	suma();	
	blad();
	ekstrema();
	zliczanie();
	
	getchar();
}


