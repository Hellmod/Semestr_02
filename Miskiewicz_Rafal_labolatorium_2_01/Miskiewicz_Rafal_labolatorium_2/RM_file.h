#ifndef RM_FILE
#define RM_FILE
#include "stdafx.h"
#include "string"
#include "fstream"
#include "iostream"

//#include "cstdlib"
//#include "string"
using namespace std;


int ***wczytaj(string nazwa);

fstream f_otworzPlik(string nazwa);
fstream f_otworzPlikZapis(string nazwa);

int *f_wczytajTablice(std::fstream & plik, int liczbaWierszy);

#endif