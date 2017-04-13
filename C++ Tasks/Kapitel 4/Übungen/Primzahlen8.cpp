//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 15
// Programm welches einem die ersten n Primzahlen berechnet mit dem Prinzip des "Sieb des Eratosthenes" bis zu einem von Benutzer festgelegtem Wert. 

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

int main() {

	int primzähler = 0;
	int grenze = 100000;
	int eingabe;
	std::cout << "Bitte geben sie an die wie viel ersten Primzahlen sie benötigen: " << std::endl;
    std:cin >> eingabe;
	
	vector<int> solutions;
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
	int i = 2;
	while (primzähler < eingabe) {
		if (primes[i] == 0) {
			primzähler++;
			std::cout << i << " ";
			Sleep(10);
		}
		i++;
	}
	
	keep_window_open();
	return 0;
}