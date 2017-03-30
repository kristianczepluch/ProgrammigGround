//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, Aufgabe 4 S.117

#include <iostream>
#include "../facilities.h"

int main() {
	int val1 = -1;
	int val2 = -1;
	std::cout << "Bitte geben sie zwei ganze Zahlen getrennt von einem Enter ein." << std::endl;
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