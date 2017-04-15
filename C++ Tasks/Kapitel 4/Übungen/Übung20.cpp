//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, Aufgabe 20 S.155
// Program dahingehend erweiter, dass zum Schluss der Benutzer die Möglichkeit hat die Punkte der Spieler durch die eingabe des Namens aufzurufen. 
// Sollte der Name nicht in der Liste sein wird ein Fehler ausgegeben und weitehrin kann das Program mit exit beendet werden.

#include "../facilities.h"

int main() {

	string name;
	int score;
	bool dublicate = false;
	bool name_found = false;

	vector<string> names;
	vector<int> scores;

	string eingabe;

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
		if (eingabe == "exit") {
			return 0;
		}
		name_found = false;
		for (int i = 0; i < names.size(); i++) {
			if (eingabe == names[i]) {
				std::cout << "Der Spieler " << eingabe << " hat " << scores[i] << " Punkte erreicht." << std::endl;
				std::cout << "Bitte geben Sie den Namen des Spielers ein, um die Punkte abzufragen oder exit um das Programm zu beenden: " << std::endl;
				name_found = true;
			}
		}
		if (!name_found) {
			std::cout << "Name nicht gefunden" << std::endl;
			std::cout << "Bitte geben Sie den Namen des Spielers ein, um die Punkte abzufragen oder exit um das Programm zu beenden: " << std::endl;
		}
	}



	keep_window_open();
	return 0;
}