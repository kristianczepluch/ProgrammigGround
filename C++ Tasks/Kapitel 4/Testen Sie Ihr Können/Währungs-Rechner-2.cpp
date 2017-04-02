//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.136 - Testen Sie Ihr Können
// Programm welches Yen, Euro und Pfund in Dollar umrechnet unter verwendung einer Switch anweisung
// Eignet sich jedoch eher weniger, da mit Switch keine Strings verglichen werden können und zunächst
// durch eine Reihe ifs, der String in einen Int umgewandelt werden muss.

#include <iostream>
#include "../facilities.h"

int main() {
	const double yen_to_dollar = 0.008974;
	const double euro_to_dollar = 1.06975;
	const double pfund_to_dollar = 1.2534;
	const double yuan_to_dollar = 0.145111;
	const double krone_to_dollar = 0.116208;
	double eingabe = -1;
	string ausgangs_währung = "default";
	int ziel_währung = 0;

	std::cout << "Bitte geben Sie den Geldbetrag und die Währung ein: " << std::endl;
	std::cin >> eingabe >> ausgangs_währung;

	
	if (ausgangs_währung == "Yen" || ausgangs_währung == "yen") {
		ziel_währung = 1;
	}
	else if (ausgangs_währung == "Euro" || ausgangs_währung == "euro") {
		ziel_währung = 2;
	}
	else if (ausgangs_währung == "Pfund" || ausgangs_währung == "pfund") {
		 ziel_währung = 3;
	}
	else if (ausgangs_währung == "Yuan" || ausgangs_währung == "yuan") {
		ziel_währung = 4;
	}
	else if (ausgangs_währung == "Krone" || ausgangs_währung == "krone") {
		 ziel_währung = 5;
	}

	switch (ziel_währung) {
	case 1:
		std::cout << "Ihr Geldbetrag: " << eingabe << " Yen" << " entspricht: " << eingabe*yen_to_dollar << " Dollar" << std::endl;
		break;
	case 2: 
		std::cout << "Ihr Geldbetrag: " << eingabe << " Euro" << " entspricht: " << eingabe*euro_to_dollar << " Dollar" << std::endl;
		break;
	case 3:
		std::cout << "Ihr Geldbetrag: " << eingabe << " Pfund" << " entspricht: " << eingabe*pfund_to_dollar << " Dollar" << std::endl;
		break;
	case 4:
		std::cout << "Ihr Geldbetrag: " << eingabe << " Yuan" << " entspricht: " << eingabe*yuan_to_dollar << " Dollar" << std::endl;
		break;
	case 5:
		std::cout << "Ihr Geldbetrag: " << eingabe << " Krone" << " entpsricht: " << eingabe*krone_to_dollar << " Dollar " << std::endl;
		break;
	}
	keep_window_open();
}