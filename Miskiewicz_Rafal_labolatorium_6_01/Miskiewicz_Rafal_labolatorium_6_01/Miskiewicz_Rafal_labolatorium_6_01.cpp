//zadanie 6.1
#include "..\..\library\RM_lab_06.h"
#include "..\..\library\RM_table.h"
#include "..\..\library\RM_file.h"
#include "..\..\library\RM_lib.h"
using namespace std;

int main(){
	// utworzenie obiektu i pliku
	fstream plik;
	plik = f_otworzPlikZapis("out");
	// metoda->metoda generacji liczb; max->maksymalna wartosc wylosowanej liczby
	int metoda, max;
	cout << "GENERATOR LICZB LOSOWYCH";
	cout << "\n\nPodaj zakres liczb losowanych liczb (max):"<<endl
		<< PL(" #W ramach poprawnosci dzia³ania algorytmu nale¿y unikaæ liczb pierwsych!!!")<<endl;
	cin >> max;
	cout << "\nWybor metody:\n------------------"<<endl;
	cout << "1. Liniowa metoda kongurencyjna"<<endl;
	cout << "2. Addytywna metoda kongurencyjna"<<endl;
	cout << "3. Metoda tasowania z jedna sekwencja losowa"<<endl;
	cout << "------------------\n\nPodaj metode losowania (cyfra 1/2/3):"<<endl;
	cin >> metoda;
	// w zaleznosci od wuboru metody liczby zostana zapisane do utworzonego pliku
	switch(metoda){
	case 1:
		f_zapiszTablice(plik, f_LMK(max), max);
		break;
	case 2:
		f_zapiszTablice(plik, f_AMK(max), max-1);
		break;
	case 3:
		f_zapiszTablice(plik, f_MT(max), max - 1);
		break;
	default: cout << "Niepoprawny numer"; break;
	}
	plik.close();
	cout << "\nWygenerowane liczby zostaly zapisane do pliku:  out.txt";

	getchar();
	cin.ignore();
	return 0;
}
