
#include <iostream>
#include "GUI.h"
#include "Ticket.h"

GUI::GUI() {                                                                                //Konstruktor: setzt den Kundenpointer auf 0 und erstellt einen Kunden objekt für das bessere Testen
    p_kunde = 0;
    kundenliste.push_back(Kunde("123", "123", "123", "123", "123", "123"));                 //Neuer Kunde anlegen für besseres Testen 
}

GUI::~GUI() {
    for (int j = 0; j < p_tickets.size(); j++) {                                            //For schleife welche den ticket vector hochzählt und die Tickets aus dem Heap löscht
        delete p_tickets[j];
    }
    for (int i = 0; i < p_buch.size(); i++) {                                               //For schleife welche den buchen vector hochzählt und die Buchenobjekte aus dem Heap löscht
        delete p_buch[i];
    }
    delete p_liste[0];                                                                      //Löscht die Flugliste aus dem Heap
}


void GUI::initialisieren() {  
    Flug* temp;
    p_liste.push_back(new Flugliste("Frankfurt"));                                          //erstellt eine neue Flugliste und pusht diese in den vector für Fluglistenpointer
    p_liste[0]->fluegeEinlesen();                                                           //ruft die Flüge einlesen Funkktion für die gerade erstelle Liste auf
    for (int h = 0; h < p_liste[0]->getFluege().size(); h++) {                              //for schleife die die Flugvektorgröße hochzählt
        temp = &p_liste[0]->getFluege()[h];
        for (int i = 0; i < 10; i++) {                                                      //for schleife die jeweils 10 Tickets erstellt und in den Ticket vector pusht
            p_tickets.push_back(new Ticket("Economy", temp));
            p_tickets.push_back(new Ticket("Business", temp));
        }
    } 
}


void GUI::registrieren() {                                                                  // fragt den benutzer nach seinen Daten und schreibt diese in die string variablen
    string username, password, IBAN, name, date, tel;
    cout << "<<<Neuer Benutzer Registrieren>>>" << endl;                        
    cout << "Benutzername: ";
    cin >> username;
    cout << endl << "Passwort: ";
    cin >> password;
    cout << endl << "Name: ";
    cin >> name;
    cout << endl << "Geburtsdatum: ";
    cin >> date;
    cout << endl << "Telefonnummer: ";
    cin >> tel;
    cout << endl << "IBAN: ";
    cin >> IBAN;
    cout << endl << "Neuer Benutzer registriert!" << endl;
    kundenliste.push_back(Kunde(username, password, name, date, tel, IBAN));                //ruft den Kundenkosntruktor auf und übergibt die string variablen um neuen Kunden zu erstellen und 
}                                                                                           //in die Kundenliste zu pushen


void GUI::anmelden() {                                                                      //fragt Benutzer nach Benutzername und Passwort
    string username, password;
    cout << "Benutzername: ";
    cin >> username;
    cout << endl << "Passwort: ";
    cin >> password;
    if (loginpruefen(username, password) == true) cout << "Login erfolgreich!" << endl;     //Loginprüfen wird aufgerufen und username und password übergeben  
    else cout << "Login fehlgeschalgen" << endl;                                            //Falls loginprüfen true zurück gibt wurde erfolgreich eingeloogt anosnten login fehlgeschlagen
}


bool GUI::loginpruefen(string name, string pw) {                                
    for (int i = 0; i < kundenliste.size(); i++) {                                          //For schleife welche die Kundenliste durchgeht
        if (kundenliste[i].getbenutzer() == name) {                                         //Falls Benutzername gleich dem übergebenen Benutzername enspricht
            if (kundenliste[i].getpw() == pw) {                                             //und das Passwort des selben Kunde dem übergebenen Passwort enspricht
                p_kunde = &kundenliste[i];                                                  //setzt den Kundenpointer auf den momentan geprüften Kunden und gibt true zurück
                return true;
            }
        }
    }
    return false;                                                                           //gibt false zurück falls keine übereinstimmung
}


