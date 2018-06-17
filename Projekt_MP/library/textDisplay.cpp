#include "textDisplay.h"

void TextDisplay::drawTriangle(int a1, int a2, int b1, int b2)
{
	cout << "\nDrawing a triangle from vectors (" << a1 << ", " << a2 << "), (" << b1 << ", " << b2 << ").";
}
void TextDisplay::drawParallelogram(int a1, int a2, int b1, int b2)
{
	cout << "\nDrawing a parallelogram from vectors (" << a1 << ", " << a2 << "), (" << b1 << ", " << b2 << ").";
}
void TextDisplay::drawCircle(int r)
{
	cout << "\nDrawing a circle with radius " << r<<".";
}
