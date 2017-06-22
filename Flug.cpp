

#include "Flug.h"

Flug::Flug(string start, string ende, string time, string nr) {                 //Konstruktor: erstellt ein Flug Objekt und setzt die Variablen gemäß der übergebenen Parameter
    startflughafen = start;
    zielflughafen = ende;
    abflugzeit = time;
    flugnr = nr;
    preiseco = 160;
    preisbusi = 210;
}

string Flug::getstart() {                                                       //gibt den Startflughafen zurück
    return startflughafen;
}

string Flug::getziel() {                                                        //gibt den Zielflughafen zurück
    return zielflughafen;
}

string Flug::gettime() {                                                        //gibt die Ablugzeit zurück
    return abflugzeit;
}

string Flug::getnr() {                                                          //gibt die Flugnummer zurück
    return flugnr;
}

double Flug::getbusi() {                                                        //gibt den Preis für ein BusinessClass Ticket zurück
    return preisbusi;
}

double Flug::geteco() {                                                         //gibt den Preis für ein EconomyClass Ticket zurück
    return preiseco;
}


