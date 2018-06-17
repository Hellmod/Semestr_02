#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"

using namespace std;

class Circle :public Shape {
public:
	Display *Wsk=nullptr;
	// promien kola
	int R;
	Circle(Display *w, int r);
	virtual void draw();
};

#endif
#pragma once
