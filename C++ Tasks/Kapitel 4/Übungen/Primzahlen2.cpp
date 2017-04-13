//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 12
// Programm welches einem die Primzahlen in einem vom Benutzer definierten Bereich ausgibt (maximum in diesem fall 1000)

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

int main() {

	int i = 0;
	int ii = 0;
	int eingabe = 0;
	
	vector<int> primes;
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	primes.push_back(11);
	primes.push_back(13);
	primes.push_back(17);
	primes.push_back(19);
	primes.push_back(23);
	primes.push_back(29);
	primes.push_back(31);
	primes.push_back(37);

	std::cout << "Bis zur welcher Zahl sollen die Primzahlen berechnet werden? (maximum:1000)" << std::endl;
	std::cin >> eingabe;

	vector<int> numbers;
	for (i = 0; i < eingabe+1; i++) {
		numbers.push_back(i);
	}

	for (int i= 0; i < eingabe+1; ++i) {
		for (ii = 0; ii < primes.size(); ii++) {
			
			if (numbers[i] == 0) { }
             else if ((i%primes[ii])==0) {
				numbers[i] = 0;
			}
		}
	}

	for (int i = 0; i < primes.size(); i++) {
		std::cout << primes[i] << " ";
		Sleep(100);
	}
	for (i = 0; i < eingabe+1; ++i) {
		
		if ((numbers[i]!=0) && (numbers[i]!=1)) {
			std::cout << i << " ";
			Sleep(100);
		}
	}
	
	keep_window_open();
	return 0;
}