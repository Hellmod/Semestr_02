#ifndef RM_GRAF_H
#define RM_GRAF_H

#include <iostream>
#include <fstream>
#include <string>
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
//------------
// struktura opisujacaa przedmiot
struct przedmiot{
	string nazwa;
	int cena;
	int masa;
};
// funkcja zwraca tablice dwuwymiarowe p i q jako macierze najlepszych upakowan plecak o zadanej pojemnosci wedlug podanych przedmiotow
void f_algorytm(int masa, int ilosc_przedmiotow, przedmiot* obiekt, int** &p, int** &q);
// funkcja zapisuje do pliku rozwiazanie jako wypisanie macierzy p i q
void zapis_do_pliku(fstream &plik, int ilosc_wierszy, int ilosc_kolumn, int** p, int** q);
// funkcja tworzy tablice dwuwymiarowa o w wierszach i k kolumnach
int **f_utworz_tablice_2(int w, int k);