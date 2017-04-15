//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, Aufgabe 19 S.155
// Program, welches einen Namen und eine Punktzahl einliest und jeweils an der selben Stelle i in zwei verschiedenen Vektoren speichert und bei einem Doppeltem Namen eine Fehlermeldung ausgibt.
// Durch Noname 0 wird die eingabe beendet und im Anschluss werden alle eingetragenen Namen und Scores zeilenweise ausgegeben.

#include "../facilities.h"

int main() {

	string name;
	int score;
	bool dublicate = false;

	vector<string> names;
	vector<int> scores;

	while (std::cin >> name >> score) {
		dublicate = false;
		for (int i = 0; i < names.size(); i++) {
			if (name == names[i]) {
				std::cout << "Fehler! Der Name: " << name << " wurde zweimal eingegeben." << std::endl;
				dublicate = true;
			}
		}
		if (!dublicate) {
			if (name == "Noname" && score == 0) {
				break;
			}
			else {
				names.push_back(name);
				scores.push_back(score);
			}
		}
	}

	for (int i = 0; i < names.size(); i++) {
		std::cout << names[i] << " " << scores[i] << std::endl;
	}



	keep_window_open();
	return 0;
}