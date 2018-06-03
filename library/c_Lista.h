#pragma once
class s_ListaTree{
public:
	int liczba,element;
	s_ListaTree *next=nullptr;

	s_ListaTree(int element1);
	bool f_czyPusta();
	int f_ileElementow();
	int f_szczytowyElement();
	bool f_dodajElement(int element);
	bool f_usunElement();
};

