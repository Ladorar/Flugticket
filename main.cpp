#include "GUI.h"
#include <cstdlib>

using namespace std;


int main() {
    GUI test;                                                                   //Erstellt ein GUI Objekt mit dem Standart Konstruktor
    test.initialisieren();                                                      //Initialisiert die Flugliste und Flüge
    test.showmenue();                                                           //Ziegt das Anmeldemenä und das Flugsuchen/buchenmenü an
    return 0;
}

