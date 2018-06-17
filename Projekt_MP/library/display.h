#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Podstawowa klasa (interfejs) deklarujaca metody wyswietlania poszczegolnych ksztaltow
class Display {
public:
	virtual void drawTriangle(int a1, int a2, int b1, int b2)=0;
	virtual void drawParallelogram(int a1, int a2, int b1, int b2)=0;
	virtual void drawCircle(int r)=0;
};


#endif
#pragma once
