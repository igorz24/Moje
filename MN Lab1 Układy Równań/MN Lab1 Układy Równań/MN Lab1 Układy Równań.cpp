#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <time.h>

using namespace std;

class Macierz_Seidel {
public:
	int nA, nB, MLI;
	double epsilon;
	int iterator = 0;
	double norma = 0;
	string nazwa_pliku;
	vector <vector <double>> A;
	vector <vector <double>> alfa;
	vector <double> B;
	vector <double> beta;

	vector<double> nowyX;
	vector<double> staryX;

	Macierz_Seidel() {
		cout << "Podaj: nazwa_pliku, rozmiar_A, epsilon, MLI:\n";
		cin >> nazwa_pliku >> nA >> epsilon >> MLI;
		nB = nA;
		vector <double> temp;
		for (int i = 0; i < nA; i++)
			temp.push_back(0);
		for (int i = 0; i < nA; i++)
			A.push_back(temp);
		temp.clear();
		for (int i = 0; i < nB; i++)
			B.push_back(0);
		alfa = A;
		beta = B;
		wczytaj_z_pliku();
	}

	void wczytaj_z_pliku() {
		fstream plik;
		plik.open(nazwa_pliku, ios::in);
		if (!plik.is_open())
			cout << "Nie wczytano!\n";
		for (int i = 0; i < nA; i++)
			for (int j = 0; j < nA; j++)
				plik >> A[i][j];
		for (int i = 0; i < nB; i++)
			plik >> B[i];
		plik.close();
	}

	int funkcja_b() {
		for (int i = 0; i < nA; i++)
			if (A[i][i] == 0)
				return 0;
		for (int i = 0; i < nA; i++) {
			for (int j = 0; j < nA; j++)
				if (i == j)
					alfa[i][j] = 0;
				else
					alfa[i][j] = -A[i][j] / A[i][i];
		}
		for (int i = 0; i < nB; i++)
			beta[i] = B[i] / A[i][i];
		return 1;
	}

	int funkcja_c() {
		nowyX = beta;
		do {
			norma = 0;
			staryX = nowyX;
			iterator++;
			for (int i = 0; i < nA; i++) {
				double temp_sum = 0.0;
				for (int j = 0; j < i; j++)
					temp_sum += alfa[i][j] * nowyX[j];
				for (int j = i + 1; j < nA; j++)
					temp_sum += alfa[i][j] * staryX[j];
				nowyX[i] = temp_sum + beta[i];
			}
			for (int i = 0; i < nA; i++)
				norma += abs(nowyX[i] - staryX[i]);
			norma = norma / double(nA);
		} while (iterator< MLI && epsilon < norma);
		return iterator;
	}

	void funkcja_d(int i) {
		fstream plik;
		plik.open(("raport " + nazwa_pliku + ".txt"), ios::out);
		plik << "Dane wejsciowe:\n";
		plik << "Dokladnosc espilon: " << epsilon << "\tMaksymalna liczba iteracji: " << MLI << endl << endl;
		plik << "Macierz A:";
		for (int i = 1; i < nA; i++)
			plik << "\t";
		plik << "Macierz B: \n";
		for (int i = 0; i < nA; i++) {
			plik << "| ";
			for (int j = 0; j < nA; j++)
				plik << A[i][j] << "\t";
			plik << "| " << B[i];
			plik << "\n";
		}
		plik << "\n";
		if (i == 0) {
			plik << "Probowano wykonac dzielenie przez zero do obliczenia macierzy alfa\nPrzerwanie obliczen\n";
			return;
		}
		plik << "Macierz alfa:";
		for (int i = 1; i < nA; i++)
			plik << "\t";
		plik << "Macierz beta: \n";
		for (int i = 0; i < nA; i++) {
			plik << "| ";
			for (int j = 0; j < nA; j++)
				plik << alfa[i][j] << "\t";
			plik << "| " << beta[i] << " \n";
		}
		plik << "\n";
		plik << scientific;
		plik.precision(10);
		plik << "Liczba wykonanych iteracji: " << iterator << endl;
		plik << "Wartoœæ drugiej normy: " << norma << endl << endl;
		plik << "Ostatnio wykonana iteracja:\t\t Przedostatnia wykonana iteracja:\n";
		for (int i = 0; i < nB; i++) {
			plik << nowyX[i] << "  \t\t";
			plik << staryX[i] << "\n";
		}
		plik << "\nBlad bezwzgledny rozwiazania:\n";
		for (int j = 0; j < nA; j++)
			plik << 1 - nowyX[j] << "\n";
		plik.close();
		cout << "Wygenerowano raport do pliku: " << "raport " + nazwa_pliku << endl;
	}
};

int main() {
	Macierz_Seidel macierz;
	int i = macierz.funkcja_b();
	macierz.funkcja_c();
	macierz.funkcja_d(i);
	system("pause");
	return 0;
}