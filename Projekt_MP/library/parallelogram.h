#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"

using namespace std;

class Parallelogram : public Shape {
public:
	Display *Wsk = nullptr;
	// wspolzedne wektowow
	int A1, A2, B1, B2;
	Parallelogram(Display *w, int a1, int a2, int b1, int b2);
	virtual void draw();
};

#endif
#pragma once
