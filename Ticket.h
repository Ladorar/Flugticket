using namespace std;
#include <string>
#include "Buchen.h"
#include "Flugliste.h"

#ifndef TICKET_H
#define TICKET_H

class Flug;

class Ticket
{
public:
    Ticket(string k, Flug* f);                                            //Konstruktor: bekommt parameter für die Flugklasse und den Flugpointer übergeben
    bool getverfuegbarkeit();                                                   //getter für die verfuegbarkeit
    void setverfuegbarkeit(bool v);                                             //setter für die verfuegbarkeit
    string getklasse();                                                         //gettter für klasse
    void setbuchen(Buchen* b);                                                  //setter für den Buchenpointer
    Flug* gettflug();                                                           //getter für den Flugpointer
    Buchen* getbuchen();                                                        //getter für den Buchenpointer
private:
    bool verfuegbarkeit;                                                        // (true=verfügbar, false=nicht verfügbar)
    string klasse;
    Buchen* p_tbuchen;                                                          //Buchenpointer zeigt auf das Buchenobjekt für das Ticket
    Flug* p_tflug;                                                              //Flugpointer zeigt auf den Flug für den das ticket gültig ist
};

#endif /* TICKET_H */

