#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "RBT.h"

using namespace std;



RBT::RBT()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	guard.color = 'B';          // Inicjujemy stra�nika
	guard.p = &guard;
	guard.left = &guard;
	guard.right = &guard;
	root = &guard;           // Korze� wskazuje stra�nika
}


bool RBT::loadFromFile(string FileName)
{
	ifstream plik;
	int buff, i = 1;
	plik.open(FileName.c_str());

	if (!plik.good()) return 0;
	
	else if (plik.good())
	{
		descRBT(root);
		guard.color = 'B';          // Inicjujemy stra�nika
		guard.p = &guard;
		guard.left = &guard;
		guard.right = &guard;
		root = &guard;           // Korze� wskazuje stra�nika
		plik >> cnt;

		for (i; i <= cnt; i++)
		{
			plik >> buff;
			addValue(buff);
		}
		plik.close();
	}
	return 1;
}

void RBT::descRBT(RBTNode * p)
{
	if (p != &guard)
	{
		descRBT((*p).left);   // usuwamy lewe poddrzewo
		descRBT((*p).right);  // usuwamy prawe poddrzewo
		delete p;              // usuwamy sam w�ze�
	}
}
void RBT::generate(int size)
{
	cnt = size;
	int buff;
	// Inicjujemy stra�nika
	guard.color = 'B';
	guard.p = &guard;
	guard.left = &guard;
	guard.right = &guard;
	root = &guard;
	for (int i = 0; i < cnt; i++) {

		buff = (rand() % RAND_MAX) - RAND_MAX / 2;
		addValue(buff);
	}
}


void RBT::printRBT(string sp, string sn, RBTNode * p)
{
	string t;

	if (p != &guard)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		printRBT(t + cp, cr, (*p).right);

		t = t.substr(0, sp.length() - 2);
		cout << t << sn << (*p).color << ":" << (*p).value << endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		printRBT(t + cp, cl, (*p).left);
	}
}

void RBT::display()
{
	printRBT("", "", root);
}

RBTNode * RBT::IsValueIn(int value)
{
	RBTNode * temp;
	//zaczyna od korzenia
	temp = root;
	//dop�ki istnieje drzewo lub nie znajdzie warto�ci
	while ((temp != &guard) && ((*temp).value != value))
		//je�li szukana jest mniejsza to przechodzi w lew� ga���
		if (value < (*temp).value) temp = (*temp).left;
	//jesli wieksza w praw� ga���
		else temp = (*temp).right;
		if (temp == &guard) return NULL;
		return temp;
}


RBTNode * RBT::minRBT(RBTNode * node)
{
	//funkcja idzie ca�y czas w lewo do ko�ca
	if (node != &guard)
		while ((*node).left != &guard) node = (*node).left;
	return node;
}

RBTNode * RBT::succ(RBTNode * node)
{
	RBTNode * temp;
	//dop�ki istenieje drzewo
	if (node != &guard)
	{
		//je�li prawy korze� ma li�cie, we� minRBT z prawego poddrzewa
		if ((*node).right != &guard) return minRBT((*node).right);
		else
		{
			//w przeciwnym razie id� w drug� stron�
			node = (*node).p;
			while ((node != &guard) && (node == (*node).right))
			{
				node = node;
				node = (*node).p;
			}
			return node;
		}
	}
	return &guard;
}

void RBT::rotateL(RBTNode * node)
{
	RBTNode * B, *temp;
	//B to wska�nik na prawego potmoka
	B = (*node).right;
	if (B != &guard)
	{
		//temp przyjmuje wska�nik na ojca
		temp = (*node).p;
		//przepnij prawego potomka do lewego poddrzewa
		(*node).right = (*B).left;
		//jesli to nie koniec, to wez rodzica prawego potomka
		if ((*node).right != &guard) (*(*node).right).p = node;
		//zamien je miesjcami
		(*B).left = node;
		(*B).p = temp;
		(*node).p = B;
		
		if (temp != &guard)
		{
			if ((*temp).left == node) (*temp).left = B;
			else (*temp).right = B;
		}
		else root = B;
	}
}

