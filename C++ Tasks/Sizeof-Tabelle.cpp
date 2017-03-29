// Programm, welches mit Hilfe von climits die Gr��e der Variablen tabellarisch ausgibt.
// iomanip wird verwendet um einzelne Stellen einzur�cken
// Tats�chlich definiert sich Byte nicht automatisch mit 8 bits (i.d.R schon) jedoch ist mit Byte die L�nge des Chars gemeint.
// welcher aber i.d.R aus 8 bits besteht. 
// 4 Bedeutet zb. also das 4-fach der l�nge von Char, was 4 Byte bedeutet bei einem Compiler der 8 bit f�r einen Char vorsieht.

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