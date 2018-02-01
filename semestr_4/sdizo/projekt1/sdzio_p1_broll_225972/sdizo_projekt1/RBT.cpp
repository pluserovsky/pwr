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
	guard.color = 'B';          // Inicjujemy stra¿nika
	guard.p = &guard;
	guard.left = &guard;
	guard.right = &guard;
	root = &guard;           // Korzeñ wskazuje stra¿nika
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
		guard.color = 'B';          // Inicjujemy stra¿nika
		guard.p = &guard;
		guard.left = &guard;
		guard.right = &guard;
		root = &guard;           // Korzeñ wskazuje stra¿nika
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
		delete p;              // usuwamy sam wêze³
	}
}
void RBT::generate(int size)
{
	cnt = size;
	int buff;
	// Inicjujemy stra¿nika
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
	//dopóki istnieje drzewo lub nie znajdzie wartoœci
	while ((temp != &guard) && ((*temp).value != value))
		//jeœli szukana jest mniejsza to przechodzi w lew¹ ga³¹Ÿ
		if (value < (*temp).value) temp = (*temp).left;
	//jesli wieksza w praw¹ ga³¹Ÿ
		else temp = (*temp).right;
		if (temp == &guard) return NULL;
		return temp;
}


RBTNode * RBT::minRBT(RBTNode * node)
{
	//funkcja idzie ca³y czas w lewo do koñca
	if (node != &guard)
		while ((*node).left != &guard) node = (*node).left;
	return node;
}

RBTNode * RBT::succ(RBTNode * node)
{
	RBTNode * temp;
	//dopóki istenieje drzewo
	if (node != &guard)
	{
		//jeœli prawy korzeñ ma liœcie, weŸ minRBT z prawego poddrzewa
		if ((*node).right != &guard) return minRBT((*node).right);
		else
		{
			//w przeciwnym razie idŸ w drug¹ stronê
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
	//B to wskaŸnik na prawego potmoka
	B = (*node).right;
	if (B != &guard)
	{
		//temp przyjmuje wskaŸnik na ojca
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
	//B to wskaŸnik na lewego potmoka
	B = (*node).left;
	if (B != &guard)
	{
		//temp przyjmuje wskaŸnik na ojca
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

	newNode = new RBTNode;        // Tworzymy nowy wêze³
	(*newNode).left = &guard;          // Inicjujemy pola
	(*newNode).right = &guard;
	(*newNode).p = root;
	(*newNode).value = value;
	//jesli drzewo jest puste
	if ((*newNode).p == &guard) root = newNode; // newNode staje siê korzeniem
	else
		while (true)             // Szukamy liœcia do zast¹pienia przez newNode
		{
			//sprawdzanie warunkow, porównywanie kluczy
			if (value < (*(*newNode).p).value)
			{
				//jeœli lewy syn nie istnieje(jest nim stra¿nik), to
				// nowy wêze³ staje siê lewyn synem
				if ((*(*newNode).p).left == &guard)
				{
					(*(*newNode).p).left = newNode;  
					break;
				}
				(*newNode).p = (*(*newNode).p).left;
			}
			else
			{
				//jeœli prawy syn nie istnieje(jest nim stra¿nik), to
				// nowy wêze³ staje siê prawym synem
				if ((*(*newNode).p).right == &guard)
				{
					(*(*newNode).p).right = newNode; 
					break;
				}
				(*newNode).p = (*(*newNode).p).right;
			}
		}
	(*newNode).color = 'R';         // Wêze³ kolorujemy na czerwono
	//w pêtli sprawdzamy kolejne przypadki
	while ((newNode != root) && ((*(*newNode).p).color == 'R'))
	{
		//skok do przypadków lustrzanych
		if ((*newNode).p == (*(*(*newNode).p).p).left)
		{
			//nodeToDel wskazuje wujka wez³a newNode
			node = (*(*(*newNode).p).p).right; 
			// jeœli wêze³ jest czerowny
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
				//wykonujemy rotacjê w lewo, newNOde przechodzi do lewego syna
				rotateL(newNode);
			}
			//wujek czarny, a nowy element to lewy syn
			(*(*newNode).p).color = 'B'; 
			//zmieniamy kolory ojca i dziadka
			(*(*(*newNode).p).p).color = 'R';
			//wykonujemy rotacjê w prawo wzglêdem dziadka
			rotateR((*(*newNode).p).p);
			break;
		}
		else
		{                  // Przypadki lustrzane
			node = (*(*(*newNode).p).p).left;

			if ((*node).color == 'R') //  jeœli wêze³ jest czerowny
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
		//Y jest usuwanym wêz³em, jest to albo X, 
		if (((*nodeToDel).left == &guard) || ((*nodeToDel).right == &guard)) Y = nodeToDel;
		// albo jego nastêpnik
		else Y = succ(nodeToDel);
		//Z jest lewym lub prawym synem usuwanego elementu
		if ((*Y).left != &guard) Z = (*Y).left;
		else Z = (*Y).right;
		//Ojcem Z bêdzie ojciec Y
		(*Z).p = (*Y).p;
		//Sprawdzamy, czy usuwany wêze³ jest korzeniem
		if ((*Y).p == &guard) root = Z; //Jeœli tak, to nowym korzeniem bêdzie jego syn
		//Przechodzimy do poprawiania struktury drzewa
		else if (Y == (*(*Y).p).left) (*(*Y).p).left = Z;
		//Z zastêpuje Y w strukturze drzewa
		else (*(*Y).p).right = Z;
		//Jeœli X nie jest usuwanym wêz³em, to przenosimy klucze z Y do X
		if (Y != nodeToDel) (*nodeToDel).value = (*Y).value;
		// Dokonujemy poprawy struktury drzewa czerwono-czarnego
		if ((*Y).color == 'B')   // Naprawa struktury drzewa czerwono-czarnego
			while ((Z != root) && ((*Z).color == 'B'))
				if (Z == (*(*Z).p).left)
				{
					W = (*(*Z).p).right;

					if ((*W).color == 'R')
					{              //jesli weze³ do usuniecia jest czerwony
						(*W).color = 'B';
						(*(*Z).p).color = 'R';
						rotateL((*Z).p);
						W = (*(*Z).p).right;
					}

					if (((*(*W).left).color == 'B') && ((*(*W).right).color == 'B'))
					{              // jesli potomkowie s¹ czarni
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
					Z = root;         // To spowoduje zakoñczenie pêtli
				}
				else
				{                // Przypadki lustrzane
					W = (*(*Z).p).left;

					if ((*W).color == 'R')
					{              // jesli weze³ do usuniêcia jest czerwony
						(*W).color = 'B';
						(*(*Z).p).color = 'R';
						rotateR((*Z).p);
						W = (*(*Z).p).left;
					}

					if (((*(*W).left).color == 'B') && ((*(*W).right).color == 'B'))
					{              // jeœli potomkowie s¹ czarni
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
					Z = root;         // To spowoduje zakoñczenie pêtli
				}

		(*Z).color = 'B';
		//Jeœli usuwany wêze³ jest czerwony, to koñczymy
		delete Y;
	}
	else cout << "W drzewie nie ma takiego elementu.";
}

void RBT::tests(int cnt, string FileName)
{
}
