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
