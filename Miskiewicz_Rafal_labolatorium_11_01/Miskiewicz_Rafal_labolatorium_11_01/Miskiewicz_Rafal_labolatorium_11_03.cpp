#include <iostream>
#include "..\..\library\c_Tree.h"
#include "..\..\library\RM_lib.h"
#include <queue>
#include <vector>

using namespace std;

int main(){	
	{
		cout << PL("Drzewo dla czêstotliwoœci wystêpowywania:") << endl;
		int name = 1;
		priority_queue <c_Tree*, vector<c_Tree*>, functor_SortTreeLess> queue;
		queue.push(new c_Tree(12, "A"));
		queue.push(new c_Tree(7, "B"));
		queue.push(new c_Tree(18, "I"));
		queue.push(new c_Tree(10, "M"));
		queue.push(new c_Tree(9, "S"));
		queue.push(new c_Tree(5, "X"));
		queue.push(new c_Tree(2, "Z"));
		
		while(queue.size() > 1){
			c_Tree *tL = new c_Tree(*queue.top());
			queue.pop();
			c_Tree *tR = new c_Tree(*queue.top());
			queue.pop();
			queue.push(new c_Tree(tL, tR, "T" + to_string(name)));
			name++;
		}

		queue.top()->f_showTree();
		cout << endl << endl;
	}

	{
		cout << PL("Drzewo dla prawdopodobieñstwa wystêpowywania:") << endl;
		int name = 1;
		priority_queue <c_Tree*, vector<c_Tree*>, functor_SortTreeGreater> queue;
		queue.push(new c_Tree(0.11, "c"));
		queue.push(new c_Tree(0.22, "e"));
		queue.push(new c_Tree(0.16, "i"));
		queue.push(new c_Tree(0.12, "r"));
		queue.push(new c_Tree(0.15, "s"));
		queue.push(new c_Tree(0.10, "t"));
		queue.push(new c_Tree(0.14, "x"));
				
		while(queue.size() > 1){
			c_Tree *tL = new c_Tree(*queue.top());
			queue.pop();
			c_Tree *tR = new c_Tree(*queue.top());
			queue.pop();
			queue.push(new c_Tree(tL, tR, "T" + to_string(name)));
			name++;
		}

		queue.top()->f_showTree();
	}

	system("pause");
	return 0;
}