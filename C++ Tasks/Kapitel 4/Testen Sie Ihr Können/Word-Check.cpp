//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, S.150 Testen Sie ihr K�nnen
// Programm welches eine Reihe von W�rter einliest (eingabe mit strg+z unterbrechen) und diese dann auf verbotene W�rter
// pr�ft und dann die W�rte durchnummeriert ausgibt und bei verbotenen W�rtern ein XXX ausgibt.
// Die Wort �berpr�fung wurde in word_check definiert

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
		if (word_check(words[i],not_allowed_words)) { //word_check pr�ft ob das Wort erlaubt ist oder nicht
			std::cout << "Wort " << i << ": " << words[i] << std::endl;
		} else { std::cout << "Wort " << i << ": " << "XXX" << std::endl; }
	}
	keep_window_open();
	return 0;
}