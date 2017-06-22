#include "Flugliste.h"
#include "vector"
#include "Kunde.h"
#include "Buchen.h"
#include "Ticket.h"
using namespace std;


#ifndef GUI_H
#define GUI_H

class GUI
{
public:
    GUI();                                                                      //Standart Konstruktor
    ~GUI();                                                                     //Dekonstruktor: löscht die Tickets, Buchenobjekte und Fluglisten aus dem Heap
    void initialisieren();                                                      //Erstellt die Flugliste und Tickets
    void showmenue();                                                           //Zeigt das Menü für anmelden/Registieren/Flugsuchen/Flugbuchen an
    void registrieren();                                                        //Funktion um neuen Kunden zu erstellen(Benutzerregistrierung)
    void anmelden();                                                            //Fragt Anmeldedaten ab
    bool loginpruefen(string name, string pw);                                  //Bekommt name und passwort übergeben und prüft die kundenliste nach übereinstimmung
    void flugsuchen();                                                          //sucht nach Flügen mit dem eingegebenen Startflughafen
    void flugbuchen();                                                          //Funktion um Tickets für einen Flug zu buchen
    void ausloggen();                                                           //ausloggen des momentanen Kunden
    void showlist(vector<Flug> list);                                           //gibt die Flüge des übergebenen Flugvectors auf der Konsole aus
    void ticketAnzeigen(int liste, int flug, string klasse);                    //zeigt das gerade erstellte ticket an                    
private:
    vector<Flugliste*> p_liste;                                                 //Vector mit Fluglistenpointern für die verschiedenen Fluglisten(momentan nur eine)
    vector<Kunde> kundenliste;                                                  //vector in dem die Kundenobjekte gespeichert sind
    vector<Buchen*> p_buch;                                                     //vector für die Buchenobjekte
    vector<Ticket*> p_tickets;                                                  //vector mit Ticketpointern
    Kunde* p_kunde;                                                             //Kundenpointern der auf den eingeloggten Kunden zeigt
};

#endif /* GUI_H */

