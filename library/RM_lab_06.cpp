#include "RM_lab_06.h"
#include "RM_file.h"
#include "RM_table.h"

// algorytm tworzacy macierz incydencji oraz wyznaczajacy sasiadow wierzcholkow grafu skierowanego
// za pomoca kontenera tablicy (std::vector)
void f_algorytm_wektor(fstream &plik){
	// ile_kraw->ilosc krawedzi grafu; max->ilosc wierzcholkow; a,b->zmienne pomocnicze
	int ile_kraw, max = 0, a, b;
	plik >> ile_kraw;
	// znalezienie ilosci wieszcholkow
	for(int i = 0; i < ile_kraw * 2; i++){
		plik >> a;
		if(a > max)
			max = a;
	}
	// utworzenie wektora dwuwymiarowego V[l.krawedzi][l.wierzcholkow]
	vector<vector<int> > V;
	vector<int> v(max);
	// powot do znaku numer 2 (wcelu ponownego czytania wierzcholkow)
	plik.seekg(1);
	// przypisanie wartosci w zaleznosci od miejsca wystepowania wierzcholka
	// 1 liczba-wierzcholek wyjsciowy(1)    2 liczba-wierzcholek docelowy(-1)  
	for(int i = 0; i < ile_kraw; i++){
		fill(v.begin(), v.end(), 0);
		plik >> a; plik >> b;
		v[a - 1] = 1;
		v[b - 1] = -1;
		V.push_back(v);
	}
	// Wstep do wyswietlenia rozwiazania
	for(int i = 0; i < max; i++){
		if(i == 0) cout << " MACIERZ INCYDENTNOSCI:\n   |";
		cout << "  " << i + 1 << "  ";
	}
	cout << "\n---|--------------------------\n";
	// w petli jest tworzona macierz incydentosci
	for(int i = 0; i < ile_kraw; i++){
		// a,k->zmienne pomocnicze
		a = 0;
		int k = 0;
		// tu wypisuja sie nazwy wierszy (krawedzie)
		do{
			if((V[i][k] == 1) || (V[i][k] == -1)){
				cout << k + 1; a++;
				if(a == 1) cout << "-";
				if(a == 2) cout << "|";
			}
			k++;
		} while(a < 2);
		// tu wypisuje sie rozwiazanie macierzy
		for(int j = 0; j < max; j++){
			if(V[i][j] == 1) cout << " +1  ";
			else if(V[i][j] == -1) cout << " -1  ";
			else cout << "  0  ";
		}
		cout << endl;
	}
	// w petli jest rozwiazanie do somsiadow wszystkich wierzcholkow grafu
	cout << "\n Sasiedzi kazdego wierzcholka grafu:\n";
	for(int i = 0; i < max; i++){
		// podanie rodzaju wierzcholka
		cout << i + 1 << ": ";
		// znalezienie wartosci +1 dla poszczegolnej kolumny
		for(int j = 0; j <ile_kraw; j++)
			if(V[j][i] == 1)
				// znalezie wartosci -1 dla poszczegolnego wiersza
				for(int k = 0; k < max; k++)
					if(V[j][k] == -1)
						// wyswietlenie somsiada
						cout << k + 1 << " ";
		cout << endl;
	}
}
// algorytm tworzacy macierz incydencji oraz wyznaczajacy sasiadow wierzcholkow grafu skierowanego
// za pomoca tablicy dynamicznej dwuymiarowej
void f_algorytm_tablica(fstream &plik){
	// ile_kraw->ilosc krawedzi grafu; max->ilosc wierzcholkow; a,b->zmienne pomocnicze
	// **t->tablica dwuwymiarowa przechowujaca +1 i -1 potrzebne do stworzenia macierzy incydentosci
	int ile_kraw, max = 0, a, b, **t = nullptr;
	plik >> ile_kraw;
	// znalezienie ilosci wieszcholkow
	for(int i = 0; i < ile_kraw * 2; i++){
		plik >> a;
		if(a > max)
			max = a;
	}
	// utworzenie tablicy dwuwymiarowej t[l.krawedzi][l.wierzcholkow]
	t=f_createTable<int>(ile_kraw, max);
	// powot do znaku numer 2 (wcelu ponownego czytania wierzcholkow)
	plik.seekg(1);
	// przypisanie wartosci w zaleznosci od miejsca wystepowania wierzcholka
	// 1 liczba-wierzcholek wyjsciowy(1)    2 liczba-wierzcholek docelowy(-1)  
	for(int i = 0; i < ile_kraw; i++){
		plik >> a; plik >> b;
		t[i][a - 1] = 1;
		t[i][b - 1] = -1;
	}
	// Wstep do wyswietlenia rozwiazania
	for(int i = 0; i < max; i++){
		if(i == 0) cout << " MACIERZ INCYDENTNOSCI:\n   |";
		cout << "  " << i + 1 << "  ";
	}
	cout << "\n---|--------------------------\n";
	// w petli jest tworzona macierz incydentosci
	for(int i = 0; i < ile_kraw; i++){
		// a,k->zmienne pomocnicze
		a = 0;
		int k = 0;
		// tu wypisuja sie nazwy wierszy (krawedzie)
		do{
			if((t[i][k] == 1) || (t[i][k] == -1)){
				cout << k + 1; a++;
				if(a == 1) cout << "-";
				if(a == 2) cout << "|";
			}
			k++;
		} while(a < 2);
		// tu wypisuje sie rozwiazanie macierzy
		for(int j = 0; j < max; j++){
			if(t[i][j] == 1) cout << " +1  ";
			else if(t[i][j] == -1) cout << " -1  ";
			else cout << "  0  ";
		}
		cout << endl;
	}
	// w petli jest rozwiazanie do somsiadow wszystkich wierzcholkow grafu
	cout << "\n Sasiedzi kazdego wierzcholka grafu:\n";
	for(int i = 0; i < max; i++){
		// podanie rodzaju wierzcholka
		cout << i + 1 << ": ";
		// znalezienie wartosci +1 dla poszczegolnej kolumny
		for(int j = 0; j <ile_kraw; j++)
			if(t[j][i] == 1)
				// znalezie wartosci -1 dla poszczegolnego wiersza
				for(int k = 0; k < max; k++)
					if(t[j][k] == -1)
						// wyswietlenie somsiada
						cout << k + 1 << " ";
		cout << endl;
	}
}


