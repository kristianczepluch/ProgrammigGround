//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 5, S.191 Übungen 6.)
// Program, welches Celsius in Fahrenheit und umgekehrt je nach Auswahl des Benutzers umrechnet.

#include "std_lib_facilities.h"
#include <limits>

double ctof(double c) {
	double f = c*1.8+32;
	return f;
}

double ftoc(double f) {
	double c = (f - 32) / 1.8;
	return c;
}

int main() {

	double eingabe = 0;
	int option = 0;
	double ausgabe = 0;
	std::cout << "Bitte geben Sie ein ob Sie (1) von Celsius nach Fahrenheit oder (2) von Fahrenheit nach Celsius umrechnen wollen: " << std::endl;
	std::cin >> option;
	try {
		while (std::cin.fail() || option < 1 || option > 2) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Ungültige Eingabe! Bitte geben sie einen Double Wert ein: ";
			std::cin >> option;
		}
		if (option == 1) {
			std::cout << "Bitte geben Sie die die Temperatur (Double oder Int) ein die Sie umrechenen möchten: " << std::endl;
			std::cin >> eingabe;
			while (cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, 'n');
				std::cout << "Ungültige Eingabe!n Versuchen Sie es nocheinmal: ";
				std::cin >> eingabe;
			}
			ausgabe = ctof(eingabe);
			std::cout << "Ihre Eingabe: " << eingabe << " Celsius entspricht: " << ausgabe << " Fahrenheit" << std::endl;
			keep_window_open();
		}
		else {
			std::cout << "Bitte geben Sie die die Temperatur (Double oder Int) ein die Sie umrechenen möchten: " << std::endl;
			std::cin >> eingabe;
			while (cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, 'n');
				std::cout << "Ungültige Eingabe!n Versuchen Sie es nocheinmal: ";
				std::cin >> eingabe;
			}
			ausgabe = ctof(eingabe);
			std::cout << "Ihre Eingabe: " << eingabe << " Fahrenheit entspricht: " << ausgabe << " Celsius" << std::endl;
			keep_window_open();
		}
		return 0;
	}
	catch (runtime_error& s) {
		std::cerr << s.what() << std::endl;
		keep_window_open();
		return 1;
	}
}