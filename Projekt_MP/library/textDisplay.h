#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <fstream>
#include <string>
#include "display.h"

using namespace std;

// clasa wypisuje nazwy i parametry figur
class TextDisplay : public Display {
public:
	virtual void drawTriangle(int a1, int a2, int b1, int b2);
	virtual void drawParallelogram(int a1, int a2, int b1, int b2);
	virtual void drawCircle(int r);
};

#endif
#pragma once