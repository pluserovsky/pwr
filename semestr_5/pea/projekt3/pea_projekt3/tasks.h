#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class tasks
{
private:
	int _time, _weight, _date,_id;
public:
	tasks();
	~tasks();
	void add(int time, int weight, int date);
	void print();

	int getTime();
	int getWeight();
	int getDate();
};
