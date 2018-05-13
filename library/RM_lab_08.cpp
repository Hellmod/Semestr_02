#include "RM_lab_08.h"

// funkcja zwraca tablice dwuwymiarowe p i q jako macierze najlepszych upakowan plecak o zadanej pojemnosci wedlug podanych przedmiotow
void f_algorytm(int masa_plecaka, int ilosc_przedmiotow, przedmiot* obiekt, int** &p, int** &q){
	// utworzenie wyzerowanych macierzy p i q 
	p=f_createTable<int>(ilosc_przedmiotow + 1, masa_plecaka + 1);
	//p = f_utworz_tablice_2(ilosc_przedmiotow + 1, masa_plecaka + 1);
	q=f_createTable<int>(ilosc_przedmiotow + 1, masa_plecaka + 1);
	//q = f_utworz_tablice_2(ilosc_przedmiotow + 1, masa_plecaka + 1);
	for(int i = 0; i < ilosc_przedmiotow + 1; i++)
		for(int j = 0; j < masa_plecaka + 1; j++){
			p[i][j] = 0; q[i][j] = 0;
		}
	for(int i = 1; i < ilosc_przedmiotow + 1; i++){
		for(int j = 1; j < masa_plecaka + 1; j++){
			int m_i = obiekt[i - 1].masa;
			int c_i = obiekt[i - 1].cena;
			// je¿eli pojemnosc plecaka jest wystarczjaca na pomieszczenie przedmiotu to komórka macierzy zmieni swoja wartosc 
			if(j >= m_i){
				// jezeli zmiesci sie wiecej niz jedne przedmiot to wartosci zostana dodane
				if(p[i - 1][j] < p[i][j - m_i] + c_i){
					p[i][j] = p[i - 1][j - m_i] + c_i;
					q[i][j] = i;
				}
				// w przeciwnym razie przepisane zostana wartosci z wiersza powyzej
				else{
					p[i][j] = p[i - 1][j];
					q[i][j] = q[i - 1][j];
				}
			}
			// w przeciwnym razie dana komórka macierzy bedzie rowna komórce znajdujacej sie nad nia
			else{
				p[i][j] = p[i - 1][j];
				q[i][j] = q[i - 1][j];
			}
		}
	}
}
// funkcja zapisuje do pliku rozwiazanie jako wypisanie macierzy p i q
void zapis_do_pliku(fstream &plik, int ilosc_wierszy, int ilosc_kolumn, int** p, int** q){
	// zapisanie macierzy p
	plik << "MACIERZ P\n#|";
	for(int i = 0; i < ilosc_kolumn; i++)
		plik << "   " << i << "   ";
	plik << "\n--|-----------------------------------------------------------------------------\n";
	for(int i = 0; i < ilosc_wierszy; i++){
		plik << i << "|";
		for(int j = 0; j < ilosc_kolumn; j++){
			if(p[i][j] < 10)
				plik << "   " << p[i][j] << "   ";
			else if((p[i][j] >= 10) && (p[i][j] < 100))
				plik << "  " << p[i][j] << "  ";
			else
				plik << " " << p[i][j] << " ";
		}
		plik << endl;
	}
	// zapisanie macierzy q
	plik << "\nMACIERZ Q\n";
	plik << "#|";
	for(int i = 0; i < ilosc_kolumn; i++)
		plik << i << " ";
	plik << "\n--|---------------------------------\n";
	for(int i = 0; i < ilosc_wierszy; i++){
		plik << i << "|";
		for(int j = 0; j < ilosc_kolumn; j++)
			plik << q[i][j] << " ";
		plik << endl;
	}
}


//--------------------------------

bool f_algorytm_3(int waga, int *t, int ile, int suma, int a, bool* &wynik){
	if(suma == waga)
		return true;
	if(suma > waga)
		return false;
	if(a >= ile)
		return false;
	wynik[a] = true;
	//wywo³anie funkcji ze zwiekszeniem sumy o kolejny element zestau 
	bool czyZnalazl = f_algorytm_3(waga, t, ile, suma + t[a], a + 1, wynik);
	if(czyZnalazl)
		return true;
	//wywo³anie funkcji bez zwiekszeniem sumy 
	wynik[a] = false;
	f_algorytm_3(waga, t, ile, suma, a + 1, wynik);
}


bool f_algorytm_2(int waga, int *t, int ile, int suma, int a, bool* &wynik){
	cout << " w[" << a << "]=F z[" << a << "]=" << t[a] << " @" << suma << "@ ";
	if(suma == waga){
		cout << "OK, koniec poszukiwan" << endl;
		return true;
	}
	if(suma > waga){
		cout << "zbyt duzo" << endl;
		return false;
	}
	if(a >= ile){
		cout << "koniec zestawu" << endl;
		return false;
	}
	//wywo³anie z wzieciem aktualnej liczby, zwiekszenie zajetosci plecaka 
	wynik[a] = true;
	cout << " w[" << a << "]=T #1";
	bool czyZnalazl = f_algorytm_3(waga, t, ile, suma + t[a], a + 1, wynik);
	cout << " ak." << a;
	if(czyZnalazl)
		return true;
	//wywo³anie bez wzieca aktualnej liczby
	wynik[a] = false;
	cout << " w[" << a << "]=F #2";
	f_algorytm_3(waga, t, ile, suma, a + 1, wynik);
	//cout << " ak." << a;
}
// algorytm
void f_algorytm_1(ofstream &plik, int waga, int *t, int ile){
	for(int i = 0; i < ile; i++){
		plik << t[i] << " ";
		cout << t[i] << " ";
	}
	plik << endl;
	cout << endl;

	int suma = 20;
	vector<int> liczby;
	if(suma == waga){
		cout << waga << "= ";
		for(int i = 0; i < liczby.size(); i++)
			cout << liczby[i] << " ";
	}


}
