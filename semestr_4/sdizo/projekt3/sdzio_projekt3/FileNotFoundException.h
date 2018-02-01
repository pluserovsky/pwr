#pragma once
#include <iostream>
#include <exception>
#include <typeinfo>

/*Klasa wyj�tku.
Wyj�tek ten jest wyrzucany, je�li nie zostanie odnaleziony plik, z kt�rego mia�y by� odczytane dane do struktury.*/
class FileNotFoundException : std::runtime_error
{
public:
	FileNotFoundException(const char* msg) : std::runtime_error(msg) {

	};
	~FileNotFoundException() {};

	virtual const char* what() const throw();
};
