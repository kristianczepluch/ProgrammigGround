//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, Aufgabe 21 S.155
// Program dahingehend erweiter, dass zum Schluss der Benutzer die Möglichkeit hat die Namen der Spieler durch die Eingabe der Punkte abzufragen.
// Sollte die Eingabe auf keine der Spieler passen wird eine entsprechende Ausgabe erzeugt.
// Mit exit kann das Program beendet werden.

#include "../facilities.h"

int main() {

	string name;
	int score;
	bool dublicate = false;
	bool name_found = false;

	vector<string> names;
	vector<int> scores;

	int eingabe;

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

	std::cout << "Bitte geben Sie den Namen des Spielers ein, um die Punkte abzufragen oder exit um das Programm zu beenden: " << std::endl;
	while (std::cin >> eingabe) {
		
		if (eingabe == -1) {
			return 0;
		}
		name_found = false;
		for (int i = 0; i < scores.size(); i++) {
			if (eingabe == scores[i]) {
				std::cout << "Der Spieler " << names[i] << " hat " << eingabe << " Punkte erreicht." << std::endl;
				name_found = true;
			}
		}
		if (!name_found) {
			std::cout << "Spielstand nicht gefunden" << std::endl;
			
		}
		std::cout << "Bitte geben Sie den Namen des Spielers ein, um die Punkte abzufragen oder exit um das Programm zu beenden: " << std::endl;
	}


	system("pause");
	keep_window_open();
	return 0;
}