// Beispiel einer Unsicheren Typumwandlung
// Da int 4 Bytes zu verfügung hat kann man viel größere Werte speichern als bei einem Char
// Findet eine Typumwandlung von int zu char statt muss auf eine entsprechend verhältnismäßige Größe von Int zu Char geachtet werden
// Da sonst der Wert von 20000 zu 32 wechselt und somit unsicher ist.

#include <iostream>

int main() {

	int a = 20000;
	char b = a;
	int c = b;

	if (a == c) {
		std::cout << "a ist gleich c" << std::endl;
	}
	else {
		std::cout << "a ist ungleich c" << std::endl;
	}

	std::cout << "a hat den Wert: " << a << std::endl;
	std::cout << "c hat den Wert: " << c << std::endl;

	system("pause");
}