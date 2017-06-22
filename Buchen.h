#include "Kunde.h"

#ifndef BUCHEN_H
#define BUCHEN_H

class Buchen
{
public:
    Buchen(Kunde* k);                                                           //Konstruktor: bekommt Kundenpointer übergeben
    Kunde* getkunde();                                                          //getter für den Kundenpointer
private:
    Kunde* p_bkunde;

};

#endif /* BUCHEN_H */

