//zadanie 5.1
#include "..\..\library\RM_lab_06.h"
#include "..\..\library\RM_file.h"
using namespace std;

int main(){
	// *t->tablica zestawu danych, o rozmiarze[ilosc_liczb]
	int liczba_zestawow, ilosc_liczb, *t;
	// tworzenie obiektów: in-do odczytu z pliku; out->do zapisu do pliku
	fstream in;
	fstream out;
	in = f_otworzPlik("in");
	out = f_otworzPlikZapis("out");
	// wczytanie liczby zestawów
	in >> liczba_zestawow;
	for(int i = 0; i < liczba_zestawow; i++){
		// wczytanie ilosci danych zestawu
		in >> ilosc_liczb;
		// tworzenie tablicy zawierajacej jeden zestaw danych
		t = new int[ilosc_liczb];
		for(int i = 0; i < ilosc_liczb; i++)
			in >> t[i];
		//zapis wyniku (liczby inwersji w tablicy t) do pliku
		out << f_algorytm(t, ilosc_liczb) << endl;
	}
	in.close();
	out.close();

	system("pause");
	
	return 0;
}
