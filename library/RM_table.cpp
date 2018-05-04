#include "RM_table.h"




void f_test(int i){
	cout << i << "<-- i" << endl;
}


int **f_createTable(int wiersze, int kolumny){
	int ** tab = new int *[wiersze];
	for(int j = 0; j <= wiersze; j++){
		tab[j] = new int[kolumny];
	}

	return tab;
}
//TODO przerobiæ tak saomo 2 wymiarow¹
int *f_createTable(int wiersze){
	int *T;
	try{
		T = new int[wiersze];
	} catch(bad_alloc){
		cout << "\n  Brak miejsca na utworzenie tablicy" << wiersze;
		cin.ignore();
		getchar();
		exit(0);
	}
	return T;
}

void f_destroyTable(int *tab){
	delete[]tab;
	tab = nullptr;
	
}

void f_readTetable(int **tab, int x, int y){
	for(int i = 0; i <= x; i++){
		for(int j = 0; j <= y; j++){
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

void f_readTetable(int * tab, int x){
	for(int i = 0; i <= x; i++){
		cout << tab[i] << " ";
	}
}

void f_readTetable(string * tab, int x){
	for(int i = 0; i < x; i++){
		cout << tab[i] << endl;
	}
}

void f_readTetable(int ***tab, int x, int y, int z){
	for(int i = 0; i <= x; i++){
		for(int j = 0; j <= y; j++){
			for(int k = 0; k <= z; k++){
				cout << tab[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << "______________" << endl;
	}
}

int **f_loadTable(int **tab, int x, int y){
	int temp;
	for(int k = 0; k < x; k++){
		for(int l = 0; l < y; l++){
			cin >> temp;
			tab[k][l] = temp;
		}
	}
	return tab;
}

int f_sumaTab(int **tab, int x, int y){
	int suma = 0;
	for(int k = 0; k <= x; k++){
		for(int l = 0; l <= y; l++){
			suma += tab[k][l];
		}
	}
	return suma;
}

int **f_cutTable(int **tab, int i, int j, int x, int y){
	int ** tab2, wiersz_wycinka = 0, kolumna_wycinka = 0;
	tab2 = f_createTable(x - i, y - j);

	for(int wiersz_oryginalu = i; wiersz_oryginalu <= x; wiersz_oryginalu++){
		kolumna_wycinka = 0;
		for(int kolumna_oryginalu = j; kolumna_oryginalu <= y; kolumna_oryginalu++){
			tab2[wiersz_wycinka][kolumna_wycinka] = tab[wiersz_oryginalu][kolumna_oryginalu];
			kolumna_wycinka++;
		}
		wiersz_wycinka++;
	}

	return tab2;
}

int f_szuajIndeksu(int *tab, int x, int liczba){
	int i, a = 0, b = x;
	//i = ((liczba - tab[0])*(x - 0)) / (tab[x] - tab[0]);
	do{
		i = ((liczba - tab[a])*(b - a)) / (tab[b] - tab[a]);
		i += a;
		if(tab[i] < liczba)
			a = i;
		else if(tab[i] > liczba)
			b = i;

		if(a == b - 1){
			i = -1;
			break;
		}

	} while(tab[i] != liczba);
	//cout << liczba << ": " << i << endl;
	return i;
}

int f_ileNadInd(int *tab, int x, int liczba){
	int suma = 0;
	while(tab[x + 1] == liczba){
		suma++;
		x++;
	}
	return suma;
}

int f_ilePodInd(int *tab, int x, int liczba){
	int suma = 0;
	while(tab[x - 1] == liczba){
		suma++;
		x--;
	}
	return suma;

}