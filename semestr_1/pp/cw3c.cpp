#include <iostream>

using namespace std;

main()
{
    
    const int n = 10;
    char tab[n];
    char tabp[n];
    
    cout<<"Wprowadz znaki (nie liczby) do "<< n <<" elementowej tablicy: "<<endl;
    for (int i=0; i<n; i++)
    {
        
        cin>>tab[i];
    }
    
    for (int i=0; i<n-1; i++)
    {
        tabp[i+1] = tab[i];//przesuwanie o 1 w gore az do przedostatniej
    
        tabp[0] = tab[n-1];// ostatni znak przeniesiony na pierwsza pozycje
    }
    cout<<endl<<"Tablica przesunieta o 1 w gore: "<<endl;
    
    for (int i=0; i<n; i++)
    {
        cout<<tabp[i]<<endl;
    }
    
    getchar();
}