void GUI::showlist(vector<Flug> list) {
    for (int i = 0; i < list.size(); i++) {                                                 //For schleife geht die übergebene Flugliste durch und printet die Informationen jedes Fluges
        cout << "________________________________" << endl;
        cout << "Startflughafen: " << list[i].getstart() << endl;
        cout << "Zielflughafen: " << list[i].getziel() << endl;
        cout << "Abflugzeit: " << list[i].gettime() << endl;
        cout << "Flugnummer: " << list[i].getnr() << endl;
        cout << "EconomyClass-Preis: " << list[i].geteco() << endl;
        cout << "BusinessClass-Preis: " << list[i].getbusi() << endl;
    }
    cout << "________________________________" << endl;
}


void GUI::flugsuchen() {                                                                    //Fragt nach dem Startflughafen
    string start;
    cout << "Startflughafen: ";
    cin >> start;
    cout << endl;
    for (int i = 0; i < p_liste.size(); i ++) {                                             //For schleife geht den Vector mit Fluglistenpointern durch
        if (p_liste[i]->getflughafen() == start) {                                          //Prüft ob eine Flugliste den selben Flughafen hat wie der vom benutzer eingegebene Flughafen
            showlist(p_liste[i]->flugSuchen());                                             //Bei übereinstimmung wird showlist aufgerufen mit dem von flugsuchen zurückgegebenen Flugvector
            return;
        }
    }
    cout << "Keine Flugliste gefunden!" << endl;                                            //Bei keiner übereinstimmung Fehlermeldung
}


void GUI::flugbuchen() {                                                                    //Fragt nach Flugnr, ticketanzahl und flugklasse
    int ecocounter = 0;
    int busicounter = 0;
    int anzahl;
    char klasse;
    string flugnr;
    cout << "Für welchen Flug sollen die Tickets gebucht werden?(Flugnummer)" << endl;      
    cin >> flugnr;
    cout << "Wieviele Tickets sollen gebucht werden?" << endl;
    cin >> anzahl;
    cout << "In welcher Klasse sollen die Tickets gebucht werden?" << endl;
    cout << "1 = Economy Class" << endl << "2 = Business Class" << endl;
    cin >> klasse;
    for (int j = 0; j < p_liste.size(); j++) {                                              //For schelife geht den Fluglistenpointer Vektor durch
        for (int k = 0; k < p_liste[j]->getFluege().size(); k++) {                          //For schleife geht die Flugliste des momentanen Fluglistenpointer durch
            if (p_liste[j]->getFluege()[k].getnr() == flugnr) {                             //if abfrage ob die Flugnummer des Fluges mit der eingegebenen Flugnummer übereinstimmt
                for (int i = 0; i < p_tickets.size(); i++) {                                //For schleife geht die tickets durch bei Flugnummerübereinstimmung
                    if (p_tickets[i]->getverfuegbarkeit() == true) {                        //if abfrage ob Ticket verfügbar ist
                        if (p_tickets[i]->getklasse() == "Economy") ecocounter++;           //Falls verfügbar und ticket für economy klasse ist wird der ecocounter erhöht
                        else busicounter++;                                                 //ansonsten der busicounter
                    }
                }
                if (klasse == '1') {                                                        //Falls Benutzer Economy Class Tickets will
                    if (ecocounter >= anzahl) {                                             //Prüft ob genügend Tickets vorhanden sind
                        
                            for (int l = 0; l < p_tickets.size(); l++) {                    //For schleife welche die Tickets durchgeht
                                if (p_tickets[l]->getverfuegbarkeit() == true) {            //Falls Ticket verfügbar
                                    if (anzahl > 0) {                                       //If abfrage damit nur die benötigte anzahl gebucht wird
                                    if (p_tickets[l]->getklasse() == "Economy") {           //If abfrage ob die Klasse mit Economy übereinstimmt
                                        p_tickets[l]->setverfuegbarkeit(false);             //Verfügbarkeit wird auf false gesetzt
                                        Buchen* temp;                                       
                                        temp = new Buchen(p_kunde);                         //Neues Buchenobjekt wird durch den Buchen Konstruktor erstellt 
                                        p_tickets[l]->setbuchen(temp);                      //Dem momentanen ticket wird Buchenobjekt zugewiesen
                                        p_buch.push_back(temp);                             //Buchenobjekt wird in den Buchenvector gepusht
                                        ticketAnzeigen(j, k, "Economy Class");              //ticket anzeigen wird aufgerufen und die forschleifen counter für j(liste) und k(flug) übergeben
                                        anzahl--;                                           //Ticket Informationen werden ausgegeben und die anzahl der benötigten Tickets verringert
                                    }
                                    }
                                }
                            }                                                               
                        
                    }else cout << "Nicht genügend Tickets vorhanden!" << endl;              //Fehlermeldung falls nicht genügend Tickets vorhanden sind
                }else{                                                                      //Falls der Kunde Business Class Tickets will
                    if (busicounter >= anzahl) {                                            //Prüft ob genügend Tickets vorhanden sind
                        
                            for (int l = 0; l < p_tickets.size(); l++) {                    //For schleife welche die Tickets durchgeht
                                if (p_tickets[l]->getverfuegbarkeit() == true) {            //Falls Ticket verfügbar
                                    if (anzahl > 0) {                                       //If abfrage damit nur die benötigte anzahl gebucht wird
                                    if (p_tickets[l]->getklasse() == "Business") {          //If abfrage ob die Klasse mit Businesss übereinstimmt
                                        p_tickets[l]->setverfuegbarkeit(false);             //Verfügbarkeit wird auf false gesetzt
                                        Buchen* temp;
                                        temp = new Buchen(p_kunde);                         //Neues Buchenobjekt wird durch den Buchen Konstruktor erstellt
                                        p_tickets[l]->setbuchen(temp);                      //Dem momentanen ticket wird Buchenobjekt zugewiesen
                                        p_buch.push_back(temp);                             //Buchenobjekt wird in den Buchenvector gepusht
                                        ticketAnzeigen(j, k, "Business Class");             //ticket anzeigen wird aufgerufen und die forschleifen counter für j(liste) und k(flug) übergeben
                                        anzahl--;                                           //anzahl der benötigten Tickets wird verringert
                                    }
                                    }
                                }
                            }
                        
                    }else cout << "Nicht genügend Tickets vorhanden!" << endl;              //Fehlermeldung falls nicht genügend Tickets vorhanden sind
                }
            }
        }
    }
} 

