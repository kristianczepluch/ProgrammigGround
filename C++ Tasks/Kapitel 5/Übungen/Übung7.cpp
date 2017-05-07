//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 5, S.191 �bungen 7.)
// Program, welches einem die L�sungsmenge f�r quadratische Gleichungen berechnet. Ung�ltige Angaben werden abgefangen und weiter Fehler wie das teilen durch 0 und das Wurzel ziehen
// von negativen Zahlen werden abgefagen => Keine L�sung

#include "std_lib_facilities.h"
#include <limits>

int main() {

	try{
		double a;
		double b;
		double c;

		double x1;
		double x2;

		

		std::cout << "Bitte geben Sie die Werte a,b,c getrennt mit einer Leertaste f�r die Gleischung ax�+bx+c=0 ein:  " << std::endl;
		std::cin >> a >> b >> c;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			std::cout << "Ung�ltige Eingbabe! Erneuter Versuch: ";
			cin >> a >> b >> c;
		}

		if ((2 * a) == 0) {
			std::cout << "Die Gleichung hat keine L�sungen!" << std::endl;
		}
		else if (((b*b) - (4 * a*c))<0) {
			std::cout << "Die Gleichung hat keine L�sungen!" << std::endl;
		}
		else {
			x1 = (-b + sqrt((b*b) - (4 * a*c))) / (2 * a);
			x2 = (-b - sqrt((b*b) - (4 * a*c))) / (2 * a);

			std::cout << "Die L�sungen lauten: x1= " << x1 << ", x2= " << x2 << std::endl;
			}
			keep_window_open();
			return 0;
	}
	catch (runtime_error& s) {
		std::cerr << s.what() << std::endl;
		keep_window_open();
		return 1;
	}
}