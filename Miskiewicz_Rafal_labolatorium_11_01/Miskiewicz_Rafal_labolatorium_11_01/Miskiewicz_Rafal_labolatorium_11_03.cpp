#include <iostream>
#include "..\..\library\c_Tree.h"

#include <vector>


using namespace std;


int main(){

	

	c_Tree t1(1, "T1"), t2(2, "T2"), t3(3, "T3"), t4(4, "T4"), t5(5, "T5");
	//	if(t1.f_czyPusta())
	//		cout << "pusta" << endl;
/*
	t3.f_dodajElement(&t4, &t5);
	t1.f_dodajElement(&t2, &t3);
	t1.f_wypisz();
*/

	s_ListaTree lista(&t1);
	lista.f_dodajElement(&t2);
	lista.f_dodajElement(&t3);
	while(!lista.f_czyPusta()){
		cout<<lista.f_szczytowyElement()->f_Wartosc()<<endl;
		lista.f_usunElement();
	}


	system("pause");
	return 0;
}