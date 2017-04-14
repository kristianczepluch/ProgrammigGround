//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, S.117 Übung 8
// Programm welches einem berechnet ob es sich bei der Eingabe um eine gerade oder ungerade Zahl handelt. 

#include "../facilities.h"

int main() {

	int eingabe = -1;

	std::cout << "Bitte geben Sie ein, welche Zahl sie überprüfen möchten: " << std::endl;
	std::cin >> eingabe;

	if ((eingabe % 2) == 0) {
		std::cout << eingabe << " ist eine gerade Zahl." << std::endl;

	}
	else {
		std::cout << eingabe << " ist eine ungerade Zahl." << std::endl;
	}
	
	keep_window_open();
	return 0;
}