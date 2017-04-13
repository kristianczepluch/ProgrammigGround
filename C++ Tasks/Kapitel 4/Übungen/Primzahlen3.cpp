//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 13
// Programm welches einem die Primzahlen berechnet mit dem Prinzip des "Sieb des Eratosthenes"

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

int main() {

	int i;
	int ii;

	vector<int> numbers;
	for (int i = 2; i < 101; i++) {
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
			std::cout << numbers[i] << " ";
			Sleep(100);
		}
	}



	keep_window_open();
	return 0;
}