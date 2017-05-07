//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 5, S.191 Übungen 8.)
// Program, welches zu Beginn den Benutzer auffordert n Zahlen einzugeben und diese zunächst in einem Vektor ablegt.
// Im nächsten Schritt kann der Benutzer eine Zahl n definieren, welche aussagt wieviele der ersten n Zahlen aufaddiert werden sollen.
// Das Program fängt ungültige Eingaben ab und kontrolliert ebenfalls ob der Benutzer Zahlen aufaddieren möchten, welche sich außerhalb des Wertebereichs befinden.

#include "std_lib_facilities.h"
#include <limits>

int addToN(int n, vector<int> v) {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += v[i];
	}
	return sum;
}

int main() {

		int eingabe = 0;
		vector<int> zahlen;
		std::cout << "Bitte geben Sie eine Reihe von Zahlen getrennt von einem Enter oder einem Leerzeichen ein.\nDie Eingabe wird beendet durch eingabe eines Zeichens.\nIhre Eingabe: ";
		while (std::cin >> eingabe) {
			zahlen.push_back(eingabe);
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Ihr Eingabe lautet: ";

		for (int i = 0; i < zahlen.size(); ++i) {
			std::cout << zahlen[i] << ", ";
		}

		std::cout << "Wieviele der erste n Zahlen möchten Sie aufaddieren?\n" << "Eingabe: ";
		std::cin >> eingabe;
		while (std::cin.fail() || eingabe > zahlen.size()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ungueltige Eingabe! Bitte eine Zahl eingeben, welche die Laenge ihrer Zahlenmenge auch nicht uebersteigt: ";
			std::cin >> eingabe;
		}

		std::cout << "Es werden die ersten " << eingabe << " Zahlen aufaddiert." << std::endl;
		std::cout << "Die Summe dieser  Zahlen ist: " << addToN(eingabe, zahlen) << std::endl;
		keep_window_open();
		return 0;
}