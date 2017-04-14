//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, Aufgabe 7 S.117
// Sortieralgorithmus für 3 String Werte ohne Schleife, auschließlich durch eine Reihe von Ifs (sortiert alphabetisch)

#include "../facilities.h"

int main() {
	string val1 = "";
	string val2 = "";
	string val3 = "";
	std::cout << "Bitte geben Sie drei Worte getrennt von einem Enter ein: " << std::endl;
	std::cin >> val1 >> val2 >> val3;

	if (((val1 <= val2) && (val1 <= val3)) && (val2 <= val3)) {
		std::cout << "Geordnete Reihenfolge: " << val1 << "," << val2 << "," << val3 << std::endl;
	}
	else if (((val1 <= val2) && (val1 <= val3)) && val2 >= val3) {
		std::cout << "Geordnete Reihenfolge: " << val1 << "," << val3 << "," << val2 << std::endl;
	}
	else if ((val2 <= val1) && (val2 <= val3) && (val1 <= val3)) {
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