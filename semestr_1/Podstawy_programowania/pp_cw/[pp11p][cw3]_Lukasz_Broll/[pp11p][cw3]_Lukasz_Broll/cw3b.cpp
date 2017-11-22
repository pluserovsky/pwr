#include <iostream>
using namespace std;

main()
{
    double tab[10];
    int i,k,s=1,powt=-1,maljc=1,rosnc=1;
    cout<<"Podaj 10 elemetow tablicy:"<<endl;
    for(i=0;i<=9;i++)
    {
        
        cin>>tab[i];
    }
    for(i=0;i<=4;i++) //sprawdzanie symetrycznosci
    {
        if(tab[i]!=tab[10-i])
        {
            s=0;
            break;
        }
    }
    for(i=0;i<=8;i++) //sprawdzadnie monotonicznosci
    {
        if(tab[i]>=tab[i+1]) rosnc=0;
        if(tab[i]<=tab[i+1]) maljc=0;
    }
    for(i=0;i<=9;i++)//sprawdzanie powtorzen
    {
        powt=-1;
        for(k=0;k<=9;k++)
        {
            if(tab[k]==tab[i]) powt++;
        }
        if(powt) break;
    }
    // w if i else if warunkiem jest wartosc zmiennej inna niz 0, wiec nie trzeba pisac konkretnego warunku
   	 if(s) cout<<"Ciag jest symetryczny"<<endl;
    else cout<<"Ciag nie jest symetryczny"<<endl;
    
    if(rosnc) cout<<"Ciag jest rosnacy"<<endl;
    else if(maljc) cout<<"Ciag jest malejacy"<<endl;
    else cout<<"Ciag nie jest monotoniczny"<<endl;
       
        if(powt) cout<<"Co namniej jedna liczba sie powtarza"<<endl;
    else cout<<"Zadna liczba sie nie powtarza"<<endl;
        
    return 0;
}
