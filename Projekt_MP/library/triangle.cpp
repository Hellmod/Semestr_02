#include "triangle.h"

Triangle::Triangle(Display *w, int a1,int a2,int b1,int b2): Shape(w), A1(a1), A2(a2), B1(b1), B2(b2)
{
}
// funkcja rysuje trojkat odwolujac sie do wskaznika clasy Shape bazujacego na virtualnej metodzie clasy Display
void Triangle::draw()
{
	Wsk = wsk;
	Wsk->drawTriangle(A1, A2, B1, B2);
}