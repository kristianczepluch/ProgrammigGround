//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, Aufgabe 7 S.117
// Ausgeschriebene Zahlen in Ziffern umwandeln zwischen 0 und 4

#include <iostream>
#include "../facilities.h"

int main() {
	string eingabe = "Keine Eingabe";
	std::cout << "Bitte geben sie eine ausgeschriebene Zahl zwischen 0 und 4 ein: " << std::endl;
	std::cin >> eingabe;
	
	if (eingabe == "null") {
		std::cout << "Die Ziffer lautet: " << "0" << std::endl;
	} else if (eingabe == "eins") {
		std::cout << "Die Ziffer lautet: " << "1" << std::endl;
	} else if (eingabe == "zwei") {
		std::cout << "Die Ziffer lautet: " << "2" << std::endl;
	} else if (eingabe == "drei") {
		std::cout << "Die Ziffer lautet: " << "3" << std::endl;
	} else if  (eingabe == "vier") {
		std::cout << "Die Ziffer lautet: " << "4" << std::endl;
	}
	else {
		std::cout << "Keine Zahl die ich kenne" << std::endl;
	}
	keep_window_open();
}