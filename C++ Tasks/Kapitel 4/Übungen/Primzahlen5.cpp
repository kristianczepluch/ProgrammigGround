//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 15
// Programm welches einem die von Benutzer definierten, ersten n Primzahlen berechnet. Funktioniert jedoch nicht bei zu großen Werten, da vorab ermittelt werden müsste wenn ich n zahlen brauche
// bis zur welchen Zahl muss das Sieb dann laufen?

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

int main() {

	vector<int> primes;
	int i, ii, eingabe;
	std::cout << "Die wie viel ersten Primzahlen soll das Programm für sie finden? " << std::endl;
	std::cin >> eingabe;


	vector<int> numbers;
	for (int i = 2; i < 1000+1; i++) {
		numbers.push_back(i);
	}

	for (i = 0; i < numbers.size(); i++) {
		for (ii = 1; ii < numbers.size(); ++ii) {
			if(numbers[i]==0){ }
			else if(numbers[ii]==numbers[i]){ }
			else if (numbers[ii] % numbers[i] == 0) {
				numbers[ii] = 0;
			}
		}
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] != 0) {
			primes.push_back(numbers[i]);
		}
	}

	for (int i = 0; i < eingabe; i++) {
		std::cout << primes[i] << " ";
		Sleep(100);
	}



	keep_window_open();
	return 0;
}