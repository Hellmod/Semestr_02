#ifndef RM_FILE
#define RM_FILE
//#include "stdafx.h"
#include "string"
#include "fstream"
#include "iostream"

//#include "cstdlib"
//#include "string"
using namespace std;


//int ***wczytaj(string nazwa);

fstream f_otworzPlik(string nazwa);
fstream f_otworzPlikZapis(string nazwa);

int *f_wczytajTablice(std::fstream & plik, int liczbaWierszy);

bool *f_zapiszTablice(std::fstream & plik, string *tab, int liczbaWierszy);

template<typename U>
bool * f_zapiszTablice(std::fstream & plik, U* tab, int liczbaWierszy){
	for(size_t i = 0; i < liczbaWierszy; i++){
		plik << tab[i] << endl;
	}

	return nullptr;//TODO dodaæ sprawdzenie zapisu
}

#endif