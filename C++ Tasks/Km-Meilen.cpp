//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, Aufgabe 2 S.117

#include <iostream>
#include "../facilities.h"

int main() {
	double miles = 0.0;
	double km = 0.0;
	std::cout << "Bitte geben Sie die Anzahl der Meilen an: " << std::endl;
	std::cin >> miles;
	km = miles*1.609;
	std::cout << "Die Anzahl der Meilen entspricht: " << km << " km. " << std::endl;
	keep_window_open();
}