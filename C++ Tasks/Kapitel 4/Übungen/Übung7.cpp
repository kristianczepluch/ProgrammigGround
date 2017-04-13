//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.153 7
// Programm welches einen einfachen Taschenrechner Simuliert, jedoch ist es nur möglich ganze Zahlen zwischen 0-9 in Ziffer oder ausgeschriebener Form auszugeben

#include <iostream>
#include "../facilities.h"

// Funktion welche die Zahl die in einem String gespeichert ist, als int zurückgibt
int string_to_int(string s) {
	if (s == "0") {
		return 0;
	}
	else if (s == "1") {
		return 1;
	}
	else if (s == "2") {
		return 2;
	}
	else if (s == "3") {
		return 3;
	}
	else if (s == "4") {
		return 4;
	}
	else if (s == "5") {
		return 5;
	}
	else if (s == "6") {
		return 6;
	}
	else if (s == "7") {
		return 7;
	}
	else if (s == "8") {
		return 8;
	}
	else if (s == "9") {
		return 9;
	}
} 
// Funktion welche den den Vektor mit den augeschrieben Zahlen zurückliefert (zur Übersichtlichkeit)
vector<string> vector_initialisierung() {
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
	return zahlen_ausgeschrieben;
}

int main() {

	string val1 = "";
	string val2 = "";
	int NewVal1 = -1;
	int NewVal2 = -1; 
	char opeartion = 'a';
	bool wert1_gefunden = false;
	bool wert2_gefunden = false;
	vector<string>zahlen_ausgeschrieben(10);  
	zahlen_ausgeschrieben = vector_initialisierung();

	std::cout << "Bitte geben sie die zwei Operanden(ganze Zahle von 0-9) und die Operation getrennt von einem Leerzeichen oder einem Enterzeichen ein: " << std::endl;
	std::cin >> val1 >> val2 >> opeartion;

	for (int i = 0; i < zahlen_ausgeschrieben.size(); ++i) {
		if (val1 == zahlen_ausgeschrieben[i]) {
			wert1_gefunden = true;
			NewVal1 = i;
		}
	}
	if (wert1_gefunden == false) {
		NewVal1 = string_to_int(val1);
	}

	for (int i = 0; i < zahlen_ausgeschrieben.size(); ++i) {
		if (val2 == zahlen_ausgeschrieben[i]) {
			wert2_gefunden = true;
			NewVal2 = i;
		}
	}

	if (wert2_gefunden == false) {
		NewVal2 = string_to_int(val2);
	}

	switch (opeartion) {
	case'+':
		std::cout << "Ausgabe: " << val1 << opeartion << val2 << "= " << NewVal1 + NewVal2 << std::endl;
		break;
	case'-':
		std::cout << "Ausgabe: " << val1 << opeartion << val2 << "= " << NewVal1 - NewVal2 << std::endl;
		break;
	case'*':
		std::cout << "Ausgabe: " << val1 << opeartion << val2 << "= " << NewVal1 * NewVal2 << std::endl;
		break;
	case'/':
		std::cout << "Ausgabe: " << val1 << opeartion << val2 << "= " << NewVal1 / NewVal2 << std::endl;
		break;
	}


	keep_window_open();
	return 0;
}