//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 5, S.191 Übungen 5.)
// Program aus der letzten Aufgabe dahingehend korrigiert, dass der Benutzer nun in der Lage ist zu wählen in welche Richtung er den Wert umwandeln möchte + Abfangen von falschen Eingaben.

#include "std_lib_facilities.h"
#include <limits>

double ctok(double c) {
	if (c < -273.15) error("Ungültige Eingabe, da die Temperatur die niedrigste Temperatur übersteigt!");
	double k = c + 273.15;
	return k;
}

double ktoc(double c) {
	if (c > 273.15) error("Ungültige Eingabe, da die Temperatur die niedrigste Temperatur übersteigt!");
	double k = c - 273.15;
	return k;
}

int main() {
	try {
		double k;
		double c;
		int option = 0;
		std::cout << "Kelvin-Celsius-Calculator\n" << "Wollen sie (1) von Celsius nach Kelvin oder (2) von Kelvin nach Celsius umrechnen?\nGeben Sie 1 oder 2 ein: " << std::endl;
		std::cin >> option;

		while (std::cin.fail() || option > 2 || option < 1) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Ungültige Eingabe! Bitte geben sie einen Integer Wert von 1 bis 2 ein: ";
			std::cin >> option;
		}

		if (option == 1) {
			std::cout << "Bitte geben Sie die gewünschte Tempreatur in Celsius ein: ";
			std::cin >> c;
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Ungültige Eingabe! Bitte geben sie einen Double Wert ein: ";
				std::cin >> c;
			}
			k = ctok(c);
			std::cout << "Die umgerechnete Eingabe in Kelvin lautet: " << k << endl;
		}
		else {
			std::cout << "Bitte geben Sie die gewünschte Tempreatur in Kelvin ein: ";
			std::cin >> c;
			while (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Ungültige Eingabe! Bitte geben sie einen Double Wert ein: ";
				std::cin >> c;
			}
			k = ktoc(c);
			std::cout << "Die umgerechnete Eingabe in Celsius lautet: " << k << endl;

		}
		keep_window_open();
		return 0;
	}
	catch (runtime_error& s) {
		std::cerr << s.what() << std::endl;
		keep_window_open();
		return 1;
	}
}