using namespace std;
#include <vector>
#include "Flug.h"
#ifndef FLUGLISTE_H
#define FLUGLISTE_H

class Flugliste
{
public:
    Flugliste(string f);                                                        //Konstruktor, bekommt den zu setztenden Flughafennamen übergeben
    void fluegeEinlesen();                                                      //liest die Flüge aus einer Datei ein
    vector<Flug> flugSuchen();                                                  //gibt den vector mit Flügen zurück
    string getflughafen();                                                      //getter für den flughafen string
    vector<Flug> getFluege();                                                   //gibt den vector mit Flügen zurück
    
private:
    string flughafen;
    vector<Flug> liste;
};

#endif /* FLUGLISTE_H */

