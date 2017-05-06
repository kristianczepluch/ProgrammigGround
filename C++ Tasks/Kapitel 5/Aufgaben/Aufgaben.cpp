//Bjarne Stroustrup Einf�hrung in die Programmierung mit C++
// Kapitel 5, S.189 Aufgaben 25 Code-Fragmente Debuggen
// Liste der Fehler:

//  1.) Klammern f�r den Funktionsrumpf der Main nicht vorhanden und Cout gro�geschrieben
//  2.) Schlie�endes Anf�hrungzeichen bei der �bergabe des Strings an den Ausgabestream nicht vorhanden
//  3.) �ffnendes Anf�hrungszeichen bei der �bgergabe des String "\n" nicht vorhanden und Semikolon am Ende fehlt ebenfalls
//  4.) success wird in den Ausgabestream gelesen ohne vorher definiert und initialisert worden zu sein 
//  5.) string Variable versucht int zu speichern (Typfehler) 
//  6.) Index wurde versucht mit runden klammern zu �bergeben 2x, und um erfolg ausgeben zu lassen wird aus "!=" ein "=="
//  7.) "cond" nicht definiert, Cond Deklarieren und mit true initialisieren f�hrt zu Erfolg!
//  8.) c steht auf false -> auf true setzen
//  9.) boolean falsch initialisiert (l vergessen) und f�r die Ausgabe muss der Vergelchsopeartor umgedreht werden da N nach A im alphabet kommt und somit c dann true ist
// 10.) == durch != ersetzen
// 11.) ein "<" beim einlesen in den Ausgabestream vergessen
// 12.) String addition nicht m�glich und if Anweisung muss einen wahrheitswert enthalten..? zb. s!="Narr"
// 13.) for-schleifen Bedingung ist immer true das die Size des Vektors 5 ist und 0 immer kleiner als 5 ist => 0 durch i ersetzen um Schleife 5x zu durchlaufen
// 14.) Erzeugt an sich keinen Fehler aber wenn man jetzt mit dem Index auf ein Element for v zugreifen will innerhalb der for schleife k�nnte man einen out of range error verursachen
// 15.) Keine wirklichen Fehler vorhanden, jedoch k�nnte man bei der Bedingung i<8 einf�gen um auch den kompletten String ausgeben zu lassen (oder s.size())
// 16.) then ist ein nicht deklarierter Bezeichner => einfach then weglassen
// 17.) Fehler der Wert von x ist zu gro� um ihn in einen Char zu speichern => Werteverlust , statt char einfach int verwenden
// 18.) Fehler bei Zugriff auf Index 10, der String enth�lt 9 Zeichen: E r f o l g ! / n
// 19.) Bei der Deklaration von Vektor wurde vergessen ihm zu sagen welche Art von Elementen er speichern soll
// 20.) Endlosschleife da i nicht ver�ndert wird und die if-Anweisung nie true wird. statt ++j -> ++i
// 21.) 1.) Es wird durch 0 geteilt. 2.) Gefahr beim Vergleich von 2 Float Werten, da diese meist nur durch eine eingeschr�nkte Zahl an Bits angen�hert werden k�nnen "==" riskant
//      Bei der L�sung 2.8155.. die sich durch  5/(x-2) = 2x + 0.5 ergibt sollte man statt zu vergleichen lieber die differenz Bilden und �berpr�fen ob x Nachkommastellen identisch sind.
//      Au�erdem w�re es sinnvoll vor dem initialiseren von d zu schauen ob (x-2) = 0 ist.
// 22.) Falls es das Ziel ist einen char Vektor mit den einzelen chars von erfolg zu f�llen und auszugeben dann muss statt string ein vector dort stehen und dann durch  push_back
//      jeder Buchstabe eingelesen werden und zum Schluss bei der Schleife die Bedinung and die size von s angepasst werden. Oder halt nur einen string zu deklarieren und intialieren und
//      dann die Bedinung �ndern.
// 23.) j wurde nicht deklariert+(endlosschleife). Wenn man i in der Schleife immer um 1 erh�ht und j um eins verringert, nachdem man j mit 19 deklariert, kommt man zum gew�nschten ergebnis
// 24.) Im Grunde genommen kein Fehler da in der if-Anwesiung kein Vergleich sondern eine zuweisung stattfindet.. ob das so vorgesehen war? 
// 25.) Fehler da cin keinen contanten char als Eingabe akzeptiert. Statt dem String einfach selbst einen String eingeben.

#include "std_lib_facilities.h"


int main() {
	try {
		// Code_aus_den_Aufgaben_einf�gen() //
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "Fehler: " << e.what() << '\n';
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Hoppla: unbekannte Ausnahme!\n";
		keep_window_open();
		return 2;
	}
}