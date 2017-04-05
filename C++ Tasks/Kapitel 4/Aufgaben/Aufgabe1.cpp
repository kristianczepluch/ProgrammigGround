//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.151 Aufgabe 1
// 2 Int in einer While schleife einlesen und bei "|" Programm unterbrechen

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
	}
	keep_window_open();
	return 0;
}