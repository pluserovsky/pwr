#pragma once
#include<iostream>
#include <exception>
#include <typeinfo>
/*Klasa wyj�tku.
Wyj�tek ten jest wyrzucany, je�li szukany indeks jest poza rozmiarem struktury.*/
class IndexOutOfBoundsException : std::runtime_error
{
public:
	IndexOutOfBoundsException(const char* msg) : std::runtime_error(msg) {

	};
	~IndexOutOfBoundsException() {};

	virtual const char* what() const throw();
};

