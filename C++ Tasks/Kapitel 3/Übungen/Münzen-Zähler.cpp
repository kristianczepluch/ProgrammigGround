//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 3, Aufgabe 11 S.117
// Aufgabe die Geldm�nzen zusammenz�hlt und dann die Summe der einzelnen St�cke formatiert ausgibt, und den Gesamtbetrag
// sowohl in Cent als auch in Euro ausgibt

#include <iostream>
#include "../facilities.h"

int main() {
	double ein_cent = -1;
	double zwei_cent = -1;
	double f�nf_cent = -1;
	double zehn_cent = -1;
	double zwanzig_cent = -1;
	double f�nfzig_cent = -1;
	double hundert_cent = -1;
	double total_cent = -1;
	double total_euro = -1;

	std::cout << "Wie viele 1 Cent Stuecke haben Sie?" << std::endl;
	std::cin >> ein_cent;
	std::cout << "Wie viele 2 Cent Stuecke haben Sie?" << std::endl;
	std::cin >> zwei_cent;
	zwei_cent *= 2;
	std::cout << "Wie viele 5 Cent Stuecke haben Sie?" << std::endl;
	std::cin >> f�nf_cent;
	f�nf_cent *= 5;
	std::cout << "Wie viele 10 Cent Stuecke haben Sie?" << std::endl;
	std::cin >> zehn_cent;
	zehn_cent *= 10;
	std::cout << "Wie viele 20 Cent Stuecke haben Sie?" << std::endl;
	std::cin >> zwanzig_cent;
	zwanzig_cent *= 20;
	std::cout << "Wie viele 50 Cent Stuecke haben Sie?" << std::endl;
	std::cin >> f�nfzig_cent;
	f�nfzig_cent *= 50;
	std::cout << "Wie viele 1 Euro Stuecke haben Sie?" << std::endl;
	std::cin >> hundert_cent;
	hundert_cent *= 100;
	total_cent = ein_cent + zwei_cent + f�nf_cent + zehn_cent + zwanzig_cent + f�nfzig_cent + hundert_cent;
	total_euro = total_cent/100;
	std::cout << "1 Cent Stuecke: " << setw(10) << ein_cent << " Cent" << std::endl;
	std::cout << "2 Cent Stuecke: " << setw(10) << zwei_cent << " Cent" <<  std::endl;
	std::cout << "5 Cent Stuecke: " << setw(10) << f�nf_cent << " Cent" <<  std::endl;
	std::cout << "10 Cent Stuecke: " << setw(9) << zehn_cent << " Cent" <<  std::endl;
	std::cout << "20 Cent Stuecke: " << setw(9) << zwanzig_cent << " Cent" <<  std::endl;
	std::cout << "50 Cent Stuecke: " << setw(9) << f�nfzig_cent << " Cent" <<  std::endl;
	std::cout << "100 Cent Stuecke: " << setw(8) << hundert_cent << " Cent" << std::endl;
	std::cout << "\nSie haben Insgesamt: " << total_cent << " Cent" << std::endl;
	std::cout << "Das entspricht: " << total_euro << " Euro" << std::endl;
	keep_window_open();
}