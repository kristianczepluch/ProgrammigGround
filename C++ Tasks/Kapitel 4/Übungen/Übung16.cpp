//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, Aufgabe 16 S.155
// Program, welches dem Benutzer ermöglicht eine Reihe von positiven integer werten einzugeben und ihm den Modalwert wiederzugeben (der Wert, der die größte häufigkeit besitzt)

#include "../facilities.h"

int main() {

	vector<int> stellen;
	vector<int> modalwerte;
	modalwerte.push_back(-1);
	vector<int> numbers;
	vector<int> häufigkeiten;
	bool wert_vorhanden = false;
	int biggest = -1;
	int eingabe;

	while (cin >> eingabe) {
		numbers.push_back(eingabe);
	}

	int counter = 0;

	for (int i = 0; i < numbers.size(); i++) { //zunächst wird für jede Zahl aus Numbers geguckt wie oft diese Zahl vorhanden ist und in häufigkeiten gespeichert
		counter = 0;                           //bei häufigkeiten an der Stelle 0 steht also wie oft die erste Zahl vorkommt
		for (int ii = 0; ii < numbers.size(); ii++) {
			if (numbers[i] == numbers[ii]) {
				counter++;
			}
		} häufigkeiten.push_back(counter);
	}

	for (int i = 0; i < häufigkeiten.size(); i++) { //dann wird geschaut, was die größte Häufigkeit ist
		                                            
		if (häufigkeiten[i] > biggest) {
			biggest = häufigkeiten[i];
		}
	}

	for (int i = 0; i < häufigkeiten.size(); i++) { //die Stellen (also die stelle i) wird in ein vector geschrieben der stellen heißt, dieser enthält nun die Stellen in Numbers
		if (häufigkeiten[i] == biggest) {           //welche die modularwerte enthalten
			stellen.push_back(i);
		}
	}
	
	for (int i = 0; i < stellen.size(); i++) { //nun werden die modularwerte hinzugefügt, und dabei überprüft ob der wert schon in dem letzendlichen vector mit den werten drinsteht
		wert_vorhanden = false;                //um zu verhindern das doppelte werte in dem ergebnis vector drin stehen
		for (int ii = 0; ii < modalwerte.size(); ii++) {
			if (numbers[stellen[i]] == modalwerte[ii]){
				wert_vorhanden = true;
           } 
		}
	
		if (!wert_vorhanden) {
			modalwerte.push_back(numbers[stellen[i]]);
		}
	}
	
	for (int i = 0; i < modalwerte.size(); i++) { //zum schluss wird der vector ausgegeben (-1 ist der erste wert im ergebnisvector der für den vergleich nötig war und ist somit keine Lösung).
		if (modalwerte[i] != -1) {
			std::cout << modalwerte[i] << " ";
		}
	}

	system("pause");
	keep_window_open();
	return 0;
}