void RBT::rotateR(RBTNode * node)
{
	RBTNode * B, *temp;
	//B to wska�nik na lewego potmoka
	B = (*node).left;
	if (B != &guard)
	{
		//temp przyjmuje wska�nik na ojca
		temp = (*node).p;
		//przepnij prawego potomka do lewego poddrzewa
		(*node).left = (*B).right;
		//jesli to nie koniec, to wez rodzica prawego potomka
		if ((*node).left != &guard) (*(*node).left).p = node;
		//zamien je miesjcami
		(*B).right = node;
		(*B).p = temp;
		(*node).p = B;

		if (temp != &guard)
		{
			if ((*temp).left == node) (*temp).left = B;
			else (*temp).right = B;
		}
		else root = B;
	}
}

void RBT::addValue(int value)
{
	RBTNode *newNode,
		*node; //wujek

	newNode = new RBTNode;        // Tworzymy nowy w�ze�
	(*newNode).left = &guard;          // Inicjujemy pola
	(*newNode).right = &guard;
	(*newNode).p = root;
	(*newNode).value = value;
	//jesli drzewo jest puste
	if ((*newNode).p == &guard) root = newNode; // newNode staje si� korzeniem
	else
		while (true)             // Szukamy li�cia do zast�pienia przez newNode
		{
			//sprawdzanie warunkow, por�wnywanie kluczy
			if (value < (*(*newNode).p).value)
			{
				//je�li lewy syn nie istnieje(jest nim stra�nik), to
				// nowy w�ze� staje si� lewyn synem
				if ((*(*newNode).p).left == &guard)
				{
					(*(*newNode).p).left = newNode;  
					break;
				}
				(*newNode).p = (*(*newNode).p).left;
			}
			else
			{
				//je�li prawy syn nie istnieje(jest nim stra�nik), to
				// nowy w�ze� staje si� prawym synem
				if ((*(*newNode).p).right == &guard)
				{
					(*(*newNode).p).right = newNode; 
					break;
				}
				(*newNode).p = (*(*newNode).p).right;
			}
		}
	(*newNode).color = 'R';         // W�ze� kolorujemy na czerwono
	//w p�tli sprawdzamy kolejne przypadki
	while ((newNode != root) && ((*(*newNode).p).color == 'R'))
	{
		//skok do przypadk�w lustrzanych
		if ((*newNode).p == (*(*(*newNode).p).p).left)
		{
			//nodeToDel wskazuje wujka wez�a newNode
			node = (*(*(*newNode).p).p).right; 
			// je�li w�ze� jest czerowny
			if ((*node).color == 'R')  
			{
				//ojca kolorujemy na czarno
				(*(*newNode).p).color = 'B';
				//wujka kolorujemy na czarno
				(*node).color = 'B';
				//dziadka kolorujemy na czerwono
				(*(*(*newNode).p).p).color = 'R';
				//za nowy element przyjmujemy dziadka
				newNode = (*(*newNode).p).p;
				continue;
			}
			// sprawdzamy przypadek, gdy wujek czarny, a nowy element to prawy syn
			if (newNode == (*(*newNode).p).right) 
			{
				//nowy element staje sie swoim ojcem
				newNode = (*newNode).p;
				//wykonujemy rotacj� w lewo, newNOde przechodzi do lewego syna
				rotateL(newNode);
			}
			//wujek czarny, a nowy element to lewy syn
			(*(*newNode).p).color = 'B'; 
			//zmieniamy kolory ojca i dziadka
			(*(*(*newNode).p).p).color = 'R';
			//wykonujemy rotacj� w prawo wzgl�dem dziadka
			rotateR((*(*newNode).p).p);
			break;
		}
		else
		{                  // Przypadki lustrzane
			node = (*(*(*newNode).p).p).left;

			if ((*node).color == 'R') //  je�li w�ze� jest czerowny
			{
				(*(*newNode).p).color = 'B';
				(*node).color = 'B';
				(*(*(*newNode).p).p).color = 'R';
				newNode = (*(*newNode).p).p;
				continue;
			}
			// sprawdzamy przypadek, gdy wujek czarny, a nowy element to lewy syn
			if (newNode == (*(*newNode).p).left) 
			{
				newNode = (*newNode).p;
				rotateR(newNode);
			}
			//wujek czarny, a nowy element to prawy syn
			(*(*newNode).p).color = 'B'; 
			(*(*(*newNode).p).p).color = 'R';
			rotateL((*(*newNode).p).p);
			break;
		}
	}
	(*root).color = 'B';
}

