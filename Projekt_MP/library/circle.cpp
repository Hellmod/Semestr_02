#include "circle.h"

Circle::Circle(Display *w, int r) :Shape(w), R(r)
{
}
// funkcja rysuje kolo odwolujac sie do wskaznika clasy Shape bazujacego na virtualnej metodzie clasy Display
void Circle::draw()
{
	Wsk = wsk;
	Wsk->drawCircle(R);
}