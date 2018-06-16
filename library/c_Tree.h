#pragma once
#include <iostream>
#include <string>

class c_Tree{
	//wartoœæ wierzcho³ka
	double value=0;
	//lewa i prawa ga³¹Ÿ drzewa
	c_Tree *branch_L = nullptr, *branch_R = nullptr;
	//nazwa wierzcho³ka
	std::string name;
	//droga do wo najwy¿szego wierzcho³ka
	std::string road="";
public:
	//Tworzy puste drzewo
	c_Tree();
	//Tworzy drzewo z podan¹ wartoœci¹
	c_Tree(double value);
	//Tworzy drzewo z podan¹ wartoœci¹ i nazw¹
	c_Tree(double value,std::string name);
	//Tworzy drzewo z podan¹ wartoœci¹ i lew¹ i praw¹ ga³êci¹
	c_Tree(double value, c_Tree * branch_L, c_Tree * branch_R);
	//Tworzy drzewo z podan¹ wartoœci¹ i lew¹ i praw¹ ga³êci¹ i nazw¹
	c_Tree(double value, c_Tree * branch_L, c_Tree * branch_R,std::string name);
	//Tworzy drzewo z lew¹ i praw¹ ga³êci¹
	c_Tree(c_Tree * branch_L, c_Tree * branch_R);
	//Tworzy drzewo z lew¹ i praw¹ ga³êci¹ i nazw¹
	c_Tree(c_Tree * branch_L, c_Tree * branch_R, std::string name);
	
	~c_Tree();
	//zwraza true je¿eli drzeo nie ma pod sob¹ ¿adnych ga³êzi
	bool f_isEmpty();
	//zwraca lew¹ ga³¹Ÿ
	c_Tree *f_branch_L();
	//zwraca praw¹ ga³¹Ÿ
	c_Tree *f_branch_R();
	//zwraca wartoœæ ga³êzi
	double getVal();
	//dodaje do drzewa korzenie
	bool f_push(c_Tree *branch_L, c_Tree *branch_R);
	//tworzy drogê do ga³êzi
	void f_addRoad(std::string nazwa);
	//wypisuje strukturê drzewa
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

