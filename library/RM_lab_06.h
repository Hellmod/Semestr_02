#ifndef RM_LAB_06_H
#define RM_LAB_06_H

#include <iostream>
#include <fstream>
#include <random>
#include <math.h>
#include <vector>

#include "RM_file.h"
using namespace std;


// algorytm zliczajacy liczbe inwersji tablicy zawierajacej zestaw liczb
int f_algorytm(int *t, int ilosc_liczb);



// Liniowa Metoda Kongruencyjna
int *f_LMK(int max);
// Addytywna Metoda Kongruencyjna
int *f_AMK(int max);
// Metoda Tasowania z Jedna sekwencja losowa
int *f_MT(int max);
// Najwiekszy Wspolny Dzielnik liczb a i b
int f_NWD(int a, int b);
// funkcja wyszukaja najbardziej korzystne pary liczb potrzebne do funkcji f_AMK
int *f_pary_liczb_AMK(int n);


#endif
#pragma once
