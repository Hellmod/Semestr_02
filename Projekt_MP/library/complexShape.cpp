#include "complexShape.h"

ComplexShape::ComplexShape(Display *w): Shape(w)
{
}
// funkcja rysuje wszystkie ksztalty bedace w tablicy wskaznikow obiektu klasy Shape
void ComplexShape::draw()
{
	int i = 0;
	while (O[i] != nullptr)
	{
		O[i]->draw();
		i++;
	}
}
// funkcja dodaje ksztalt do tablicy wskaznikow obiektu clasy Shape (maksymalnie 5 elementow)
bool ComplexShape::add(Shape *o)
{
	for (int i = 0; i < 5; i++)
	{
		if (O[i] == nullptr)
		{
			O[i] = o;
			return true;
		}
	}
	return false;
}