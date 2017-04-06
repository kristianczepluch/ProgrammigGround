//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.153 4 Zahlenratespiel
// Programm welches innerhalb von 7 Fragen die Zahl durch ja/nein fragen ermitteln soll
// Im Grund genommen Binary Search

#include <iostream>
#include "../facilities.h"

int main() {
	int min = 1; //Untere Schranke
	int max = 100; //Obere Schranke
	string eingabe = "";

	// "(min - 1) + (max - (min -1)) / 2" geht an den Anfang der Elemente und dann bis zur Hälfte der Verdächtigen Elemente
	// was im falle das der wert darunter liegt die neue obere Schranke ist

	while (min  != max) { // Solange die Werte nicht gleich sind führe aus:
		std::cout << "Ist die Zahl kleiner oder gleich: " << (min - 1) + (max - (min - 1)) / 2 << "?" << std::endl; //Zahl kleiner oder gleich
		std::cin >> eingabe;                                                                                        //der Hälfte?
		if (eingabe == "Ja") { // Wenn Ja dann setze die Obereschranke auf die Hälfte
			max = (min - 1) + (max - (min - 1))/2; } 
		else {	min = min + ((max - (min - 1)) / 2); } // Wenn Nein dann hebe die untere Schranke bis +1 vor der hälfte an
	}
	std::cout << "Gesuchte Zahl ist: " << max << std::endl;
	keep_window_open();
	return 0;
}