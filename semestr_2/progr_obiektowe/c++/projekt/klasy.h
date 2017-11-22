#pragma once
#include <iostream>
#include <string>

using namespace std;

//funkcje menu glownego
void menuGlowne();
void dodajKomputer();
void dodajLicencje();
void dodajPrzedmiot();
void dodajAkcesorium();
void autor();
void systemWprowadzania();
void wyswietlListe();
void koniec();
void porownaj();

class interfejs
{
public:
	virtual bool operator<(interfejs& d) const = 0;
	virtual bool operator>(interfejs& d) const = 0;
	virtual int getNr() = 0;
};
class inwentarz:public interfejs
{
protected:
	string sprawny,
		nazwa;
	int ilosc,
		nrPomieszczenia;
public:
	virtual ~inwentarz() {};
	virtual void setInwentarz() = 0;
	virtual void getInwentarz() = 0;
};
class komputer : public inwentarz
{
protected:
	string RAM,	
		dysk,	
		procesor,	
		grafika;	
public:
	virtual ~komputer() {};
};
class stacjonarny : public komputer
{
private:
	string mobo; 
public:
	stacjonarny() {};
	void setInwentarz();
	void getInwentarz();
	virtual bool operator<(interfejs& d) const
	{
		stacjonarny& k = dynamic_cast<stacjonarny&>(d); 
		return ilosc < k.ilosc;
	};
	virtual bool operator>(interfejs& d) const
	{
		stacjonarny& k = dynamic_cast<stacjonarny&>(d);
		return ilosc > k.ilosc;
	};
	virtual int getNr() { return nrPomieszczenia; };
};
class notebook : public komputer
{
private:
	string bateria;	
public:
	notebook() {};
	void setInwentarz();
	void getInwentarz();
	virtual bool operator<(interfejs& d) const
	{
		notebook& k = dynamic_cast<notebook&>(d); 
		return ilosc < k.ilosc;
	};
	virtual bool operator>(interfejs& d) const
	{
		notebook& k = dynamic_cast<notebook&>(d);
		return ilosc > k.ilosc;
	};
	virtual int getNr() { return nrPomieszczenia; };
};
class licencje : public inwentarz
{
protected:
	string okres, 
		stanowiska,	
		typ;	
public:
	virtual ~licencje() {};
};
class systemOperacyjny : public licencje
{
private:
	string nazwaSys,
		wersjaSys;
public:
	systemOperacyjny() {};
	void setInwentarz();
	void getInwentarz();
	virtual bool operator<(interfejs& d) const
	{
		systemOperacyjny& k = dynamic_cast<systemOperacyjny&>(d); 
		return ilosc < k.ilosc;
	};
	virtual bool operator>(interfejs& d) const
	{
		systemOperacyjny& k = dynamic_cast<systemOperacyjny&>(d);
		return ilosc > k.ilosc;
	};
	virtual int getNr() { return nrPomieszczenia; };
};
class pakietBiurowy : public licencje
{
private:
	string nazwaPakietu,
		wersjaPakietu;
public:
	pakietBiurowy() {};
	void setInwentarz();
	void getInwentarz();
	virtual bool operator<(interfejs& d) const
	{
		pakietBiurowy& k = dynamic_cast<pakietBiurowy&>(d); 
		return ilosc < k.ilosc;
	};
	virtual bool operator>(interfejs& d) const
	{
		pakietBiurowy& k = dynamic_cast<pakietBiurowy&>(d);
		return ilosc > k.ilosc;
	};
	virtual int getNr() { return nrPomieszczenia; };
};
class antywirus : public licencje
{
private:
	string nazwaAntywirusa,
		wersjaAntywirusa;
public:
	antywirus() {};
	void setInwentarz();
	void getInwentarz();
	virtual bool operator<(interfejs& d) const
	{
		antywirus& k = dynamic_cast<antywirus&>(d); 
		return ilosc < k.ilosc;
	};
	virtual bool operator>(interfejs& d) const
	{
		antywirus& k = dynamic_cast<antywirus&>(d);
		return ilosc > k.ilosc;
	};
	virtual int getNr() { return nrPomieszczenia; };
};
class akcesoria :public inwentarz
{
private:
	string nazwaAkcesoria;
public:
	akcesoria() {};
	void setInwentarz();
	void getInwentarz();
	virtual bool operator<(interfejs& d) const
	{
		akcesoria& k = dynamic_cast<akcesoria&>(d); 
		return ilosc < k.ilosc;
	};
	virtual bool operator>(interfejs& d) const
	{
		akcesoria& k = dynamic_cast<akcesoria&>(d);
		return ilosc > k.ilosc;
	};
	virtual int getNr() { return nrPomieszczenia; };
};

