//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 5, S.191 Übungen 11.)
// Program, welches einem die Fibonacci-Zahlen berechnet und ausgibt bis der Speicherplatz für Int vollläuft (ab. der 47 Fibo-Zahl negative Werte => 4Byte reichen nicht mehr aus)

#include "std_lib_facilities.h"
#include <limits>



int main() {

	int fibo1 = 1;
	int fibo2 = 1;
	int newFibo = 0;
	vector<int> v;
	v.push_back(fibo1);
	v.push_back(fibo2);

	std::cout << "Fibonacci-Zahl Nr. 1: " << v[0] << std::endl;
	std::cout << "Fibonacci-Zahl Nr. 2: " << v[1] << std::endl;

	int i = 1;
	while (i<46) {
		newFibo = v[i] + v[i - 1];
		v.push_back(newFibo);
		std::cout << "Fibonacci-Zahl Nr. " << i + 2 << ": " << newFibo << std::endl;
		++i;
	}
	keep_window_open();
	return 0;
}