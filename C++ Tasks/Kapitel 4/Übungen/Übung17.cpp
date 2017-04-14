//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, Aufgabe 17 S.155
// Program aus der letzen Aufgabe soweit ge�ndert, dass der Benutzter String eingeben kann und einem neben dem Modalwert noch das Maximum, Minimum und eine Alphabetische Ausgabe berechnet wird.

#include "../facilities.h"

int main() {

	vector<int> stellen;
	vector<string> modalwerte;
	modalwerte.push_back("default");
	vector<string> numbers;
	vector<int> h�ufigkeiten;
	bool wert_vorhanden = false;
	int biggest = -1;
	string eingabe;

	while (cin >> eingabe) {
		numbers.push_back(eingabe);
	}

	int counter = 0;

	for (int i = 0; i < numbers.size(); i++) { //zun�chst wird f�r jede Zahl aus Numbers geguckt wie oft diese Zahl vorhanden ist und in h�ufigkeiten gespeichert
		counter = 0;                           //bei h�ufigkeiten an der Stelle 0 steht also wie oft die erste Zahl vorkommt
		for (int ii = 0; ii < numbers.size(); ii++) {
			if (numbers[i] == numbers[ii]) {
				counter++;
			}
		} h�ufigkeiten.push_back(counter);
	}

	for (int i = 0; i < h�ufigkeiten.size(); i++) { //dann wird geschaut, was die gr��te H�ufigkeit ist
		                                            
		if (h�ufigkeiten[i] > biggest) {
			biggest = h�ufigkeiten[i];
		}
	}

	for (int i = 0; i < h�ufigkeiten.size(); i++) { //die Stellen (also die stelle i) wird in ein vector geschrieben der stellen hei�t, dieser enth�lt nun die Stellen in Numbers
		if (h�ufigkeiten[i] == biggest) {           //welche die modalwerte enthalten
			stellen.push_back(i);
		}
	}
	
	for (int i = 0; i < stellen.size(); i++) { //nun werden die modalwerte hinzugef�gt, und dabei �berpr�ft ob der wert schon in dem letzendlichen vector mit den werten drinsteht
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
	
	std::cout << "Modalwerte(am h�ufigst auftretende/nste Wort/W�rter): ";
	for (int i = 0; i < modalwerte.size(); i++) { //zum schluss wird der vector ausgegeben (-1 ist der erste wert im ergebnisvector der f�r den vergleich n�tig war und ist somit keine L�sung).
		if (modalwerte[i] != "default") {
			std::cout << modalwerte[i] << ", ";
		}
	}

	sort(numbers.begin(), numbers.end());

	std::cout << "\nAlphabetisch sortierte ausgabe: ";

	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << ", ";
	}

	std::cout << "\nMinimum(alphabetisch): " << numbers[0] << std::endl;
	std::cout << "Maximum(alphabetisch): " << numbers[numbers.size() - 1] << std::endl;
	

	system("pause");
	keep_window_open();
	return 0;
}