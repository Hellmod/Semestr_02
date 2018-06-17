#include "graphicalDisplay.h"

// rysuje trojkat na podstawie wektorow o wspolrzednych [a1,a2] oraz [b1,b2]
void GraphicalDisplay::drawTriangle(int a1, int a2, int b1, int b2)
{
	// obliczane jest pole trojkata o podanych wektorach
	double tr = pole(a1, a2, b1, b2, 0, 0);
	// z-> przyjmuje wartosc wiekszej z dwoch wspolrzednych, potrzebne do okreslenia max polozenia w poziomie
	int z = (a1 > b1) ? a1 : b1;
	// petle okreslaja maksymalny zakres trojkata w pione <a2,b2> oraz w poziomie <0,z> j->wsp w pionie; i->wsp w poziomie
	for (int j = a2; j >(b2 - 1); j--)
	{
		for (int i = 0; i < (z + 1); i++)
		{
			// obliczane sa trzy pola trojkata utworzonego przez wspolzedne wektorow i pare wspolzednych (i,j) 
			double p1 = pole(a1, a2, b1, b2, i, j);
			double p2 = pole(0, 0, b1, b2, i, j);
			double p3 = pole(a1, a2, 0, 0, i, j);
			// obliczana jest suma wszystkich 3 trojkatow
			double pc = p1 + p2 + p3;
			// jezeli suma 3 trojkatow jest rowna polu trojkata utworzonego z wektorow to badany punkt nalezy do trojkata
			if (((tr + 0.1) > pc) && ((tr - 0.1) < pc))
				cout << "t";
			else
				cout << " ";
		}
		cout << endl;
	}
}
// rysuje rownoleglobok na podstawie wektorow o wspolrzednych [a1,a2] oraz [b1,b2]
void GraphicalDisplay::drawParallelogram(int a1, int a2, int b1, int b2)
{
	// obliczane sa dlugosci wektorow tworzacy boki rownolegloboku
	double dl_a = sqrt(pow((a1 - 0), 2) + pow((a2 - 0), 2));
	double dl_b = sqrt(pow((b1 - 0), 2) + pow((b2 - 0), 2));
	// obliczane jest pole worwnolegloboku
	double P = dl_a*dl_b;
	// petle okreslaja maksymalny zakres rownolegloboku w pione <a2,b2> oraz w poziomie <0,a1+b1> j->wsp w pionie; i->wsp w poziomie
	for (int j = a2; j >(b2 - 1); j--)
	{
		for (int i = 0; i < (a1 + b1 + 1); i++)
		{
			// obliczane sa cztery pola trojkata utworzonego przez wspolzedne wektorow i pare wspolzednych (i,j) 
			double p1 = pole(a1, a2, (a1 + b1), (a2 + b2), i, j);
			double p2 = pole((a1 + b1), (a2 + b2), b1, b2, i, j);
			double p3 = pole(0, 0, b1, b2, i, j);
			double p4 = pole(a1, a2, 0, 0, i, j);
			// obliczana jest suma wszystkich 4 trojkatow
			double pc = p1 + p2 + p3 + p4;
			// jezeli suma 4 trojkatow jest rowna polu rownolegloboku to badany punkt nalezy do trojkata
			if (((P + 0.2) > pc)||(((P + 0.2) > pc) && ((P - 0.2) < pc)))
				cout << "p";
			else
				cout << " ";
		}
		cout << endl;
	}
}
// rysuje kolo o promieniu r
void GraphicalDisplay::drawCircle(int r)
{
	// petle okreslaja maksymalny zakres kola w pione <-r,r> oraz w poziomie <0,2r>
	for (int i = r; i > ((-1 * r) - 1); i--)
	{
		for (int j = 0; j < ((2 * r) + 1); j++)
		{
			// na podstawie wzoru x^2 + y^2 = r^2 okreslane jest czy punkt nalezy do kola i->y; j->x
			float x = pow((i - 0), 2) + pow((j - r), 2);
			if ((x - 0.01) < (pow(r, 2)))
				cout << "c";
			else
				cout << " ";
		}
		cout << endl;
	}
}
// metoda oblicza pole na podstawie wspolzednch 3 wierzcholkow (a,b), (c,d) oraz (e,f)
double GraphicalDisplay::pole(int a1, int a2, int b1, int b2, int e, int f)
{
	// liczone sa dlugosci poszczegolnych bokow
	double dl_a = sqrt(pow((a1 - e), 2) + pow((a2 - f), 2));
	double dl_b = sqrt(pow((b1 - e), 2) + pow((b2 - f), 2));
	double dl_c = sqrt(pow((a1 - b1), 2) + pow((a2 - b2), 2));
	// nastepnie obliczany jest obwod trojkata i polowa jego wartosci-> p - prametr potrzbny do liczenia pola
	float obw = dl_a + dl_b + dl_c;
	double p = obw / 2;
	// obliczenie pola trojkata na podstawie wzory wykorzystujacego dlugosci jego bokow
	double P = sqrt(sqrt(pow((p*(p - dl_a)*(p - dl_b)*(p - dl_c)), 2)));
	return P;
}