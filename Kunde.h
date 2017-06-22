using namespace std;
#include <string>
#ifndef KUNDE_H
#define KUNDE_H

class Kunde
{
public:
    Kunde(string bname, string password, string rname, string datum, string telnr, string ibannr);      //Konstruktor: bekommt Parameter die Variablen des Objekts übergeben
    string getname();                                                                                   //getter für name
    string getpw();                                                                                     //getter für pw
    string getgebDatum();                                                                               //getter für gebDatum
    string gettel();                                                                                    //getter für tel
    string getIBAN();                                                                                   //getter für IBAN
    string getbenutzer();                                                                               //getter für benutzer
    
private:
    string name;                                                                                        //richtiger Name des Kunden
    string gebDatum;
    string tel;
    string IBAN;
    string benutzer;                                                                                    //Benutzername/Loginname des Kunden
    string pw;
};

#endif /* KUNDE_H */

