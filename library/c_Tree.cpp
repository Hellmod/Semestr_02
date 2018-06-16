#include "c_Tree.h"



c_Tree::c_Tree(){
	value = 0;
	f_addRoad(this->name);
}

c_Tree::c_Tree(double value){
	this->value = value;
	f_addRoad(this->name);
}

c_Tree::c_Tree(double value, std::string name){
	this->value = value;
	this->name = name;
	f_addRoad(this->name);
}

c_Tree::c_Tree(double value, c_Tree *branch_L, c_Tree *branch_R){
	this->value = value;
	this->branch_L = branch_L;
	this->branch_R = branch_R;
	f_addRoad(this->name);
}

c_Tree::c_Tree(double value, c_Tree * branch_L, c_Tree * branch_R, std::string name){
	this->value = value;
	this->branch_L = branch_L;
	this->branch_R = branch_R;
	f_addRoad(this->name);
}

c_Tree::c_Tree(c_Tree * branch_L, c_Tree * branch_R){
	this->branch_L = branch_L;
	this->branch_R = branch_R;
	this->value = branch_L->getVal() + branch_R->getVal();
	f_addRoad(this->name);
}

c_Tree::c_Tree(c_Tree * branch_L, c_Tree * branch_R, std::string name){
	this->name = name;
	this->branch_L = branch_L;
	this->branch_R = branch_R;
	this->value = branch_L->getVal() + branch_R->getVal();
	f_addRoad(this->name);
}

c_Tree::~c_Tree(){
}

bool c_Tree::f_isEmpty(){
	if(branch_L == nullptr && branch_L == nullptr)
		return true;
	else
		return false;
}

c_Tree * c_Tree::f_branch_L(){
	return this->branch_L;
}

c_Tree * c_Tree::f_branch_R(){
	return this->branch_R;
}

double c_Tree::getVal(){
	return this->value;
}

bool c_Tree::f_push(c_Tree *branch_L, c_Tree *branch_R){
	this->branch_L = branch_L;
	this->branch_R = branch_R;
	this->value = branch_L->getVal() + branch_R->getVal();
	f_addRoad(this->name);
	return false;
}

void c_Tree::f_addRoad(std::string name){

	if(this->branch_L != nullptr){
		this->branch_L->f_addRoad(name);
		this->branch_L->road += name + " ";
	}
	if(this->branch_R != nullptr){
		this->branch_R->f_addRoad(name);
		this->branch_R->road += name + " ";
	}
}

void c_Tree::f_showTree(){

	std::cout << this->road << "<- droga " << this->name << " " << this->value << std::endl;

	if(this->branch_L != nullptr){
		this->branch_L->f_showTree();
	}
	if(this->branch_R != nullptr){
		this->branch_R->f_showTree();

	}
}

bool operator==(c_Tree t1, c_Tree t2){
	if(t1.getVal() == t2.getVal())
		return true;
	else
		return false;
}

bool operator<(c_Tree t1, c_Tree t2){
	if(t1.getVal() < t2.getVal())
		return true;
	else
		return false;
}

bool operator>(c_Tree t1, c_Tree t2){
	if(t1.getVal() > t2.getVal())
		return true;
	else
		return false;
}

bool functor_SortTreeLess::operator()(c_Tree * nod1, c_Tree * nod2){
	if(nod1->getVal() > nod2->getVal())
		return true;
	return false;
}

bool functor_SortTreeGreater::operator()(c_Tree * nod1, c_Tree * nod2){
	if(nod1->getVal() < nod2->getVal())
		return true;
	return false;

}