// Liniowa Metoda Kongruencyjna
int *f_LMK(int max){
	// x->wygenerowana liczba   Xo->wartosc poczzatkowa (ziarno);   
	// a->mnoznik  m->modul;  c->przyrost; 
	int x, m = max + 1, a = 0, c = 0, *t = nullptr, Xo = 6;
	t = f_createTable<int>(max);
	// wyliczenie c (przyrostu) ktory jest wzglednie peirwszy z m 
	do{
		c++;
	} while(f_NWD(m, c) != 1);
	// wyliczenie a (mnoznika) za pomoca zaleznosci  (a^y) mod m=1
	// p=a^y     t2->tablica dwuwymiarowa: 1 kolumna->mnozniki a;  2 kolumna->lambda y  
	// max_y->najwieksza wartosc lambdy (y);  max_a->maksymalne a dla ktorego lambda=max_y 
	int **t2 = nullptr, max_y = 0;
	t2=f_createTable<int>((max - 1), 2);

	for(long long int i = 0; i < max - 1; i++){
		// y->lambda
		long long int y = 1, p;
		do{
			p = pow(i + 2, y);
			if(p < 0)
				p = (-1)*p;
			if((p % m) == 1){
				t2[i][0] = i;
				t2[i][1] = y;
				if(y > max_y)
					max_y = y;
			}
			y++;
		} while(((p % m) != 1) && (y < 20));
	}
	for(int i = 0; i < max - 2; i++){
		if(t2[i][1] == max_y){
			if((m % 4 == 0) && (((i + 2) - 1) % 4 == 0)){
				a = i + 2; break;
			}
			else if(i + 2 > a)
				a = i + 2;
		}
	}
	// wylosowanie licb i przypisanie rozwiazania
	for(int i = 0; i < max; i++){
		if(i == 0)
			t[i] = (a*Xo + c) % m;
		else
			t[i] = (a*t[i - 1] + c) % m;
	}
	return t;
}
// Addytywna Metoda Kongruencyjna
int *f_AMK(int max){
	// m->modulo; t->tablica liczb losowych(metoda LMK); t1->odwrocona tablica t
	int  m = max + 1, n = m - 2, *t = nullptr, *t1 = nullptr, j, k;
	// n->zakres wielkosci z rekomendowanych par liczb do metody AMK
	// j->1 liczba z pary;   k->2 liczba z pary   (j,k)
	j = f_pary_liczb_AMK(n)[0];
	k = f_pary_liczb_AMK(n)[1];
	// przypisanie liczb pseudolosowych metoda LMK do tablicy
	t = f_LMK(max);
	// utworzenie tablicy o rozmiarze n
	t1 = f_createTable<int>(n);
	// przypisanie to tablicy t1 odwrotnosci tablicy t;  a->zmienna pomocnicza
	int a = n;
	for(int i = 0; i < n; i++){
		t1[i] = t[a - 1]; a--;
	}
	// w petli na podstawie wzoru dokonuje sie wyliczenie liczb pseudolosowych i przypisanie ich do t1
	for(int i = 0; i < n; i++){
		t1[k - 1] = (t1[j - 1] + t1[k - 1]) % m;
		k--; j--;
		if(j == 0)
			j = n;
		if(k == 0)
			k = n;
	}
	return t1;
}
// Metoda Tasowania z Jedna sekwencja losowa
int *f_MT(int max){
	// m->modul; Y->tablica wygenerowanych liczb; j->zmienna pomocnicze przy generacji licb
	int m = max + 1, k = m - 2, j = 0, *Y = nullptr, *V = nullptr;
	// przypisanie liczb pseudolosowych metoda AMK do tablicy V
	V = f_AMK(max);
	Y = f_createTable<int>(k);
	// glowny algorytm generatora
	for(int i = 0; i < k; i++){
		// pierwsza liczba jest wygenerowana metoda AMK
		if(i == 0)
			Y[i] = f_AMK(max)[1];
		// kolejne liczby sa rowne liczba pochodzaca z tablicy V z miejsca wyliczanego
		// na podstawie wzoru (k*Y)%m, nastepnie liczba ta zamieniana jest w tablicy na nowo wygenerowana
		else{
			j = (k*Y[i - 1]) % (m - 2);
			Y[i] = V[j];
			V[j] = f_AMK(max)[i];
		}
	}
	return Y;
}
// Najwiekszy Wspolny Dzielnik liczb a i b  warunek! a>b
int f_NWD(int a, int b){
	int i;
	while(b){
		i = b;
		b = a % b;
		a = i;
	}
	return a;
}
// funkcja wyszukaja najbardziej korzystne pary liczb potrzebne do funkcji f_AMK
int *f_pary_liczb_AMK(int n){
	// pare liczb stanowi wyrazenie: (a,b); szerokosc=b-a; char z->zmienna pomocnicza zczytujaca znaki z pliku
	// t->rozwiazanie (para liczb o najwiekszej szerokosci) t[0]=a t[1]=b
	int a, b, szerokosc = 0, *t = nullptr;
	t = f_createTable<int>(2);
	char z;
	// utworzenieobiektu i otwarcie pliku zawierajacego dane
	fstream plik;
	plik = f_otworzPlik("pary_liczb");

	//f_otworzplik(plik, "pary_liczb.txt");
	// petla wykona sie do napatkonia konca pliku lub osiagniecia przez b wartosci n
	while((!plik.eof()) && (t[1] < n - 1)){
		// pobranie znaku
		plik >> z;
		// jezeli znakiem jest '(' to zostana pobrane liczby
		if(z == '('){
			plik >> a;
			// w celu poprawnosci kodu pobrany zostanie znak ', '
			plik >> z;
			plik >> b;
			if(b > n - 1)
				break;
			// warunek sprawdzajacy rozwiazanie
			if((b - a) >= szerokosc)
				t[0] = a; t[1] = b;
		}
	}
	plik.close();
	return t;
}

