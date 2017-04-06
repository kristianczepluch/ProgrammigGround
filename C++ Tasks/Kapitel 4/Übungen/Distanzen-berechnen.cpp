//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 4, S.153 3 �bung
// Programm welches den Median berechnet

#include <iostream>
#include "../facilities.h"

int main() {

	vector<double> numbers;
	double temp = 0;
	double median = 0;
	double summe = 0;

	while (std::cin >> temp) {
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());
	std::cout << "Ihr eingabe sortiert: ";

	for (int i = 0; i < numbers.size(); ++i) {
		summe += numbers[i];
		std::cout << numbers[i] << ", ";
	}
	std::cout << "Die Summe der Distanzen betr�gt: " << summe << "\nDer kleinste Wert betr�gt: " << numbers[0] << ".\nDer gr��te Wert betr�gt: " << numbers[numbers.size()-1] 
		      << "\nDer durchschnittliche Wert (Summe der Distanzen/Anzahl der Distanzen) betr�gt: " << summe / numbers.size() << std::endl;
	system("Pause");
	return 0;
}