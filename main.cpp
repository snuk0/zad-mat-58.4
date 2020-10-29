#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int N = 1100;

int t[N], tmp;

int bin(string x) {
	int ans = 0;
	int licz = 1;
	for (int i = x.size() - 1; i >= 0; i--) {
		if (x[i] == '-')
			ans *= -1;
		if (x[i] == '1')
			ans += licz;
		licz *= 2;
	}
	return ans;
}

int obliczSkok(int ti, int tj, int i, int j) {
	int licznik = (ti - tj) * (ti - tj);
	int mianownik = abs(i - j);
	float ans = (float)licznik / (float)mianownik;
	ans = ceil(ans);
	return (int)ans;
}

int main(int argc, char** argv) {
	ifstream file; //plik wejsciowy
	ofstream fileOut; //plik wynikowy do zapis
	bool wczytaj = false;
	file.open("dane_systemy1.txt"); //otworz plik liczb
	fileOut.open("wyjscie.txt"); //otworz plik do wynikow
	if (file.good())  //sprawdzenie czy plik istnieje
		while (!file.eof()) {
			string x;
			file >> x;
			if (wczytaj) {
				t[tmp] = bin(x);
				tmp++;
			}
			wczytaj = !wczytaj;
		
		}//eof() koniec pliku
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int skok = obliczSkok(t[i], t[j], i, j);
			//cout << skok << " ";
			if (skok > max) {
				max = skok;
				//cout << max << " ";
			}
		}
	}
	cout << "58.4: " << max << endl; //zapisanie najmniejszej liczby z pliku czworkowego do pliku wynikowego
	fileOut << "58.4: " << max << endl; //zapisanie najmniejszej liczby z pliku czworkowego do pliku wynikowego
	file.close();
	fileOut.close();
		
	return 0;
}
