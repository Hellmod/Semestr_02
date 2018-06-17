#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <fstream>
#include <string>
#include "display.h"

using namespace std;

// bazowa klasa do wyswietlania ksztaltow
class Shape  {
public:
	Display *wsk=nullptr;
	// konstruktor przyjumuje wsk jako wskaznik do klasy display odnoszacego sie dokonkretnej biblioteki graficznej
	Shape(Display *w);
	// wirtualan funkcja pozwalajaca na rysowanie ksztaltow odwolujac sie do clasy Display
	virtual void draw()=0;
	// zmiana biblioteki graficznej przy pomocy zamian wsk na nowy wskaznik clasy Display
	void changeDisplay(Display *newDisplay);
};

#endif
#pragma once
