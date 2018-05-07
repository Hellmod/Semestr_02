
#include "RM_file.h"
#include "RM_lib.h"
#include "RM_table.h"
using namespace std;

/*
int ***wczytaj(string nazwa){
fstream plik;
int liczba, iloscIteracji, liczbaDanych, liczbaWyszukan, ***tab;
tab = new int **[2];
nazwa += ".txt";
plik.open(nazwa, ios::in);
if(plik.good() == true){
plik >> iloscIteracji;
tab[0] = new int*[iloscIteracji];
for(int i = 0; i < iloscIteracji; i++){
plik >> liczbaDanych;
tab[i][0] = new int[liczbaDanych];
for(int j = 0; j < liczbaDanych; j++)
plik >> tab[i][0][j];

plik >> liczbaWyszukan;
tab[i][1] = new int[liczbaWyszukan];
for(int j = 0; j < liczbaWyszukan; j++)
plik >> tab[i][1][j];

}
plik.close();
}
else{
cout << PL("B³¹d przy odczytywaniu pliku") << endl;
}

f_readTetable(tab, 0,1, 11);
return nullptr;
}
*/
fstream f_otworzPlik(string nazwa){
	fstream plik;
	nazwa += ".txt";
	plik.open(nazwa, ios::in);
	if(plik.good() == true){
		return plik;
	}
	else{
		cout << PL("Nie uda³o siê otworzyæ pliku ") <<nazwa<< endl;
		system("pause");
		exit(0);
	}
}

fstream f_otworzPlikZapis(string nazwa){
	fstream plik;
	nazwa += ".txt";
	plik.open(nazwa, ios::out);
	if(plik.good() == true){
		return plik;
	}
	else{
		cout << PL("Nie uda³o siê otworzyæ pliku") << endl;
		exit(0);
	}
}

int *f_wczytajTablice(std::fstream & plik, int liczbaWierszy){
	int * tab = new int[liczbaWierszy];
	for(int i = 0; i <= liczbaWierszy; i++){
		plik >> tab[i];
	}
	return tab;
}

bool * f_zapiszTablice(std::fstream & plik, string * tab, int liczbaWierszy){
	for(size_t i = 0; i < liczbaWierszy; i++){
		plik << tab[i] << endl;
	}

	return nullptr;//TODO dodaæ sprawdzenie zapisu
}


// ToAsk czemu nie dzia³a b³¹d przy wywo³aniu "type name is not allowed template" 
//f_zapiszTablice<int>(plik, f_LMK(max), max);



