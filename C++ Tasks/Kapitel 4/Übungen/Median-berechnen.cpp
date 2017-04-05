//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 4, S.153 1 Übung
// Programm welches den Median berechnet

#include <iostream>
#include "../facilities.h"


int main() {
	vector<double> numbers;
	double temp = 0;
	double median = 0;

	while (std::cin >> temp) {
		numbers.push_back(temp);
	}
	sort(numbers.begin(), numbers.end());
	std::cout << "Ihr eingabe sortiert: ";

	for (int i = 0; i < numbers.size(); ++i) {
		std::cout << numbers[i] << ", ";
	}

	if (numbers.size() % 2 == 0) {
		median = (numbers[(numbers.size()/2)-1] + numbers[(numbers.size() / 2)]) / 2;
	}
	else {
		median = numbers[(numbers.size() / 2)];
	}
	std::cout << "Der Median beträgt: " << median << std::endl;


	system("Pause");
	return 0;
}