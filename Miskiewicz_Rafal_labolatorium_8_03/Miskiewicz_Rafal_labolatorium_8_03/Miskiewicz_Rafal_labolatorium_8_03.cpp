#include "..\..\library\RM_lab_08.h"
#include "..\..\library\RM_file.h"
#include "..\..\library\RM_table.h"
using namespace std;

int main(){
	// liczba zestawów--pojemnosc plecaka--zestaw danych--ilosc danych w zestawie
	int l_zestawow, pojemnosc, *zestaw = nullptr, rozmiar_zestawu;
	// ele_zestawu->tablica danych zestawu, przyjmujaca true jezeli element jest czescia rozwiazania
	bool *ele_zestawu;
	// utworzenie oraz otwarcie obiektow wyjscia i wejscia
	fstream in;
	fstream out;
	in = f_otworzPlik("in");
	out = f_otworzPlikZapis("out");
	// pobranie danych z pliku
	in >> l_zestawow;
	for(int i = 0; i < l_zestawow; i++){
		in >> pojemnosc;
		in >> rozmiar_zestawu;
		// utworzenie tablic o rozmiarze rownym ilosci danych w zestawie i przypisanie do nich wartosci
		ele_zestawu = new bool[rozmiar_zestawu];
		zestaw=f_createTable<int>(rozmiar_zestawu);
		//zestaw = f_utworz_tablice_1(rozmiar_zestawu);
		for(int j = 0; j < rozmiar_zestawu; j++){
			in >> zestaw[j];
			ele_zestawu[j] = false;
		}
		// jezeli zestaw zawiera kombinacje liczb ktorych suma jest rowna pojemnosci, to zostanie wypisane rozwiazanie
		if(f_algorytm_3(pojemnosc, zestaw, rozmiar_zestawu, 0, 0, ele_zestawu) == true){
			out << pojemnosc << "=";
			for(int j = 0; j < rozmiar_zestawu; j++)
				// zostana wypisane wartosci ktore sa czescia rozwiazania (czyli przyjely warosc TRUE w f_algorytm)
				if(ele_zestawu[j] == true)
					out << zestaw[j] << " ";
		}
		// w przeciwnym razie pojawi sie napis BRAK
		else
			out << "BRAK";
		out << endl;
		delete[]ele_zestawu;
		delete[]zestaw;
	}
	out.close();
	in.close();

	system("pause");
	return 0;
}

