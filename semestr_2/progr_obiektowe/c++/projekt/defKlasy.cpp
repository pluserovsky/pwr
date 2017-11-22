#include "klasy.h"
#include <iostream>
#include <string>

using namespace std;

void stacjonarny::setInwentarz()
{
	cout << "Nazwa / ID: "; cin >> stacjonarny::nazwa;
	cout << "Numer pomieszczenia: "; cin >> stacjonarny::nrPomieszczenia;
	cout << "Ilosc: "; cin >> stacjonarny::ilosc;
	cout << "Sprawny (TAK/NIE): "; cin >> stacjonarny::sprawny;
	cout << "RAM (GB): "; cin >> stacjonarny::RAM;
	cout << "Dysk (GB): "; cin >> stacjonarny::dysk;
	cout << "Model procesora: "; cin >> stacjonarny::procesor;
	cout << "Model kart graficznej: "; cin >> stacjonarny::grafika;
	cout << "Model plyty glownej: "; cin >> stacjonarny::mobo;
}
void notebook::setInwentarz()
{
	cout << "Model / ID: "; cin >> notebook::nazwa;
	cout << "Numer pomieszczenia: "; cin >> notebook::nrPomieszczenia;
	cout << "Ilosc: "; cin >> notebook::ilosc;
	cout << "Sprawny (TAK/NIE): "; cin >> notebook::sprawny;
	cout << "RAM (GB): "; cin >> notebook::RAM;
	cout << "Dysk (GB): "; cin >> notebook::dysk;
	cout << "Rozmiar baterii: "; cin >> notebook::bateria;
}
void systemOperacyjny::setInwentarz()
{
	cout << "Nazwa systemu: "; cin >> systemOperacyjny::nazwaSys;
	cout << "Wersja: "; cin >> systemOperacyjny::wersjaSys;
	cout << "Numer pomieszczenia: "; cin >> systemOperacyjny::nrPomieszczenia;
	cout << "Ilosc: "; cin >> systemOperacyjny::ilosc;
	cout << "Sprawny (TAK/NIE): "; cin >> systemOperacyjny::sprawny;
	cout << "Czas trwania licencji: "; cin >> systemOperacyjny::okres;
	cout << "Stanowisk na licencje: "; cin >> systemOperacyjny::stanowiska;
	cout << "Typ licencji: "; cin >> systemOperacyjny::typ;
}
void pakietBiurowy::setInwentarz()
{
	cout << "Nazwa pakietu: "; cin >> pakietBiurowy::nazwaPakietu;
	cout << "Wersja: "; cin >> pakietBiurowy::wersjaPakietu;
	cout << "Numer pomieszczenia: "; cin >> pakietBiurowy::nrPomieszczenia;
	cout << "Ilosc: "; cin >> pakietBiurowy::ilosc;
	cout << "Sprawny (TAK/NIE): "; cin >> pakietBiurowy::sprawny;
	cout << "Czas trwania licencji: "; cin >> pakietBiurowy::okres;
	cout << "Stanowisk na licencje: "; cin >> pakietBiurowy::stanowiska;
	cout << "Typ licencji: "; cin >> pakietBiurowy::typ;
}
void antywirus::setInwentarz()
{
	cout << "Nazwa antywirusa: "; cin >> antywirus::nazwaAntywirusa;
	cout << "Wersja: "; cin >> antywirus::wersjaAntywirusa;
	cout << "Numer pomieszczenia: "; cin >> antywirus::nrPomieszczenia;
	cout << "Ilosc: "; cin >> antywirus::ilosc;
	cout << "Sprawny (TAK/NIE): "; cin >> antywirus::sprawny;
	cout << "Czas trwania licencji: "; cin >> antywirus::okres;
	cout << "Stanowisk na licencje: "; cin >> antywirus::stanowiska;
	cout << "Typ licencji: "; cin >> antywirus::typ;
}
void akcesoria::setInwentarz()
{
	cout << "Nazwa akcesoria: "; cin >> akcesoria::nazwaAkcesoria;
	cout << "Numer pomieszczenia: "; cin >> akcesoria::nrPomieszczenia;
	cout << "Ilosc: "; cin >> akcesoria::ilosc;
	cout << "Sprawny (TAK/NIE): "; cin >> akcesoria::sprawny;
}


