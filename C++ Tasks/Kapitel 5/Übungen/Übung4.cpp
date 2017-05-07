//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 5, S.191 �bungen 4.)
// Program aus der letzten Aufgabe dahingehend korrigiert, dass ein Fehler gemeldet wird, wenn die Eingabe den absoluten Nullpunkt �bersteigt. �nderung sollte in der Funktion durchgef�hrt werden.

#include "std_lib_facilities.h"
#include <limits>

double ctok(double c) {
	if (c < -273.15) error("Ung�ltige Eingabe, da die Temperatur die niedrigste Temperatur �bersteigt!");
	double k = c + 273.15;
	return k;
}

int main() {
	try {
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
	catch (runtime_error& s) {
		std::cerr << s.what() << std::endl;
		keep_window_open();
		return 1;
	}
}