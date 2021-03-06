#include "stdafx.h"
#include "iostream"

using namespace std;


int **createTable(int wiersze, int kolumny){
	int ** tab = new int *[wiersze];
	for(int j = 0; j <= wiersze; j++){
		tab[j] = new int[kolumny];
	}

	return tab;
}

void readTetable(int **tab, int x, int y){
	for(int i = 0; i <= x; i++){
		for(int j = 0; j <= y; j++){
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

int **loadTable(int **tab, int x, int y){
	int temp;
	for(int k = 0; k < x; k++){
		for(int l = 0; l < y; l++){
			cin >> temp;
			tab[k][l] = temp;
		}
	}
	return tab;
}

int sumaTab(int **tab, int x, int y){
	int suma = 0;
	for(int k = 0; k <= x; k++){
		for(int l = 0; l <= y; l++){
			suma += tab[k][l];
		}
	}
	return suma;
}

/*
i wiersz od której		1
j kolumna od której		0

x wiersz do której		0
y kolumna do której		0
*/
int **cutTable(int **tab, int i, int j, int x, int y){
	int ** tab2,wiersz_wycinka=0,kolumna_wycinka=0;
	tab2 = createTable(x - i, y - j);

	for(int wiersz_oryginalu=i; wiersz_oryginalu <= x; wiersz_oryginalu++){
		kolumna_wycinka = 0;
		for(int kolumna_oryginalu = j; kolumna_oryginalu <= y; kolumna_oryginalu++){
			tab2[wiersz_wycinka][kolumna_wycinka] = tab[wiersz_oryginalu][kolumna_oryginalu];
			kolumna_wycinka++;
		}
		wiersz_wycinka++;
	}
	
	return tab2;
}

int checkTable(int **tab, int x, int y){
	int max;
	max = sumaTab(cutTable(tab, 0, 0, 1, 1), 1, 1);
	for(int a = 0; a < x; a++){//<-- od 0
		for(int b = 0; b < y; b++){
			for(int i = a; i < x; i++){
				for(int j = b; j < y; j++){
					//cout << a << b << "," << i << j << " " << i - a << j - b << endl;
					if(max < sumaTab(cutTable(tab, a, b, i, j), i - a, j - b))
						max = sumaTab(cutTable(tab, a, b, i, j), i - a, j - b);
				}
			}
		}
	}

	return max;
}

int main(){
	int z, x, y, **tab;
	cin >> z;

	
	for(int i = 0; i < z; i++){
		cin >> x >> y;
		tab = createTable(x, y);
		tab = loadTable(tab, x, y);
		cout << checkTable(tab, x, y) << endl;
		cout << "___________________" << endl;
	}

	system("pause");
	return 0;
}