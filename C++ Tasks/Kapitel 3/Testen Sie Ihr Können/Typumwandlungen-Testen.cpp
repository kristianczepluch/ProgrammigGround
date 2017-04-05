// Programm zur Veranschaulichung verschiedener Typumwandlungen 
// Double zu Int, Int zu Char und Char zu Int
// Eignet sich gut zum realisieren wie der Compiler je nach festgelegtem Datentyp die gespeicherten Bits interpretiert
// und welche Umwandlungen überhaupt möglich sind.

#include <iostream>

int main() {
	double d = 0;
	while (std::cin >> d) {
		int i = d;
		char c = i;
		int i2 = c;
		
		std::cout << "d==" << d << "\n" << "i==" << i << "\n" << "i2==" << i2 << "\n" << "char==" << c << "\n";
	}
	system("pause");
}