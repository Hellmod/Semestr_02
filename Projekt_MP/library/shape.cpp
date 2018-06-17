#include "shape.h"

Shape::Shape(Display *w)
{
	wsk = w;
}
void Shape::draw()
{
}
void Shape::changeDisplay(Display *newDisplay)
{
	 wsk = newDisplay;
}