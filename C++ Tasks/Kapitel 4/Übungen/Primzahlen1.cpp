//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 11
// Programm welches einem die Primzahlen im bereich 1-100 ausgibt, indem es schaut ob die zahlen im bereich 1-100 durch die Primzahlen 2,3,5, und 7 teilbar sind

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

int main() {
	
	int i = 0;
	int ii = 0;
	
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);

	vector<int> numbers;
	for (i = 0; i < 101; i++) {
		numbers.push_back(i);
	}

	for (int i= 0; i < 101; ++i) {
		for (ii = 0; ii < 4; ii++) {
			
			if (numbers[i] == 0) { }
             else if ((i%primes[ii])==0) {
				numbers[i] = 0;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		std::cout << primes[i] << " ";
		Sleep(1000);
	}
	for (i = 0; i < 101; ++i) {
		if ((numbers[i]!=0) && (numbers[i]!=1)) {
			std::cout << i << " ";
			Sleep(1000);
		}
	}
	
	keep_window_open();
	return 0;
}