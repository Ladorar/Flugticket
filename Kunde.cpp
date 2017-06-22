
#include "Kunde.h"

Kunde::Kunde(string bname, string password, string rname, string datum, string telnr, string ibannr) {      //Konstruktor: Erstellt ein Kundeobjekt und setzt Variablen gemäß 
    benutzer = bname;                                                                                       //der übergebenen Parameter
    pw = password;
    name = rname;
    gebDatum = datum;
    tel = telnr;
    IBAN = ibannr;
}

string Kunde::getname() {                                                       //gibt den Namen des Kunden zurück
    return name;
}

string Kunde::getpw() {                                                         //gibt das Passwort zurück
    return pw;
}

string Kunde::getgebDatum() {                                                   //gibt das Geburtsdatum zurück
    return gebDatum;
}

string Kunde::gettel() {                                                        //gibt die Telefonnummer zurück
    return tel;
}

string Kunde::getIBAN() {                                                       //gibt die IBAN zurück
    return IBAN;
}

string Kunde::getbenutzer() {                                                   //Gibt den Benutzernamen/Loginnamen zurück
    return benutzer;
}


