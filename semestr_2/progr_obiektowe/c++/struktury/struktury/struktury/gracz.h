struct gracz
{
	char nazwa[30] = "Anoninek";
	char kierunek[30] = "Prawo";
	unsigned int wiek = 20;
	unsigned int zdrowie = 100;
	unsigned int wiedza = 10;
	unsigned int morale = 50;
	unsigned int etap = 0;	// 0-zapisy,1-studiowanie,2-todo
	unsigned int licz_impr = 0; //licznik dni imprez
	unsigned int licz_nauk = 0; //licznik dni nauki
	unsigned int licz_sen = 0; //licznik dni snu
	unsigned int licz_dni = 1; //licznik dni
	
};


// funkcje menu glownego
void wczytaj_gracza(gracz& zawodnik); //nadrzedna funkcja, decydujaca czy dodac nowego gracza czy wczytac istniejacy zapis
void nowy_gracz(gracz& zawodnik);// tworzenie nowego zapisu/nadpisywanie istniejacego
void wczytaj_zapis(gracz& zawodnik);// ladowanie zapisu z pliku zawodnik.dat
void menu_glowne(gracz& zawodnik);
void statystyki(gracz& zawodnik);
//funkcje story 
void licznik();// losowe odliczanie czasu
void story1(gracz& zawodnik);// etap gry zawierajacy tylko rekrutacje
void story2(gracz& zawodnik);// glowny etap z menu wyboru akcji podczas studiowania
void zapisy(gracz& zawodnik);// generator losoej akcji podczas zapisow
void menu_studenta(gracz& zawodnik);
void imprezujemy(gracz& zawodnik);
void nauka(gracz& zawodnik);
void sen(gracz& zawodnik);
void koniec(gracz& zawodnik);// menu przed wyjscie gry z zapisem
void autor();
