//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.140 - Testen Sie Ihr Können
// Programm welches in einer Schleife das charset a-z aus dem ASCII Zeichensatz ausgibt mit dem jeweiligen Integer Wert
// innerhalb einer for-Schleife. Diese for-Schleife beeinhaltet eine weitere Schleife, welche eher einer while Schleife
// ähnelt, die das charset A-Z mit dem jeweiligen Int Wert.

#include <iostream>
#include "../facilities.h"

int main() {
	int b = 65;
	char c2 = 'A';
	char c = 'a';
	for (int i = 97; i < 123; ++i) {
		c = i;
		std::cout << c << "\t" << i << "\t" << "|  " << c2 << "\t" << b << std::endl;
		++b;
		c2 = b;
	}
	keep_window_open();
}