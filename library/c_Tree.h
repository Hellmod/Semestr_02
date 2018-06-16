#pragma once
#include <iostream>
#include <string>

class c_Tree{
	//warto�� wierzcho�ka
	double value=0;
	//lewa i prawa ga��� drzewa
	c_Tree *branch_L = nullptr, *branch_R = nullptr;
	//nazwa wierzcho�ka
	std::string name;
	//droga do wo najwy�szego wierzcho�ka
	std::string road="";
public:
	//Tworzy puste drzewo
	c_Tree();
	//Tworzy drzewo z podan� warto�ci�
	c_Tree(double value);
	//Tworzy drzewo z podan� warto�ci� i nazw�
	c_Tree(double value,std::string name);
	//Tworzy drzewo z podan� warto�ci� i lew� i praw� ga��ci�
	c_Tree(double value, c_Tree * branch_L, c_Tree * branch_R);
	//Tworzy drzewo z podan� warto�ci� i lew� i praw� ga��ci� i nazw�
	c_Tree(double value, c_Tree * branch_L, c_Tree * branch_R,std::string name);
	//Tworzy drzewo z lew� i praw� ga��ci�
	c_Tree(c_Tree * branch_L, c_Tree * branch_R);
	//Tworzy drzewo z lew� i praw� ga��ci� i nazw�
	c_Tree(c_Tree * branch_L, c_Tree * branch_R, std::string name);
	
	~c_Tree();
	//zwraza true je�eli drzeo nie ma pod sob� �adnych ga��zi
	bool f_isEmpty();
	//zwraca lew� ga���
	c_Tree *f_branch_L();
	//zwraca praw� ga���
	c_Tree *f_branch_R();
	//zwraca warto�� ga��zi
	double getVal();
	//dodaje do drzewa korzenie
	bool f_push(c_Tree *branch_L, c_Tree *branch_R);
	//tworzy drog� do ga��zi
	void f_addRoad(std::string nazwa);
	//wypisuje struktur� drzewa
	void f_showTree();
	

friend 	bool operator==(c_Tree t1, c_Tree t2);
friend 	bool operator<(c_Tree t1, c_Tree t2);
friend 	bool operator>(c_Tree t1, c_Tree t2);
};

struct functor_SortTreeLess{
	bool operator()(c_Tree* nod1, c_Tree* nod2);
};

struct functor_SortTreeGreater{
	bool operator()(c_Tree* nod1, c_Tree* nod2);
};

