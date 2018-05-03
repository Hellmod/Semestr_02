/*
Program generuje plik tekstowy (out3.txt), ktory zawiera ciag podzialow liczby n w porzadku odwrotnym do leksykograficznego

oFile - plik dla danych wyjsciowych
n - liczba ktora program podzieli na podzialy
*/

#include <iostream>
#include <fstream>

template<typename U>
void ft_destroytable1d(U* T){
	delete[] T;
	T = nullptr;
}

template<typename U>
U* ft_createtable1d(int size, U* T){
	if(size <= 0)
		return nullptr;

	try{ T = new U[size]; } catch(std::bad_alloc){
		std::cout << "!";
		exit(EXIT_FAILURE);
	}
	return T;
}

void f_close(std::fstream &File){
	File.close();
}

bool f_createfile(std::string file_name){
	std::fstream File;
	File.open(file_name, std::fstream::out | std::fstream::trunc);
	if(File.is_open()){
		f_close(File);
		return true;
	}
	else
		return false;
}

bool f_open(std::fstream &File, std::string file_name){
	File.open(file_name, std::fstream::in | std::fstream::out);
	if(File.is_open())
		return true;
	else
		return false;

}

bool f_invertedlexicograpical_seriesdivisions(int n, std::fstream& File){
	/*
	ogolna zasada dzialania:
	liczby podzialu do wypisania sa zapisywane w tablicy S a ilosc tych liczb
	jaka nalezy wypisac jest w tablicy R pod tym samym indeksem co wartosc do wypisania

	B - wskaznik na tablice pomocnicza
	coutner - liczba dotychczas wygenerowanych podzbiorow
	p - zmienna potrzebna do algorytmu
	*/

	int* S = nullptr;
	int* R = nullptr;
	int d, p, sum;

	if(n <= 0)
		return false;

	if(!(S = ft_createtable1d<int>(n + 1, S))){ std::cout << "!\n"; exit(EXIT_FAILURE); }
	if(!(R = ft_createtable1d<int>(n + 1, R))){ std::cout << "!\n"; exit(EXIT_FAILURE); }
	for(int i = 1; i <= n; ++i){ S[i] = 0; }
	for(int i = 1; i <= n; ++i){ R[i] = 0; }

	S[1] = n; R[1] = 1; d = 1;

	File << S[1] << std::endl;

	while(S[1] > 1){
		sum = 0;
		if(S[d] == 1)
			sum += R[d--];

		sum += S[d];
		--(R[d]);
		p = S[d] - 1;
		if(R[d] > 0)
			++d;

		S[d] = p;
		R[d] = sum / p;
		p = sum % p;

		if(p != 0){
			S[++d] = p;
			R[d] = 1;
		}
		else
			R[d + 1] = 0;

		for(int i = 1; i <= n; ++i){
			for(int j = R[i]; j > 0; --j)
				File << S[i] << " ";
		}
		File << std::endl;

	}
	ft_destroytable1d<int>(S);
	ft_destroytable1d<int>(R);
	return true;
}

int main(void){
	std::fstream oFile;
	const int n = 10;

	if(!f_createfile("out3.txt")){ std::cout << "!\n"; exit(EXIT_FAILURE); }
	if(!f_open(oFile, "out3.txt")){ std::cout << "!\n"; exit(EXIT_FAILURE); }

	if(!f_invertedlexicograpical_seriesdivisions(n, oFile)){ std::cout << "!\n"; exit(EXIT_FAILURE); }
	std::cout << "DONE" << std::endl;
	return 0;
}