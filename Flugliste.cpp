#include <string>
#include <iostream>
#include <fstream>
#include "Flugliste.h"

Flugliste::Flugliste(string f) {                                                //Konstruktor: erstellt ein Fluglistenobjekt und setzt den Flughafen gemäß Parameter
    flughafen = f;
}

void Flugliste::fluegeEinlesen() {
    string start;
    string ende;
    string time;
    string nr;
    bool breakpoint = false;
    fstream datei ("load.txt", ios::in);                                        //Erstellt ein Stream Objekt und lädt das Textdokument
    string line;                                                                                            
    while (breakpoint == false) {                                               //Liest solange Zeilen ein bis ein Punkt eingelesen wurde
            getline (datei, line);
            if (line == ".") {                                                  //Falls ein Punkt eingelesen wurde wird das einlesen beendet
                breakpoint = true;
                break;
            }
            start = line;
            getline (datei, line);
            ende = line;
            getline (datei, line);
            time = line;
            getline (datei, line);
            nr = line;
            liste.push_back(Flug(start, ende, time, nr));                       //erstellt ein Flugobjekt mit den eingelesenen Parametern
    
    
    }
    datei.close();                                                              //schließt datei nachdem einelsen
}

vector<Flug> Flugliste::flugSuchen() {
    return liste;
}

string Flugliste::getflughafen() {                                              //gibt den Flughafennamen der Flugliste zurück
    return flughafen;
}

vector<Flug> Flugliste::getFluege() {                                           //gibt den Vector in dem die Flüge gespeichert sind zurück
    return liste;
}