void GUI::ticketAnzeigen(int liste, int flug, string klasse) {
    cout << "Ticket für Flugnummer " << p_liste[liste]->getFluege()[flug].getnr() << endl;
    cout << "Von " << p_liste[liste]->getFluege()[flug].getstart() << " nach " << p_liste[liste]->getFluege()[flug].getziel() << endl;
    cout << "Startzeit: " << p_liste[liste]->getFluege()[flug].gettime() << endl;
    cout << klasse << endl;
    cout << "Besitzer: " << p_kunde->getname() << endl;
}




void GUI::ausloggen() {                                                                     //Setzt den Kundenpointer auf 0
    p_kunde = 0;
}


void GUI::showmenue() {                                                                     //Zeigt das Menü an
    string username, password, IBAN, name, date, tel;
    int input;
    while (1) {                                                                             //while schleife damit das menü ständig aktiv ist
        if (p_kunde == 0) {                                                                 //Falls der Kundenpointer auf nichts zeigt wird das Anmelde-/Registrierungsmenü angezeigt
            cout << "<<<Menue>>>" << endl;
            cout << "1. Anmelden" << endl;
            cout << "2. Registrieren" << endl;
            cout << "0. Beenden" << endl;
            cin >> input;                                                       
            if (input == 1) anmelden();                                                     //If abfrage welcher Menüpunkt gewählt wurde bei 1: anemlden funktion wird aufgerufen
            else if (input == 2) registrieren();                                            //bei 2:registrieren funktion wird aufgerufen
            else if (input == 0) return;                                                    //bei 0: programm wird beendet
        }
        else {
            cout << "<<<Menue>>>" << endl;                                                  //Falls der Kundepointer auf etwas zeigt wird das Flugsuchen/buchen Menü aufgerufen
            cout << "1. Flug suchen" << endl;
            cout << "2. Flug buchen" << endl;
            cout << "0. Ausloggen" << endl;
            cin >> input;
            if (input == 1) flugsuchen();                                                   //If abfrage welcher Menüpunkt gewählt wurde bei 1: flugsuchen funktion wird aufgerufen
            else if (input == 2) flugbuchen();                                              //bei 2: flugbuchen funktion wird aufgerufen
            else if (input == 0) ausloggen();                                               //bei 0: ausloggen funktion wird aufgerufen
        }
    }
}

