//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, S.142 Testen Sie ihr K�nnen
// Programm welches die Funktion quadrat selbst definiert, w�hrend sie auf das Multiplikationszeichen verzichtet.

#include <iostream>
#include "../facilities.h"

int quadrat(int v) {
	int c = 0;
	for (int i = 0; i < v; i++) {
		c += v;
	} return c;
}

int main() {
	
	std::cout << quadrat(5) << std::endl;
	keep_window_open();
	return 0;
}
