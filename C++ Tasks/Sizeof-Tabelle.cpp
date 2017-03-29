// Programm, welches mit Hilfe von climits die Größe der Variablen tabellarisch ausgibt.
// iomanip wird verwendet um einzelne Stellen einzurücken

#include <iostream>
#include <climits>
#include <iomanip>

int main() {
	std::cout << "Datentyp\tGroesse in Byte" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "Short" << std::setw(12) << sizeof(short) << std::endl;
	std::cout << "Integer" << std::setw(10) << sizeof(int) << std::endl;
	std::cout << "Long" << std::setw(13) << sizeof(long) << std::endl;
	std::cout << "Long Long" << std::setw(8) << sizeof(long long) << std::endl;
	std::cout << "Char" << std::setw(13) << sizeof(char) << std::endl;
	std::cout << "Float" << std::setw(12) << sizeof(float) << std::endl;
	std::cout << "Double" << std::setw(11) << sizeof(double) << std::endl;
	std::cout << "Long Double" << std::setw(6) << sizeof(long double) << std::endl;
	system("pause");
}