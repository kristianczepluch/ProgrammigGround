//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.151 Aufgabe 7+8
// Liest immer einen double Wert pro Iteration ein und bestimmt dann ob es der größte/kleinste bisher eingelesene Wert ist
// oder ob er irgendwo dazwischen liegt und berücksichtig dabei die Einheit (cm,in,ft,m)

#include <iostream>
#include "../facilities.h"

//Methoden um alles auf Meter umzuwandeln
double cm_to_m(double d) {
	return d /= 100;
}

double in_to_m(double d) {
	return cm_to_m(d *= 2.54);
}

double ft_to_m(double d) {
	return in_to_m(d *= 12);
}

int main() {

	double smallest = 0;
	double biggest = 0;
	double eingabe = 0;
	bool gültige_eingabe = true;
	string einheit = "default";

	std::cout << "Momentan ist der kleinste/größte Wert 0!" << std::endl;
	while (std::cin >> eingabe >> einheit) {
		// Auf Startwert setzen
		gültige_eingabe = true; 
	     //Einheiten in m umrechnen
		if (einheit == "cm") { 
			eingabe = cm_to_m(eingabe);
			einheit = "m";
		}
		else if (einheit == "in") {
			eingabe = in_to_m(eingabe);
			einheit = "m";
		}
		else if (einheit == "ft") {
			eingabe = ft_to_m(eingabe);
			einheit = "m";
		}
		else if (einheit == "m") {
		}
		else {
			gültige_eingabe = false;
			std::cout << "Ungültige Einheit" << std::endl;
		}


		//Kein Vergleich bei ungültiger Eingabe der Einheit
		if (gültige_eingabe) {
		//Lage bestimmung des Wertes
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
	}
	keep_window_open();
	return 0;
}