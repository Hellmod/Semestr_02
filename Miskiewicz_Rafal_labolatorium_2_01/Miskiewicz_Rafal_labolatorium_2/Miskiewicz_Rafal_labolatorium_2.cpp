#include "stdafx.h"
#include "RM_file.h"
#include "iostream"
#include "string"
#include "fstream"
#include "RM_table.h"
#include "RM_lib.h"

using namespace std;

int main(){
	fstream plik, wyjscie;
	string wej, wyj;
	int liczbaDanych, liczbaWierszyDanych, liczbaWierszySzukanych, *tabDane, *tabSzukane,liczbaWJednejLini=0, liczbaWJednejParti=0;
	tabDane = nullptr;
	tabSzukane = nullptr;
	//inicjalizacja wszystkich potrzebnych zmiennych;
	cout << PL("Podaj nazwę pliku wejściowego bez rozszeżenia "); cin >> wej;
	cout << PL("Podaj nazwę pliku wyjściowego bez rozszeżenia "); cin >> wyj;

	plik = f_otworzPlik(wej);
	wyjscie = f_otworzPlikZapis(wyj);
	//utworzenie uchwytów do plików dla wejścia i wyjśćia 
	plik >> liczbaDanych;

	for(int i = 0; i < liczbaDanych; i++){

		plik >> liczbaWierszyDanych;
		liczbaWierszyDanych--;
		tabDane = f_wczytajTablice(plik, liczbaWierszyDanych);// wczytuje tablicę z pliku do dynamicznej tbalicy

		plik >> liczbaWierszySzukanych;
		liczbaWierszySzukanych--;
		tabSzukane = f_wczytajTablice(plik, liczbaWierszyDanych);// wczytuje tablicę z pliku do dynamicznej tbalicy

		for(int j = 0; j <= liczbaWierszySzukanych; j++){
			int indeks, suma = 1;
			indeks = f_szuajIndeksu(tabDane, liczbaWierszyDanych, tabSzukane[j]);//wyszukuje indeks pod kturym występuje liczba 
			if(indeks != -1){
				suma += f_ileNadInd(tabDane, indeks, tabSzukane[j]);
				suma += f_ilePodInd(tabDane, indeks, tabSzukane[j]);
			}//liczy ilość na i pod elementów
			else
				suma = 0;
			wyjscie << "(" << suma << "," << indeks << ") ";//wpisuje do pliku sumę lelmentów i inedks
		}
		//suswanie powtużeniń z tablicy
		wyjscie << endl;
		for(int czas = 0; czas <= liczbaWierszyDanych; czas++){
			if(tabDane[czas] != tabDane[czas + 1]){
				wyjscie << tabDane[czas]<<" ";

				liczbaWJednejLini++;//kontrola przekroczenia 50 znaków w wierszu
				liczbaWJednejParti++;//kontrola przekroczneia 200 znaków w zestwie
				if(liczbaWJednejParti >= 200)
					break;
				if(liczbaWJednejLini >= 50){
					wyjscie << endl;
					liczbaWJednejLini = 0;
				}
			}
		}
	}



	cout << endl;
	system("pause");
	return 0;
}
