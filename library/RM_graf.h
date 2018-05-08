#ifndef RM_GRAF_H
#define RM_GRAF_H

#include <iostream>
#include <fstream>
using namespace std;

// struktura listy jednokierunkowej
struct elementy_listy{
	int liczba;
	elementy_listy  *next;
};
// algorytm tworzy liste incydencji oraz wyznacza stopien wierzcholkow w grafie nieskierowanym
void f_algorytm(fstream &plik);

#endif
#pragma once
