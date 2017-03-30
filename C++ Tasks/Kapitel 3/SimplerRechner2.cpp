//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, Aufgabe 5 S.117

#include <iostream>
#include "../facilities.h"

int main() {
	double val1 = -1.0;
	double val2 = -1.0;
	std::cout << "Bitte geben sie zwei Kommazahlen getrennt von einem Enter ein." << std::endl;
	std::cin >> val1;
	std::cin >> val2;

	if (val1 < val2) {
		std::cout << "Der kleinste Wert ist: " << val1 << " und der groesste Wert ist: " << val2 << std::endl;
	}
	else {
		std::cout << "Der kleinste Wert ist: " << val2 << " und der groesste Wert ist: " << val1 << std::endl;
	}

	std::cout << "Die Summe ist: " << val1 + val2 << "\nDie Different ist: " << val1 - val2 << "\nDas Produkt ist: "
		      << val1*val2 << "\nUnd der Quotient ist: " << val1 / val2 << std::endl;                         
	keep_window_open();
}