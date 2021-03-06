//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, S.151 Aufgabe 10+11
// Liest immer einen double Wert pro Iteration ein und bestimmt dann ob es der gr��te/kleinste bisher eingelesene Wert ist
// oder ob er irgendwo dazwischen liegt und ber�cksichtig dabei die Einheit (cm,in,ft,m) + gibt zum Schluss die Anzahl der eingelesen Werte+Summe aus.
// Au�erdem werden die eingaben in m konvertiert in einem Vector "Numbers" gespeichert und zum Schluss sortiert ausgegeben.

#include <iostream>
#include "../facilities.h"

//Methoden um alles auf Meter umzuwandeln
double cm_to_m(double d) {
	return d /= 100;
}

double in_to_m(double d) {
	return cm_to_m(d *= 2.54);
}

double ft_to_m(double d) {
	return in_to_m(d *= 12);
}

int main() {
	vector<double> numbers;
	double smallest = 0;
	double biggest = 0;
	double eingabe = 0;
	bool g�ltige_eingabe = true;
	double summe = 0;
	int werte_anzahl = 0;
	string einheit = "default";

	std::cout << "Momentan ist der kleinste/gr��te Wert 0!" << std::endl;
	while (std::cin >> eingabe >> einheit) {
		// Auf Startwert setzen
		g�ltige_eingabe = true; 
	     //Einheiten in m umrechnen
		if (einheit == "cm") { 
			eingabe = cm_to_m(eingabe);
			einheit = "m";
		}
		else if (einheit == "in") {
			eingabe = in_to_m(eingabe);
			einheit = "m";
		}
		else if (einheit == "ft") {
			eingabe = ft_to_m(eingabe);
			einheit = "m";
		}
		else if (einheit == "m") {
		}
		else {
			g�ltige_eingabe = false;
			std::cout << "Ung�ltige Einheit" << std::endl;
		}
		//Kein Vergleich bei ung�ltiger Eingabe der Einheit
		if (g�ltige_eingabe) {
        // Aufgabe 9 - Summe und Anzahl der Werte festhalten
			summe += eingabe;
			++werte_anzahl;
			numbers.push_back(eingabe);
		//Lage bestimmung des Wertes
		if (eingabe < smallest) {
			std::cout << "bisher der kleinste Wert" << std::endl;
			smallest = eingabe;
		}
		else if (eingabe > smallest && eingabe > biggest) {
			std::cout << "bisher der gr��te Wert" << std::endl;
			biggest = eingabe;
		}
		else if (eingabe == smallest) {
			std::cout << "bisher der kleinste Wert" << std::endl;
		}
		else if (eingabe == biggest) {
			std::cout << "bisher der gr��te Wert" << std::endl;
		}
		else {
			std::cout << "Irgendwo dazwischen" << std::endl;
		}
	 }
	}
	std::cout << "Ingesamt gab es: " << werte_anzahl << " Eingaben.\n" << "Die Summe der Eingaben betr�gt: " << summe << "m\n" << std::endl;
	std::cout << "Der Insgesamt kleinste Werte betr�gt: " << smallest << "\nDer Insgesamt gr��te Wert betr�gt: " << biggest << std::endl;
	std::cout << "Ihre Eingaben lauteten: " << std::endl;
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); ++i) {
		std::cout << numbers[i] << "m" << ", ";
	}
	system("pause");
	return 0;
}