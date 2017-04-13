//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 14
// Programm welches einem die Primzahlen berechnet mit dem Prinzip des "Sieb des Eratosthenes" bis zu einem von Benutzer festgelegtem Wert. 

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

int main() {
	
	int grenze;
	std::cout << "Bitte geben sie den maximalen wert ein zu dem Sie die Primzahlen berechnen möchten: " << std::endl;
    std:cin >> grenze;
	

	vector<int> primes;

	for (int i = 0; i < grenze; i++) {
		primes.push_back(0);
	}

	for (int i = 2; i < grenze; i++) {
		if (primes[i] == 0) {
			
			for (int ii = 2; ii*i < grenze ; ii++) {
				primes[ii*i] = 1;
			}
		}
	}

	for (int i = 2; i < primes.size(); i++) {
		if (primes[i] == 0) {
			std::cout << i << " ";
			Sleep(100);
		}
	}
	keep_window_open();
	return 0;
}