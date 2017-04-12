//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, S.154 10
// Schere, Stein, Papier Spiel mit vereinfachtem Zufall des Computers, abh�ngig von 3 Zahlen die der Benutzer eingibt.

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

vector<string> vector_initialisierung1() {
	vector<string> computer_z�ge;
	computer_z�ge.push_back("Papier");
	computer_z�ge.push_back("Papier");
	computer_z�ge.push_back("Stein");
	computer_z�ge.push_back("Schere");
	computer_z�ge.push_back("Schere");
	computer_z�ge.push_back("Stein");
	computer_z�ge.push_back("Papier");
	computer_z�ge.push_back("Schere");
	computer_z�ge.push_back("Stein");
	computer_z�ge.push_back("Stein");
	return computer_z�ge;
}

vector<string> vector_initialisierung2() {
	vector<string> Auswahlm�glichkeiten;
	Auswahlm�glichkeiten.push_back("Schere");
	Auswahlm�glichkeiten.push_back("Stein");
	Auswahlm�glichkeiten.push_back("Papier");
	return Auswahlm�glichkeiten;
}




int main() {

	vector<string> Auswahlm�glichkeiten;
	vector<string> computer_z�ge;
	computer_z�ge = vector_initialisierung1();
	Auswahlm�glichkeiten = vector_initialisierung2();
	int eingabe = 0;
	int zufallswert1 = 0;
	int zufallswert2 = 0;
	int zufallswert3 = 0;

	std::cout << "Bitte w�hlen sie 3 zahlen zwischen 0-9 aus und geben sie diese getrennt von einem Komma ein: " << std::endl;
	std::cin >> zufallswert1 >> zufallswert2 >> zufallswert3;
	std::cout << "W�hlen Sie zwischen Schere(1), Stein(2) oder Papier(3)!" << std::endl;
	std::cin >> eingabe;
	std::cout << "Der Computer w�hlt noch.." << std::endl;
	Sleep(2000);
	std::cout << "..." << std::endl;
	Sleep(2000);
	std::cout << "Der Computer hat seine Wahl getroffen" << std::endl;
	Sleep(1000);
	std::cout << "3" << std::endl;
	Sleep(1000);
	std::cout << "2" << std::endl;
	Sleep(1000);
	std::cout << "1" << std::endl;
	Sleep(1000);

	std::cout << "Sie: " << Auswahlm�glichkeiten[eingabe-1] << std::endl;
	std::cout << "Computer: " << computer_z�ge[(zufallswert1 + zufallswert3) / 2] << std::endl;

	switch (eingabe) {
	case(1):
		if (computer_z�ge[zufallswert1 + zufallswert3] == Auswahlm�glichkeiten[eingabe - 1]) {
			Sleep(1000);
			std::cout << "Unentschieden!" << std::endl;
		}
		else if (computer_z�ge[zufallswert1 + zufallswert3] == "Stein") {
			Sleep(1000);
			std::cout << "Sie haben leider verloren.." << std::endl;
		}
		else {
			std::cout << "Sie haben gewonnen!" << std::endl;
		}
		break;
	case(2):
		if (computer_z�ge[(zufallswert1 + zufallswert3)/2] == Auswahlm�glichkeiten[eingabe - 1]) {
			Sleep(1000);
			std::cout << "Unentschieden!" << std::endl;
		}
		else if (computer_z�ge[(zufallswert1 + zufallswert3) / 2] == "Papier") {
			Sleep(1000);
			std::cout << "Sie haben leider verloren.." << std::endl;
		}
		else {
			std::cout << "Sie haben gewonnen!" << std::endl;
		}
		break;
	case(3):
		if (computer_z�ge[(zufallswert1 + zufallswert3) / 2] == Auswahlm�glichkeiten[eingabe - 1]) {
			Sleep(1000);
			std::cout << "Unentschieden!" << std::endl;
		}
		else if (computer_z�ge[(zufallswert1 + zufallswert3) / 2] == "Papier") {
			Sleep(1000);
			std::cout << "Sie haben leider verloren.." << std::endl;
		}
		else {
			std::cout << "Sie haben gewonnen!" << std::endl;
		}
		break;
	}


	keep_window_open();
	return 0;
}