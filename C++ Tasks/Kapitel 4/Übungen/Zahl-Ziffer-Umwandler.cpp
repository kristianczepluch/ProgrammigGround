//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.153 5
// Programm welches eine ausgeschriebene Zahl in eine Ziffer umwandelt und andersrum.
// Schwierigkeit hierbeit ist, dass man zunächst nicht weis ob in dem string eine zahl ist oder nicht und wenn ja wie man sie in einen integer 
// umwandelt. Musterlösung setzt können aus Kapitel 10 vorraus....

#include <iostream>
#include "../facilities.h"

// Funktion welche die Zahl die in einem String gespeichert ist, als int zurückgibt
int string_to_int(string s) {
	if (s == "0") {
		return 0;
	} else if (s == "1") {
		return 1;
	} else if (s == "2") {
		return 2;
	} else if (s == "3") {
		return 3;
	} else if (s == "4") {
		return 4;
	} else if (s == "5") {
		return 5;
	} else if (s == "6") {
		return 6;
	} else if (s == "7") {
		return 7;
	} else if (s == "8") {
		return 8;
	} else if (s == "9") {
		return 9;
	}
} // Funktion welche die Zahl die in einem String gespeichert ist, als int zurückgibt

int main() {
	vector<string>zahlen_ausgeschrieben(10);
	zahlen_ausgeschrieben[0] = "null";
	zahlen_ausgeschrieben[1] = "eins";
	zahlen_ausgeschrieben[2] = "zwei";
	zahlen_ausgeschrieben[3] = "drei";
	zahlen_ausgeschrieben[4] = "vier";
	zahlen_ausgeschrieben[5] = "fuenf";
	zahlen_ausgeschrieben[6] = "sechs";
	zahlen_ausgeschrieben[7] = "sieben";
	zahlen_ausgeschrieben[8] = "acht";
	zahlen_ausgeschrieben[9] = "neun";

	string eingabe = "";
	bool wert_gefunden = false;
	std::cout << "Bitte geben Sie eine Zahl zwischen 0-9 als Ziffer oder eingeschrieben ein: " << std::endl;
	std::cin >> eingabe;
	for (int i = 0; i < zahlen_ausgeschrieben.size(); ++i) {
		if (eingabe == zahlen_ausgeschrieben[i]) {
			wert_gefunden = true;
			std::cout << i << std::endl;
		}
	}
	if (wert_gefunden == false) {
		std::cout << zahlen_ausgeschrieben[string_to_int(eingabe)] << std::endl;
	}
	keep_window_open();
	return 0;
}