#ifndef RM_TABLE
#define RM_TABLE
#include <iostream>
#include <string>
//#include "stdafx.h"
using namespace std;


/*
funckja tesutj¹ca
*/
void f_test(int i);


/*
tworzy dwu wymiarow¹ tablicê

@param tab tablicza
@param x iloœæ wierszy tablicy
@param y iloœæ kolumn tablicy

@return dynamiczna tablica
*/
int **f_createTable(int wiersze, int kolumny);

int *f_createTable(int wiersze);

/*
czyta tablice

@param tab tablicza
@param x iloœæ wierszy tablicy
@param y iloœæ kolumn tablicy
*/
void f_readTetable(int **tab, int x, int y);

void f_readTetable(int *tab, int x);

void f_readTetable(string *tab, int x);

void f_readTetable(int ***tab, int x, int y, int z);

/*
Wczytuje dane do tablicy od urzytkownika

@param tab tablicza
@param x iloœæ wierszy tablicy
@param y iloœæ kolumn tablicy

@return tablica z danymi
*/
int **f_loadTable(int **tab, int x, int y);

/*
Zwraca sumê wszystkich elementów tablicy

@param tab talica
@param x iloœæ wierszy tablicy
@param y iloœæ kolumn tablicy

@retunr suma wszystkich elementów
*/
int f_sumaTab(int **tab, int x, int y);

/*
Wycina tablicê z tablicy, parametrem wejœcia s¹ adres komurki lewej dolnej i prawej górnej

@param tab tablica z której wycina czêœæ tablicy
@param i wiersz od której
@param j kolumna od której
@param x wiersz do której
@param y kolumna do której

@return tablica wyciêta z tablicy o_0
*/
int **f_cutTable(int **tab, int i, int j, int x, int y);

int f_szuajIndeksu(int *tab, int x, int liczba);

int f_ileNadInd(int *tab, int x, int liczba);
int f_ilePodInd(int *tab, int x, int liczba);
#endif