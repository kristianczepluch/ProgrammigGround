//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.150 Testen Sie ihr Können
// Programm welches eine Reihe von Wörter einliest (eingabe mit strg+z unterbrechen) und diese dann auf verbotene Wörter
// prüft und dann die Wörte durchnummeriert ausgibt und bei verbotenen Wörtern ein XXX ausgibt.
// Die Wort überprüfung wurde in word_check definiert

#include <iostream>
#include "../facilities.h"

bool word_check(string s, vector<string> v) {
	bool legit = true;
	for (int i = 0; i < v.size(); ++i) {
		if (s == v[i]) {
			legit = false;
		} else {}
	} return legit;
}

int main() {
	vector<string> words;
	vector<string> not_allowed_words;
	string temp = "default";
	not_allowed_words.push_back("Fuck");
	not_allowed_words.push_back("Suck");
	not_allowed_words.push_back("Idiot");

	while (std::cin >> temp) {
		words.push_back(temp);
	}

	for (int i = 0; i < words.size(); ++i) {
		if (word_check(words[i],not_allowed_words)) { //word_check prüft ob das Wort erlaubt ist oder nicht
			std::cout << "Wort " << i << ": " << words[i] << std::endl;
		} else { std::cout << "Wort " << i << ": " << "XXX" << std::endl; }
	}
	keep_window_open();
	return 0;
}