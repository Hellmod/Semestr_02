#include <windows.h>
#include <iostream>
#include <string>
#include "..\..\library\RM_table.h"


using namespace std;



int main(){
	//f_test(5);
	
	string **tab;
	
	tab = f_createTable<string>(10,2);

	for(size_t i = 0; i < 10; i++){
		tab[i][0] = "ala";
	}

	cout << tab[4][0] << endl;
	
	system("pause");
	return 0;
}