// lotonum.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.


#include <iostream>
#include <string>

using namespace std;



int numLoto(int quantity, int efforts) { // quantity - Zahlenbereich   // efforts - Versuche
    srand(time(0));
    int randomNum = rand() % quantity + 1; //+ 1 schließt Null aus
    int effortCount = 1;
    cout << "you have a " << efforts << " efforts:  (fur Test ist Random Nummer sichtbar : " << randomNum <<")" << endl;

    do  {
        int effort;
        cout << "enter a number from 1 to " << quantity << " :" << endl;
        cin >> effort;


        if (effort && effort == randomNum) {
            cout << "you are win!!!" << endl;
            cout << "you used only " << effortCount << " efforts!";
            return 1;
        }
        else if (effort && efforts != effortCount && effort <= quantity) {
            if (effort < randomNum)  cout << "smaller number!" << endl;
            if (effort > randomNum)  cout << "number larger than!" << endl;
            cout << "try more" << endl;
            cout <<  "you have "<< efforts - effortCount << " more tries." << endl;
            effortCount++;
            
        }
        else if (efforts == effortCount && effort <= quantity) {
            cout << "all " << efforts << " efforts are over. You are lost.." << endl;
            return 0;
        }
        else {
            cout << "invalid number!\a" << endl;
            cout << "WARNING: Only !NUMBERS! FROM 1 TO " << quantity << " are to be entered" << endl;
            cin.clear(); // Zurücksetzen des Fehlerflags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Eingabepuffer löschen
             // falsche Versuche werden nicht gezählt
           
        }
    } while (effortCount <= efforts);

}


int main()
{
    numLoto(100, 3);

    return 0;

}


