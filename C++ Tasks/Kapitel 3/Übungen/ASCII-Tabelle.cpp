
//Programm zur erzeugung einer ASCII Tabelle mithilfe der Typumwandlung von char zu int und umgekehrt.

#include "../../std_lib_facilities.h"

int main() {

	char numbers = 'a';
	int asci_number = numbers;
     
	for (int i = 0; i < 26; i++) {
		cout << numbers << " in ASCII: " << asci_number << "\n";
		asci_number++;
		numbers = asci_number;
	}

	keep_window_open();
	return 0;
}
