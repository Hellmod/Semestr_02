#include"..\..\library\RM_graf.h"
#include"..\..\library\RM_file.h"
using namespace std;

int main(){
	int masa_plecaka, ilosc_przedmiotow;
	// p->macierz najlepszego upakowania plecaka o zadanej pojemnosci z danego zbioru; 
	// q->macierz skojarzona z macierza P rzeczy pakowanych w ostatnim ruchu
	int **p = nullptr, **q = nullptr;
	// utworzenie wskaznika obiektu struktury przedmiot
	przedmiot *obiekt;
	// utworzenie i otwarcie obiektow strumieni wyjscia i wejscia
	fstream in;
	fstream out;
	in = f_otworzPlik("in");
	out = f_otworzPlikZapis("out");
	// zczytanie danych z pliku
	in >> masa_plecaka;
	in >> ilosc_przedmiotow;
	obiekt = new przedmiot[ilosc_przedmiotow];
	for(int i = 0; i < ilosc_przedmiotow; i++){
		in >> obiekt[i].nazwa;
		in >> obiekt[i].cena;
		in >> obiekt[i].masa;
	}
	// utworzenie macierzy i zapis rozwiazania do pliku
	f_algorytm(masa_plecaka, ilosc_przedmiotow, obiekt, p, q);
	zapis_do_pliku(out, ilosc_przedmiotow + 1, masa_plecaka + 1, p, q);
	// zwolnienie pamieci tablic i zamknieci plikow
	for(int i = 0; i < ilosc_przedmiotow + 1; i++){
		delete[] p[i];  delete[] q[i];
	}
	delete[] p; delete[] q;
	in.close();
	out.close();

	system("pause");
	return 0;
}


