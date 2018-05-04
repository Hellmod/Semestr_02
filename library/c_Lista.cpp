#include "c_Lista.h"

c_Lista::c_Lista(int element1){
	next = new c_Lista(0);
	element = element1;
}

bool c_Lista::f_czyPusta(){
	if(liczba <=0)
		return 1;
	else
		return 0;
}

int c_Lista::f_ileElementow(){
	return liczba;
}

int c_Lista::f_szczytowyElement(){
	return element;
}

bool c_Lista::f_dodajElement(int element1){
	c_Lista *nowy=new c_Lista(element1);
	*next = *nowy;
	return 1;
}

bool c_Lista::f_usunElement(){
	//*next = next->*next;
	
	return false;
}
