#pragma once
class c_Lista{
public:
	int liczba,element;
	c_Lista *next=nullptr;

	c_Lista(int element1);
	bool f_czyPusta();
	int f_ileElementow();
	int f_szczytowyElement();
	bool f_dodajElement(int element);
	bool f_usunElement();
};

