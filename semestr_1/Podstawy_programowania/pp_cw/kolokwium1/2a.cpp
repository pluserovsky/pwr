#include <cstdlib>
#include <iostream>
#include <cmath>
 
using namespace std;
 

void zadanie()
{
    Napisz funkcjê drukuj¹c¹ na ekranie kolejne N liczb nieparzystych
podzielnych przez 7. Wartoœæ N powinna byæ parametrem.
    int n,k=1;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
    	cout<<k*7<<endl;
    	k=k+2;
	}
	
}

void zadanie2()
{
	Napisz funkcjê sprawdzaj¹c¹ numerycznie ile par
liczb ca³kowitych z przedzia³u [a,b] spe³nia nierównoœæ x2 +y2 <= 50 .
Wartoœci a,b powinny byæ zadawane jako parametry funkcji.
	int a,b,x,y,k=0;
	cin>>a;
	cin>>b;
	x=a;
	y=a;
	
	for(int i=0;i<=b+1;i++)
	{
		
		if(x*x+y*y<=50)
		{
			cout<<x*x<<"+"<<y*y<<"<="<<50<<endl;
			k++;
		}
		
		if(x!=y) x++;		
		else y++;
	}
	
	cout<<k;
}

void zadanie3()
{\
Napisz funkcjê wczytuj¹c¹ znaki z klawiatury tak d³ugo,
a¿ zostan¹ podane trzy kolejne znaki o takich samych kodach.
Na zakoñczenie program powinien wyœwietliæ podsumowanie
czy wiêcej naciœniêtych klawiszy by³o "literami" czy "cyframi".
	char tab[3],liczby=0,litery=0;
	
	cin>>tab[0];
	if(isdigit(tab[0])) liczby++;
	else if(isalpha(tab[0])) litery++;
	cin>>tab[1];
	if(isdigit(tab[1])) liczby++;
	else if(isalpha(tab[1])) litery++;
	
	int i=0;
	do
	{
		if(i)
		{
		
			tab[0]=tab[1];
			tab[1]=tab[2];
		}
		cin>>tab[2];
		if(isdigit(tab[2])) liczby++;
	else if(isalpha(tab[2])) litery++;
		
		
		i++;
	}
	while(tab[0]!=tab[1] || tab[1]!=tab[2]  || tab[2]!=tab[0] );
	if(liczby==litery) cout<<"po rowno";
	if(liczby>litery) cout<<"wiecej liczb";
	if(litery>liczby) cout<<"wiecej liter";
	
	
}

void zadanie4()
{
	Napisz funkcjê sumuj¹c¹ kwadraty wszystkich liczb nieparzystych
z przedzia³u [-N, N ]. Wartoœæ N powinna byæ parametrem wejœciowym tej funkcji.
	int n,m,s=0;
	cin>>n;
	m=-n;
	
	while(m<=n)
	{
		if(m%2) s=s+m*m;
		m++;
	}
	cout<<endl<<s;
}

void zadanie5()
{
	Policz iloczyn wszystkich liczb nieparzystych
z domkniêtego przedzia³u liczb ca³kowitych [ pierwsza  ..  ostatnia ].
Wartoœci zmiennych pierwsza, ostatnia nale¿y wczytaæ z klawiatury.
	int pierwsza,ostatnia,iloczyn=1,a;
	cin>>pierwsza;
	cin>>ostatnia;
	a=pierwsza;
	while(a<=ostatnia)
	{
		if(a%2) iloczyn=iloczyn*a;
		a++;
	}
	cout<<endl<<iloczyn;
}

void zadanie6()
{
	Napisz program wyznaczaj¹cy numerycznie sumê n wyrazów ci¹gu
o elementach: a0 = 1; a1=sin(1); a2=sin(2); .... ; an=sin(n)
	int n;
	float a,suma=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a=sin(i);
		suma=suma+a;
	}
	cout<<endl<<suma;
}
void zadanie7()
{
	Napisz funkcjê sprawdzaj¹c¹ numerycznie jakie liczby ca³kowite
z przedzia³u [1,1000] spe³niaj¹ równanie:
	double s;
	cout<<"Spelniaja: ";
	for(double i=1;i<=1000;i++)
	{
		
		if(i!=50) 
		{
			s=(i*i)/(50-i)-sin(i);
			if(s>=0)
			cout<<"s"<<"["<<i<<"]="<<s<<">0"<<endl;
		}
	}
	cout<<(51*51)/(50-51)-sin(51);
}

void zadanie9()
{
	Napisz funkcjê wyœwietlaj¹c¹ na ekranie wszystkie mo¿liwe
4-ro literowe palindromy (wyrazy jednakowo czytane od przodu i od ty³u).
	int i,j;

	for(i=97;i<123;i++)
	{

		for(j=97;j<123;j++)

			cout<<char(i)<<char(j)<<char(j)<<char(i)<<endl;   //wyœwietlanie palindromów
	}
 	 
}
int main()
{
	zadanie9();
	getchar();
}
