// PROJECT
#include "..\library\graphicalDisplay.h"
#include "..\library\textDisplay.h"
#include "..\library\circle.h"
#include "..\library\triangle.h"
#include "..\library\parallelogram.h"
#include "..\library\complexShape.h"
#include "..\library\shape.h"
#include "..\library\display.h"

using namespace std;

int main(){
	// utworzenie wskaznikow bibliotek graficznych
	Display *w1 = new GraphicalDisplay();
	Display *w2 = new TextDisplay();
	// utworzenie obiektow ksztaltu figor
	Shape * o1 = new Triangle(w1, 7, 6, 6, -6);
	Shape * o2 = new Parallelogram(w1, 7, 6, 6, -6);
	Shape * o3 = new Circle(w1, 10);
	// utorzenie obiektu ksztalu zlozonego i dodanie do niego figor
	ComplexShape * o4 = new ComplexShape(w1);
	o4->add(o1);
	o4->add(o2);
	o4->add(o3);
	// wyswietlenie figor przy pomocy biblioteki graficznej
	o4->draw();
	o1->draw();
	o2->draw();
	o3->draw();
	// zmiana biblioteki graficznej dla obiekiektow
	o1->changeDisplay(w2);
	o2->changeDisplay(w2);
	o3->changeDisplay(w2);
	o4->changeDisplay(w2);
	//wyswietlenie figor przy pomocy nowo zaladowanj biblioteki graficznej
	o4->draw();
	o1->draw();
	o2->draw();
	o3->draw();
	// zwolnienie miejsca w pamieci obejmujacej utworzone obiekty 
	delete o1;
	delete o2;
	delete o3;
	delete o4;
	delete w2;
	delete w1;

	getchar();
	cin.ignore();
	return 0;
}
