#include <iostream>
#include "..\..\library\RM_table.h"
#include "..\..\library\RM_lib.h"
#include "..\..\library\c_Lista.h"
using namespace std;

struct s_Lista{
	int liczba=0,*tab=nullptr;
	
	s_Lista(){
		tab = f_createTable(1);
	}

	bool f_czyPusta(){
		if(liczba <= 0)
			return 1;
		else
			return 0;
	}

	int f_ileElementow(){
		return liczba;
	}

	int f_szczytowyElement(){
		return tab[liczba-1];
	}

	bool f_dodajElement(int element){
		//-------------------------------
		int *tab2;//tab2 jest tablic¹ tymaczasow¹
		liczba++;
		tab2= f_createTable(liczba);
		*tab2 = *tab;
		f_destroyTable(tab);
		tab = f_createTable(liczba);
		*tab = *tab2;
		f_destroyTable(tab2);
		tab[liczba-1] = element;
		return 1;
	}

	bool f_usunElement(){
		tab[liczba-1] = NULL;
		liczba--;
		//ToAsk czy w ten sposub zwalniam pamiêæ ?

		/*
		int *tab2;
		liczba--;
		tab2 = f_createTable(liczba);
		*tab2 = *tab;
		f_destroyTable(tab);		
		tab = f_createTable(liczba);
		*tab = *tab2;
		f_destroyTable(tab2);
		*/
		return 1;
	}
};

int main(){

	/*
	{
		s_Lista l1;
		//-------------sprawdzenie zwalniania pamiêci-----------------
		cout << PL("sprawdzam zwalanianie pamiêci") << endl;
		l1.f_dodajElement(1);
		l1.f_dodajElement(2);
		for(size_t i = 0; i < 1000000; i++){//zwiêkrz iloœæ iteracji aby lepeij sprawdziæ zu¿ycie RAMu

			if(l1.f_szczytowyElement() != 2){
				cout << l1.f_szczytowyElement();
				break;
			}
			l1.f_usunElement();
			l1.f_dodajElement(2);
		}
		l1.f_usunElement();
		l1.f_usunElement();
		cout << PL("dodajê 10 elementów") << endl;
		//---------------czyszczenie stosu------------------------------
		for(size_t i = 0; i < 10; i++){
			l1.f_dodajElement(i);
		}
		cout << l1.f_ileElementow() << PL("<-- iloœæ elemenetów") << endl;
		cout << PL("zmniejeszam iloœæ elementów do puki nie pusta") << endl;

		while(l1.f_czyPusta() != 1){
			l1.f_usunElement();
			cout << l1.f_ileElementow() << endl;
		}
		if(l1.f_czyPusta() == 1)
			cout << PL("list5a powinna byæ puste") << endl;
		cout << l1.f_ileElementow() << PL("<-- iloœæ elemenetów") << endl;
	}
	*/

	
	{
		c_Lista l1(0);
		//-------------sprawdzenie zwalniania pamiêci-----------------
		cout << PL("sprawdzam zwalanianie pamiêci") << endl;
		l1.f_dodajElement(1);
		l1.f_dodajElement(2);
		for(size_t i = 0; i < 1000000; i++){//zwiêkrz iloœæ iteracji aby lepeij sprawdziæ zu¿ycie RAMu

			if(l1.f_szczytowyElement() != 2){
				cout << l1.f_szczytowyElement();
				break;
			}
			l1.f_usunElement();
			l1.f_dodajElement(2);
		}
		l1.f_usunElement();
		l1.f_usunElement();
		cout << PL("dodajê 10 elementów") << endl;
		//---------------czyszczenie stosu------------------------------
		for(size_t i = 0; i < 10; i++){
			l1.f_dodajElement(i);
		}
		cout << l1.f_ileElementow() << PL("<-- iloœæ elemenetów") << endl;
		cout << PL("zmniejeszam iloœæ elementów do puki nie pusta") << endl;

		while(l1.f_czyPusta() != 1){
			l1.f_usunElement();
			cout << l1.f_ileElementow() << endl;
		}
		if(l1.f_czyPusta() == 1)
			cout << PL("list5a powinna byæ puste") << endl;
		cout << l1.f_ileElementow() << PL("<-- iloœæ elemenetów") << endl;
	}

	
	system("pause");
	return 0;
}


