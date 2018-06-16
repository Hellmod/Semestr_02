#include <iostream>
#include "..\..\library\c_Tree.h"
#include <queue>
#include <vector>




using namespace std;



int main(){

	

	c_Tree t1(1, "T1"), t2(2, "T2"), t3(3, "T3"), t4(4, "T4"), t5(5, "T5");

	priority_queue <c_Tree> kolejka;
	priority_queue <c_Tree*, vector<c_Tree*>,functor_SortNodeising> kolejka2;

	kolejka.push(t1);
	kolejka.push(t2);
	kolejka.push(t5);
	kolejka.push(t4);
	kolejka.push(t3);
	kolejka2.push(new c_Tree());

	for(int i = 0; i <= 5; i++){
		c_Tree *tL=new c_Tree(kolejka.top());
		kolejka.pop();
		c_Tree *tR=new c_Tree(kolejka.top());
		kolejka.pop();
		c_Tree t7(tL,tR);
		kolejka.push(t7);

	}



	//s_ListaTree lista(&t1);
	//lista.f_dodajElement(&t2);
	//lista.f_dodajElement(&t3);
	//while(!lista.f_czyPusta()){
	//	cout<<lista.f_szczytowyElement()->f_Wartosc()<<endl;
	//	lista.f_usunElement();
	//}


	system("pause");
	return 0;
}