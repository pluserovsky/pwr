#pragma once


class KomorkaListy {
public:
	KomorkaListy * nastepny;
	int koniecKrawedzi = 0, 
		wagaKrawedzi;
	KomorkaListy ** tablica;
	KomorkaListy *nowaKomorka, *usuwacz;
	KomorkaListy();

	~KomorkaListy();

};

