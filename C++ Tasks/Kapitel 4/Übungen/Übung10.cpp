//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.154 10
// Schere, Stein, Papier Spiel mit vereinfachtem Zufall des Computers, abhängig von 3 Zahlen die der Benutzer eingibt.

#include <iostream>
#include "../facilities.h"
#include <Windows.h>

vector<string> vector_initialisierung1() {
	vector<string> computer_züge;
	computer_züge.push_back("Papier");
	computer_züge.push_back("Papier");
	computer_züge.push_back("Stein");
	computer_züge.push_back("Schere");
	computer_züge.push_back("Schere");
	computer_züge.push_back("Stein");
	computer_züge.push_back("Papier");
	computer_züge.push_back("Schere");
	computer_züge.push_back("Stein");
	computer_züge.push_back("Stein");
	return computer_züge;
}

vector<string> vector_initialisierung2() {
	vector<string> Auswahlmöglichkeiten;
	Auswahlmöglichkeiten.push_back("Schere");
	Auswahlmöglichkeiten.push_back("Stein");
	Auswahlmöglichkeiten.push_back("Papier");
	return Auswahlmöglichkeiten;
}




int main() {

	vector<string> Auswahlmöglichkeiten;
	vector<string> computer_züge;
	computer_züge = vector_initialisierung1();
	Auswahlmöglichkeiten = vector_initialisierung2();
	int eingabe = 0;
	int zufallswert1 = 0;
	int zufallswert2 = 0;
	int zufallswert3 = 0;

	std::cout << "Bitte wählen sie 3 zahlen zwischen 0-9 aus und geben sie diese getrennt von einem Komma ein: " << std::endl;
	std::cin >> zufallswert1 >> zufallswert2 >> zufallswert3;
	std::cout << "Wählen Sie zwischen Schere(1), Stein(2) oder Papier(3)!" << std::endl;
	std::cin >> eingabe;
	std::cout << "Der Computer wählt noch.." << std::endl;
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

	std::cout << "Sie: " << Auswahlmöglichkeiten[eingabe-1] << std::endl;
	std::cout << "Computer: " << computer_züge[(zufallswert1 + zufallswert3) / 2] << std::endl;

	switch (eingabe) {
	case(1):
		if (computer_züge[zufallswert1 + zufallswert3] == Auswahlmöglichkeiten[eingabe - 1]) {
			Sleep(1000);
			std::cout << "Unentschieden!" << std::endl;
		}
		else if (computer_züge[zufallswert1 + zufallswert3] == "Stein") {
			Sleep(1000);
			std::cout << "Sie haben leider verloren.." << std::endl;
		}
		else {
			std::cout << "Sie haben gewonnen!" << std::endl;
		}
		break;
	case(2):
		if (computer_züge[(zufallswert1 + zufallswert3)/2] == Auswahlmöglichkeiten[eingabe - 1]) {
			Sleep(1000);
			std::cout << "Unentschieden!" << std::endl;
		}
		else if (computer_züge[(zufallswert1 + zufallswert3) / 2] == "Papier") {
			Sleep(1000);
			std::cout << "Sie haben leider verloren.." << std::endl;
		}
		else {
			std::cout << "Sie haben gewonnen!" << std::endl;
		}
		break;
	case(3):
		if (computer_züge[(zufallswert1 + zufallswert3) / 2] == Auswahlmöglichkeiten[eingabe - 1]) {
			Sleep(1000);
			std::cout << "Unentschieden!" << std::endl;
		}
		else if (computer_züge[(zufallswert1 + zufallswert3) / 2] == "Papier") {
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