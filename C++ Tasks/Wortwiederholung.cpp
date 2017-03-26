// Programm zur Überprüfung auf Wortwiederholungen 


#include "../../std_lib_facilities"

int main(){
    
    string current = " ";
    string previous;

    while(cin >> current){
         if(current == previous)
            cout << "Wiederholung: " << current << "\n";
         previous=current;  
       }
    
    keep_window_open();
    return 0;
}