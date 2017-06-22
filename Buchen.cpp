

#include "Buchen.h"

Buchen::Buchen(Kunde* k) {                                                      //Konstruktor: erstellt ein Buchenobjekt und weist dem Kundenpointer den übergebenen Kundenpointer zu
    p_bkunde = k;
}

Kunde* Buchen::getkunde() {                                                     //gibt den Kundenpointer des Buchenobjekts zurück
    return p_bkunde;
}





