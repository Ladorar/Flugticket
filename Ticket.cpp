

#include "Ticket.h"


Ticket::Ticket(string k, Flug* f) {                                             //Konstruktor: erstellt ein Ticketobjekt, setzt die Flugklasse und den Flugpointer gemäß 
    klasse = k;                                                                 //der übergebenen Parameter. Buchenpointer standartmäßig ein Nullpointer und verfügbarkeit true
    p_tflug = f;
    p_tbuchen = 0;
    verfuegbarkeit = true;
}

void Ticket::setverfuegbarkeit(bool v) {                                        //setzt die Verfügbarkeit gemäß des übergebenen Parameters
    verfuegbarkeit = v;
}

bool Ticket::getverfuegbarkeit() {                                              //gibt die Verfügbarkeit als bool wert zurück 
    return verfuegbarkeit;
}

string Ticket::getklasse() {                                                    //gibt die Flugklasse des Tickets zurück
    return klasse;
}

void Ticket::setbuchen(Buchen* b) {                                             //setzt den buchenpointer gemäß des übergebenen Parameters
    p_tbuchen = b;
}

Flug* Ticket::gettflug() {                                                      //gibt den Flugpointer zurück
    return p_tflug;
}

Buchen* Ticket::getbuchen() {                                                   //gibt den Buchenpointer zurück
    return p_tbuchen;
}