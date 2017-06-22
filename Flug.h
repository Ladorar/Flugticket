using namespace std;
#include <string>
#ifndef FLUG_H
#define FLUG_H

class Flug
{
public:
    Flug(string start, string ende, string time, string nr);                    //Konstruktor: bekommt Parameter für start- endflughafen zurück, sowie Abflugzeit und Flugnummer
    string getstart();                                                          //getter für startflughafen
    string getziel();                                                           //getter für zielflughafen
    string gettime();                                                           //getter für abflugzeit
    string getnr();                                                             //getter für flugnr
    double geteco();                                                            //getter für preiseco
    double getbusi();                                                           //getter für preisbusi
private:
    string startflughafen;
    string zielflughafen;
    string abflugzeit;
    string flugnr;
    double preiseco;
    double preisbusi;
    
    
};

#endif /* FLUG_H */

