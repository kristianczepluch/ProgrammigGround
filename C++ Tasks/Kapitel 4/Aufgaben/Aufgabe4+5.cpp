//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.151 Aufgabe 4+5
// 2 Double in einer While schleife einlesen und bei "|" Programm unterbrechen
// Kleineren und größeren Wert jeweils ausgeben
// Innerhalb der If anweisung eine weitere Verschachtelung welche schaut ob die Differenz der Beiden < ist als 10/10000000 und
// ausgibt das die Zahlen fast gleich sind wenn es wahr ist

#include <iostream>
#include "../facilities.h"


int main() {
	vector<int> numbers;
	double eingabe1 = -1;
	double eingabe = -1;
	double eingabe2 = -1;
	while (std::cin >> eingabe1) {
		eingabe = eingabe1;
		std::cin >> eingabe2;
		std::cout << "Ihr eingabe: " << eingabe << " und " << eingabe2 << std::endl;
		if (eingabe < eingabe2) {
			std::cout << "Der kleinere Wert ist: " << eingabe << " und der größere Wert ist: " << eingabe2 << std::endl;
			if ((eingabe2 - eingabe) < (1.0 / 10000000)) {
				std::cout << "Die Beiden Zahlen sind fast gleich." << std::endl;
			}
		}
		else if (eingabe > eingabe2) {
			std::cout << "Der kleinere Wert ist: " << eingabe2 << " und der größere Wert ist: " << eingabe << std::endl;
			if (eingabe < eingabe2 && (eingabe2 - eingabe) < (1.0 / 10000000)) {
				std::cout << "Die Beiden Zahlen sind fast gleich." << std::endl;
			}
		}
	}
	keep_window_open();
	return 0;
}