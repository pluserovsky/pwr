#pragma once

class Figura
{
private:
	double pole, obwod;
	unsigned int licznik;
	double *tablica;
	static unsigned int ilosc;
public:
	Figura();	
	Figura(double r);	
	~Figura();
	void boki(int a);
	void setBoki();
	void getBoki();
	Figura operator+(const Figura &tab)const;
	Figura operator-(const Figura &tab)const;

};


