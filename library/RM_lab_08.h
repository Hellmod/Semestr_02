#ifndef RM_LAB_08_H
#define RM_LAB_08_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

//-------------------------------------------------------
bool f_algorytm_3(int waga, int *t, int ile, int suma, int a, bool* &wynik);
// algorytm
bool f_algorytm_2(int waga, int *t, int ile, int suma, int a, bool* &wynik);
// algorytm
void f_algorytm_1(ofstream &plik, int waga, int *t, int ile);



#endif
#pragma once
