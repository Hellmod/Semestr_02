#include "RM_graf.h"

// algorytm tworzy liste incydencji oraz wyznacza stopien wierzcholkow w grafie nieskierowanym
void f_algorytm(fstream &plik){
	// max->ilosc wierzcholkow grafu; ile_kra->ilosc krawedzi grafu; a,b->zmienne pomocnicze
	int max = 0, a, b, ile_kra;
	plik >> ile_kra;
	// znalezienie ilosci wieszcholkow
	for(int i = 0; i < ile_kra * 2; i++){
		plik >> a;
		if(a > max)
			max = a;
	}
	// w petli dla kazdego wierzcholka zostanie podana lista incydentnosci i waga
	for(int i = 0; i < max; i++){
		// utworzenie obiektu struktury(lista jednokierunkowa)  head->glowa listy; nowy->nowy element listy
		elementy_listy *head = NULL;
		elementy_listy *nowy;
		// dla kazdego wierzcholka  plik zostanie szczytany od drugiego znaku
		plik.seekg(1);
		// petla wykona sie tyle razy ile jest krawedzi grafu
		// jezeli w badanym wierszu jedna z zczytanych liczb bedzie rowna nr. wierzcholka
		// to druga liczba zostanie przypisana do listy incydentnosci tego wierzcholka
		for(int j = 0; j < ile_kra; j++){
			plik >> a;
			plik >> b;
			if(a == i + 1){
				nowy = new elementy_listy;
				nowy->liczba = b;
				nowy->next = head;
				head = nowy;
			}
			if(b == i + 1){
				nowy = new elementy_listy;
				nowy->liczba = a;
				nowy->next = head;
				head = nowy;
			}
		}
		// wypisanie lsity incydentnosci oraz zliczenie wagi wierzcholka (a->waga)
		a = 0;
		elementy_listy *temp = head;
		cout << "\t" << i + 1 << "\t\t\t";
		while(temp != NULL){
			cout << temp->liczba << " ";
			temp = temp->next;
			a++;
		}
		// wyswietlenie wagi wierzcholka
		if(a<4)
			cout << "\t\t\t" << a << endl;
		else
			cout << "\t\t" << a << endl;
	}
}



//-------------


// funkcja zwraca tablice dwuwymiarowe p i q jako macierze najlepszych upakowan plecak o zadanej pojemnosci wedlug podanych przedmiotow
void f_algorytm(int masa_plecaka, int ilosc_przedmiotow, przedmiot* obiekt, int** &p, int** &q){
	// utworzenie wyzerowanych macierzy p i q 
	p = f_utworz_tablice_2(ilosc_przedmiotow + 1, masa_plecaka + 1);
	q = f_utworz_tablice_2(ilosc_przedmiotow + 1, masa_plecaka + 1);
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
// funkcja tworzy tablice dwuwymiarowa o w wierszach i k kolumnach
int **f_utworz_tablice_2(int w, int k){
	int **T = NULL;
	try{
		T = new int*[w];
	} catch(bad_alloc){
		cout << "Brak miejsca na utworzenie tablicy";
		getchar();
		cin.ignore();
		exit(0);
	}
	for(int i = 0; i<w; i++)
		try{
		T[i] = new int[k];
	} catch(bad_alloc){
		cout << "Brak miejsca na utworzenie tablicy";
		getchar();
		cin.ignore();
		exit(0);
	}
	return T;
}