#include "BST.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

bool BST::loadFromFile(string FileName)
{
	int buff;
	ifstream plik;

	plik.open(FileName.c_str());
	if (!plik.good()) return 0;

	else if (plik.good())
	{
		plik >> cnt;


		for (int i = 0; i < cnt; i++)
		{
			plik >> buff;
			addValue(buff);
		}
		plik.close();
	}
	return true;
}

bool BST::IsValueIn(int val)
{
	//funkcja iterujaæ po wêz³ach sprawdza po kolei ka¿dy element
	//korzystaj¹c z tymczasowego elmentu
	BSTNode *temp = root;
	while ((temp))
	{
		if ((*temp).value == val)
		{
			return 1;
			delete temp;
		}
		if (val < (*temp).value) temp = (*temp).left;
		else temp = (*temp).right;
	}
	delete temp;
	return 0;
}

void BST::addValue(int val)
{
	/*
	BSTNode *temp = root,
		*y; //wskaznik na rodzica wêz³a
	BSTNode *node = new BSTNode();
	y = (*node).left = (*node).right = NULL;
	(*node).value = val;
	while (temp)
		{ //dla takich samych kluczy funkcja usuwa nowy
			if ((*node).value == (*temp).value)
			{
				delete node;
			}
			y = temp;
			//zgodnie z regu³¹ drzewa BST - po lewej mniejsze, po prawej wiêksze
			if ((*node).value < (*temp).value) temp = (*temp).left;
			else temp = (*temp).right;
		}
		(*node).p = y;
		if (!y) root = node;
		else if ((*node).value < (*y).value) (*y).left = node;
		else  (*y).right = node;
		cnt++;
		*/
	BSTNode * y, *x = root;
	BSTNode *n = new BSTNode();
	(*n).value = val;
	y = n->left = n->right = NULL;

	while (x)
	{
		if (n->value == x->value)
		{
			delete n;
			
		}
		y = x;
		x = (n->value < x->value) ? x->left : x->right;
	}

	n->p = y;

	if (!y) root = n;
	else if (n->value < y->value) y->left = n;
	else                     y->right = n;

	cnt++;
	
}


void BST::deleteValue(int val)
{
	BSTNode *temp = root;
	while ((temp))
	{
		if ((*temp).value == val)
		{
			remove(temp);
		}
		if (val < (*temp).value) temp = (*temp).left;
		else temp = (*temp).right;
	}
	remove(temp);
}

BSTNode * BST::pred(BSTNode * x)//zwraca wêze³ poprzednika
{
	if (x->left) {
		while (x->right) x = x->right;
		return x;
	}
	BSTNode * y;

	do
	{
		y = x;
		x = x->p;
	} while (x && (x->right != y));

	return x;
}
BSTNode * BST::succ(BSTNode * x)//zwraca wêze³ nastêpnika
{
	if (x->right) {
		while (x->left) x = x->left;
		return x;
	}
	BSTNode * y;

	do
	{
		y = x;
		x = x->p;
	} while (x && (x->left != y));

	return x;
}
BSTNode * BST::remove(BSTNode * x)
{
	BSTNode * y = x->p, *z;

	if ((x->left) && (x->right))
	{
		z = (rand() % 2) ? remove(pred(x)) : remove(succ(x));
		z->left = x->left;   if (z->left)  z->left->p = z;
		z->right = x->right; if (z->right) z->right->p = z;
		cnt++;
	}
	else z = (x->left) ? x->left : x->right;

	if (z) z->p = y;

	if (!y) root = z;
	else if (y->left == x) y->left = z; else y->right = z;

	cnt--;
	return x;
}


void BST::inorder(BSTNode * root)
{

	if (root)
	{
		inorder(root->left);
		cout << root->value << endl;  // tutaj przetwarzamy bie¿¹cy wêze³
		inorder(root->right);
	}
}

void BST::display()
{
	inorder(root);
}

void BST::generate(int size)
{
	int buff;
	for (int i = 0; i < cnt; i++) {

		buff = (rand() % RAND_MAX) - RAND_MAX / 2;
		addValue(size);
	}
}

void BST::tests(int cnt, string FileName)
{
}


