//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, S.154 8
// Programm welches berechnet, wie viele Schachfelder n�tig sind, bei einer gegebenen Menge an Reis. 
// Das erste Schachfeld gibt 1 Reiskorn, das zweite 2, das dritte 4 usw.. 

#include <iostream>
#include "../facilities.h"

int main() {

	int K�rnerSumme = 1;
	int Feld = 1;
	int K�rner = 1;
	long long eingabe = -1;
	
	std::cout << "Wie viele Reiskoerner benoetigen Sie?" << std::endl;
	std::cin >> eingabe;

	if (eingabe == 0) {
		std::cout << "Dazu ben�tigen sie garkein Schachfeld!" << std::endl;
	}
	else if (eingabe < 0) {
		std::cout << "Wollen sie Reis bezahlen oder Reis als Belohnung bekommen?" << std::endl;

	}
	else {

		while (K�rnerSumme < eingabe) {
			++Feld;
			K�rner = K�rner * 2;
			K�rnerSumme += K�rner;
		} std::cout << "Sie benoetigen fuer diese Menge an Koernern " << Feld << " Schachfelder" << std::endl;
	}
	keep_window_open();
	return 0;
}