//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, S.113 - Testen Sie Ihr K�nnen
// Programm welches Yen, Euro und Pfund in Dollar umrechnet

#include <iostream>
#include "../facilities.h"

int main() {
	const double yen_to_dollar = 0.008974;
	const double euro_to_dollar = 1.06975;
	const double pfund_to_dollar = 1.2534;
	double eingabe = -1;
	string ausgangs_w�hrung = "default";

	std::cout << "Bitte geben Sie den Geldbetrag und die W�hrung ein: " << std::endl;
	std::cin >> eingabe >> ausgangs_w�hrung;
	if (ausgangs_w�hrung=="Yen" || ausgangs_w�hrung == "yen") {
		std::cout << "Ihr Geldbetrag: " << eingabe << " Yen" << " entspricht: " << eingabe*yen_to_dollar << " Dollar" << std::endl;
	} else if (ausgangs_w�hrung == "Euro" || ausgangs_w�hrung == "euro") {
		std::cout << "Ihr Geldbetrag: " <<  eingabe << " Euro" << " entspricht: " << eingabe*euro_to_dollar << " Dollar" << std::endl;
	} else if (ausgangs_w�hrung == "Pfund" || ausgangs_w�hrung == "pfund") {
		std::cout << "Ihr Geldbetrag: " << eingabe << " Pfund" << " entspricht: " << eingabe*pfund_to_dollar << " Dollar" << std::endl;
	}
	keep_window_open();
}