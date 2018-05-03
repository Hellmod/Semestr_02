/*
Program generuje plik tekstowy (out2.txt), ktory zawiera wszystkie k-elementowe podzbiory zbioru {1, ..., n} w porzadku leksykograficznym

oFile - plik dla danych wyjsciowych
n - wielkosc zbioru {1,...,n} z ktorego tworzone sa podzbiory
k - wielkosc podzbiorow tworzonych ze zbioru n
*/

#include <iostream>
#include <fstream>

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

template<typename U>
void ft_destroytable1d(U* T){
	delete[] T;
	T = nullptr;
}

bool f_lexicograpical_subsetgenerator(int n, int k, std::fstream& File){
	/*
	B - wskaznik na tablice pomocnicza
	coutner - liczba dotychczas wygenerowanych podzbiorow
	p - zmienna potrzebna do algorytmu
	*/

	int* B = nullptr;
	int p;

	if(k >= n || k <= 0 || n <= 0)
		return false;

	if(!(B = ft_createtable1d<int>(k + 1, B)  )){ std::cout << "!\n"; exit(EXIT_FAILURE); }
	for(int i = 1; i <= k; ++i)
		B[i] = i;
	p = k;
	while(p >= 1){
		for(int i = 1; i <= k; ++i)
			File << B[i] << " ";
		File << std::endl;

		if(B[k] == n)
			--p;
		else
			p = k;

		if(p >= 1)
			for(int i = k; i >= p; --i)
				B[i] = B[p] + i - p + 1;
	}
	ft_destroytable1d<int>(B);
	return true;
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


int main(void){
	std::fstream oFile;
	const int n = 8;
	const int k = 5;

	if(!f_createfile("out2.txt")){ std::cout << "!\n"; exit(EXIT_FAILURE); }
	if(!f_open(oFile, "out2.txt")){ std::cout << "!\n"; exit(EXIT_FAILURE); }

	if(!f_lexicograpical_subsetgenerator(n, k, oFile)){
		std::cout << "!\n";
		exit(EXIT_FAILURE);
	}
	std::cout << "DONE" << std::endl;
	return 0;
}