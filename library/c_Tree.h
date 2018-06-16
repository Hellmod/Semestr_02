#pragma once
#include <iostream>
#include <string>

class c_Tree{
	
public:

	double wartosc=0;
	c_Tree *branch_L = nullptr, *branch_R = nullptr;
	std::string nazwa,droga="";

	c_Tree();
	c_Tree(double wartosc);
	c_Tree(double wartosc,std::string nazwa);
	c_Tree(double wartosc, c_Tree * branch_L, c_Tree * branch_R);
	c_Tree(c_Tree * branch_L, c_Tree * branch_R);
	
	~c_Tree();

	bool f_czyPusta();
	c_Tree *f_Element_L();
	c_Tree *f_Element_R();
	double f_Wartosc();
	bool f_dodajElement(c_Tree *branch_L, c_Tree *branch_R);
	void f_dopiszdroge(std::string nazwa);
	void f_wypisz();

friend 	bool operator==(c_Tree t1, c_Tree t2);
friend 	bool operator<(c_Tree t1, c_Tree t2);
friend 	bool operator>(c_Tree t1, c_Tree t2);
//friend 	bool operator=(c_Tree t1);
};

