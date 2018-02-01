#pragma once
#include <string>
using namespace std;

// klasa pojedynczego elementu listy
class BSTNode
{
public:
	BSTNode *p, //rodzic w�z�a
		*left, //lewy potomek (mniejszy)
		*right; //prawy potomek wi�kszy
	int value; //wartosc

};

class BST
{
private:
	BSTNode *root, //korze� drzewa
		*temp;
	int cnt; // liczna w�z��w

public:

	bool loadFromFile(string FileName);

	bool IsValueIn(int val);

	void addValue(int value);

	void deleteValue(int value);

	BSTNode * pred(BSTNode * x); //zwraca poprzednika

	BSTNode * succ(BSTNode * x); //zwraca nast�pnika

	BSTNode * BST::remove(BSTNode * x);

	void BST::inorder(BSTNode * x);


	void display();

	void generate(int cnt);

	void tests(int cnt, string FileName);

	int setCnt(int cnt) {
		return this->cnt = cnt;
	}
	int getCnt() {
		return cnt;
	}

};
