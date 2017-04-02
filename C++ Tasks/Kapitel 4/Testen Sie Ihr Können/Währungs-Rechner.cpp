//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.113 - Testen Sie Ihr Können
// Programm welches Yen, Euro und Pfund in Dollar umrechnet

#include <iostream>
#include "../facilities.h"

int main() {
	const double yen_to_dollar = 0.008974;
	const double euro_to_dollar = 1.06975;
	const double pfund_to_dollar = 1.2534;
	double eingabe = -1;
	string ausgangs_währung = "default";

	std::cout << "Bitte geben Sie den Geldbetrag und die Währung ein: " << std::endl;
	std::cin >> eingabe >> ausgangs_währung;
	if (ausgangs_währung=="Yen" || ausgangs_währung == "yen") {
		std::cout << "Ihr Geldbetrag: " << eingabe << " Yen" << " entspricht: " << eingabe*yen_to_dollar << " Dollar" << std::endl;
	} else if (ausgangs_währung == "Euro" || ausgangs_währung == "euro") {
		std::cout << "Ihr Geldbetrag: " <<  eingabe << " Euro" << " entspricht: " << eingabe*euro_to_dollar << " Dollar" << std::endl;
	} else if (ausgangs_währung == "Pfund" || ausgangs_währung == "pfund") {
		std::cout << "Ihr Geldbetrag: " << eingabe << " Pfund" << " entspricht: " << eingabe*pfund_to_dollar << " Dollar" << std::endl;
	}
	keep_window_open();
}