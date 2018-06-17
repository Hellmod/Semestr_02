#ifndef COMLEXSHAPE_H
#define COMLEXSHAPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"

using namespace std;

// klasa umozliwiajaca tworznie zlozonych ksztaltow
class ComplexShape  : public Shape {
public:
	// tablica przy pomocy ktorej bedzie mozna polaczyc 5 ksztaltow
	Shape *O[5];
	ComplexShape(Display *w);
	virtual void draw();
	// dodaje ksztalt o do tablicy figor
	bool add(Shape *o);
};


#endif
#pragma once
