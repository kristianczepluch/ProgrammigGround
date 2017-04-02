//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.151 Aufgabe 3
// 2 Int in einer While schleife einlesen und bei "|" Programm unterbrechen
// Kleineren und größeren Wert jeweils ausgeben
// Gleiche Werte werden erkannt

#include <iostream>
#include "../facilities.h"


int main() {
	vector<int> numbers;
	int eingabe1 = -1;
	int eingabe = -1;
	int eingabe2 = -1;
	while (std::cin >> eingabe1) {
		eingabe = eingabe1;
		std::cin >> eingabe2;
		std::cout << "Ihr eingabe: " << eingabe << " und " << eingabe2 << std::endl;
		if (eingabe < eingabe2) {
			std::cout << "Der kleinere Wert ist: " << eingabe << " und der größere Wert ist: " << eingabe2 << std::endl;
		}else if (eingabe > eingabe2) { 
			std::cout << "Der kleinere Wert ist: " << eingabe2 << " und der größere Wert ist: " << eingabe << std::endl;}
		else { std::cout << "Die Beiden Werte sind gleich!" << std::endl;}
	}
	keep_window_open();
	return 0;
}