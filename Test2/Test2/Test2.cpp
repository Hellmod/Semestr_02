// Test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <windows.h>
#include <iostream>
#include <string>
#include "..\..\library\RM_table.h"


using namespace std;



int main(){
	string *tab;

	tab = f_createTable<string>(10);
	for(size_t i = 0; i < 10; i++){
		tab[i] = "ala";
	}

	cout << tab[4] << endl;
	system("pause");
	return 0;
}

