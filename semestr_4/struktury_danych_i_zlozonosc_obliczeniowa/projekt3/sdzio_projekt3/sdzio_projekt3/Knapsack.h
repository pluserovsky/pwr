#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

#include "FileNotFoundException.h"
#include "RandKnapsackDataGen.h"

struct Item {
	unsigned int waga;
	unsigned int wartosc;
	double stosunek;
};
class Knapsack
{
private:

	class sackElement {
	public:
		Item it;
		sackElement* next;

		sackElement(Item _it) {
			it = _it;
			next = nullptr;
		}
		~sackElement() {
			if (this->next != nullptr) 
				delete next;

		}
	};
	
	unsigned int pojemnosc;
	int zapakowana_waga;
	int zapakowana_wartosc;
	
	sackElement* plecak;
	Item* przedmioty;
	int przedmioty_rozmiar;

	void quickSort(Item* tab, int left, int right);
	int partition(Item* tab, int left, int right);
	void packItem(Item _it);
public:
	Knapsack();
	Knapsack(int _capacity);
	~Knapsack();

	void loadItemsSet(std::string fileName);
	void loadItemsSet(Item* items, unsigned int n);
	
	bool greedy_pack();
	bool brute_force_pack();
	
	void printItemsSet();
	std::string toString();
	void saveToFile(std::string fileName);
	friend std::ostream & operator << (std::ostream & output, Knapsack & knapsack);

};

