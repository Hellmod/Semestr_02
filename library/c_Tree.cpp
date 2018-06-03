#include "c_Tree.h"



c_Tree::c_Tree(){
	wartosc = 0;
}

c_Tree::c_Tree(double wartosc){
	this->wartosc = wartosc;
}

c_Tree::c_Tree(double wartosc, std::string nazwa){
	this->wartosc = wartosc;
	this->nazwa = nazwa;
}

c_Tree::c_Tree(double wartosc, c_Tree *branch_L, c_Tree *branch_R){
	this->wartosc = wartosc;
	this->branch_L = branch_L;
	this->branch_R = branch_R;
}

c_Tree::~c_Tree(){
}

bool c_Tree::f_czyPusta(){
	if(branch_L == nullptr && branch_L == nullptr)
		return true;
	else
		return false;
}

c_Tree * c_Tree::f_Element_L(){
	return this->branch_L;
}

c_Tree * c_Tree::f_Element_R(){
	return this->branch_R;
}

double c_Tree::f_Wartosc(){
	return this->wartosc;
}

bool c_Tree::f_dodajElement(c_Tree *branch_L, c_Tree *branch_R){
	this->branch_L = branch_L;
	this->branch_R = branch_R;
	this->wartosc = branch_L->f_Wartosc() + branch_R->f_Wartosc();
	f_dopiszdroge(this->nazwa);
	return false;
}

void c_Tree::f_dopiszdroge(std::string nazwa2){


	if(this->branch_L != nullptr){
		this->branch_L->f_dopiszdroge(nazwa2);
		this->branch_L->droga += nazwa2 + " ";
	}
	if(this->branch_R != nullptr){
		this->branch_R->f_dopiszdroge(nazwa2);
		this->branch_R->droga += nazwa2 + " ";
	}
}

void c_Tree::f_wypisz(){

	std::cout << this->droga << "<- droga " << this->nazwa << " " << this->wartosc << std::endl;

	if(this->branch_L != nullptr){
		this->branch_L->f_wypisz();
	}
	if(this->branch_R != nullptr){
		this->branch_R->f_wypisz();

	}
}

//------------------------------------------------------------



s_ListaTree::s_ListaTree(c_Tree *element1){
	
	this->drzewo = element1;
	liczba = 1;
}

bool s_ListaTree::f_czyPusta(){
	if(next == nullptr)
		return true;
	else
		return false;
}

int s_ListaTree::f_ileElementow(){
	return liczba;
}

c_Tree * s_ListaTree::f_szczytowyElement(){
	std::cout << drzewo->wartosc << "<-wartosc" << head->drzewo->wartosc << "head wartosc" << std::endl;
	return drzewo;
}

bool s_ListaTree::f_dodajElement(c_Tree *element1){

	s_ListaTree *nowy = new s_ListaTree(element1);
	nowy->next = head;
	if(head == nullptr)
		this->head = new s_ListaTree;
	head->next = nowy;
	













	//s_ListaTree *nowy = new s_ListaTree(element1);
	//nowy->next = head;
	//head = nowy;

	liczba++;
	std::cout << "dodano element o wartosci " << element1->f_Wartosc() << std::endl;
	return 1;
}

bool s_ListaTree::f_usunElement(){
	std::cout << "usuwam element o wartosci " << this->drzewo->f_Wartosc() << std::endl;
	head->next = next->next;
	liczba--;
	return false;
}
