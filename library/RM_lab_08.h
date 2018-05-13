#ifndef RM_LAB_08_H
#define RM_LAB_08_H

#include <iostream>
#include <fstream>
#include <string>

#include "RM_table.h"
using namespace std;

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


#endif
#pragma once