void stacjonarny::getInwentarz()
{
	cout << "Nazwa / ID: " << stacjonarny::nazwa << endl;
	cout << "Numer pomieszczenia: " << stacjonarny::nrPomieszczenia << endl;
	cout << "Ilosc: " << stacjonarny::ilosc << endl;
	cout << "Sprawny: " << stacjonarny::sprawny << endl;
	cout << "RAM (GB): " << stacjonarny::RAM << endl;
	cout << "Dysk (GB): " << stacjonarny::dysk << endl;
	cout << "Model procesora: " << stacjonarny::procesor << endl;
	cout << "Model kart graficznej: " << stacjonarny::grafika << endl;
	cout << "Model plyty glownej: " << stacjonarny::mobo << endl;
}
void notebook::getInwentarz()
{
	cout << "Model / ID: " << notebook::nazwa << endl;
	cout << "Numer pomieszczenia: " << notebook::nrPomieszczenia << endl;
	cout << "Ilosc: " << notebook::ilosc << endl;
	cout << "Sprawny: " << notebook::sprawny << endl;
	cout << "RAM (GB): " << notebook::RAM << endl;
	cout << "Dysk (GB): " << notebook::dysk << endl;
	cout << "Rozmiar baterii: " << notebook::bateria << endl;
}
void systemOperacyjny::getInwentarz()
{
	cout << "Nazwa systemu: " << systemOperacyjny::nazwaSys << endl;
	cout << "Wersja systemu: " << systemOperacyjny::wersjaSys << endl;
	cout << "Numer pomieszczenia: " << systemOperacyjny::nrPomieszczenia << endl;
	cout << "Ilosc: " << systemOperacyjny::ilosc << endl;
	cout << "Sprawny: " << systemOperacyjny::sprawny << endl;
	cout << "Czas trwania licencji: " << systemOperacyjny::okres << endl;
	cout << "Stanowisk na licencje: " << systemOperacyjny::stanowiska << endl;
	cout << "Typ licencji: " << systemOperacyjny::typ << endl;

}
void pakietBiurowy::getInwentarz()
{
	cout << "Nazwa pakietu: " << pakietBiurowy::nazwaPakietu << endl;
	cout << "Wersja pakietu: " << pakietBiurowy::wersjaPakietu << endl;
	cout << "Numer pomieszczenia: " << pakietBiurowy::nrPomieszczenia << endl;
	cout << "Ilosc: " << pakietBiurowy::ilosc << endl;
	cout << "Sprawny: " << pakietBiurowy::sprawny << endl;
	cout << "Czas trwania licencji: " << pakietBiurowy::okres << endl;
	cout << "Stanowisk na licencje: " << pakietBiurowy::stanowiska << endl;
	cout << "Typ licencji: " << pakietBiurowy::typ << endl;
}
void antywirus::getInwentarz()
{
	cout << "Nazwa pakietu: " << antywirus::nazwaAntywirusa << endl;
	cout << "Wersja pakietu: " << antywirus::wersjaAntywirusa << endl;
	cout << "Numer pomieszczenia: " << antywirus::nrPomieszczenia << endl;
	cout << "Ilosc: " << antywirus::ilosc << endl;
	cout << "Sprawny: " << antywirus::sprawny << endl;
	cout << "Czas trwania licencji: " << antywirus::okres << endl;
	cout << "Stanowisk na licencje: " << antywirus::stanowiska << endl;
	cout << "Sprawny: " << antywirus::typ << endl;
}
void akcesoria::getInwentarz()
{
	cout << "Nazwa akcesoria: " << akcesoria::nazwaAkcesoria << endl;
	cout << "Numer pomieszczenia: " << akcesoria::nrPomieszczenia << endl;
	cout << "Ilosc: " << akcesoria::ilosc << endl;
	cout << "Sprawny: " << akcesoria::sprawny << endl;
}