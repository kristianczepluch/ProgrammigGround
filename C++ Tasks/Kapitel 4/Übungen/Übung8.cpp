//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 8
// Programm welches berechnet, wie viele Schachfelder nötig sind, bei einer gegebenen Menge an Reis. 
// Das erste Schachfeld gibt 1 Reiskorn, das zweite 2, das dritte 4 usw.. 

#include <iostream>
#include "../facilities.h"

int main() {

	int KörnerSumme = 1;
	int Feld = 1;
	int Körner = 1;
	long long eingabe = -1;
	
	std::cout << "Wie viele Reiskoerner benoetigen Sie?" << std::endl;
	std::cin >> eingabe;

	if (eingabe == 0) {
		std::cout << "Dazu benötigen sie garkein Schachfeld!" << std::endl;
	}
	else if (eingabe < 0) {
		std::cout << "Wollen sie Reis bezahlen oder Reis als Belohnung bekommen?" << std::endl;

	}
	else {

		while (KörnerSumme < eingabe) {
			++Feld;
			Körner = Körner * 2;
			KörnerSumme += Körner;
		} std::cout << "Sie benoetigen fuer diese Menge an Koernern " << Feld << " Schachfelder" << std::endl;
	}
	keep_window_open();
	return 0;
}