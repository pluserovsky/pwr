#include "tasks.h"


tasks::tasks()
{
}
tasks::~tasks()
{
}

void tasks::add(int czas, int waga, int termin)
{
	_time = czas;
	_weight = waga;
	_date = termin;
}

void tasks::print()
{
	cout << " Czas:" << _time << " Waga:" << _weight << " Termin:" << _date << endl;
}

int tasks::getTime()
{
	return _time;
}

int tasks::getWeight()
{
	return _weight;
}

int tasks::getDate()
{
	return _date;
}

