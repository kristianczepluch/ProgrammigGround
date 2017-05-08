//Bjarne Stroustrup Einführung in die Programmierung mit C++
// Kapitel 5, S.191 Übungen 11.)
// Program, welches einem die Fibonacci-Zahlen berechnet und ausgibt bis der Speicherplatz für Int vollläuft (ab. der 47 Fibo-Zahl negative Werte => 4Byte reichen nicht mehr aus)
// ++ Diesmal mit der Bib climit die größte Zahl die in einem Int auf diesem Compiler gespeichert werden kann ermittelt und diese in die Bedinung der while-Schleife geschrieben
// um somit "ausprobieren zu vermeiden" => Größe könnte man i.d.R auch berechnen mit 2^((sizeof(int)*8)-1) => size of liefer 4 Byte zurück also 32 bit und die größte darstellbar Zahl
// mit 32 bit ist 2 hoch 32-1

#include "std_lib_facilities.h"
#include <limits>
#include <climits>



int main() {

	int fibo1 = 1;
	int fibo2 = 1;
	int newFibo = 1;
	vector<int> v;
	int sizeOfIntInBit = sizeof(int) * 8;
	v.push_back(fibo1);
	v.push_back(fibo2);

	
	std::cout << "Groesse des Int Speichers in Byte : " << sizeOfIntInBit << std::endl;
	std::cout << "Maximaler Wert, der in einem Int gespeichert werden kann: " << INT_MAX  << std::endl;
	std::cout << "Fibonacci-Zahl Nr. 1: " << fibo1 << std::endl;
	std::cout << "Fibonacci-Zahl Nr. 2: " << fibo2 << std::endl;
	int i = 1;
	while (newFibo<INT_MAX && newFibo>0) {
		newFibo = v[i] + v[i - 1];
		v.push_back(newFibo);
		std::cout << "Fibonacci-Zahl Nr. " << i + 2 << ": " << newFibo << std::endl;
		++i;
	}
	keep_window_open();
	return 0;
}