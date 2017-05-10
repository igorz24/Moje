// wzorce.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
using namespace std;

// Zad 1A
template <typename typ> 
class kalk
{
public:
	kalk() = default;
	~kalk() = default;
	
	typ multiply(typ x, typ y);
	typ add(typ x, typ y);
	typ subtract(typ x, typ y);
	typ divide(typ x, typ y);
};



template <typename typ>
typ kalk<typ>::multiply(typ x, typ y)
{
	return x*y;
}

template <typename typ>
typ kalk<typ>::add(typ x, typ y)
{
	return x + y;
}

template <typename typ>
typ kalk<typ>::subtract(typ x, typ y)
{
	return x - y;
}

template <typename typ>
typ kalk<typ>::divide(typ x, typ y)
{
	if (y == 0) throw 0;
	return x/y;
}

// Zad 1B
//Specjalizacja
template<>
class kalk <string> {
private:
	double wartosc_a;
	double wartosc_b;
public:
	kalk(string a, string b) {
		string tab[10] = { "zero","jeden", "dwa", "trzy", "cztery", "piêæ", "szeœæ", "siedem", "osiem", "dziewiêæ" };
		for (int i = 0; i < 10; i++) {
			if (a == tab[i]) wartosc_a = i;
			if (b == tab[i]) wartosc_b = i;
		}
	}

		double add();
		double multiply();
		double subtract();
		double divide();

};

	double kalk<string>::add() {
		return wartosc_a + wartosc_b;
	}

	double kalk<string>::multiply() {
		return wartosc_a * wartosc_b;
	}

	double kalk<string>::subtract() {
		return wartosc_a - wartosc_b;
	}

	double kalk<string>::divide() {
		if (wartosc_b == 0) throw 0;
		return wartosc_a / wartosc_b;
	}



	// Zad 2
	
	// Zwyk³a funkcja rekurencyjna
	int fibonacci(int n) {
		if (n == 0) return 0;
		else if (n == 1) return 1;
		else return fibonacci(n - 1) + fibonacci(n - 2);
	}

	template<static const int n>
	struct Fib
	{
		static const int el = Fib<n - 1>::el + Fib<n - 2>::el;
	};

	template<>
	struct Fib<0> {
		static const int el = 0;
	};

	template<>
	struct Fib<1> {
		static const int el = 1;
	};


int main()
{
	// Zad 1
	kalk <int> KI;
	kalk <double> KD;

	cout << KI.add(10, 5) << endl;
	cout << KD.subtract(14.12, 124.1241) << endl;
	cout << KI.multiply(1.2, 12) << endl;


	kalk <string> KS("cztery", "osiem");
	cout << KS.multiply() << endl;

	// Zad 2
	const int n = 35;

	clock_t start = clock();

	cout << fibonacci(n) << endl; //d³ugo
	cout << "czas wykonania zwyk³ej funkcji rekurencyjnej " << clock() - start << "ms" << endl;

	start = clock();
	cout << Fib<n>::el << endl; //krótko
	cout << "czas wykonania metafunkcji " << clock() - start << "ms" << endl ;


	system("pause");
}

