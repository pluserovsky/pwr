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
	RBTNode guard;             // stra¿nik (czarne liœcie)
	RBTNode * root;        // korzeñ
	string cr, cl, cp;       // obs³uga wyœwietlania
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
	// Wyszukuje wêze³  value
	RBTNode * IsValueIn(int value); 
	// Wyszukuje najmniejszy wêze³ w node
	RBTNode * minRBT(RBTNode * node); 
	void RBT::descRBT(RBTNode * node);
	// Wyszukuje nastêpnik node
	RBTNode * succ(RBTNode * node);
	// Rotacja w lewo wzglêdem node
	void rotateL(RBTNode * node); 
	// Rotacja w prawo wzglêdem node
	void rotateR(RBTNode * node); 
	// Wstawia wêze³  value
	void addValue(int value);   
	// Usuwa wêze³ node
	void deleteValue(int value); 
	void tests(int cnt, string FileName);

	int setCnt(int cnt) {
		return this->cnt = cnt;
	}
	int getCnt() {
		return cnt;
	}
};