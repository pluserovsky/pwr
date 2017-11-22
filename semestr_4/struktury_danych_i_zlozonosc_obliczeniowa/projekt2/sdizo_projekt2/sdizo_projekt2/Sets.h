#pragma once
#include "Queue.h"
struct WierzcholekSetu
{
	int reprezentant, ranga;
};

class Sety
{
private:
	WierzcholekSetu * Z;
public:
	Sety(int n);
	~Sety();
	Sety();
	void tworzSet(int poczatekKrawedzi);
	int znajdzSet(int poczatekKrawedzi);
	void laczSety(KrawedzKolejki e);
};

