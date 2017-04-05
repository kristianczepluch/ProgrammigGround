//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, Aufgabe 6 S.117
// Sortieralgorithmus für 3 Integer Werte ohne Schleife, auschließlich durch eine Reihe von Ifs

#include <iostream>
#include "../facilities.h"

int main() {
	int val1 = -1;
	int val2 = -1;
	int val3 = -1;
	std::cout << "Bitte geben Sie drei ganze Zahlen getrennt von einem Enter ein: " << std::endl;
	std::cin >> val1 >> val2 >> val3;

	if (((val1 <= val2) && (val1 <= val3)) && (val2<=val3)){
		std::cout << "Geordnete Reihenfolge: " << val1 << "," << val2 << "," << val3 << std::endl;
	}
	else if (((val1 <= val2) && (val1 <= val3)) && val2 >= val3) {
		std::cout << "Geordnete Reihenfolge: " << val1 << "," << val3 << "," << val2 << std::endl;
	}
	else if ((val2<=val1)&&(val2<=val3) && (val1<=val3)) {
		std::cout << "Geordnete Reihenfolge: " << val2 << "," << val1 << "," << val3 << std::endl;
	}
	else if ((val2 <= val1) && (val2 <= val3) && (val1 >= val3)) {
		std::cout << "Geordnete Reihenfolge: " << val2 << "," << val3 << "," << val1 << std::endl;
	}
	else if ((val3 <= val1) && (val3 <= val2) && (val1 <= val2)) {
		std::cout << "Geordnete Reihenfolge: " << val3 << "," << val1 << "," << val2 << std::endl;
	}
	else if ((val3 <= val1) && (val3 <= val2) && (val1 >= val2)) {
		std::cout << "Geordnete Reihenfolge: " << val3 << "," << val2 << "," << val1 << std::endl;
	}
	keep_window_open();
}