//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.153 5
// Programm welches 2 double Werte und ein Eingabeoperator entgegen nimmt und dann die entsprechende Rechnung durchführt und ausgibt.


#include <iostream>
#include "../facilities.h"

int main() {
	double val1 = 0;
	double val2 = 0;
	string eingabe = "";

	std::cout << "Bitte geben Sie die 2 Operanden und die gewünschte Operation ein: " << std::endl;
	std::cin >> val1 >> val2 >> eingabe;
	if (eingabe == "+") {
		std::cout << val1 << "+" << val2 << "=" << val1 + val2 << std::endl;

	} else if (eingabe == "-") {
		std::cout << val1 << "-" << val2 << "=" << val1 - val2 << std::endl;
	} else if (eingabe == "*") {
		std::cout << val1 << "*" << val2 << "=" << val1*val2 << std::endl;
	} else if (eingabe == "/" || eingabe == ":") {
		std::cout << val1 << "/" << val2 << "=" << val1/val2 << std::endl;
	}
	else { std::cout << "Kein gültiges Rechenzeichen." << std::endl; 
	}
	keep_window_open();
	return 0;
}