void RBT::deleteValue(int value)
{
	RBTNode *nodeToDel = IsValueIn(value);

	if (nodeToDel != NULL) {

		RBTNode * W, *Y, *Z;
		//Y jest usuwanym w�z�em, jest to albo X, 
		if (((*nodeToDel).left == &guard) || ((*nodeToDel).right == &guard)) Y = nodeToDel;
		// albo jego nast�pnik
		else Y = succ(nodeToDel);
		//Z jest lewym lub prawym synem usuwanego elementu
		if ((*Y).left != &guard) Z = (*Y).left;
		else Z = (*Y).right;
		//Ojcem Z b�dzie ojciec Y
		(*Z).p = (*Y).p;
		//Sprawdzamy, czy usuwany w�ze� jest korzeniem
		if ((*Y).p == &guard) root = Z; //Je�li tak, to nowym korzeniem b�dzie jego syn
		//Przechodzimy do poprawiania struktury drzewa
		else if (Y == (*(*Y).p).left) (*(*Y).p).left = Z;
		//Z zast�puje Y w strukturze drzewa
		else (*(*Y).p).right = Z;
		//Je�li X nie jest usuwanym w�z�em, to przenosimy klucze z Y do X
		if (Y != nodeToDel) (*nodeToDel).value = (*Y).value;
		// Dokonujemy poprawy struktury drzewa czerwono-czarnego
		if ((*Y).color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
			while ((Z != root) && ((*Z).color == 'B'))
				if (Z == (*(*Z).p).left)
				{
					W = (*(*Z).p).right;

					if ((*W).color == 'R')
					{              //jesli weze� do usuniecia jest czerwony
						(*W).color = 'B';
						(*(*Z).p).color = 'R';
						rotateL((*Z).p);
						W = (*(*Z).p).right;
					}

					if (((*(*W).left).color == 'B') && ((*(*W).right).color == 'B'))
					{              // jesli potomkowie s� czarni
						(*W).color = 'R';
						Z = (*Z).p;
						continue;
					}

					if ((*(*W).right).color == 'B')
					{              // jesli prawy potomek jest czarny
						(*(*W).left).color = 'B';
						(*W).color = 'R';
						rotateR(W);
						W = (*(*Z).p).right;
					}

					(*W).color = (*(*Z).p).color; // jesli wezel do usuniecia ma ten sam kolor co rodzic
					(*(*Z).p).color = 'B';
					(*(*W).right).color = 'B';
					rotateL((*Z).p);
					Z = root;         // To spowoduje zako�czenie p�tli
				}
				else
				{                // Przypadki lustrzane
					W = (*(*Z).p).left;

					if ((*W).color == 'R')
					{              // jesli weze� do usuni�cia jest czerwony
						(*W).color = 'B';
						(*(*Z).p).color = 'R';
						rotateR((*Z).p);
						W = (*(*Z).p).left;
					}

					if (((*(*W).left).color == 'B') && ((*(*W).right).color == 'B'))
					{              // je�li potomkowie s� czarni
						(*W).color = 'R';
						Z = (*Z).p;
						continue;
					}

					if ((*(*W).left).color == 'B')
					{              // jesli lewy potomek jest czarny
						(*(*W).right).color = 'B';
						(*W).color = 'R';
						rotateL(W);
						W = (*(*Z).p).left;
					}

					(*W).color = (*(*Z).p).color;  // jesli wezel do usuniecia ma ten sam kolor co rodzic
					(*(*Z).p).color = 'B';
					(*(*W).left).color = 'B';
					rotateR((*Z).p);
					Z = root;         // To spowoduje zako�czenie p�tli
				}

		(*Z).color = 'B';
		//Je�li usuwany w�ze� jest czerwony, to ko�czymy
		delete Y;
	}
	else cout << "W drzewie nie ma takiego elementu.";
}

void RBT::tests(int cnt, string FileName)
{
}
