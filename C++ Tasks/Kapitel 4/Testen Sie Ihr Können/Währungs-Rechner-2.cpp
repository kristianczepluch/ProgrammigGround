//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, S.136 - Testen Sie Ihr K�nnen
// Programm welches Yen, Euro und Pfund in Dollar umrechnet unter verwendung einer Switch anweisung
// Eignet sich jedoch eher weniger, da mit Switch keine Strings verglichen werden k�nnen und zun�chst
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
	string ausgangs_w�hrung = "default";
	int ziel_w�hrung = 0;

	std::cout << "Bitte geben Sie den Geldbetrag und die W�hrung ein: " << std::endl;
	std::cin >> eingabe >> ausgangs_w�hrung;

	
	if (ausgangs_w�hrung == "Yen" || ausgangs_w�hrung == "yen") {
		ziel_w�hrung = 1;
	}
	else if (ausgangs_w�hrung == "Euro" || ausgangs_w�hrung == "euro") {
		ziel_w�hrung = 2;
	}
	else if (ausgangs_w�hrung == "Pfund" || ausgangs_w�hrung == "pfund") {
		 ziel_w�hrung = 3;
	}
	else if (ausgangs_w�hrung == "Yuan" || ausgangs_w�hrung == "yuan") {
		ziel_w�hrung = 4;
	}
	else if (ausgangs_w�hrung == "Krone" || ausgangs_w�hrung == "krone") {
		 ziel_w�hrung = 5;
	}

	switch (ziel_w�hrung) {
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