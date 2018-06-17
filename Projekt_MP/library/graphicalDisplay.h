#ifndef GRAPHICALDISPLAY_H
#define GRAPHICALDISPLAY_H

#include <iostream>
#include <fstream>
#include <string>
#include "display.h"

using namespace std;

// clasa rysujace ksztalty figur
class GraphicalDisplay : public Display {
public:
	virtual void drawTriangle(int a1, int a2, int b1, int b2);
	virtual void drawParallelogram(int a1, int a2, int b1, int b2);
	virtual void drawCircle(int r);
	// metoda oblicza pole na podstawie wspolzednch 3 wierzcholkow (a,b), (c,d) oraz (e,f)
	double pole(int a, int b, int c, int d, int e, int f);
};

#endif
#pragma once
