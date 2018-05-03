#ifndef RM_TABLE
#define RM_TABLE
#include <iostream>
#include <string>
//#include "stdafx.h"
using namespace std;


/*
funckja tesutj�ca
*/
void f_test(int i);


/*
tworzy dwu wymiarow� tablic�

@param tab tablicza
@param x ilo�� wierszy tablicy
@param y ilo�� kolumn tablicy

@return dynamiczna tablica
*/
int **f_createTable(int wiersze, int kolumny);

int *f_createTable(int wiersze);

/*
czyta tablice

@param tab tablicza
@param x ilo�� wierszy tablicy
@param y ilo�� kolumn tablicy
*/
void f_readTetable(int **tab, int x, int y);

void f_readTetable(int *tab, int x);

void f_readTetable(string *tab, int x);

void f_readTetable(int ***tab, int x, int y, int z);

/*
Wczytuje dane do tablicy od urzytkownika

@param tab tablicza
@param x ilo�� wierszy tablicy
@param y ilo�� kolumn tablicy

@return tablica z danymi
*/
int **f_loadTable(int **tab, int x, int y);

/*
Zwraca sum� wszystkich element�w tablicy

@param tab talica
@param x ilo�� wierszy tablicy
@param y ilo�� kolumn tablicy

@retunr suma wszystkich element�w
*/
int f_sumaTab(int **tab, int x, int y);

/*
Wycina tablic� z tablicy, parametrem wej�cia s� adres komurki lewej dolnej i prawej g�rnej

@param tab tablica z kt�rej wycina cz�� tablicy
@param i wiersz od kt�rej
@param j kolumna od kt�rej
@param x wiersz do kt�rej
@param y kolumna do kt�rej

@return tablica wyci�ta z tablicy o_0
*/
int **f_cutTable(int **tab, int i, int j, int x, int y);

int f_szuajIndeksu(int *tab, int x, int liczba);

int f_ileNadInd(int *tab, int x, int liczba);
int f_ilePodInd(int *tab, int x, int liczba);
#endif