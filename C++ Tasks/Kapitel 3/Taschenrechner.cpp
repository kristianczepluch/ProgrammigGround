//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, Aufgabe 7 S.117
// Operation und 2 Operanden einlesen und ergenis ausgeben lassen

#include <iostream>
#include "../facilities.h"

int main() {
	std::cout << "Bitte geben Sie den gewünschten Operator und die zwei Operanden getrennt von einem Enter ein." << std::endl;
	char operation = 'a';
	double val1 = -1;
	double val2 = -1;
	double ergebnis = -1;
	std::cin >> operation >> val1 >> val2;
	if (operation == '+') {
		ergebnis = val1 + val2;
		std::cout << val1 << "+" << val2 << "=" << ergebnis << std::endl;
	} else if (operation == '-') {
		ergebnis = val1 - val2;
		std::cout << val1 << "-" << val2 << "=" << ergebnis << std::endl;
	} else if (operation == '*') {
		ergebnis = val1 * val2;
		std::cout << val1 << "*" << val2 << "=" << ergebnis << std::endl;
	} else if (operation == ':' || operation == '/') {
		ergebnis = val1 / val2;
		std::cout << val1 << "/" << val2 << "=" << ergebnis << std::endl;
	} 
	keep_window_open();
}