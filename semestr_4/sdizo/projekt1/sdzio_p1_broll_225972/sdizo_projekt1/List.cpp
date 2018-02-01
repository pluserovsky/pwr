#include "List.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

bool List::loadFromFile(string FileName)
{
	ifstream plik;
	int size;
	plik.open(FileName.c_str());
	if (!plik.good());

	else if (plik.good())
	{
		head = NULL;
		tail = NULL;
		plik >> size;
		cnt = size;
		for (int i = 0; i < size; i++)
		{
			plik >> buff;
			addLast(buff);
		}
		plik.close();
		return true;
	}
	return false;
}

bool List::IsValueIn(int val)
{
	//funkcja iterujać po liście sprawdza po kolei każdy element
	//korzystając z tymczasowego elmentu
	ListsCell *temp;
	temp = head;
	//dopóki istnieją elmenty
	if (!head) {
		return true;
	}
	for (int i = 0; i < cnt; i++)
	{
		if ((*temp).value == val)
		{
			//jeśli znajdzie wartość usunie temp i zwróci true
			return true;
		}
		//iterator listy
		if (!(*temp).next) return false;
		temp = (*temp).next;
	}
	return false;

}
void List::addValue(int val, int index) {
	{
		ListsCell *temp;
		ListsCell  *cell = new ListsCell();
		temp = head;
		if (!head) {
			(*cell).value = val;
			(*cell).prev = NULL;
			(*cell).next = NULL;
			head = cell;
			tail = cell;
		}
		else {
			int i = 0;
			while (i != index && (*temp).next) {
				i++;
				temp = (*temp).next;
			}
			if (!(*temp).next) addLast(val);
			else if (temp!=head || temp!=tail) {
				//nowy element przejmuje nastepny starego
				(*cell).next = temp;
				//nowy element wskazuje na poprzedni
				(*cell).prev = (*temp).prev;
				//poprzedni wskazuje na nowy
				(*temp).prev = cell;
				//wskaznik starego na poprzedni wskazuje na nowy, jesli istnieje
				if ((*cell).prev) (*(*cell).prev).next = cell;
				else head = cell;
				(*cell).value = val;
				cnt++;
			}	
		}
	}
}
/*
void List::addValue(int val, int index)
{
	ListsCell *temp;
	ListsCell  *cell = new ListsCell();
	temp = head;
	if (!head) {
		(*cell).value = val;
		(*cell).prev = NULL;
		(*cell).next = NULL;
		head = cell;
		tail = cell;
	}
	else {
		for (int i = 0; i < cnt; i++) {
			//gdy znajdzie element

			if ((*temp).value == index) {
				//nowy element przejmuje nastepny starego
				(*cell).next =temp;
				//nowy element wskazuje na poprzedni
				(*cell).prev = (*temp).prev;
				//poprzedni wskazuje na nowy

				(*temp).prev = cell;
				//wskaznik starego na poprzedni wskazuje na nowy, jesli istnieje
				if ((*cell).prev) (*(*cell).prev).next = cell;
				else head = cell;
				(*cell).value = val;
				cnt++;
				break;

			}
			else temp = (*temp).next;
		}
	}

}
*/
void List::addLast(int val)
{
	ListsCell *cell = new ListsCell();
	// nowy element staje się końcem
	(*cell).prev = tail;
	(*cell).next = NULL;
	// stary ogon musi wskazywać na nowy
	if (tail) (*tail).next = cell;
	//nowy element staje sie ogonem
	tail = cell;
	//jeśli to pierwszy element w liście, to staje się też głową
	if (!head) head = tail;
	(*cell).value = val;
	cnt++;
}

void List::addFirst(int val)
{
	ListsCell *cell = new ListsCell();
	//pierwszy element nie ma poprzednika
	(*cell).prev = NULL;
	//nowy element wskazuje na ten, który do tej pory był pierwszy
	(*cell).next = head;
	// stara 'głowa' wskazuje jako poprzednika nowy elemnent
	if (head) (*head).prev = cell;
	head = cell;

	//jeśli to jedyny element, to głowa jest też końcem
	if (!tail) tail = head;
	(*cell).value = val;
	cnt++;
}

void List::deleteValue(int val)
{
	ListsCell *temp;
	temp = head;
	for (int i = 0; i < cnt; i++) {

		if ((*temp).value == val) {
			//pominięcie elementu usuwanego jesli jest w środku listy
			if ((*temp).next && (*temp).prev)
			{
				//zlaczenie poprzednika i nastepnia usuwanego elementu
				(*(*temp).next).prev = (*temp).prev;
				(*(*temp).prev).next = (*temp).next;
				cnt--;
				delete temp;
				break;
			}
			// jesli to ogon to usuniecie ostatniego elmentu
			else if (!(*temp).next)
			{
				deleteLast();
				break;
			}
			//jeśli głowa to odcięcie głowy
			else if (!(*temp).prev)
			{
				deleteFirst();
				break;
			}
		}
		else temp = (*temp).next;
	}
}
void List::deleteLast()
{
	if (cnt == 0) cout << "Lista jest pusta. " << endl;
	else if (!(*tail).prev) {
		delete tail;
		tail = NULL;
		head = NULL;
		cnt--;
	}
	else
	{
		//przesunięcie wskaźnika *tail na element poprzedni
		tail = (*tail).prev;
		delete (*tail).next;
		(*tail).next = NULL;
		cnt--;
	}
}

void List::deleteFirst()
{
	if (cnt == 0) cout << "Lista jest pusta. " << endl;
	else if (!(*head).next) {
		delete head;
		tail = NULL;
		head = NULL;
		cnt--;
	}
	else
	{
		//przesunięcie wskaźnika *head na następny element
		head = (*head).next;
		delete (*head).prev;
		(*head).prev = NULL;
		cnt--;
	}
}

void List::display()
{
	ListsCell *temp = new ListsCell(); //tymczasowy element
	if (!head)	cout << "Lista jest pusta. " << endl;
	else
	{
		temp = head;
		cout << "Head - Tail:" << endl;
		for (int i = 0; i < cnt; i++)
		{
			if (temp) {
				cout << " " << (*temp).value;
				temp = (*temp).next;
			}// temp przyjmuje kolejne wartosci listy
			// iterujac po next i w petli je drukuje
		}
		cout << endl << "Tail - Head:" << endl;
		if (!tail) tail = head;
		temp = tail;
		for (int i = 0; i < cnt; i++)
		{
			if (temp) {
				cout << " " << (*temp).value;
				temp = (*temp).prev; // temp przyjmuje kolejne wartosci listy
			}			 // iterujac po prev i w petli je drukuje
		}
		cout << endl;
	}
}

void List::generate(int size)
{
	cnt = size;
	for (int i = 0; i < size; i++) {
		//losowanie wartości i wykonywanie dodania na początek
		buff = (rand() % RAND_MAX) - RAND_MAX / 2;
		addFirst(buff);
	}
}

void List::tests(int cnt, string FileName)
{

	fstream plik(FileName, ios::out);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
	}
	plik << cnt << "\n";
	for (int i = 0; i < cnt; i++)
	{
		plik << (rand() % RAND_MAX) - RAND_MAX / 2 << "\n";
		plik.flush();
	}
	plik.close();
}
void List::setCnt(int cnt) {
	this->cnt = cnt;
}
int List::getCnt() {
	return cnt;
}


