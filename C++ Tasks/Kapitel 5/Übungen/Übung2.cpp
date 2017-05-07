//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 5, S.191 �bungen 2.)
// Korrigiertes Programm welches Celsius in Kelvin umrechnet und ung�ltige Eingaben des Benutzers abf�ngt

#include "std_lib_facilities.h"
#include <limits>

double ctok(double c) {
	double k = c + 273.15;
	return k;
}

int main() {
	double k; 
	double c;
	
	std::cout << "Bitte geben Sie die gew�nschte Tempreatur in Celsius ein: ";
	std::cin >> c;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Ung�ltige Eingabe! Bitte geben sie einen Double Wert ein: ";
		std::cin >> c;
	}
	
	k = ctok(c);
	std::cout << "Die umgerechnete Eingabe in Kelvin lautet: " << k << endl;
	keep_window_open();
	return 0;
}