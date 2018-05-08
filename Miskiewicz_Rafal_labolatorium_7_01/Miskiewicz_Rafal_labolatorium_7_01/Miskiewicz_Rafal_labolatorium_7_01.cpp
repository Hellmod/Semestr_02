#include "..\..\library\RM_file.h"
#include "..\..\library\RM_graf.h"
using namespace std;

int main(){
	// stworzenie obiektu
	fstream plik;
	plik = f_otworzPlik("in");

	// Wstep do rozwiazania
	cout << " Nr. Wierzcholka:\tLista Incydentnosci:\tWaga Wierzcholka:\n";
	f_algorytm(plik);
	// zamkniecie obiektu
	plik.close();
	system("pause");
	
	return 0;
}
