//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 14
// Programm welches einem die Primzahlen berechnet mit dem Prinzip des "Sieb des Eratosthenes" bis zu einem beliebig hohem Wert, den der Benutzer definiert

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

int main() {

	vector<bool> gestrichen;
	for (int i = 0; i < 101; i++) {
		gestrichen.push_back(false);
	}


	keep_window_open();
	return 0;
}