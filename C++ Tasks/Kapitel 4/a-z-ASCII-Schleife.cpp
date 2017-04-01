//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.138 - Testen Sie Ihr Können
// Programm welches in einer Schleife das charset a-z aus dem ASCII Zeichensatz ausgibt mit dem jeweiligen Integer Wert

#include <iostream>
#include "../facilities.h"

int main() {
	int i = 97; 
	char c = 'a';
	while (i < 123) {
		std::cout << c << "\t" << i << std::endl;		
		++i;
		c = i;
	}
	keep_window_open();
}