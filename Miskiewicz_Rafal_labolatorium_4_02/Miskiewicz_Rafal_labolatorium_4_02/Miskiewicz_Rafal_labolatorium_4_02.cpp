//zadanie 4.2
#include "..\..\library\RM_ONP.h"
#include "..\..\library\RM_file.h"
using namespace std;

int main(){
	// n->liczba linii zawierajacych wyrazenie arytmetyczne
	unsigned int n;
	// typ-> zmienna wskazujaca na to ktora funkcja ma sie wykonac (z INF do ONP czy z ONP do INF)
	string typ;
	// utworzenie obiektu
	fstream file;
	// otwarcie pliku
	file=f_otworzPlik("in");
	//f_otworzplik(file, "in.txt");
	file >> n;
	// dla kazdej lini w zaleznosci od typu wykona sie odpowiednia funkcja
	for(int i = 0; i < n; i++){
		cout << i + 1 << " ";
		file >> typ;
		if(typ == "INF:")
			f_from_INF_to_ONP(file);
		else if(typ == "ONP:")
			f_from_ONP_to_INF(file);
		else cout << "zly zapis";
		cout << endl;
	}
	file.close();

	system("pause");
	return 0;
}
