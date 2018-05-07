#include "..\..\library\RM_lab_06.h"
#include "..\..\library\RM_file.h"
#include "..\..\library\RM_table.h"
//#include "libFiles.h"
using namespace std;

int main(){
	// stworzenie obiektu
	fstream plik;
	plik = f_otworzPlik("in");
	//f_otworzplik(plik, "in.txt");
	cout << "Rozwiazanie przy pomocy tablicy dynamicznej dwuwymiarowej:\n\n";
	f_algorytm_tablica(plik);
	cout << "\n\n\nRozwiazanie przy pomocy kontenera tablicy (std::vector):\n\n";
	// ustawienie kursora na pierwszy znak z pliku
	plik.seekg(0);
	f_algorytm_wektor(plik);
	//zamkniecie obiektu
	plik.close();

	system("pause");
	return 0;
}
