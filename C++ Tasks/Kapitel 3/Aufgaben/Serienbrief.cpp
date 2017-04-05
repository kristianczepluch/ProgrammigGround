//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 3, Aufgaben S. 115

#include <iostream>
#include "../facilities.h"

int main() {
	//Aufgabe 1,2 initialisierung
    std::cout << "Geben Sie den Namen der Person ein, die den Brief erhalten soll: " << std::endl;
	string first_name = "default";
	std::cin >> first_name;
	////Aufgabe 3 initialisierung
	std::cout << "Geben Sie den Namen eines Freundes ein: " << std::endl;
	string friends_name = "default";
	std::cin >> friends_name;
	//Aufgabe 4 initialisierung
	std::cout << "Geben Sie das Geschlecht des Freundes an. (m/w)?" << std::endl;
	char friends_sex = 'd'; // d für default
    std:cin >> friends_sex;
	//Aufgabe 5 initialisierung
	int age = -1;
	std::cout << "Bitte geben sie das Alter des Empfängers ein: " << std::endl;
	std::cin >> age;
	std::cout << "Lieber " << first_name << " ..." << std::endl; //Aufgabe 1
	std::cout << "Wie geht es Dir?\nMir geht es gut. Ich vermisse dich "; //Aufgabe 2
	std::cout << "Hast du " << friends_name << " in letzer Zeit gesehen? " << std::endl; //Aufgabe 3
	if (friends_sex == 'm') {
		std::cout << "Wenn du " << friends_name << " siehst, bitte ihn, mich anzurufen." << std::endl;
	}
	else {
		std::cout << "Wenn du " << friends_name << "siehst, bitte sie, mich anzurufen." << std::endl;
	} //Aufgabe 4
	std::cout << "Ich habe gehört, dass du Geburtstag gehabt hast und " << age << " Jahre alt geworden bist." << std::endl;
	if (age <= 0 || age>=110) {
		std::cout << "Du willst mich doch auf den Arm nehmen!" << std::endl;
	} //Aufgabe 5
	if (age<12) {
		std::cout << "Nächst Jahr wirst du " << ++age << " Jahre alt sein." << std::endl;
	}
	else if (age == 17) {
		std::cout << "Nächstes Jahr darfst du wählen." << std::endl;
	}
	else if (age > 70) {
		std::cout << "Ich hoffe, Du genießt den Ruhestand." << std::endl;
	} //Aufgabe 6
	std::cout << "Liebe Gruesse \n" << first_name << std::endl; //Aufgabe 7
	keep_window_open();
}