#include "RM_lab_06.h"
#include "RM_file.h"
#include "RM_table.h"

// algorytm zliczajacy liczbe inwersji tablicy zawierajacej zestaw liczb
int f_algorytm(int *t, int ilosc_liczb){
	// warunek podstawowy
	if(ilosc_liczb == 1)
		return 0;
	int wynik = 0;
	for(int i = 1; i < ilosc_liczb; i++){
		// porownanie zerowego elementu tablicy z kazym kolejnym
		if(t[0] > t[i])
			wynik++;
	}
	//z kazdym krokiem rozmiar tablicy sie zmniejsza o 1, a zerowy element tablicy jest rowny kolejnemu
	return wynik + f_algorytm(t + 1, ilosc_liczb - 1);
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

