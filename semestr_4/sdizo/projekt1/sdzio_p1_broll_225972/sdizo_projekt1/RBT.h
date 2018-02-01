#pragma once
#include <string>
using namespace std;
class RBTNode
{
public:
	RBTNode * p, //rodzic
		*left, //lewy
		*right,
		*temp; //prawy
	int value;
	char color;
};
class RBT
{
private:
	RBTNode guard;             // stra�nik (czarne li�cie)
	RBTNode * root;        // korze�
	string cr, cl, cp;       // obs�uga wy�wietlania
	int cnt;
	void printRBT(string sp, string sn, RBTNode * p); // Wypisuje drzewo

public:
	// Konstruktor klasy
	RBT();             
	bool loadFromFile(string FileName);
	void generate(int cnt);
	// Usuwa rekurencyjnie drzewo
	// Wypisuje drzewo
	void display();     
	// Wyszukuje w�ze�  value
	RBTNode * IsValueIn(int value); 
	// Wyszukuje najmniejszy w�ze� w node
	RBTNode * minRBT(RBTNode * node); 
	void RBT::descRBT(RBTNode * node);
	// Wyszukuje nast�pnik node
	RBTNode * succ(RBTNode * node);
	// Rotacja w lewo wzgl�dem node
	void rotateL(RBTNode * node); 
	// Rotacja w prawo wzgl�dem node
	void rotateR(RBTNode * node); 
	// Wstawia w�ze�  value
	void addValue(int value);   
	// Usuwa w�ze� node
	void deleteValue(int value); 
	void tests(int cnt, string FileName);

	int setCnt(int cnt) {
		return this->cnt = cnt;
	}
	int getCnt() {
		return cnt;
	}
};