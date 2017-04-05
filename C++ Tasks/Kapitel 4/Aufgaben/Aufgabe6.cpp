//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.151 Aufgabe 6
// Liest immer einen double Wert pro Iteration ein und bestimmt dann ob es der größte/kleinste bisher eingelesene Wert ist
// oder ob er irgendwo dazwischen liegt

#include <iostream>
#include "../facilities.h"


int main() {
	vector<int> numbers;
	double smallest = 0;
	double eingabe = 0;
	double biggest = 0;
	std::cout << "Momentan ist der kleinste/größte Wert 0!" << std::endl;
	while (std::cin >> eingabe) {
		if (eingabe < smallest) {
			std::cout << "bisher der kleinste Wert" << std::endl;
			smallest = eingabe;
		}
		else if (eingabe > smallest && eingabe > biggest) {
			std::cout << "bisher der größte Wert" << std::endl;
			biggest = eingabe;
		}
		else if (eingabe == smallest) {
			std::cout << "bisher der kleinste Wert" << std::endl;
		} 
		else if (eingabe == biggest) {
			std::cout << "bisher der größte Wert" << std::endl;
		}
		else {
			std::cout << "Irgendwo dazwischen" << std::endl;
		}
	}
	keep_window_open();
	return 0;
}