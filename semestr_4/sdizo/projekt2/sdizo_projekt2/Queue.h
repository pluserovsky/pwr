#pragma once

// Definicja obiektu kolejki priorytetowej
struct KrawedzKolejki
{
	int poczatekKrawedzi, koniecKrawedzi, wagaKrawedzi;  
};

class Kolejka
{
private:
	KrawedzKolejki * Kopiec;
	int pozycjaKopca;
public:
	Kolejka(int n);
	Kolejka();
	~Kolejka();
	KrawedzKolejki zwrocKorzen();
	void dodaj(KrawedzKolejki e);
	void zdejmij();
};